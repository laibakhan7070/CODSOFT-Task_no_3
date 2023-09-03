#include <iostream>
#include <limits>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void displayBoard() {
    //prints 3x3 Grid Board
    cout << "------------";
    cout << "\nTic Tac Toe|\n";
    cout << "------------\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) {
                cout << "|";
            }
        }
        cout << "\n";
        if (i < 2) {
            cout << "-----------\n";
        }
    }
    cout << "\n";
}

bool isCellOccupied(int choice) {
    //Checks if cell is already occupied 
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    return (board[row][col] == 'X' || board[row][col] == 'O');
}

bool makeMove(int choice) {
    if (choice < 1 || choice > 9) {
        cout << "Invalid move. Please enter a number between 1 and 9.\n";
        return false;
    }

    if (isCellOccupied(choice)) {
        cout << "Cell " << choice << " is already occupied.Choose an empty cell.\n";
        return false;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = currentPlayer;
    return true;
}


bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {     //row (---)
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {     //column (|)
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {         //diadonal (\)
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {         //diagonal (/)
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void TicTacToeGame() {
    int choice;
    bool gameover = false;

    cout << "----------------------------------------------------------------\n";
    cout << "|             Welcome to the TIC TAC TOE GAME!                 |\n";
    cout << "----------------------------------------------------------------\n";
    while (!gameover) {
        displayBoard();
        cout << "Player " << currentPlayer << ", please enter a number (1-9): ";
        cin >> choice;

        if (cin.fail()) {
            cout << "\nInvalid input. Please enter a valid number.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "\n";

        if (makeMove(choice)) {
            if (checkWin()) {
                displayBoard();
                cout << "Congratulations, Player " << currentPlayer << " wins!\n\n";
                gameover = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n\n";
                gameover = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            cout << "Please try again.\n\n";
        }
    }

}

void Rules() {
    cout << "\n|----------------------------RULES:------------------------|\n";
    cout << "|1. The game is played on a 3x3 grid.                      |\n" ;
    cout << "|2. There are two players, X and O.                        |\n" ;
    cout << "|3. Players take turns to place their symbol on the grid.  |\n" ;
    cout << "|4. The first player to get 3 of their symbols in a row    |\n" ;
    cout << "|   (horizontally, vertically, or diagonally) wins.        |\n" ;
    cout << "|5. If grid is filled & no player has won, game is a draw. |\n" ;
    cout << "|6. Have fun and enjoy the game!                           |\n\n" ;
}

int main() {
    string choice;

    do {
        cout << "\n---------------------------|\n";
        cout << "1. View Game Rules         |\n";
        cout << "2. Start Tic Tac Toe Game  |\n";
        cout << "3. Quit Game               |\n";
        cout << "---------------------------|\n\n";

        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n";

        if (choice.length() == 1) {
            switch (choice[0]) {
            case '1':
                Rules();
                break;

            case '2':
                TicTacToeGame();
                break;

            case '3':
                cout << "\nThanks for playing.Hope you had fun.\n\n";
                break;

            default:
                cout << "\nInvalid input :( Please enter a valid number.\n" << endl;

        }
        }
        else {
            cout << "\nInvalid input :( Please enter a valid number.\n" << endl;
        }
    } while (choice != "3");

    return 0;
}