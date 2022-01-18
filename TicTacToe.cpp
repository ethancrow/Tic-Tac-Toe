#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//var declaration
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
int row,column;
char turn = 'X';
bool tie = false;

//Function to show the current status of the gaming board
void display_board() {

    //Array for the board
    char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

    // playing board
    cout << "PLAYER - 1 [X] PLAYER - 2 [O] \n";
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  | " << board[0][1] << "   | " << board[0][2] << "   \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  | " << board[1][1] << "   | " << board[1][2] << "   \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  | " << board[2][1] << "   | " << board[2][2] << "   \n";
    cout << "     |     |     \n";
}

//Function to get the player input and update the board

void player_turn() {

    //Allows the player to select the space
    if (turn == 'X') {
        cout << "Player 1's turn please enter: ";
        cout << "\n";
    }
    if (turn == 'O') {
        cout << "Player 2's turn please enter: ";
        cout << "\n";
    }

    cin >> choice;
   
    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }


    //checks if the space has already been choosen and updates if it hasn't
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        //if input position already filled
        cout << "Box already filled!n Please choose another!!nn";
        player_turn();
    }
    //displays the board after players turn
    //display_board();
}

//Function to get the game status

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return false;

    //Checking the if game already draw
    tie = true;
    return false;
}

//Program Main Method

int main()
{
    cout << "Enter a name for Player 1 : \n";
    string n1;
    getline(cin, n1);
    cout << "Enter a name for Player 2 : \n";
    string n2;
    getline(cin, n2);

    cout << n1 << " is player1 so they will play first \n";
    cout << n2 << " is player2 so they will play second \n";

    while (!gameover()) {
        display_board();
        player_turn();
        gameover();
    }
    if (turn == 'X' && tie == false) {
        cout << n2 << " Wins!!" << endl;
    }
    else if (turn == 'O' && tie == false) {
        cout << n1 << " Wins!!" << endl;
    }
    else
        cout << "Draw!" << endl;
}