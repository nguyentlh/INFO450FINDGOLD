#include <iostream>
#include <time.h>
using namespace std;
const int ROW = 10; 
const int COL = 10; 
const int GOLD = 5;


char assignGold(char gameBoard[ROW][COL]); 
char assignBomb(char gameBoard[ROW][COL]);
 
int main()
{
	srand(time(NULL));
	char answer = ' ';
	int numGold = 0; 
// game intro and hidden game board. 
	do
	{
		char hiddenBoard[ROW][COL] = { {' ','|','1','2','3','4','5','6','7','8'}
		, {'_','_','_','_','_','_','_','_','_','_',}, {'1','|', '?','?','?','?',
		'?', '?','?','?'}, {'2','|','?','?','?','?','?','?','?','?'}, {'3','|',
		'?', '?', '?','?','?','?','?','?'},{'4','|','?','?','?','?','?','?','?',
		'?'},{'5', '|', '?','?','?','?','?','?','?','?'}, {'6','|','?','?','?',
		'?','?','?', '?','?'}, {'7','|','?','?','?','?','?','?','?','?'}, {'8',
		'|','?','?', '?','?','?','?','?','?'} };

		int i, n, a, b;

		for (i = 0; i < 10; i++)
		{
			for (n = 0; n < 10; n++)
			{
				cout << hiddenBoard[i][n] << "  ";
			}
			cout << endl;
		}
	//rules of the game 
		cout << "Find the gold!" << endl;
		cout << "Choose your x and y coordinate, numbers 1-8" << endl;
		cout << "You have 5 tries to find the gold." <<" ";
		cout << "If you find a piece of gold, you get 1 extra try." << endl;
		cout << "If you hit the bomb, game over. " << endl;

	//initialize the gameboard with gold and bomb.  
			char gameBoard[ROW][COL] = { {' ', '|', '1', '2', '3', '4', '5', '6', 
			'7', '8'}, {'_','_','_','_','_','_','_','_','_','_'},{ '1', '|',' ', 
			' ',' ',' ',' ',' ',' ',' '}, { '2','|',' ',' ',' ',' ',' ',' ',' ',' '
			}, { '3','|',' ',' ',' ',' ',' ',' ',' ',' ' }, { '4', '|', ' ',' ',
			' ',' ',' ',' ',' ',' ' },{ '5','|',' ',' ',' ',' ',' ',' ',' ',' ' },{
			'6','|',' ',' ',' ',' ',' ',' ',' ',' ' },{ '7','|', ' ', ' ', ' ',' ',
			' ',' ',' ',' ' }, { '8', '|', ' ',' ',' ',' ',' ',' ',' ',' ' } };
	//board assigns 5 gold pieces and places 1 bomb in the game board 
			for (i = 0; i < GOLD; i++)
			{
				assignGold(gameBoard);
			}
			assignBomb(gameBoard);
	//get user input/guesses 
		//all guesses need to add + 1 to account for bordering spaces
			
			int guess1;
			int guess2;
			int numGuess = 5;
			
			do {
				cout << "enter x-coordinate: " << endl;
				cin >> guess2; //x refers to column
				cout << "enter y-coordinate: " << endl;
				cin >> guess1; // y refers to row 
				if (gameBoard[guess1 + 1][guess2 + 1] == 'G')
				{
					cout << "You found gold!" << endl;
					numGuess++;
					numGold++; 
					cout << "You have " << numGuess << " guess(es) left. " << endl;
					gameBoard[guess1 + 1][guess2 + 1] = 'F';
				}
				else if (gameBoard[guess1 + 2][guess2 + 2] == 'B')
				{
					cout << "game over!" << endl;
					break;
				}
				else if (gameBoard[guess1 + 1][guess2 + 1] == ' ')
				{
					numGuess--;
					gameBoard[guess1 + 1][guess2 + 1] = 'X';
					cout << "nothing here. " << endl;
					cout << "you have " << numGuess << " guess(es) left." << endl;
				}
				else if ((gameBoard[guess1 + 1][guess2 + 1] == 'X') || (gameBoard
				[guess1 + 1][guess2 + 1] == 'F'))
				{
					cout << "you already looked here." << endl;
					cout << "you still have " << numGuess << " guess(es) left." << endl;
				}
			} while ((numGuess != 0) || (answer == 0) || (numGold == 5));
			
	//print out actual game board results  
			cout << "Results:" << endl;
			for (a = 0; a < ROW; a++)
			{
				for (b = 0; b < COL; b++)
				{
					cout << gameBoard[a][b] << "  ";
				}
				cout << endl;
			}
		cout << "you found " << numGold << " gold pieces." << endl;
	//scenario for winner
		if (numGold == 5)
			cout << "congrats, you won!" << endl; 

			cout << "play again? y/n" << endl;
			cin >> answer;

	} while ((answer == 'Y') || (answer == 'y')); //repeat game when 'y' pressed

	system ("pause"); 
	return 0; 
}
//function to randomly place gold  
char assignGold(char gameBoard[ROW][COL])
{
	int RANDROW = (rand() % 8) + 1; //generate random number for row
	int RANDCOL = (rand() % 8) + 1; //generate random number for col 
	gameBoard[RANDROW + 1][RANDCOL + 1] = 'G';
	return ' '; 
}
//function to randomly place bomb
char assignBomb(char gameBoard[ROW][COL])
{
	int RANDROW = (rand() % 8) + 1; //generate random number for row
	int RANDCOL = (rand() % 8) + 1; //generate random number for col
	gameBoard[RANDROW + 1][RANDCOL + 1] = 'B'; //add 1 to account for border 
	return ' ';
}

 

