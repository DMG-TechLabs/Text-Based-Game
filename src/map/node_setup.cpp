#include "node_setup.h"
#include "items.h"
#include "engine.h"

using namespace Engine;
using namespace CliKit;

void NodeSetup::node6Setup(Node *node6){
    node6->description =
        "You look around you. You decide to examine the corner where the " +
        Text::blue + "terminal" + Text::normal +
        " is."
        "\nThere is a table there and a chair. You decide to take a closer "
        "look."
        "\nThe chair looks rusty and the table is old and dusty."
        "\nIt feels like everything is going to collapse anytime soon."
        "\nYou decide to take a step back. In the right corner of the room, "
        "there is a " +
        Text::blue + "safe" + Text::normal +
        ". "
        "\nIt has some rough spots where the colour has faded to copperish red."
        "\nIt's locked. Above that, you notice the " +
        Text::blue + "board" + Text::normal + + ". "
        "It has a few pins laying around with"
        "\nsome old notes attached. All in all, nothing special. Then you decide "
        "to rest on the"
        "\n" + Text::blue + "bed" + Text::normal + ". It makes a \"screeching\" sound when"
        "you sit. Besides the terminal lies a piece of paper. You take a closer"
        "\nlook. It's actually a " +
        Text::blue + "note" + Text::normal + ".";

    node6->addItem(new Door(
        true, 2942,
        "A really tall metal door. It's surprisingly in a better condition"
        "\nthan the rest of the room. It has a few rusty spots here and "
        "there "
        "\nbut all in all it's fine. It needs a combination to unlock it."));

    Terminal *terminal = new Terminal('$', "It's an old computer. It's big and it's covered in dust. You touch the curved screen and feel static electricity going through your finger and you pull it back frantically. \"It's a miracle that it still works\" you thought to yourself.", {"exit", "list", "hack", "help"}, {new File("Top Secret File", "10KB", "Top Secret Content")});
    terminal->setKey("ceab");
    terminal->setChars("abcdef");
    terminal->setReward("8291");
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
    board.push_back(new Note("Note1", "description", "2028/04/25"));
    board.push_back(new Note("Note2", "description", "Matthew Carter"));
    board.push_back(new Note("Note3", "description", "(555) 472-349"));
    board.push_back(new Note("Note4", "description", "37°13'58.9\"N 115°48'41.8\"W"));
    node6->addItem(
        new Board("A regular board made from soft material. There are pins "
                  "with notes attached to them. There are a few free pins too.",
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
            Operation Vigilant Shield #2942 represents the unwavering commitment of our military forces to protect
            and defend national interests. Through meticulous planning, rigorous training, and the application
            of advanced technologies, this operation aims to maintain a high state of readiness and ensure the security of our nation.

        This document is classified as TOP SECRET and must be handled with the utmost confidentiality.
        Unauthorized disclosure or distribution of its contents is strictly prohibited.

        [END OF DOCUMENT])";

    safe.push_back(new File("id", "OPERATION SENTINEL SHIELD", "A military like document", file_content));
    node6->addItem(
        new Safe(8291,
                 "A worn-out safe. The paint has faded in some spots. Due to "
                 "oxidation, the colour turned cooper red. It's locked.",
                 safe));
}
