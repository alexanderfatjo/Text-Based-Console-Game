#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <utility>
#include <limits>
#include <windows.h>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;

//All classes
class Being;

class Player;

class Bosses;

class Boss_UI;

class Fight;

class Player_items;

//----------------------UI class----------------------------
class UI {
public:
    UI() = default;

    void print_item_info();

    static void pause_screen();

    void clear_screen();
};

//Recycled class code
void print(const std::vector<std::string> &picture) {
    std::cout << '\n';
    for (const auto &line: picture) std::cout << line << '\n';
    std::cout << '\n';
}

class Boss_UI : public UI {
private:

public:
    Boss_UI() = default;
};

//Parent class
//----------------------Being class----------------------------
class Being {
public:
    string name;
    int HP;
    int ATK;

    void attack(Being &target);
};


//----------------------Player class----------------------------
//Inherited from class Being
class Player : public Being {
protected:

public:
    //Default constructor
    Player() = default;

    //Constructor to assign variable instances to an argument
    Player(std::string, int new_hp, int new_ATK);

    void display_player_stats();
};

//Inherited from class Player
class Player_items : public Player {
public:
    //default constructor
    Player_items() = default;
    ///overload constructor

    //Prototype function to allow player to choose an item, which then will give its attributes accordingly
    void get_item(int item_num);

};

//----------------------Bosses class----------------------------
class Bosses : public Being {
public:
    Bosses() = default;

    Bosses(std::string, int, int);
};
//----------------------Fight class----------------------------

class Fight {

public:
    //default constructor
    Fight() = default;

    //to hold true/false value if the player beat the floor level or not
    bool player_win{};

    Bosses &Boss;

    //points the next floor's boss to assign its new address
    Fight(Bosses &);

    //initiate fight between enemy and whichever new enemy is assigned next(if player continues)
    void start_fight(Player &p);

    //Getter and Setter
    //called and set in fight.cpp to set players' status to dead or alive
    //Virtual so that it compiles after runtime since the arguments' values will be constantly changing
    virtual inline void set_player_win(bool player_won) { player_win = player_won; };

    bool get_player_win() const;
    /*bool reset_player_win() const;*/
};

#endif