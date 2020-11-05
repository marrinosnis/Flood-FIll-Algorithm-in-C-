#include <iostream>

using namespace std;

int floodfill(int arrayImage[8][8], int posI, int posJ, int oldColor, int newColor);



int main()
{
	//given a fixed array of colors from an image
	int arrayImage[8][8] = { {0,0,0,1,1,1,2,2},{0,4,4,4,1,1,1,2},{4,4,4,4,4,2,2,2},{0,0,3,3,3,3,3,3},{0,0,0,0,3,3,1,1},{0,0,3,3,3,1,1,1},{0,1,1,1,1,1,1,2},{1,2,2,2,2,2,2,2} }, // the array is given, and it appears when the program runs
	newColor, posI, posJ, oldColor, afterFunction;


	int i, j;

	//print the array, so we can have better visual understanding
	for (i = 0; i < 8; i++)
	{
		cout << "|    ";
		for (j = 0; j < 8; j++)
		{
			cout << arrayImage[i][j] << "    |    ";
		}
		cout << endl;
		cout << "----------------------------------------------------------------------------------";
		cout << endl;
	}

	cout << "Please give the position of i " << endl;
	cin >> posI;
	cout << "Please give the position of j " << endl;
	cin >> posJ;
	oldColor = arrayImage[posI][posJ]; // here is the number of the color I want to change

	cout << "Please give the new color number ";
	cin >> newColor;

	afterFunction = floodfill(arrayImage, posI, posJ, oldColor, newColor);

	if (afterFunction == 99)  // the 99 is hazardous, and it means the given numbers are out of bound
		cout << "Not valid numbers" << endl;
	else
	{
		cout << "The final array is " << endl;

		
		for (i = 0; i < 8; i++)
		{
			cout << "|    ";
			for (j = 0; j < 8; j++)
			{
				cout << arrayImage[i][j] << "    |    ";
			}
			cout << endl;
			cout << "----------------------------------------------------------------------------------";
			cout << endl;
		}

	}


	return 0;
}

int floodfill(int arrayImage[8][8], int posI, int posJ, int oldColor, int newColor)
{

	if (posI >= 0 && posI < 8 && posJ >= 0 && posJ < 8)
	{
		arrayImage[posI][posJ] = newColor;

		if (arrayImage[posI + 1][posJ] == oldColor) // one row down
		{
			floodfill(arrayImage, posI + 1, posJ, oldColor, newColor);
		}

		if (arrayImage[posI - 1][posJ] == oldColor)  // one row up
		{
			floodfill(arrayImage, posI - 1, posJ, oldColor, newColor);
		}

		if (arrayImage[posI][posJ + 1] == oldColor)  // one column right
		{
			floodfill(arrayImage, posI, posJ + 1, oldColor, newColor);
		}
		if (arrayImage[posI][posJ - 1] == oldColor)   //one column left 
		{
			floodfill(arrayImage, posI, posJ - 1, oldColor, newColor);
		}

	}
	else
		return 99;  // 99 => means UN-SUCCESSFULL!!. If returns 99, that means  the user had put numbers bigger than array dimensions, so it returns 99 (fail)

}