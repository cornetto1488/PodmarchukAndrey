#include <iostream>
#include <cmath>

using namespace std;

int getInt();

int main()
{
	double a[3] = { 0,0,0 };
	double b[3] = { 0,0,0 };
	double scalarProduct = 0;
	double lengthVectorA = 0;
	double lengthVectorB = 0;
	double alpha = 0;
	cout << "Type your a:  ";
	for (int i = 0; i < 3; i++)
		a[i] = getInt();
	cout << "Type your b:  ";
	for (int i = 0; i < 3; i++)
		b[i] = getInt();
	for (int i = 0; i < 3; i++)
		scalarProduct += a[i] * b[i];
	for (int i = 0; i < 3; i++) {
		lengthVectorA += a[i] * a[i];
		lengthVectorB += b[i] * b[i];
	}
	lengthVectorA = sqrt(lengthVectorA);
	lengthVectorB = sqrt(lengthVectorB);
	alpha = acos(scalarProduct / (lengthVectorA * lengthVectorB));
	cout << "Your alpha:  " << alpha;
}

int getInt() {
	while (true) {
		int number;
		cin >> number;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Do input again." << endl;
		}
		else {
			//cin.ignore(32767, '\n');
			return number;
		}
	}
}
