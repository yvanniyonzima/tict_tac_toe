#include "Game.hh"
#include <string>


namespace tictactoe
{

Game::Game()
{ 
    player_one = new Player();
    player_one->setPlayerId(1);

    player_two = new Player();
    player_one->setPlayerId(2);
}

Game::Game(string player_name, char player_tag)
{    
    player_one = new Player(player_name,player_tag, 1);
    
    //make computer player   
    if (player_one->getPlayerTag() == computer_tags[1])
    {
        
        player_two = new Player("Computer", computer_tags[0], 2);
    }
    else
    {
        player_two = new Player ("Computer", computer_tags[1], 2);
    }   
}

Game::Game(string player_one_name, string player_two_name, char player_one_tag, char player_two_tag)
{
    player_one = new Player(player_one_name, player_one_tag, 1);
    player_two = new Player(player_two_name,player_two_tag, 2);
}

Game::~Game()
{
    delete player_one;
    delete player_two;
    delete winner;
}

string Game::getPlayerNameById(int playerId)
{
    string name = (player_one->getPlayerId() == playerId) ? player_one->getPlayerName() : player_two->getPlayerName();
    return name;
}

void Game::drawBoard()
{
    #ifdef _WIN64
        system("cls");
    #else
        system("clear");
    #endif

    system("clear");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1: "<<player_one->getPlayerName() << " (" << player_one->getPlayerTag() << ")";
    cout << " -  Player 2: "<<player_two->getPlayerName() << " (" << player_two->getPlayerTag() << ")" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;

}

int Game::checkWin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void Game::startGame()
{
    int curr_player_id  = player_one->getPlayerId(), i , choice;

    char mark;
    bool invalidMove = false;

    do 
    {
        drawBoard();

        if (!invalidMove)
        {
            if(curr_player_id == 1)
            {
                curr_player_id = 2;
            }
            else
            {
                curr_player_id = 1;
            }
        }
        else
        {
            invalidMove = false;
        }

        mark = (curr_player_id == player_one->getPlayerId()) ? player_one->getPlayerTag() : player_two->getPlayerTag();
        
        cout << "It's " << getPlayerNameById(curr_player_id) << "'s turn (Player ID: " << curr_player_id << ", Tag: " << mark << ")." << endl;

        cin >> choice;

        if (choice == 1 && square[1] == '1')
        {
            square[1] = mark;
        }
        else if (choice == 2 && square[2] == '2')
        {
            square[2] = mark;
        }   
        else if (choice == 3 && square[3] == '3')
        {
            square[3] = mark;
        }   
        else if (choice == 4 && square[4] == '4')
        {
            square[4] = mark;
        }  
        else if (choice == 5 && square[5] == '5')
        {
            square[5] = mark;
        }   
        else if (choice == 6 && square[6] == '6')
        {
            square[6] = mark;
        }   
        else if (choice == 7 && square[7] == '7')
        {
            square[7] = mark;
        }   
        else if (choice == 8 && square[8] == '8')
        {
            square[8] = mark;
        }   
        else if (choice == 9 && square[9] == '9')
        {
            square[9] = mark;
        }  
        else
        {
            cout<<"Invalid move. Try again!: ";
            invalidMove = true;
            cin.ignore();
        }

        i = checkWin();

    }while(i == -1);

    drawBoard();

    if(i==1)
    {
        winner = (curr_player_id == player_one->getPlayerId()) ? player_one : player_two;
        string winner_name = winner->getPlayerName();
        cout<<"==>\a "<< winner_name << " ( Player: "<< curr_player_id << ", Tag: "<< mark << ")" <<" wins "<<endl;
    }
    else
    {
        cout<<"==>\aGame draw" << endl;;
    }

    cin.ignore();
    
}

ostream& operator<<(ostream &out, const Game &game)
{
    out << "Game" << "\n----\n" << "Player 1 Name: "<< game.player_one->getPlayerName() << " with game tag: " << game.player_one->getPlayerTag();

    return out;
}


};