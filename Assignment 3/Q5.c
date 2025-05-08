#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    IN_PROGRESS,
    X_WINS,
    O_WINS,
    DRAW
} Gamestate;

void print_board(char board[])
{
    printf(" %c |", board[0]);
    printf(" %c |", board[1]);
    printf(" %c \n", board[2]);

    printf("-----------\n");

    printf(" %c |", board[3]);
    printf(" %c |", board[4]);
    printf(" %c \n", board[5]);

    printf("-----------\n");

    printf(" %c |", board[6]);
    printf(" %c |", board[7]);
    printf(" %c \n", board[8]);
}

Gamestate check_win(char board[])
{
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // satırlar
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // sütunlar
        {0, 4, 8}, {2, 4, 6}             // çaprazlar
    };

    for (int i = 0; i < 8; i++)
    {
        int a = wins[i][0];
        int b = wins[i][1];
        int c = wins[i][2];

        if (board[a] == board[b] && board[a] == board[c] && board[a] != ' ')
        {
            return (board[a] == 'X') ? X_WINS : O_WINS;
        }
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            return IN_PROGRESS;
        }
    }
    return DRAW;
}

bool make_move(char board[], int move, char player)
{
    if (board[move] != ' ')
    {
        return false;
    }
    else
    {
        board[move] = player;
        return true;
    }
}

int main(){
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    print_board(board);
    int move;

    bool turn = true; // true -> X, false -> O
    
    while (check_win(board) == IN_PROGRESS)
    {
        if (turn)
        {
            printf("It's the move for X. Enter the move target: ");
            scanf("%d", &move);
            
            if (!make_move(board, move - 1, 'X'))
            {
                printf("Invalid move.\n");
            }
            else turn = false;
        }
        else
        {
            printf("It's the move for O. Enter the move target: ");
            scanf("%d", &move);
            
            if (!make_move(board, move - 1, 'O'))
            {
                printf("Invalid move.\n");
            }
            else turn = true;
        }
        print_board(board);
    }

    switch (check_win(board))
    {
    case X_WINS:
        printf("X wins the game.\n");
        break;

    case O_WINS:
        printf("O wins the game.\n");
        break;

    case DRAW:
        printf("Nobody wins the game, it's a DRAW.\n");
        break;
    
    default:
        printf("Invalid result.\n");
        break;
    }

    return EXIT_SUCCESS;
}