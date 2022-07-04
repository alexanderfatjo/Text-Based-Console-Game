#include <iostream>
#include "header.h"
#include "source.cpp"
/*
Bosses low_devil() {
    // Bosses();//initializes class 'Bosses' in order to call to it
    std::string boss_name = "Low Devil";
    int boss_HP = 5;
    int boss_ATK = 5;
    return Bosses{boss_name, boss_HP, boss_ATK};
    //return {"Low Devil", bs.HP, bs.ATK};
}
Bosses high_devil() {
    Bosses bs;//initializes class 'Bosses' in order to call to it
    return Bosses{"High Devil", 10, 5};
}
Bosses demon() {
    Bosses bs;//initializes class 'Bosses' in order to call to it
    return Bosses{"low_devil", 20, 10};
}*/
//source: https://www.dreamincode.net/forums/topic/96499-make-a-text-combat-game-in-c/
//Author:Asvati
Player create_player() {
    Player p = Player();//initializes class 'Player' in order to call to it
    std::string n;
    int start_HP = 10;
    int start_ATK = 10;
    cout << "Please Enter Name: " << std::endl;
    cin >> n;
    cout << "Your current stats are HP: " << start_HP << " ATK: " << start_ATK << std::endl;
    return Player{n, start_HP, start_ATK};
}
Bosses boss_one("Low Devil", 15, 6);
Bosses boss_two("High Devil", 15, 6);
Bosses boss_final("Demon", 25, 10);
int main(int argc, char *const argv[]) {
    Bosses boss;
    UI ui = UI();//initializes class 'UI' in order to call to it
    Boss_UI b = Boss_UI();//initializes class 'Boss_UI' in order to call to it
    Player_items items = Player_items();//initializes class 'Player_items' in order to call to it
    int item_select;
    Player p = create_player();//Assigns character values & prompts player to choose their first item.
    cin.ignore(); //ignores the input from line above.
    //Without ignoring input(cin), 'print(labyrinth_intro_image);' will be skipped.
    ui.clear_screen();//clears screen in console in order to keep focus on thing at a time

    print_dialogue("intro"); //prints background info from a narrator
    print(labyrinth_intro_image); //prints a string literal vector that holds the ASCII image of a boss
    ui.pause_screen();//pauses screen to let player choose when there done reading/viewing what's currently in focus by pressing a 'enter'
    ui.clear_screen();
    do {
        //IDEA: REPLACE THIS WITH A BOOL FUNCTION THAT IS FALSE WHEN THE PLAYER IS DEAD
        int floor_active = 1;
        if (floor_active == 1) {
            /*ui.pause_screen();
            ui.clear_screen();
            ui.pause_screen();
*/
            p.display_player_stats();
            ui.print_item_info();//Gives info on all items
            cout << "Select Item: " << std::endl;
            cin >> item_select;
            if (item_select == 1) { p.HP += 5; }
            if (item_select == 2) { p.ATK + 5; }
            if (item_select == 3) { std::cout << "\nBoss HP: " << boss.HP << "\nBoss ATK: " << boss.ATK << std::endl; }
            if (item_select == 4) { p.HP = 1, p.ATK = 2 * (p.ATK); }
            items.get_item(item_select);//pushes choosen items' name into a vector to add to inventory
            p.display_player_stats();

            p.display_player_stats();
            ui.pause_screen();

            //ui.clear_screen();

            print(boss_image_one);
            print(background_image_floor_one);

            Fight Fight(boss_one);
            Fight.start_fight(p);//start fight between Player and floor boss one(Low Devil)

            p.display_player_stats();
            ui.pause_screen();
            ui.clear_screen();
            //gets the true/false value from class Fight to determine what to do next(continue to next floor or exit game)
            Fight.get_player_win();
            if (Fight.player_win = true) {
                ui.clear_screen();
                print(player_win_image);
                ui.pause_screen();
                ui.clear_screen();
                floor_active++;
            } else if (Fight.player_win = false) {
                ui.clear_screen();
                cout << "ruh roh, looser!" << std::endl;
                ui.pause_screen();
                break;
            }
        };
        //floor two functions
        if (floor_active == 2) {
            print(player_win_image);
            ui.pause_screen();
            ui.clear_screen();
            print_dialogue(background_info_floor_two);
            print(background_image_floor_two);
            print_dialogue("floor_two");
            ui.clear_screen();
            ui.clear_screen();

            print(boss_image_two);
            ui.pause_screen();

            p.display_player_stats();
            ui.print_item_info();//Gives info on all items
            cout << "Select Item: " << std::endl;
            cin >> item_select;
            if (item_select == 1) { p.HP += 5; }
            if (item_select == 2) { p.ATK + 5; }
            if (item_select == 3) { std::cout << "\nBoss HP: " << boss.HP << "\nBoss ATK: " << boss.ATK << std::endl; }
            if (item_select == 4) { p.HP = 1, p.ATK = 2 * (p.ATK); }
            items.get_item(item_select);
            p.display_player_stats();

            ui.pause_screen();
            ui.clear_screen();

            Fight Fight(boss_two);
            Fight.start_fight(p);
            p.display_player_stats();
            Fight.get_player_win();
            if (Fight.player_win == true) {
                ui.clear_screen();
                print(player_win_image);
                ui.pause_screen();
                ui.clear_screen();
                floor_active++;//if Player survives, they move onto the next floor
            } else {
                ui.clear_screen();
                cout << "ruh roh, looser!" << std::endl;
                ui.pause_screen();
                break;
            }
        }
        if (floor_active == 3) {
            print(player_win_image);
            ui.pause_screen();
            ui.clear_screen();
            print_dialogue("floor_final");
            print(background_image_floor_final);
            ui.pause_screen();
            ui.clear_screen();

            print(boss_image_final);
            ui.pause_screen();

            p.display_player_stats();
            ui.print_item_info();//Gives info on all items
            cout << "Select Item: " << std::endl;
            cin >> item_select;
            if(item_select == 1){p.HP += 5;}
            if(item_select == 2){p.ATK + 5;}
            if(item_select == 3 ){std::cout << "\nBoss HP: " << boss.HP << "\nBoss ATK: " << boss.ATK <<std::endl; }
            if (item_select == 4) {p.HP = 1, p.ATK = 2*(p.ATK);}
            items.get_item(item_select);
            p.display_player_stats();

            ui.pause_screen();
            ui.clear_screen();

            Fight Fight(boss_final);
            Fight.start_fight(p);
            p.display_player_stats();
            // **MAKE THIS PRINT TWO DIFFERENT MESSAGES DEPENDING ON THE FIGHTS OUTCOME***
            Fight.get_player_win();
                if (Fight.player_win == true) {
                    ui.clear_screen();
                    print(player_win_image);
                    ui.pause_screen();
                    ui.clear_screen();
                    floor_active++;
                    break;
                } else {
                    ui.clear_screen();
                    cout << "ruh roh, looser!" << std::endl;
                    ui.pause_screen();
                    break;
                };
        }
    }while (p.HP > 0);  //while (start_game == "y");
    return 0;
};