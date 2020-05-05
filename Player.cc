#include "Player.hh"

namespace tictactoe
{

Player::Player(){}

Player::Player(string player_name, char player_tag, int player_id)
{
    m_player_name = player_name;
    m_player_tag = player_tag; 
    m_player_id = player_id;
}

Player::~Player()
{

}
    
} // tictactoe
