#ifndef PLAYER_H_
#define PLAYER_H_
#include <memory>
#include <string>

using namespace std;

namespace tictactoe
{

class Player
{
    public: 
        Player();
        Player(string player_name, char player_tag, int player_id);
        virtual ~Player();

        void setPlayerTag(char player_tag){m_player_tag = player_tag;};
        void setPlayerName(string player_name){m_player_name = player_name;};
        void setPlayerId(int player_id){m_player_id = player_id;};

        char getPlayerTag(){return m_player_tag;};
        string getPlayerName(){return m_player_name;};
        int getPlayerId(){return m_player_id;};

    private: 
        int m_player_id;
        char m_player_tag;
        string m_player_name;
};

};

#endif