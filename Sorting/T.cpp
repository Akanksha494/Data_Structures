
  
#include <iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<cstdlib>
#include<MMSystem.h>

using namespace std;

char best_move(char[][3], char, char, int);
void won(string);
void rules();
void display_game(char[3][3]);
void counter();
bool set_game(char[][3], char, char);
void invalid();
void singlePlayer();
void multiPlayer();
bool check_win(char[][3]);
void display_score(int, int, int, string, string);
bool ask();

int main()
{
    system("cls");

    PlaySound(TEXT("Faded.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    char choice = '0';

    while(choice != '4')
    {
        system("cls");
        cout << endl << endl;
        cout << "1. Single Player.\n";
        cout << "2. Multi Player.\n";
        cout << "3. Rules.\n";
        cout << "4. Exit.\n" << endl;
        cout << "Enter your choice:\n";
        cin >> choice;

        switch(choice)
        {
            case '1':
                singlePlayer();
                break;
            case '2':
                multiPlayer();
                break;
            case '3':
                rules();
                break;
            case '4':
                return 0;
            default:
                invalid();
        }
    }

    getch();
    return 0;
}



void singlePlayer()
{
    int player_score = 0, computer_score = 0, tie = 0;

    system("cls");

    string name;
    char player_mark, computer_mark, chance, mark;

    cout << "Enter your name:" << endl;
    cin >> name;

    mark5:
        cout << endl << "Choose you mark" << endl;
        cout << "1. 0\n2. X" << endl;
        cin >> player_mark;

        if(player_mark == '1')
        {
            player_mark = '0';
            computer_mark = 'X';
        }
        else if(player_mark == '2')
        {
            player_mark = 'X';
            computer_mark = '0';
        }
        else
        {
            invalid();
            goto mark5;
        }

    mark6:
        int moves = 0;
        char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'},{'7', '8', '9'}};
        cout << endl << "Do you want to start the game:" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> chance;

        if(chance != '1' && chance != '2')
        {
            invalid();
            goto mark6;
        }

        counter();

        while(moves < 9)
        {
            display_score(player_score, computer_score, tie, name, "Computer");
            display_game(game);
            if(chance == '1')
            {
                cout << "Your Chance" << endl;
                cout << "Your mark is : " << player_mark << endl;
                mark7:
                    cin >> mark;
                    if(!set_game(game, mark, player_mark))
                        goto mark7;
                moves++;
                if(moves > 4 && check_win(game))
                {
                    player_score++;
                    display_score(player_score, computer_score, tie, name, "Computer");
                    display_game(game);
                    won(name);
                    if(ask())
                    {
                        system("cls");
                        goto mark6;
                    }
                    return;
                }
                chance = '2';
            }
            else
            {
                mark = best_move(game, computer_mark, player_mark, moves);
                moves++;

                if(set_game(game, mark, computer_mark) && moves > 4)
                {
                    if(check_win(game))
                    {
                        computer_score++;
                        display_score(player_score, computer_score, tie, name, "Computer");
                        display_game(game);
                        won("Computer");
                        if(ask())
                        {
                            system("cls");
                            goto mark6;
                        }
                        return;
                    }
                }

                chance = '1';
            }
        }
    tie++;
    display_score(player_score, computer_score, tie, name, "Computer");
    display_game(game);
    cout << "It's a tie" << endl;

     if(ask())
    {
        system("cls");
        goto mark6;
    }
    return;
}


void multiPlayer()
{
    system("cls");

    int player1_score = 0, player2_score = 0, tie = 0;
    string player1_name, player2_name;
    char player1_mark , player2_mark, chance, mark;

    cout << "Enter 1st player's name:   ";
    cin >> player1_name;

    cout << endl << "Enter 2nd player's name:   ";
    cin >> player2_name;
    cout << endl;
    cout << player1_name << " - \nPlease choose 0 or X as mark\n";

    mark1:

    cout << "1. 0 \n2. X" << endl;
    cin >> chance;
    cout << endl;

    switch(chance)
    {
        case '1':
            player1_mark = '0';
            player2_mark = 'X';
            cout << player1_name << " has chosen " << player1_mark << endl;
            cout << player2_name << " has chosen " << player2_mark << endl;
            break;
        case '2':
            player1_mark = 'X';
            player2_mark = '0';
            cout << player1_name << " has chosen " << player1_mark << endl;
            cout << player2_name << " has chosen " << player2_mark << endl;
            break;
        default:
            invalid();
            goto mark1;
    }

    cout << endl;
    cout << "Who wants to start !!!\n";

    mark2:

    cout << "1. " << player1_name << endl << "2. " << player2_name << endl;
    cin >> chance;

    if(chance != '1' && chance != '2')
    {
        invalid();
        goto mark2;
    }

    char game[3][3] = {'1', '2', '3', '4', '5', '6','7', '8', '9'};
    int moves = 0;
    counter();

    while(moves < 9)
    {
        display_score(player1_score, player2_score, tie, player1_name, player2_name);
        display_game(game);

        if(chance == '1')
        {
            cout << player1_name << "\'s chance \n";
            cout << "Your mark is : " << player1_mark << endl;
            mark3:
                cin >> mark;

            if(!set_game(game, mark, player1_mark))
                goto mark3;

            moves++;

            if(moves > 4 && check_win(game))
            {
                player1_score++;
                display_score(player1_score, player2_score, tie, player1_name, player2_name);
                display_game(game);
                won(player1_name);

                if(ask())
                {
                    system("cls");
                    cout << "Who wants to start !!!\n";
                    goto mark2;
                }
                return;
            }
            chance = '2';
        }

        else
        {
            cout << player2_name << "\'s chance \n";
            cout << "Your mark is : " << player2_mark << endl;
            mark4:
                cin >> mark;

            if(!set_game(game, mark, player2_mark))
                goto mark4;

            moves++;

            if(moves > 4 && check_win(game))
            {
                player2_score++;
                display_score(player1_score, player2_score, tie, player1_name, player2_name);
                display_game(game);
                won(player2_name);

                if(ask())
                {
                    system("cls");
                    cout << "Who wants to start !!!\n";
                    goto mark2;
                }
                return;
            }
            chance = '1';
        }
    }

    tie++;
    display_score(player1_score, player2_score, tie, player1_name, player2_name);
    display_game(game);
    cout << "It's a tie..." << endl;
    if(ask())
    {
        system("cls");
        cout << "Who wants to start !!!\n";
        goto mark2;
    }
    return;
}


void rules()
{
    system("cls");
    cout << endl << endl << endl << "\t\t\t\t";
    cout << "RULES...";
    cout << endl << endl << endl << "\t\t\t\t";
    cout << "1. The game is played on a grid that's 3 squares by 3 squares.";
    cout << endl << "\t\t\t\t";
    cout << "2. You are X, your friend (or the computer in this case) is O.\n\t\t\t\t   ";
    cout << "Players take turns putting their marks in empty squares.";
    cout << endl << "\t\t\t\t";
    cout << "3. The first player to get 3 of his/her marks in a row\n\t\t\t\t   (row-wise, column-wise or diagonally) is the winner.";
    cout << endl << "\t\t\t\t";
    cout << "4. When all 9 squares are full, the game is over.\n\t\t\t\t   If no player has 3 marks in a row, the game ends in a tie.";
    cout << endl << endl;
    cout << "Press any key to exit...!!!";
    getch();
}

void invalid()
{
    cout << endl << "Invalid choice...!!! \nChoose again!!!" << endl;
}

void display_game(char game[3][3])
{
    int i, j, k = 0,l = 0;

    cout << endl << endl << endl;
    for(i=0;i<13;i++)
    {
        if(i == 6 || i == 8)
        {
            l = 0;
        }

        for(j = 0; j < 20; j++)
            cout << "  ";

        if(i == 0 || i == 4 || i == 8 || i == 12)
        {
            for(j = 0; j < 13; j++)
                cout << "* ";
            cout << endl;
        }
        else
        {
            for(j = 0; j < 25; j++)
            {
                if(j % 8 == 0)
                    cout << "*";

                else if(i == 2 && (j == 4 || j == 12 || j == 20))
                    cout << game[0][l++];

                else if(i == 6 && (j == 4 || j == 12 || j == 20))
                    cout << game[1][l++];

                else if(i == 10 && (j == 4 || j == 12 || j == 20))
                    cout << game[2][l++];

                else
                    cout << " ";
            }
            cout << endl;
        }
    }
}

void counter()
{
    int min;
    system("cls");

    cout << "\n\n\n\n\t Play begins in :";

    cout << "\n\n\n";

    for(min = 5; min > 0; min--)
    {
        Sleep(1000);
        cout << "\r\t\t\t" << min;
    }

    Sleep(1000);
}

bool set_game(char game[3][3],char mark, char p)
{
    if(mark == '1' && game[0][0] == '1')
    {
        game[0][0] = p;
        return true;
    }

    else if(mark == '2' && game[0][1] == '2')
    {
        game[0][1] = p;
        return true;
    }

    else if(mark == '3' && game[0][2] == '3')
    {
        game[0][2] = p;
        return true;
    }

    else if(mark == '4' && game[1][0] == '4')
    {
        game[1][0] = p;
        return true;
    }

    else if(mark == '5' && game[1][1] == '5')
    {
        game[1][1] = p;
        return true;
    }

    else if(mark == '6' && game[1][2] == '6')
    {
        game[1][2] = p;
        return true;
    }

    else if(mark == '7' && game[2][0] == '7')
    {
        game[2][0] = p;
        return true;
    }

    else if(mark == '8' && game[2][1] == '8')
    {
        game[2][1] = p;
        return true;
    }

    else if(mark == '9' && game[2][2] == '9')
    {
        game[2][2] = p;
        return true;
    }

    invalid();
    return false;
}

bool check_win(char game[3][3])
{
    int i;
    for(i = 0; i < 3; i++)
    {
        if(game[i][0] == game[i][1] && game[i][0] == game[i][2] && (game[i][0] == '0' || game[i][0] == 'X'))
            return true;
    }

    for(i = 0; i < 3; i++)
    {
        if(game[0][i] == game[1][i] && game[0][i] == game[2][i] && (game[0][i] == '0' || game[0][i] == 'X'))
            return true;
    }

    if(game[0][0] == game[1][1] && game[0][0] == game[2][2] && (game[0][0] == '0' || game[0][0] == 'X') )
        return true;

    if(game[0][2] == game[1][1] && game[0][2] == game[2][0] && (game[0][2] == '0' || game[0][2] == 'X') )
        return true;
    return false;
}

void won(string name)
{
    string s = "Computer";
    if(strcmp(name.c_str(), s.c_str()) != 0)
    {
        cout << "CONGRATULATIONS....!!!!" << endl;
        cout << name << " you Won" << endl;
    }
    else
    {
        cout << "You Lose..." << endl;
    }
}

char best_move(char game[3][3], char computer_mark, char player_mark, int moves)
{
    if(game[0][0] == computer_mark)
    {
        if(game[0][0] == game[0][1] && game[0][2] == '3')
            return game[0][2];

        if(game[0][0] == game[0][2] && game[0][1] == '2')
            return game[0][1];

        if(game[0][0] == game[1][0] && game[2][0] == '7')
            return game[2][0];

        if(game[0][0] == game[2][0] && game[1][0] == '4')
            return game[1][0];

        if(game[0][0] == game[1][1] && game[2][2] == '9')
            return game[2][2];

        if(game[0][0] == game[2][2] && game[1][1] == '5')
            return game[1][1];
    }

    if(game[1][1] == computer_mark)
    {
        if(game[1][1] == game[0][1] && game[2][1] == '8')
            return game[2][1];

        if(game[1][1] == game[2][1] && game[0][1] == '1')
            return game[0][1];

        if(game[1][1] == game[0][2] && game[2][0] == '7')
            return game[2][0];

        if(game[1][1] == game[1][2] && game[1][0]== '4')
            return game[1][0];

        if(game[1][1] == game[2][2] && game[0][0] == '1')
            return game[0][0];

        if(game[1][1] == game[2][0] && game[0][2] == '3')
            return game[0][2];

        if(game[1][1] == game[1][0] && game[1][2] == '6')
            return game[1][2];
    }

    if(game[0][1] == computer_mark)
    {
        if(game[0][1] == game[0][2] && game[0][0] == '1')
            return game[0][0];

        if(game[0][1] == game[2][1] && game[1][1] == '5')
            return game[1][1];
    }

    if(game[0][2] == computer_mark)
    {
        if(game[0][2] == game[1][2] && game[2][2] == '9')
            return game[2][2];

        if(game[0][2] == game[2][0] && game[1][1] == '5')
            return game[1][1];

        if(game[0][2] == game[2][2] && game[1][2] == '6')
            return game[1][2];
    }

    if(game[1][0] == computer_mark)
    {
        if(game[1][0] == game[1][2] && game[1][1] == '5')
            return game[1][1];

        if(game[1][0] == game[2][0] && game[0][0] == '1')
            return game[0][0];
    }

    if(game[1][2] == computer_mark)
    {
        if(game[1][2] == game[2][2] && game[0][2] == '3')
            return game[0][2];
    }

    if(game[2][0] == computer_mark)
    {
        if(game[2][0] == game[2][1] && game[2][2] == '9')
            return game[2][2];

        if(game[2][0] == game[2][2] && game[2][1] == '8')
            return game[2][1];
    }

    if(game[2][1] == computer_mark)
    {
        if(game[2][1] == game[2][2] && game[2][0] == '7')
            return game[2][0];
    }

    if(game[0][0] == player_mark)
    {
        if(game[0][0] == game[0][1] && game[0][2] == '3')
            return game[0][2];

        if(game[0][0] == game[0][2] && game[0][1] == '2')
            return game[0][1];

        if(game[0][0] == game[1][0] && game[2][0] == '7')
            return game[2][0];

        if(game[0][0] == game[2][0] && game[1][0] == '4')
            return game[1][0];

        if(game[0][0] == game[1][1] && game[2][2] == '9')
            return game[2][2];

        if(game[0][0] == game[2][2] && game[1][1] == '5')
            return game[1][1];
    }

    if(game[1][1] == player_mark)
    {
        if(game[1][1] == game[0][1] && game[2][1] == '8')
            return game[2][1];

        if(game[1][1] == game[2][1] && game[0][1] == '1')
            return game[0][1];

        if(game[1][1] == game[0][2] && game[2][0] == '7')
            return game[2][0];

        if(game[1][1] == game[1][2] && game[1][0]== '4')
            return game[1][0];

        if(game[1][1] == game[2][2] && game[0][0] == '1')
            return game[0][0];

        if(game[1][1] == game[2][0] && game[0][2] == '3')
            return game[0][2];

        if(game[1][1] == game[1][0] && game[1][2] == '6')
            return game[1][2];

        if(game[1][1] == game[1][2] && game[1][0] == '4')
            return game[1][0];
    }

    if(game[0][1] == player_mark)
    {
        if(game[0][1] == game[0][2] && game[0][0] == '1')
            return game[0][0];

        if(game[0][1] == game[2][1] && game[1][1] == '5')
            return game[1][1];
    }

    if(game[0][2] == player_mark)
    {
        if(game[0][2] == game[1][2] && game[2][2] == '9')
            return game[2][2];

        if(game[0][2] == game[2][0] && game[1][1] == '5')
            return game[1][1];

        if(game[0][2] == game[2][2] && game[1][2] == '6')
            return game[1][2];
    }

    if(game[1][0] == player_mark)
    {
        if(game[1][0] == game[1][2] && game[1][1] == '5')
            return game[1][1];

        if(game[1][0] == game[2][0] && game[0][0] == '1')
            return game[0][0];
    }

    if(game[1][2] == player_mark)
    {
        if(game[1][2] == game[2][2] && game[0][2] == '3')
            return game[0][2];
    }

    if(game[2][0] == player_mark)
    {
        if(game[2][0] == game[2][1] && game[2][2] == '9')
            return game[2][2];

        if(game[2][0] == game[2][2] && game[2][1] == '8')
            return game[2][1];
    }

    if(game[2][1] == player_mark)
    {
        if(game[2][1] == game[2][2] && game[2][0] == '7')
            return game[2][0];
    }

    if(moves == 8)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(game[i][j] != computer_mark && game[i][j] != player_mark)
                    return game[i][j];
            }
        }
    }

    char mark;
    int flag;
    do
    {
        mark = 48 + (rand() % 9);
        flag = 0;

        if(mark != '0')
        {
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(game[i][j] == mark)
                    {
                        flag = 1;
                        break;
                    }
                }

            }
        }
    }while(flag == 0);

    return mark;
}

void display_score(int player1_score, int player2_score, int tie, string player1_name, string player2_name)
{
    system("cls");
    cout << "SCORE : " << endl;
    cout << player1_name << " : " << player1_score << endl;
    cout << player2_name << " : " << player2_score << endl;
    cout << "Tie : " << tie << endl;
}

bool ask()
{
    cout << endl;
    cout << "Want to play again???" << endl;
    cout << "Y. Yes" << endl;
    cout << "N. No" << endl;
    char choice;
    label:
    cin >> choice;
    switch(choice)
    {
        case 'Y':
            return true;
        case 'y':
            return true;
        case 'N':
            return false;
        case 'n':
            return false;
        default:
            invalid();
            goto label;
    }
}