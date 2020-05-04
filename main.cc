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

    cin >> choice;
    while(cin.fail())
    {
        cout << "Error. Please enter a number!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choice;
    }

    cin.ignore();
    return choice;

}

void getGameData()
{
    int mode = 0;
    cout << "Welcome to Tic Tac Toe" << endl;

    while(1)
    {
        mode = vs_player_or_computer();

        if (mode < 1 || mode > 3)
        {
            cout << "Invalid inpute. Please choose 1, 2 or 3\n" << endl;
        }
        else
        {
            break;
        }
    }

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
    else
    {
        cout << "Bye!" << endl;
        exit(1);
    }
    
}

void getPlayerData(string& playerName, char& player_tag)
{
    cout << "Enter Player Name: ";
    cin >> playerName;
    cin.ignore();

    while (1)
    {
        cout << "Enter Player Game Tag: ";
        cin >> player_tag;
        cin.ignore();

        if(isdigit(player_tag))
        {
            cout << "Invalid player tag. Please enter a tag that is not a number!" << endl;
        }
        else
        {
            break;
        }   
    }
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
        else if (playAgainChoice == 'Y' || playAgainChoice == 'y')
        {
            cout << "New game in session" << endl;
        }
        else
        {
            cout << "Invalid choice: Please choose between Y or N" << endl;
            playAgainChoice = playAgain();
        }
    }

    return 0;
}