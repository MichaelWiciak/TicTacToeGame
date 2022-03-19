#include <stdio.h>
#include <stdlib.h>
#include "tic.h"



char grid[MaxGrid][MaxGrid]; // this is the grid that will be used to store the moves of the game

int __Check_Count;

void promptEnterGridSize ()
{
  printf ("Enter grid size (3-10):");
}

void promptEnterWinLength (int max_win_length)
{
	printf ("Enter winning length (3-%i):", max_win_length);
}

void promptChooseLocation (char symbol)
{
	printf ("Player %c, Choose Location (row,col): ", symbol);
}

void showErrIndex ()
{
  printf ("Index out of range, please re-enter\n");
}

void showErrTaken ()
{
  printf ("This location is already taken\n");
}

void showWinMessage (char symbol)
{
	printf ("**************************\n");
	printf ("Player %c has won the game\n", symbol);
	printf ("**************************\n");
}

void showGameOverMessage ()
{
	printf ("Game over; there are no winners\n");
}

void promptPlayBackGame ()
{
  printf ("\nWould you like to play back the recorded game? (y,n)?");
}

void promptNextOrExit ()
{
  printf ("Next or Exit (n,e)?");
}

int check (int row, int col, char symbol)
{
	__Check_Count++;
	if (grid[row][col] == symbol)
		return 1;
	return 0;
}

int peek (int row, int col)
{
	return grid[row][col];
}

int gridsize = 0;
int checkSymbol (char symbol);


int newGame (int gridsize, int winlength)
{
	if ((gridsize < 3) || (gridsize > 10))
  return 0;

  if ((winlength < 3) || (winlength > gridsize))
  return 0;

  return 1;
}

void showGrid ()
{
printf("\n\t");
for (int row=0; row<=gridsize-1; row++){
  if (row==0){
    for (int i=0; i<=gridsize-1; printf("%i ", i),i++);{
    printf("\n");}
    printf("\n");
  }

  printf("%i\t", row);
  for (int element=0; element<=gridsize-1;element++){
    printf("%c ", grid[row][element]);}
  printf("\n");}

printf("\n");

}

int makeMove(int row, int col, char symbol)
{
    if ((row >= 0) && (row<=gridsize) && (col >= 0) && (col<=gridsize) && (grid[row][col] == '.') && ((symbol=='X')||(symbol=='O'))){
    grid[row][col] = symbol;
    return 1;}
    else return 0;

}

int boardIsFull()
{
  for (int i =0; i<=gridsize ;i++)
  {for (int j=0; j<=gridsize ;j++)
    {if (grid[i][j] == '.')
      return 0;}}
	return 1;
}

int checkHorizontal (char symbol, int length)
{
  int currentLength;
  if ((length < 3) || (length > gridsize) || (checkSymbol(symbol)==0))
  return -1;

  for (int row=0; row <=gridsize-1; row++)
  {
    currentLength=0;
    for (int column=0; column <=gridsize-1; column++)
    {
      if (grid[row][column] == symbol)
      {
        currentLength++;}
      if (currentLength == length)
      {
        return 1;
      }
      if (grid[row][column] != symbol)
      {
        currentLength=0;
      }
    }

  }
  return 0;
}


int checkVertical (char symbol, int length)
{
  int currentLength;
  if ((length < 3) || (length > gridsize)|| (checkSymbol(symbol)==0))
  return -1;
  for (int row=0; row <=gridsize-1; row++)
  {
    currentLength=0;
    for (int column=0; column <=gridsize-1; column ++)
    {
      if (grid[column][row] == symbol)
      {
        currentLength++;}
      if (currentLength == length)
      {
        return 1;
      }
      if (grid[column][row] != symbol)
      {
        currentLength=0;
      }
    }
  }
  return 0;
}

int checkDiagonals (char symbol, int length)
{
  int currentLength;
  if ((length < 3) || (length > gridsize)|| (checkSymbol(symbol)==0))
  return -1;

  for (int column=0, row=gridsize-1; row >=0; row--)
  {
    currentLength=0;
    for (int x=column, y=row; ((y<=gridsize-1) && (x<=gridsize-1)); x++, y++)
    {
      if (grid[y][x] == symbol)
      {
        currentLength++;}
      if (currentLength == length)
      {
        return 1;
      }
      if (grid[y][x] != symbol)
      {
        currentLength=0;}
    }
  }
  for (int column=1, row=0; column <=gridsize-1; column++)
  {
    currentLength=0;
    for (int x=column, y=row; ((y<=gridsize-1) && (x<=gridsize-1)) ; x++, y++)
    {
      if (grid[y][x] == symbol)
      {
        currentLength++;}
      if (currentLength == length)
      {
        return 1;
      }
      if (grid[y][x] != symbol)
      {
        currentLength=0;}
    }
  }
  return 0;
}

int checkAntiDiagonals (char symbol, int length)
{
  int currentLength=0;
  if ((length < 3) || (length > gridsize)|| (checkSymbol(symbol)==0))
  return -1;

  for (int column=gridsize-1, row=gridsize-1; row >=0; row--)
  {
    currentLength=0;
    for (int x=column, y=row; ((y>=0) && (x>=0)); x--, y++)
    {
      if (grid[y][x] == symbol)
      {
        currentLength++;}
      if (currentLength == length)
      {
        return 1;
      }
      if (grid[x][y] != symbol)
      {
        currentLength=0;}
    }
  }
  for (int column=gridsize-2, row=0; column >=0; column--)
  {
    currentLength=0;
    for (int x=column, y=row; ((y>=0) && (x>=0)) ; x--, y++)
    {
      if (grid[y][x] == symbol)
      {
        currentLength++;}
      if (currentLength == length)
      {
        return 1;
      }
      if (grid[x][y] != symbol)
      {
        currentLength=0;}
    }
  }
  return 0;
}


