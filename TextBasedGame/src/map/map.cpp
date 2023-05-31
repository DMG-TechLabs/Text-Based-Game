#include "map.h"

#include "../items/items.h"

using namespace Engine;

string nodesToString(vector<Node *> nodes);

void Map::initMap() {
    // Init nodes
    Node *node1 = new Node(1, "Room 1", true);
    node1->addItem(new Door());

    Node *node2 = new Node(2, "Room 2", true);
    node2->addItem(new Door());

    Node *node3 = new Node(3, "Room 3", true);
    node3->addItem(new Door());

    Node *node4 = new Node(4, "Room 4", true);
    node4->addItem(new Door());

    Node *node5 = new Node(5, "Room 5", true);
    node5->addItem(new Door());

    Node *node6 = new Node(6, "Room 6", false);
    node6->description =
        "You look around you. You decide to examine the corner where the " +
        Text::blue + "terminal" + Text::normal +
        " is."
        "\nThere is a table there and a chair. You decide to take a closer "
        "look."
        "\nThe chair looks rusty and the table is old and dusty."
        "\nIt feels like everything is going to collapse anytime soon."
        "\nYou decide to take a step back.In the right corner of the room, "
        "there is a " +
        Text::blue + "safe" + Text::normal +
        ". "
        "\nIt has some rough spots where the colour has faded to copperish red."
        "\nIt's locked. Above that, you notice the " +
        Text::blue + "board" + Text::normal +
        ". It has a few pins laying around with"
        "\nsome old notes attached.All in all, nothing special.Then you decide "
        "to rest on the"
        "\n" + Text::blue + "bed" + Text::normal + ".It makes a \"screeching\" sound when you sit. Besides the "
        "terminal lies a piece of paper. You take a closer"
        "\nlook. It's actually a " +
        Text::blue + "note" + Text::normal + ".";

    node6->addItem(new Door(
        true, 1234,
        "A really tall metal door. It's surprisingly in a better condition"
        "\nthan the rest of the room. It has a few rusty spots here and "
        "there "
        "\nbut all in all it's fine. It needs a combination to unlock it."));

    Terminal *terminal = new Terminal('$', "Description", {"exit", "list", "hack", "help"}, {new File("Top Secret File", "File desc", "Top Secret Content")});
    terminal->setKey("abcd");
    terminal->setChars("abcdef");
    terminal->setReward("4321");
    node6->addItem(terminal);
    node6->addItem(
        new Note("",
                 "It's a piece of paper. It's wrinckly and its colour turned "
                 "yellow. The bottom right corner is folded.",
                 "dmg-techlabs.theworkpc.com/gamesite - 8rb3jdsu"));
    node6->addItem(new Bed(
        "Worn-out you deside to call it a day. You are now laying on the bed "
        "\nlooking at the ceiling, thinking about today."
        "Am I dreaming? Or is this a sick joke?' you wonder to yourself. "
        "Your thoughts start rushing but the exhaustion overtakes you."
        "\nYou dozed off hoping this will just be a bad dream. Tommorow is a "
        "new day after all...",
        "\nAn ordinary cheap looking metal bed with a really thin matress. "
        "It's "
        "\numcomfortable to sit there for an extended period of time. When you "
        "\nsit on it, it makes a loud piercing noise."));

    vector<Item *> board;
    board.push_back(new Note("note1", "description", "text1"));
    board.push_back(new Note("note2", "description", "text2"));
    board.push_back(new Note("note3", "description", "text3"));
    board.push_back(new Note("note4", "description", "text4"));
    node6->addItem(
        new Board("A regular board made from soft material. There are pins "
                  "with notes attached to them. There are a few free pins too. "
                  "Who knows? You might need them later.",
                  board)
    );

    vector<Item *> safe;
    string file_content = R"(
        [CLASSIFIED DOCUMENT]
        TOP SECRET // EYES ONLY

        OPERATION VIGILANT SHIELD

            Purpose:
            The purpose of Operation Vigilant Shield is to establish and maintain a robust
            defense infrastructure to protect national interests and safeguard strategic assets.
            This operation focuses on enhancing readiness, coordination, and response capabilities across multiple military branches.

            Objective:
            a. Enhance Situational Awareness: Employ advanced surveillance and reconnaissance systems
                to gather critical intelligence, monitor potential threats, and enable rapid decision-making.
            b. Strengthen Defensive Capabilities: Deploy and fortify defensive
                measures to deter and repel any hostile actions that may compromise national security.
            c. Conduct Joint Training Exercises: Foster interoperability and coordination among military units
                through rigorous and realistic training scenarios.
            d. Ensure Continuity of Operations: Establish resilient communication networks and redundant systems
                to ensure uninterrupted command and control capabilities.

            Task Force Composition:
            Operation Vigilant Shield brings together elite military units from various branches to
            form an integrated task force. The task force comprises highly trained personnel with diverse skill
            sets and expertise, including infantry, aviation, logistics, and intelligence specialists.

            Command Structure:
            a. Overall Command: The operation is led by a highly decorated senior officer with extensive combat experience, 
                who is responsible for overseeing all operational aspects.
            b. Task Force Command: A seasoned officer, known for exceptional leadership and tactical acumen, is appointed as 
                the task force commander. This individual manages and directs all activities within the task force.
            c. Unit Command: Each participating military unit retains its respective chain of command under the task force 
                structure, ensuring effective communication and streamlined execution of orders.

            Operation Execution:
            a. Intelligence Gathering: Highly trained intelligence personnel will leverage advanced information
                systems and traditional intelligence collection methods to identify potential threats and analyze enemy capabilities.
            b. Defensive Measures: Military units will deploy cutting-edge technologies and conventional defensive systems to secure
                key strategic locations and critical infrastructure.
            c. Joint Training Exercises: The task force will conduct joint training exercises simulating various scenarios to enhance
                coordination, refine tactics, and test the effectiveness of defensive strategies.
            d. Communication and Command Systems: Advanced communication systems will be employed to ensure seamless coordination
                between task force elements and higher command, allowing for real-time information exchange and situational updates.

            Conclusion:
            Operation Vigilant Shield #1234 represents the unwavering commitment of our military forces to protect
            and defend national interests. Through meticulous planning, rigorous training, and the application
            of advanced technologies, this operation aims to maintain a high state of readiness and ensure the security of our nation.

        This document is classified as TOP SECRET and must be handled with the utmost confidentiality.
        Unauthorized disclosure or distribution of its contents is strictly prohibited.

        [END OF DOCUMENT])";

    safe.push_back(new File("id", "OPERATION SENTINEL SHIELD", "A military like document", file_content));
    node6->addItem(
        new Safe(4321,
                 "A worn-out safe. The paint has faded in some spots. Due to "
                 "oxidation, the colour turned cooper red. It's locked.",
                 safe));

    Node *node7 = new Node(7, "Room 7", true);
    node7->addItem(new Door());

    Node *node8 = new Node(8, "Room 8", true);
    node8->addItem(new Door());

    // Connect nodes to main hall and add them to map vector
    addNode(node1, vector<int>{0});
    addNode(node2, vector<int>{0});
    addNode(node3, vector<int>{0});
    addNode(node4, vector<int>{0});
    addNode(node5, vector<int>{0});
    addNode(node6, vector<int>{0});
    addNode(node7, vector<int>{0});
    addNode(node8, vector<int>{0});
}

void printMap(Map map) {
    for (int i = 0; i < map.nodes.size(); i++) {
        println(
            "ID: " + to_string(map.nodes.at(i)->id) +
                ", Description: " + map.nodes.at(i)->description +
                ", Unlocked: " + to_string(map.nodes.at(i)->isAccessible()) +
                ", Accessible Nodes: " +
                nodesToString(map.nodes.at(i)->accessible_nodes),
            0);
    }
}

string nodesToString(vector<Node *> nodes) {
    string s = "";
    for (int i = 0; i < nodes.size(); i++) {
        s += "ID: " + to_string(nodes.at(i)->id) +
             ", Description: " + nodes.at(i)->description + " \n\t\t\t\t\t";
    }
    return s;
}