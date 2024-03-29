#include <iostream> 
using namespace std; 

// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) 
    { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) 
        { 
            cout << board[i][j] << " | "; 
        }   
        cout << "\n-------------\n"; 
    } 
} 

// Function to check for a win 
bool checkWin(char board[3][3], char player) 
{ 
    // Check rows, columns, and diagonals 
    for (int i = 0; i < 3; i++) 
    { 
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            cout << "Player " << player << " wins by completing a row!\n";
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            cout << "Player " << player << " wins by completing a column!\n";
            return true; 
        }
    } 
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        cout << "Player " << player << " wins by completing the main diagonal!\n";
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        cout << "Player " << player << " wins by completing the secondary diagonal!\n";
        return true; 
    }
    return false; 
}

int main() 
{ 
    char board[3][3];
    char choice = 'Y'; // Initialize choice to start the loop
    char play = 'Y'; // Initialize play to some default value
    
    while (choice == 'Y' || choice == 'y') {
        // Initialize the board and players 
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        char player = 'X'; 
        int row, col; 
        int turn; // Declare turn here 
        cout << "Welcome to Tic-Tac-Toe!\n"; 


        // Game loop 
        for (turn = 0; turn < 9; turn++)
        { 
            // Draw the board 
            drawBoard(board); 
            // Prompt for valid input 
            while (true) 
            { 
                cout << "Player " << player << ", enter row (0-2) and column (0-2): "; 
                cin >> row >> col; 
                if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') 
                { 
                    cout << "Invalid move. Try again.\n"; 
                } 
                else 
                { 
                    break;  
                } 
            } 
            // Make the move 
            board[row][col] = player; 
            // Check for a win after making a move 
            if (checkWin(board, player)) 
            { 
                drawBoard(board); 
                break; 
            } 
            // Switch to the other player 
            player = (player == 'X') ? 'O' : 'X'; 
        } 
        // End of the game  
        // Check for a draw 
        if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) 
        { 
            cout << "It's a draw!\n";  
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;

        if (choice != 'Y' && choice != 'y') {
            cout << "Thank you for playing!\n";
            break;
        }

        cout << "Are you willing to play again? (Y/N): ";
        cin >> play;
        if (play != 'Y' && play != 'y') {
            cout << "Thank you for playing!\n";
            break;
        }
        
    } 

    return 0; 
}

