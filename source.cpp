#include "header.h"
//---------------------------UI Elements----------------------------

void UI::pause_screen() {
    std::cout << "--------Press Enter to Continue--------" << std::endl;
    getchar();
}

//source:https://www.cplusplus.com/articles/4z18T05o/#TheSimpleAnswer
//Author:Duthomhas
//utilizing the Windows api, this will write a space to every cell in the console
void UI::clear_screen() {
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    // Get the number of cells in the current buffer
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR) ' ',
            cellCount,
            homeCoords,
            &count
    ))
        return;

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count
    ))
        return;

    // Move the cursor home
    SetConsoleCursorPosition(hStdOut, homeCoords);
}
const string background_info_intro = "Welcome newcomer, this is what is called the DUNGEON OF TERROR!\nAs the name suggest"
                                     ", it will be no easy feat. to escape with your life.\nYour goal will be to defeat each boss you come across."
                                     "\nYou will be given an opportunity to choose an item before battling each boss.\nYour reward will be your LIFE!";
const string background_info_floor_one = "You suddenly jolt awake and find yourself laying in a near pitch black, empty room.\n"
                                         "You are unable to recall how you ended up here, as you are trying to get everything "
                                         "sorted out in your head, you are stricken by a sinister laugh.\n"
                                         "To which a devil-ish looking being comes from the shadows and says:\n"
                                         "'Fun! You have until the sun goes down to prepare. Good luck...'\n";
const string background_info_floor_two = "Not bad...though you are nearing an infamous labyrinth boss!\nBeware! "
                                         "this land is getting increasingly treacherous...\n";
const string background_info_floor_final = "You made that look easy!\nFloor three has not "
                                           "been conquered in over a century.\n"
                                           "It will prove to not be for the faint of heart...\n"
                                           "Rumor has it that the so called 'Foreseeing Eye'"
                                           " can even glimpse into floor bosses HP & ATK!\n";

//when called from main, this will output the background information that belongs to the floor level this is pointed to.
void print_dialogue(const std::string &floor_dialogue) {
    if (floor_dialogue == "intro") {
        std::cout << background_info_intro << std::endl;
    }
    if (floor_dialogue == "floor_one") {
        std::cout << background_info_floor_one << std::endl;
    }
    if (floor_dialogue == "floor_two") {
        std::cout << background_info_floor_two << std::endl;
    }
    if (floor_dialogue == "floor_final") {
        std::cout << background_info_floor_final << std::endl;
    }
}

//source: https://www.asciiart.eu/buildings-and-places/temple
//Author: Glory Moon
//string labyrinth_image_intro
std::vector<std::string> labyrinth_intro_image =
        {
                R"(  `,.      .   .            .    .      .  _    ..          . )",
                R"(    \\,~-.         *      *    .    .       _.       *    .   )",
                R"(          \\ *          .   .   |    *  . .  ~    .      .  .  ,)",
                R"(,           `-.  .            :         *     .      *    , )",
                R"( -             `-.    *    *._/_\\_.       .       .   ,   )",
                R"( -                 `-_.,      |n|     .  *   .       ; )",
                R"(   -                    \\ ._/_,_\\_.  .          . ,'         , )",
                R"(    -                    `-.|.n.||      .   ,-.__,'          -)",
                R"(     -                   ._/_,_,_\\_.    ,-'               -)",
                R"(     -                     |..n..|-`'-'                 -)",
                R"(      -                 ._/_,_,_,_\\_.                  -)",
                R"(        -               ,-|...n...|                    -)",
                R"(          -         ,-'._/_,_,_,_,_\\_.                -)",
                R"(            -  ,-=-'     |....n....|                -)",
                R"(             -;       ._/_,_,_,_,_,_\\_.           -)",
                R"(            ,-          |.....n.....|            -)",
                R"(          ,;         ._/_,_,_,_,_,_,_\\_.          -)",
                R"( `,  '.  `.  \".  `,  '.| n   ,-.   n |  \",  `.  `,  '.  `,  ', ,)",
                R"(.:;..;;..;;.,:;,.;:,o__|__o !.|.! o__|__o;,.:;.,;;,,:;,.:;,;;:::)",
                R"(][  ][  ][  ][  ][  |_i_i_H_|_|_|_H_i_i_|  ][  ][  ][  ][  ][ ])",
                R"(                    |_____//=====\\\\_____|)",
                R"(                    |____//=======\\\\____|)",
                R"(                    |___//=========\\\\\__|)",
        };
