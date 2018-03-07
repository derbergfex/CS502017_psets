/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void linSearch(int t);
bool legalMove(void);

int blank_row;
int blank_column;
int tile_row;
int tile_column;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);

    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n", DIM_MIN, DIM_MIN, DIM_MAX,
               DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality (move returns a bool, but changes the value of tile)
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // Number of tiles.
    int tiles = d * d - 1;

    // i rows.
    for (int i = 0; i < d; i++)
    {
        // j columns.
        for (int j = 0; j < d; j++)
        {
            board[i][j] = tiles;
            tiles--;
        }
    }

    // Swap the tiles of 1 and 2 if the total number of tiles is odd.
    if (d % 2 == 0)
    {
        int temp = board[d - 1][d - 3];
        board[d - 1][d - 3] = board[d - 1][d - 2];
        board[d - 1][d - 2] = temp;
    }

    // We note the position of the empty tile as follows (where board[d - 1][d - 1] == 0).
    blank_row = d - 1;
    blank_column = d - 1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf("  _ ");
            }
            else
            {
                printf(" %2i ", board[i][j]);
            }
        }

        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // Make sure the tile is valid.
    if (tile > d * d - 1 || tile < 1)
    {
        return false;
    }

    // Find location of tile.
    linSearch(tile);

    if (legalMove())
    {
        int temp = board[tile_row][tile_column];
        board[tile_row][tile_column] = board[blank_row][blank_column];
        board[blank_row][blank_column] = temp;

        blank_row = tile_row;
        blank_column = tile_column;
        return true;
    }
    else
    {
        return false;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int counter = 1;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == counter)
            {
                counter++;
            }

        }
    }

    if (counter == d * d && board[d - 1][d - 1] == 0)
    {
        return true;
    }

    else
    {
        return false;
    }

    return false;
}


// Linear Search
void linSearch(int t)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == t)
            {
                tile_row = i;
                tile_column = j;
            }
        }
    }
}

// Returns true if the move is legal, and false othersie.
bool legalMove(void)
{
    // First case: the blank is above of it.
    if (tile_row > 0 && board[tile_row - 1][tile_column] == 0)
    {
        return true;
    }
    // Second case: the blank is below it.
    if (tile_row < d - 1 && board[tile_row + 1][tile_column] == 0)
    {
        return true;
    }
    // Third case: the blank is to its right.
    if (tile_column < d - 1 && board[tile_row][tile_column + 1] == 0)
    {
        return true;
    }
    // Fourth case: the blank is to its left.
    if (tile_column > 0 && board[tile_row][tile_column - 1] == 0)
    {
        return true;
    }

    return false;
}