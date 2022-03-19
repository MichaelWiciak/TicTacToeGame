//#define TEST

#define MaxGrid 10					// the maximum size of the game's grid
extern char grid[MaxGrid][MaxGrid];	// the game's grid

// prototypes of the functions
// the functions themselves are in the tic.c file
int newGame (int gridsize, int winlength);
int makeMove(int row, int col, char symbol);
int boardIsFull();
int checkHorizontal (char symbol, int length);
int checkVertical (char symbol, int length);
int checkDiagonals (char symbol, int length);
int checkAntiDiagonals (char symbol, int length);
int playerHasWon (char symbol , int length);
int effPlayerHasWon (int row, int col, char symbol , int length);
void showGrid ();

int check (int row, int col, char symbol);

int peek (int row, int col);
extern int __Check_Count;
extern int IsAutoGradinng;