//using raw string literal to make output cleaner/less troublesome
//raw string literals' escape characters are ' )", ' which allows for a more universal print function
std::vector<std::string> background_image_floor_one =
        {
                R"( ||===========================================||)",
                R"( ||+++++++++++++++|Floor One|+++++++++++++++++||)",
                R"( ||++++++++++++++++--+---+--++++++++++++++++++||)",
                R"( ||++--+One+---+++---|Two|----+++-+|Three|+-++||)",
                R"( ||+|  +---+   |+|   +---+    |+|  +------+ |+||)",
                R"( ||+|  Heart   |+|Testosterone|+|   Heart   |+||)",
                R"( ||+|----------|+|------------|+|-----------|+||)",
                R"( ||+|  +5 HP   |+|   +5 ATK   |+|   +5 HP   |+||)",
                R"( ||+|++++++++++|+|++++++++++++|+|+++++++++++|+||)",
                R"( ||++----------|+|------------|+|-----------|+||)",
                R"( ||++++++++++++|Choose Carefully...|++++++++++||)",
                R"( ||===========================================||)",
        };

std::vector<std::string> background_image_floor_two =
        {
                R"(||===========================================||\n)",
                R"( ||+++++++++++++++|Floor Two|+++++++++++++++++||\n)",
                R"( ||++++++++++++++++--+---+--++++++++++++++++++||\n)",
                R"( ||++--+One+---+++---|Two|----+++-+|Three|+-++||\n)",
                R"( ||+|  +---+   |+|   +---+    |+|  +------+ |+||\n)",
                R"( ||+|  Heart   |+|Testosterone|+|Foreseeing |+||\n)",
                R"( ||+|----------|+|------------|+|----eye----|+||\n)",
                R"( ||+|  +5 HP   |+|   +5 ATK   |+|-----------|+||\n)",
                R"( ||+|++++++++++|+|++++++++++++|+|+++++++++++|+||\n)",
                R"( ||++----------|+|------------|+|-----------|+||\n)",
                R"( ||++++++++++++|Choose Carefully|++++++++++||\n)",
                R"( ||===========================================||\n)",
        };

std::vector<std::string> background_image_floor_final =
        {
                R"( ||===========================================||)",
                R"( ||++++++++++++++|Floor Three|++++++++++++++++||)",
                R"( ||++++++++++++++++--+---+--++++++++++++++++++||)",
                R"( ||++--+One+---+++---|Two|----+++-+|Three|+-++||)",
                R"( ||+|  +---+   |+|   +---+    |+|  +------+ |+||)",
                R"( ||+|  Heart   |+|Testosterone|+|   Heart   |+||)",
                R"( ||+|----------|+|------------|+|-----------|+||)",
                R"( ||+|  +5 HP   |+|   +5 ATK   |+|   +5 HP   |+||)",
                R"( ||+|++++++++++|+|++++++++++++|+|+++++++++++|+||)",
                R"( ||++----------|+|------------|+|-----------|+||)",
                R"( ||++++++++++++|Choose Carefully|+++++++++++|+||)",
                R"( ||===========================================||)",
        };

//Source Citation: https://www.asciiart.eu/mythology/devils.
//Author: Joan G. Stark.
std::vector<std::string> boss_image_one =
        {
                R"(    Floor One Boss     )",
                R"(||*******************||)",
                R"(||         , , ,  ,, ||)",
                R"(||   <(__)>| | |  || ||)",
                R"(||  | \\/ | \\_|_//  ||)",
                R"(||  \\+  +/    |     ||)",
                R"(||  /\\--/\\  /|     ||)",
                R"(|| /  \\/  \\/ |     ||)",
                R"(||*******************||)",
        };