int playerHasWon (char symbol , int length)
{
  if ((length < 3) || (length > gridsize)|| (checkSymbol(symbol)==0))
  return -1;
  if ((checkHorizontal(symbol, length)==1) ||(checkVertical(symbol, length)==1) ||(checkDiagonals(symbol, length)==1) ||(checkAntiDiagonals(symbol, length)==1)){
    return 1;}
  else return 0;

}

int effPlayerHasWon (int row, int col, char symbol , int length)
{

  if ((row < 0) || (row>gridsize) || (col < 0) || (col>gridsize) || (length<3) || (checkSymbol(symbol)==0)){
    return -1;}

  int horizontalLine=1, verticalLine=1, diagonalLine=1, antidiagonalLine=1;

  // Horizontal check(row,col,symbol)
  for (int x=1; check(row,col+x,symbol)==1; horizontalLine++, x++);
  for (int x=1; check(row,col-x,symbol)==1; horizontalLine++, x++);
  // Vertical
  for (int y=1; check(row+y,col,symbol)==1; verticalLine++, y++);
  for (int y=1; check(row-y,col,symbol)==1; verticalLine++, y++);
  // diagonal
  for (int x=1; check(row+x,col+x,symbol)==1; diagonalLine++, x++);
  for (int x=1; check(row-x,col-x,symbol)==1; diagonalLine++, x++);
  // Antidiagonal
  for (int x=1; check(row+x,col-x,symbol)==1; antidiagonalLine++, x++);
  for (int x=1; check(row-x,col+x,symbol)==1; antidiagonalLine++, x++);

  if ((horizontalLine==length)||(verticalLine==length)||(diagonalLine==length)||(antidiagonalLine==length))
  return 1;
  else return 0;

}

int fillGrid ()
{
    for (int i=0;i<=gridsize-1;i++){
        for (int j=0;j<=gridsize-1;j++){
            grid[i][j]='.';}}
}

int checkSymbol (char symbol)
{
  if ((symbol=='X') || (symbol =='O')){
    return 1;
  }
  return 0;
}

#ifndef TEST
int  main (int argc, char* argv[])
{
	// ENTER THE CODE OF YOUR main FUNCTION BELOW
  int winlength=0;
  for (;newGame(gridsize, winlength)==0;){
    promptEnterGridSize();
    scanf("%i", &gridsize);
    if ((gridsize < 3) || (gridsize > 10)) // Max/Min size of grid the program will accept. Can alter this for it to work on any dimensions
      continue;
    promptEnterWinLength(gridsize);
    scanf("%i", &winlength);

  }

  fillGrid();

  showGrid();

  int playerWon=0, row=0,col=0;
  char playerTurn='X';
  int recordOfCoordinates[MaxGrid*MaxGrid*2];
  int sizeOfCoordinateArray=0;
  for (;(boardIsFull()==0)&&playerWon==0;)
  {

    promptChooseLocation(playerTurn);
    scanf("%i,%i", &row, &col);

    for (;makeMove(row, col, playerTurn) == 0;){
      if ((row<0)||(row>=gridsize)||(col<0)||(col>=gridsize)){
        showErrIndex();
        promptChooseLocation(playerTurn);
        scanf("%i,%i", &row, &col);
      }
      else if ((grid[row][col] == 'X')||(grid[row][col] == 'O')){
        showErrTaken();
        promptChooseLocation(playerTurn);
        scanf("%i,%i", &row, &col);
      }

    }
    recordOfCoordinates[sizeOfCoordinateArray] = row;
    sizeOfCoordinateArray ++;
    recordOfCoordinates[sizeOfCoordinateArray] = col;
    sizeOfCoordinateArray ++;
    showGrid();

    //if (effPlayerHasWon(row, col, playerTurn, winlength) == 1)
    if (playerHasWon(playerTurn, winlength)==1)
    {
        playerWon=1;
        continue;
    }


    if (playerTurn =='X'){
        playerTurn='O';
    }
    else{
        playerTurn = 'X';
    }

  }
    if (playerWon==1)
    showWinMessage(playerTurn);
    else showGameOverMessage();

    char enterFlag;
    promptPlayBackGame();
    scanf(" %c", &enterFlag);

    if (enterFlag=='y'){
      fillGrid();
      showGrid();
      char exitFlag='n';
      int index=0;
      playerTurn = 'X';
      promptNextOrExit();
      scanf(" %c", &exitFlag);
      if (exitFlag =='n'){
          while ((exitFlag=='n')&&(index<sizeOfCoordinateArray)){
            makeMove(recordOfCoordinates[index],recordOfCoordinates[index+1], playerTurn);
            showGrid();
            index += 2;
            if (index<sizeOfCoordinateArray){
            promptNextOrExit();
            scanf(" %c", &exitFlag);
            }

            if (playerTurn =='X')
                playerTurn='O';
            else playerTurn = 'X';
          }
      }

    }

  return 0;
}
#endif
