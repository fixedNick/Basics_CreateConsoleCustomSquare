#include <iostream>
#include <wtypes.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	bool fillInnerSquare = false;

	short widthManualMarginLeft = 0;
	short currentConsoleEmptyHeight = 0;
	short height, width;
	cout << "Enter height: "; // 1
	cin >> height;
	cout << "Enter width: "; // 2
	cin >> width;

	cout << "Would you like to fill the inner of square?[0 - no & 1 - yes]: "; // 3
	cin >> fillInnerSquare;

	cout << "Enter left margin: "; // 4
	cin >> widthManualMarginLeft;

	cout << endl << endl; // 5,6

	currentConsoleEmptyHeight += 6;

	for (short h = currentConsoleEmptyHeight; h < currentConsoleEmptyHeight + height; h++)
	{
		for (short w = widthManualMarginLeft; w < widthManualMarginLeft + width; w++)
		{
			if (fillInnerSquare || (h == currentConsoleEmptyHeight || h == currentConsoleEmptyHeight + height - 1))
			{
				COORD pos = { w, h};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				cout << "*";
			}
			else
			{
				COORD pos = { widthManualMarginLeft, h };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				cout << "*";

				short lastPosInRow = width - 1 + widthManualMarginLeft;
				pos = { lastPosInRow, h };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				cout << "*";
				break;
			}
		}
		cout << endl;
	}
	cout << endl << endl;

}