std::vector<std::string> boss_image_two =
        {
                R"(    Floor Two Boss     )",
                R"(||*******************||)",
                R"(||         , , ,  ,, ||)",
                R"(||   <(__)>| | |  || ||)",
                R"(||  | \\/ | \\_|_//  ||)",
                R"(||  \\+  +/    |     ||)",
                R"(||  /\\--/\\  /|     ||)",
                R"(|| /  \\/  \\/ |     ||)",
                R"(||*******************||)",
        };

//Source Citation: https://www.asciiart.eu/mythology/devils.
//Author: eVil
std::vector<std::string> boss_image_final =
        {
                R"(                        FINAL BOSS                          )",
                R"(                            ,-.                               )",
                R"(       ___,---.__          /'|`\\          __,---,___          )",
                R"(    ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-.       )",
                R"(  ,'        |           ~'\\     /`~           |        `.      )",
                R"( /      ___//              `. ,'          ,  , \\___      \\    )",
                R"(|    ,-'   `-.__   _         |        ,    __,-'   `-.    |    )",
                R"(|   /          /\\_  `   .    |    ,      _/\\          \\   |   )",
                R"(\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /  )",
                R"( \\  \\           | `._   `\\\\  |  //'   _,' |           /  /      )",
                R"(  `-.\\         /'  _ `---'' , . ``---' _  `\\         /,-'     )",
                R"(     ``       /     \\    ,='/ \\`=.    /     \\       ''          )",
                R"(             |__   /|\\_,--.,-.--,--._/|\\   __|                  )",
                R"(             /  `./  \\\\`\\ |  |  | /,//' \\,'  \\                  )",
                R"(           /   /     ||--+--|--+-/-|     \\   \\                 )",
                R"(           |   |     /'\\_\\_\\ | /_/_/`\\     |   |                )",
                R"(            \\   \\__, \\_     `~'     _/ .__/   /            )",
                R"(             `-._,-'   `-._______,-'   `-._,-'-/)",
        };
//To output when Player defeats boss
std::vector<std::string> player_win_image =
        {
                R"(######################################################################)",
                R"(#   __    __                    __      __                   __      #)",
                R"(#  /\ \  /\ \                  /\ \  __/\ \                 /\ \     #)",
                R"(#  \ `\`\\/'/  ___    __  __   \ \ \/\ \ \ \    ___     ___ \ \ \    #)",
                R"(#   `\ `\ /'  / __`\ /\ \/\ \   \ \ \ \ \ \ \  / __`\ /' _ `\\ \ \   #)",
                R"(#     `\ \ \ /\ \L\ \\ \ \_\ \   \ \ \_/ \_\ \/\ \L\ \/\ \/\ \\ \_\  #)",
                R"(#       \ \_\\ \____/ \ \____/    \ `\___x___/\ \____/\ \_\ \_\\/\_\ #)",
                R"(#        \/_/ \/___/   \/___/      '\/__//__/  \/___/  \/_/\/_/ \/_/ #)",
                R"(#                                                                    #)",
                R"(######################################################################)",
        };

void Being::attack(Being& target) {
    target.HP -= ATK;
/*    //Displays Player's stats in fight
    std::cout << "Player: " << name << "\nHP: " << HP << "\nATK: " << ATK << std::endl;*/
    //Displays current Bosses' stats in fight
    cout << "Boss: " << name << "\nHP: " << HP << "\nATK: " << ATK << std::endl;
};

//___________________________Player class Implementation____________________________________
Player::Player(std::string set_player_name, int new_HP, int new_ATK) {
    name = set_player_name;
    HP = new_HP;
    ATK = new_ATK;
};
void Player::display_player_stats() { std::cout << "Player: " << name << "\nHP: " << HP << "\nATK: " << ATK << std::endl; }


