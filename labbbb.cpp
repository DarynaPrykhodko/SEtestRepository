#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <limits>
using namespace std;

int main()
{
	int n, m = 0;
	double a, b, step, x;
	double y = 0;


	cout << '\n';		//Introduction
	cout << "============================================" << endl;
	cout << setw(38) << "Function calculation application" << endl;
	cout << "============================================" << endl;
	cout << "Welcome to the program!" << endl;
	cout << '\n';
	cout << "Here you can calculate the function." << endl;
	cout << "Press any key to continue: ";
	_getch();

	for (;;) {
		system("cls");		//Menu


		cout << '\n' << "===========================================" << endl;
		cout << setw(23) << "MENU" << endl;
		cout << "===========================================" << endl;
		cout << "1. Calculate function for singular X." << endl;
		cout << "2. Calculate function for a range of X." << endl;
		cout << "3. Exit program." << endl;
		cout << "Enter your choice:   ";
		cin >> m;

		if (cin.fail() || cin.peek() != '\n') {
			cout << "Error, input number from 1 to 3!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			_getch();
			continue;
		}

		switch (m) {
		case 1:											//CASE 1 ------------
			system("cls");
			y = 0.0;
			cout << "================================" << endl;
			cout << setw(28) << "Calculating for singular X" << endl;
			cout << "================================" << endl;
			cout << "\n";

			cout << "Input n > 1, n = ";			//Getting n and x from user's input
			do {
				cin >> n;
				if (cin.fail() || cin.peek() != '\n' || n < 2) {
					cout << "Error, input correct n: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (cin.fail() || cin.peek() != '\n' || n < 2);


			cout << "Input x = ";
			while (!(cin >> x)) {
				cout << "Error, input correct x : " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (x < -3) {				//Function that calculates formula of domain and returns results
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
			cout << setw(28) << "Calculating for a range of X" << endl;
			cout << "================================" << endl;
			cout << "\n";
			cout << "Input n>1, n=";

			do {
				cin >> n;
				if (cin.fail() || cin.peek() != '\n' || n < 2) {
					cout << "Error: Input correct n: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (cin.fail() || cin.peek() != '\n' || n < 2);


			cout << "Input start of range a: ";
			do {
				if (cin >> a) {
					break;
				}
				else {
					cout << "Error: Input correct a:  ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (true);


			do {
				cout << "Input end of range b: ";
				if (!(cin >> b) || b < a) {
					cout << "Error: Input correct b (b > a)." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (b < a || cin.fail());


			do {
				cout << "Input step for x (x>0): ";
				cin >> step;
				if (cin.fail()) {
					cout << "Error: Input correct step." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (step <= 0) {
					cout << "Error: Step must be bigger than 0." << endl;
				}
			
			} while (step <= 0);

			cout << '\n';			//Outputting results
			cout << "------------------------------------------------" << endl;
			cout << "CALCULATION RESULTS (n = " << n << "):" << endl;
			cout << "================================================" << endl;
			cout << "X value" << setw(25) << "Y value" << endl;
			cout << "------------------------------------------------" << endl;

			int k = 1;		//Function that calculates formula of domain and returns results

			for (double x = a; x <= b; x = x + step) {

				double y = 0;

				if (x < -3) {
					for (int i = 1; i <= n; i++) {
						y = y + (pow(i + x, 2)) / (2.0 * i);
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
				cout << fixed << setprecision(5);
				cout << "x" << k << "=" << x << setw(15) << "y" << k << "=" << y << endl;
				k++;
			}
			cout << '\n';
			cout << "Press any key to return to the menu: ";
			_getch();
			break;
		}
		case 3:		//Case 3
			cout << '\n' << "Exiting program..." << '\n' << endl;
			cout << "Goodbye!" << endl;
			return 0;
		}
	}
}
