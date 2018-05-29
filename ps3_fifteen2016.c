/**
 * created by Martin Straußberger
 * Game: Fifteen (generalized to d x d)
 * Note usleep is obsolete, but it offers more granularity thand sleep)
*/

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board Global
int board[DIM_MAX][DIM_MAX];

// dimensions GLOBAL
int d;
// dahs_index_coordinates GLOBAL
int di;
int dj;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage fifteen d\n");
        return 1;
    }

    //ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive. \n",
                DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
            return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with intro
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

        //log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for ( int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d -1)
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

        //log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

    // move if possible, else report impossible)
        if (!move(tile))
        {
            printf("\nImppossible move.\n");
            usleep(500000);
        }

            //sleep thread for animation
            usleep(500000);
    }

    // clear log
    fclose(file);

    // success
    return 0;
}

/**
 * Clear screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d, %dH", 0, 0);
}

/**
* Greets player.
*/
void greet(void)
{
    clear();
    printf("Welcome to the Game: Fifteen\n");
    usleep(2000000);
}


/**
 * Initialize the game´s board with tiles numbered 1 through d*d -1
 * (i.e, fills 2D array with values but does not actually print them.)
 */
void init(void)
{
     // [8 7 6]
     // [5 4 3]
     // [2 1 0]

     int fill_up = d*d-1;
     for (int i = 0; i < d; i++)
        for (int j = 0; j < d; j++)
            board[i][j] = fill_up--;
    dj = d-1;
    dj = d-1;

    // swap if d is even
    if (d % 2 == 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1; // [ 3 1 2 _ ]
    }
}

 /**
  * Prints the board in its current state.
 */
void draw(void)
{
    // [8 7 6]
    // [5 4 3]
    // [2 1 0]
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
                printf(" _ ");
            else
                printf(" %2i ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * If tile border emtpy space, move tile and reutnrs true, else
 * return false.
 */
bool move (int tile)
{
    // [8 7 6]
    // [5 4 3]
    // [2 1 0]

    if (dj != 0 && board[di][dj-1] == tile)
    {
        // swap
        board[di][dj] = tile;
        board[di][dj-1] = 0;
        //update dash_position [ 1 _ 3] => [_ 1 3]
        dj = dj - 1;
        return true;
    }

    if (dj != d-1 && board[di][dj+1] == tile)
    {
        board[di][dj] = tile;
        board[di][dj+1] = 0;

        // update dash_position [1 _ 3] => [1 3 _]
        dj = dj + 1;
        return true;
    }
    if (di != 0 && board[di-1][dj] == tile)
    {
        board[di][dj] = tile;
        board[di-1][dj] = 0;

        di = di - 1;
        return true;
    }
    if (di != d-1 && board[di+1][dj] == tile)
    {
        board[di][dj] = tile;
        board[di+1][dj] = 0;

        di = di + 1;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false
 */
bool won(void)
{
    // TO DO
    int counter = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //if (i == d && j == d-1 && board[i][j] == 0)
              //  return true;

            if (board[i][j] != counter)
            {
                return false;
            }
            counter = (counter + 1) % (d*d);
            // ending must have zero
            }
        }

        return true;
}