struct item_names {
    const std::string heart = "Heart";
    const std::string testosterone = "Testosterone";
    const std::string forseeing_eye = "Forseeing eye";
    const std::string glass_cannon = "Glass Cannon";
    //possibly add item that gives a chance to double HP.
};
struct item_info {
    const std::string heart = "Gives Player +5 HP.";
    const std::string testosterone = "Gives Player +5 ATK";
    const std::string forseeing_eye = "Allows Player to see the Floor Bosses HP & ATK(works one time).";
    const std::string glass_cannon = "Decreases Players HP to 1 & Increases ATK by 2X there current ATK.";
};

//only including items with simple addition attributes to avoid scope errors from referencing Players current stats
struct item_attributes {
    int heart = 5;
    int testosterone = 5;
};

item_info item_info;
item_names iv;
item_attributes ia;

void UI::print_item_info() {
    std::cout << "Items & Their Attributes:\n[1]Heart: " << item_info.heart << "\n[2]Testosterone: " << item_info.testosterone <<
              "\n[3]Foreseeing Eye: " << item_info.forseeing_eye << "\n[4]Glass Cannon: " << item_info.glass_cannon << std::endl;
}

void display_inventory(std::vector<std::string> const &inventory) {
std::cout << "Current Items: " << std::endl;
for (const auto &iv: inventory)
std::cout << iv << ", " << std::endl;
}

//For printing out a live item inventory when the player chooses a new item
std::vector<std::string> inventory;

//Bosses.cpp
/*void Being::Attack(Being& target) {
    target.HP -= ATK;
    std::cout << target.name << "\nHP:  " << target.HP << "  ATK: " << target.ATK << std::endl;
    std::cout << name << " HP: " << HP << std::endl;
};*/

Bosses::Bosses(std::string new_boss_name, int new_boss_HP, int new_boss_ATK) {
    name = std::move(new_boss_name);
    HP = new_boss_HP;
    ATK = new_boss_ATK;
};
//**Could not get this to work, tried making it a virtual void function, along with setting the returned variables to virtual. Though, no luck**
/*void get_item(int item_select) {
     Player p = Player();
    switch (item_select) {
        case 1:
            p.HP += 5;
            inventory.push_back(iv.heart);
            display_inventory(inventory);
            break;
        case 2:
            p.ATK += 5;
            inventory.push_back(iv.testosterone);
            display_inventory(inventory);
            break;
        case 3:
            inventory.push_back(iv.forseeing_eye);
            display_inventory(inventory);
            break;
        case 4:
            p.HP = 1;
            p.ATK = 2 * p.ATK;
            inventory.push_back(iv.glass_cannon);
            display_inventory(inventory);
            break;
        default:
            std::cout << "item_choice error(set)" << std::endl;
            break;
    };
}*/
void Player_items::get_item(int item_select) {
    switch (item_select) {
        case 1:
            inventory.push_back(iv.heart);
            display_inventory(inventory);
            break;
        case 2:
            inventory.push_back(iv.testosterone);
            display_inventory(inventory);
            break;
        case 3:
            inventory.push_back(iv.forseeing_eye);
            display_inventory(inventory);
            break;
        case 4:
            inventory.push_back(iv.glass_cannon);
            display_inventory(inventory);
            break;
        default:
            std::cout << "item_choice error(set)" << std::endl;
            break;
    }};

//----------------------------Fight class implementation-------------------------------
//As mentioned in "Works Cited", this class along with its foundation & functions was derived from:
//Source: https://www.dreamincode.net/forums/topic/96499-make-a-text-combat-game-in-c/
//Author: Asvati
    Fight::Fight(Bosses& newB) : Boss(newB){}

    void Fight::start_fight(Player &p) {
        while (Boss.HP > 0 && p.HP > 0) {
            Boss.attack(p);
        }
        if (Boss.HP <= 0) {
            std::cout << "You Win!" << std::endl;
            set_player_win(true);
            print(player_win_image);
            UI::pause_screen();
        }
        if (p.HP <= 0) {
            set_player_win(false);
            std::cout << "GAME OVER:/" << std::endl;
        }

    };
    bool Fight::get_player_win() const { return player_win; }



