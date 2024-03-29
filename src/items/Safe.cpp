#include "engine.h"
#include "items.h"

#include <iostream>
#include <algorithm>
#include <string>

using namespace CliKit;
using namespace std;

namespace SafeUtils {
	bool exists(vector<Item> vector, Item *item);
	bool isNumber(string s);
	string defaultPrint(Item *i, int index);
	int matchItem(vector<Item *> items, string name);
	int matchItem(vector<Item *> items, int index);
	void printAvailableCommands(Prompt p);
}  // namespace SafeUtils

void Safe::search(Player *player) {
	if (this->isLocked) {
		println("Safe is locked", 0);
		return;
	}

	println("Searching the safe...");
	printItems();

	Prompt p;
	p.prompt_char = '#';
	p.accepted_commands = {"collect", "exit", "help", "save"};
	Response r;

	while (r.command != "exit") {
		r = prompt(p);
		this->run(r, p, player);
	}
}

void Safe::run(Response response, Prompt p, Player *player) {
	CollectableItem *ci;
	SaveableItem *si;
	int item_index;

	switch (response.args.size()) {
		case 0:
			if (response.command == "exit") {
				return;
			} else if (response.command == "help") {
				SafeUtils::printAvailableCommands(p);
			} else if (response.command == "save") {
				cout << Text::red + "save" + Text::normal + " needs 1 argument" << endl;
				return;
			}
			break;
		case 1:
			if(SafeUtils::isNumber(response.args.at(0))){
				item_index = SafeUtils::matchItem(this->bundle_items, stoi(response.args.at(0)));
			} else {
				item_index = SafeUtils::matchItem(this->bundle_items, response.args.at(0));
			}

			if (item_index < 0) {
				cout << "Invalid argument" << endl;
				return;
			}

			ci = dynamic_cast<CollectableItem *>(this->bundle_items.at(item_index));
			si = dynamic_cast<SaveableItem *>(this->bundle_items.at(item_index));

			if (response.command == "collect" && ci != NULL) {
				ci->collect(player, this);
			} else if (response.command == "save" && si != NULL) {
				si->save();
			} else {
				println("The command doesn't match the item", 0);
			}

			break;
		default:
			println("This number of arguments is not yet implemnted", 0);
			break;
	}
}

void Safe::printItems() {
	for (int i = 0; i < bundle_items.size(); i++) {
		cout << SafeUtils::defaultPrint(bundle_items.at(i), i);
		ReadableItem *ri = dynamic_cast<ReadableItem *>(bundle_items.at(i));
		if (ri != NULL) {
			(ri->contents.size() > 50) ? cout << ", Contents: [Too long - Save to vault/]" : cout << ", Contents: " << ri->contents;
		}
		cout << endl;
	}
}

void Safe::unlock() { this->isLocked = false; }

bool Safe::enterPasscode() {
	string passcode;
	if (!this->isLocked) {
		println("Safe is already unlocked", 0);
		return true;
	}

	print("Enter passcode: ");
	getline(cin, passcode);

	if (!SafeUtils::isNumber(passcode)) {
		println("Invalid passcode", 0);
		return false;
	}

	if (stoi(passcode) != this->passcode) {
		println("Wrong passcode");
		return false;
	} else {
		this->unlock();
		println("Safe unlocked", 0);
		return true;
	}
}

int SafeUtils::matchItem(vector<Item *> items, int index) {
	if (index > items.size() || index < 1) return -1;

	return index - 1;
}

int SafeUtils::matchItem(vector<Item *> items, string name) {
	for (int i = 0; i < items.size(); i++) {
		if (name == items.at(i)->getName()) {
			return i;
		}
	}
	return -1;
}

void SafeUtils::printAvailableCommands(Prompt p) {
	println("-" + Text::b_green + "Available commands" + Text::normal + "-", 0);
	for (int i = 0; i < p.accepted_commands.size(); i++) {
		cout << Text::red << i + 1 << ". " << Text::normal << p.accepted_commands.at(i)
			<< endl;
	}
}

bool SafeUtils::isNumber(string s) {
	return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
			return !std::isdigit(c);
			}) == s.end();
}

string SafeUtils::defaultPrint(Item *i, int index) {
	return to_string(index + 1) + ". Type: " + i->getName() +
		", Description: " + i->getDescription();
}

// Utils
bool SafeUtils::exists(vector<Item> vector, Item *item) {
	for (size_t i = 0; i < vector.size(); i++) {
		if (vector.at(i).getItemId() == item->getItemId()) return true;
	}

	return false;
}
