#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

/*
    For tracking all pieces' positions (board state) at any given time.

    Each element is a bitboard (64 bits). The 1s' positions in the binary 
    equivalent of the element's value represents all positions that that piece(s)
    exist at on the board.

    E.g. Black pawns starting position would be 
*/

typedef struct
{
    /* Black pieces */
    uint64_t blackKing;
    uint64_t blackQueen;
    uint64_t blackRooks;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackPawns;

    /* White pieces */
    uint64_t whiteKing;
    uint64_t whiteQueen;
    uint64_t whiteRooks;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whitePawns;

} BoardState;

#endif