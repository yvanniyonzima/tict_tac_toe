#ifndef GAME_H_
#define GAME_H_
#include <string>
#include <iostream>
#include "Player.hh"
#include <memory>
using namespace std;


namespace tictactoe
{

class Game
{
   
    public: 
        Game();
        Game(string player_name, char player_tag);
        Game(string player_one_name,string player_two_name, char player_one_tag, char player_two_tag);
        ~Game();

        void drawBoard();
        int checkWin();
        void startGame();

        friend ostream& operator<<(ostream &out, const Game &game);

    public: 
        Player* player_one{nullptr};
        Player* player_two{nullptr};
        Player* winner{nullptr};

        char computer_tags[2]{'D','C'};
        char square[10]{'o','1','2','3','4','5','6','7','8','9'}; //c++11 initialization
    

    private: 
        string getPlayerNameById(int playerId);

        /*generates this error at compile time

         error: 'auto' not allowed in non-static class member
        auto getPlayerNameById = [](int playerId)-> string
        */
        // auto getPlayerNameById = [this](int playerId)-> string
        // {
        //     string name = (player_one->getPlayerId() == playerId) ? player_one->getPlayerName() : player_two->getPlayerName();

        //     return name;
        // };


};

};


#endif