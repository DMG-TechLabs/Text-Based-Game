#include "interactions.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace Engine;


void FormattedPrint::typingInTerminal(string who, string text) {
    if (who != "player" && who != "terminal") return;

    if (who == "player") {
        println("", 1);
        print(Text::red + "$ " + Text::normal);
        Text::delayedTyping(text);
    } else if (who == "terminal") {
        println("", 3);
        Text::delayedTyping(text);
    }
}

void FormattedPrint::playerTalking(string text){
    println(Text::italic + "\n-"+ text +"\n" + Text::normal);
}