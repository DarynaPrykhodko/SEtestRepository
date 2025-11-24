#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <limits>
using namespace std;


void checkN(int n) {
	if (n < 2) {
		throw "Error: n must be bigger than 1!";
	}
}

void checkRangeParams(double a, double b, double step) {
	if (b <= a) {
		throw "Error: b must be bigger than a!";
	}
	if (step <= 0) {
		throw "Error: step must be bigger than 0!";
	}
}

double checkValidInt(const char* ex) {
	cout << ex;
	int temp;
	cin >> temp;
	if (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw "Error: input correct data.";
	}
	else {
		return temp;
	}
}

double checkValidDouble(const char* ex) {
	cout << ex;
	double temp;
	cin >> temp;
	if (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw "Error: input correct data.";
	}
	else {
		return temp;
	}
}

double calcFunc1(int n, double x) {
	double y = 0;
	if (x < -3) {
		for (int i = 1; i <= n; i++) {
			y += (pow(i + x, 2)) / (2.0 * i);
		}
	}

	else {
		double mlt = 1.0;
		for (int j = 1; j <= n - 1; j++) {
			double sum = 0.0;
			for (int i = 2; i <= n + 1; i++) {
				double temp = pow(i + (double)i / j - j, 2);
				sum = sum + temp;
			}
			mlt = mlt * sum;
		}
		y = mlt;
	}
	return y;
}

void calcFunc2(int n, double a, double b, double step) {
	//Outputting results
	int k = 1;
	for (double x = a; x <= b; x += step) {
		double y = calcFunc1(n, x);
		cout << fixed << setprecision(5);
		cout << "x" << k << "=" << x << setw(15) << "y" << k << "=" << y << endl;
		k++;
	}

}


#ifndef UNIT_TESTING

int main()
{
	int n, m = 0;
	double a, b, step, x;
	double y = 0;


	cout << '\n';		//Introduction
	cout << "=============================================" << endl;
	cout << "       Function calculation application      " << endl;
	cout << "============================================" << endl;
	cout << "Welcome to the program!" << endl;
	cout << '\n';
	cout << "Here you can calculate the function." << endl;
	cout << "Press any key to continue: ";
	_getch();

	for (;;) {
		system("cls");		//Menu

		cout << "\n===========================================" << endl;
		cout << "                    MENU                    " << endl;
		cout << "===========================================" << endl;
		cout << "1. Calculate function for singular X." << endl;
		cout << "2. Calculate function for a range of X." << endl;
		cout << "3. Exit program." << endl;

		try {
			m = checkValidInt("Enter your choice: ");
			if (m < 1 || m > 3) {
				throw "Error: input correct data.";
			}
		}
		catch (const char* ex) {
			cout << ex << endl;
			_getch();
			continue;
		}
		switch (m) {

		case 1:											//CASE 1 ------------
			system("cls");
			cout << "================================" << endl;
			cout << "   Calculating for singular X   " << endl;//Getting n and x from user's input
			cout << "================================\n" << endl;

			while (true) {
				try {
					n = checkValidInt("Input n > 1, n = ");
					checkN(n);
					break;
				}
				catch (const char* ex) {
					cout << ex << endl;
				}
			}
			while (true) {
				try {
					x = checkValidDouble("Input x = ");
					break;
				}
				catch (const char* ex) {
					cout << ex << endl;
				}
			}

			//Function that calculates formula of domain and returns results
			y = calcFunc1(n, x);
			cout << "Results: x = " << x << endl;			//Outputting results
			cout << setw(13) << "y = " << y << endl;
			cout << '\n';
			cout << "Press any key to return to the menu: ";
			_getch();
			break;

		case 2: {									//CASE 2 -------------
			system("cls");
			y = 0.0;
			cout << "================================" << endl;
			cout << "  Calculating for a range of X  " << endl;
			cout << "================================\n" << endl;

			while (true) {
				try {
					n = checkValidInt("Input n > 1, n = ");
					checkN(n);
					break;
				}
				catch (const char* ex) {
					cout << ex << endl;
				}
			}
			while (true) {
				try {
					a = checkValidDouble("Input start of range a = ");
					break;
				}
				catch (const char* ex) {
					cout << ex << endl;
				}
			}
			while (true) {
				try {
					b = checkValidDouble("Input end of range b = ");
					if (b <= a) {
						throw "Error: b must be bigger than a!";
					}
					break;
				}
				catch (const char* ex) {
					cout << ex << endl;
				}
			}
			while (true) {
				try {
					step = checkValidDouble("Input step for x (step>0) = ");
					checkRangeParams(a, b, step);
					break;
				}
				catch (const char* ex) {
					cout << ex << endl;
				}
			}
			cout << "\n------------------------------------------------" << endl;
			cout << "      CALCULATION RESULTS (n = " << n << "):      " << endl;
			cout << "================================================" << endl;
			cout << "X value" << setw(25) << "Y value" << endl;
			cout << "------------------------------------------------" << endl;
			calcFunc2(n, a, b, step);
			cout << '\n';
			cout << "Press any key to return to the menu: ";
			_getch();
			break;
		}
		case 3:		//Case 3
			cout << "\nExiting program...\n\n";
			cout << "Goodbye!\n";
			return 0;
		}
	}
}
#endif