#include <iostream>
#include "Game.hh"

using namespace std;
using namespace tictactoe;

int vs_player_or_computer();
void getGameData();
void getPlayerData(string& playerName, char& player_tag);

struct GameData
{
    string player_one_name;
    char player_one_tag;

    string player_two_name;
    char player_two_tag;
}gameData;

int vs_player_or_computer()
{

    int choice = 0;

    cout <<"Choose from one of the following options"<<endl;
    cout <<"----------------------------------------"<<endl;
    cout <<"1.VS Computer"<<endl;
    cout <<"2.Two players"<<endl;
    cout <<"3.Exit"<<endl;
    cout <<"Choice:";

    while(choice < 1 || choice > 3)
    {
        cin >> choice;

        if (choice < 1 || choice > 3)
        {
            cout << "Invalid choice. Try again!" << endl;
            cout <<"Choice:";
        }
    }
    cin.ignore();
    // cin.get();
    return choice;

}

void getGameData()
{
    int mode = 0;
    cout << "Welcome to Tic Tac Toe" << endl;

    mode = vs_player_or_computer();

    if (mode == 1)
    {
        cout << "Playing Vs Computer " << endl;
    }
    else if (mode == 2)
    {
        cout << "First player information"<<endl;
        cout <<"-------------------------"<<endl;
        getPlayerData(gameData.player_one_name, gameData.player_one_tag);
        cout << "\nSecond player information"<<endl;
        cout <<"-------------------------"<<endl;
        getPlayerData(gameData.player_two_name, gameData.player_two_tag);

    }
}

void getPlayerData(string& playerName, char& player_tag)
{
    cout << "Enter Player Name: ";
    cin >> playerName;
    cin.ignore();

    cout << "Enter Player Game Tag: ";
    cin >> player_tag;
    cin.ignore();
}

char playAgain()
{
   char choice;

    cout <<"Play Again(Y/N)?";

    while(1)
    {
        cin >> choice;

        if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Try again!" << endl;
            cout <<"Play Again(Y/N)?";
        }
    }
    cin.ignore();
    // cin.get();
    return choice;
}



int main()
{
    char playAgainChoice;
    cout << "Welcome to Tic Tac Toe" << endl;

    getGameData();

    while(1)
    {
        Game *game = new Game();
        game->player_one->setPlayerName(gameData.player_one_name);
        game->player_one->setPlayerTag(gameData.player_one_tag);

        game->player_two->setPlayerName(gameData.player_two_name);
        game->player_two->setPlayerTag(gameData.player_two_tag);
        game->startGame();

        playAgainChoice = playAgain();

        if(playAgainChoice == 'N' || playAgainChoice == 'n')
        {
            break;
        }
    }

    return 0;
}