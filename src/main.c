#include <stdio.h>
#include <stdlib.h>

#include "square.h"
#include "board.h"

/**
 * @brief Initializes the board object that will be used throughout the game.
 * 
 * @param None.
 * 
 * @return Pointer to the board object.
 */
Board* initBoard(void)
{
    Board* newBoard = malloc(sizeof(Board));

    if (newBoard != NULL)
    {
        newBoard->blackKing = 1ULL << E8;
        newBoard->blackQueen = 1ULL << D8;
        newBoard->blackRooks = (1ULL << A8) | (1ULL << H8);
        newBoard->blackKnights = (1ULL << B8) | (1ULL << G8);
        newBoard->blackBishops = (1ULL << C8) | (1ULL << F8);
        newBoard->blackPawns = 0xFFULL << A7;

        newBoard->whiteKing = 1ULL << E1;
        newBoard->whiteQueen = 1ULL << D1;
        newBoard->whiteRooks = (1ULL << A1) | (1ULL << H1);
        newBoard->whiteKnights = (1ULL << B1) | (1ULL << G1);
        newBoard->whiteBishops = (1ULL << C1) | (1ULL << F1);
        newBoard->whitePawns = 0xFFULL << A2;

        newBoard->who2move = WHITE;
        newBoard->checkmate = false;
    }

    return newBoard;
}


/**
 * @brief Main game loop. Runs until checkmate is detected.
 * 
 * @param board: Pointer to board object
 * 
 * @return None.
 */
void runGame(Board* board)
{
    while (!board->checkmate)
    {

        if (board->who2move == WHITE)
        {
            /* Calculate pseudo-legal moves for white side. */

            board->who2move = BLACK;
        }
        else
        {
            /* Calculate pseudo-legal moves for black side. */

            board->who2move = WHITE;
        }

    }
}

int main(void)
{
    printf("Welcome to gcchess-engine!\n");

    printf("Initializing board...\n");
    Board* board = initBoard();

    if (board == NULL)
    {
        fprintf(stderr, "Failed to initialize the board. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Board initialized.\n");

    printf("Running the game...\n");
    runGame(board);

    return EXIT_SUCCESS;
}