#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// @brief prints the board, adds extra newlines to make it look nicer
void print_board(char board[]) {
    // FILL ME
    // Hint: you can use '-' and '|' to create the borders of the board
}


// @brief modifies the board given a move and a player character
// @param board the board to modify
// @param move [0-8]
// @param player ('X' or 'O')
// @return true if the move is valid, false otherwise
bool make_move(char board[], int move, char player) {
    // FILL ME
}


// @brief enum for the game state
typedef enum {
    IN_PROGRESS,
    X_WINS,
    O_WINS,
    DRAW
} GameState;

// @brief checks the board for a win or draw
// @param board the board to check
// @return IN_PROGRESS if the game is still in progress, X_WINS if X wins, O_WINS if O wins, DRAW if it's a draw
GameState check_win(char board[]) {
    // FILL ME
    // check rows

    // check columns

    // check diagonals

    // check for a draw

    // if no winner, it's a draw
}


// - creates a game board,
// - prints the board,
// - in a while loop until the game is over:
//     - reads the player's move,
//     - checks if the move is valid,
//     - makes the move,
//     - prints the board,
//     - switches the turn,
// - checks the game state,
// - prints the result.
int main() {
    // COMPLETE ME

    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    // print the board
    print_board(board);

    bool turn = true; // true = X, false = O

    while (check_win(board) == IN_PROGRESS)
    {
        // FILL ME
    }

    // print the result
    
    return 0;
}