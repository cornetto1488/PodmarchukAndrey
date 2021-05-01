#include <iostream>
#include <math.h>

using namespace std;

class Complex;

double getDouble();
int getInt();
void printEquation(Complex number1, Complex number2, Complex result, char operation);
void printEquation(Complex number1, int number2, Complex result, char operation);

const double pi = 3.1415;

class ExpForm {
public:
	void setComplex(int number);
	void print();
	double getX();
	double getY();
	ExpForm operator+ (ExpForm number);
	ExpForm operator- (ExpForm number);
	ExpForm operator+ (int number);
	ExpForm operator- (int number);
private:
	double x, y;
};

class TrigForm {
public:
	void print();
	void translate(ExpForm expForm);
	double getR();
	double getPhi();
private:
	double r;
	double phi;
};

void ExpForm::setComplex(int number) {
	cout << "Enter complex number #" << number <<": x + i * y" << endl;
	cout << "Enter x: ";
	x = getDouble();
	cout << "Enter y: ";
	y = getDouble();
}

void ExpForm::print()
{
	cout << x << " + i * " << y;
}

double ExpForm::getX() {
	return x;
}

double ExpForm::getY() {
	return y;
}

ExpForm ExpForm::operator+(ExpForm number)
{
	ExpForm result;
	result.x = x + number.x;
	result.y = y + number.y;
	return result;
}

ExpForm ExpForm::operator-(ExpForm number)
{
	ExpForm result;
	result.x = x - number.x;
	result.y = y - number.y;
	return result;
}

ExpForm ExpForm::operator+(int number)
{
	ExpForm result;
	result.x = x + number;
	result.y = y;
	return result;
}

ExpForm ExpForm::operator-(int number)
{
	ExpForm result;
	result.x = x - number;
	result.y = y;
	return result;
}

void TrigForm::print() {
	cout << r << " * cos(" << phi << ") + " << r << " * i * sin(" << phi << ")";
}

void TrigForm::translate(ExpForm expForm) {
	r = sqrt(pow(expForm.getX(), 2) + pow(expForm.getY(), 2));
	double cos = acos(expForm.getX() / r);
	double sin = asin(expForm.getY() / r);

	double rawPhi = abs(sin);
	if (sin > 0 && cos > 0)
		phi = rawPhi;
	else if (sin < 0 && cos>0)
		phi = -rawPhi;
	else if (sin < 0 && cos < 0)
		phi = -pi + rawPhi;
	else if (sin > 0 && cos < 0)
		phi = pi - rawPhi;
	else
		phi = rawPhi;
}

double TrigForm::getR() {
	return r;
}

double TrigForm::getPhi() {
	return phi;
}

class Complex {
public:
	void inputComplex(int number);
	void printComplexNumber();
	Complex operator+ (Complex number);
	Complex operator- (Complex number);
	Complex operator+ (int number);
	Complex operator- (int number);
private:
	ExpForm expForm;
	TrigForm trigForm;
};

void Complex::inputComplex(int number) {
	expForm.setComplex(number);
}

void Complex::printComplexNumber() {
	trigForm.translate(expForm);
	//expForm.print();
	trigForm.print();
}

Complex Complex::operator+(Complex number)
{
	Complex result;
	result.expForm = expForm + number.expForm;
	return result;
}

Complex Complex::operator-(Complex number)
{
	Complex result;
	result.expForm = expForm - number.expForm;
	return result;
}

Complex Complex::operator+(int number)
{
	Complex result;
	result.expForm = expForm + number;
	return result;
}

Complex Complex::operator-(int number)
{
	Complex result;
	result.expForm = expForm - number;
	return result;
}

int main() {
	int number;
	Complex number1, number2, buffer;
	number1.inputComplex(1);
	number2.inputComplex(2);
	cout << "Enter integer: ";
	number = getInt();
	buffer = number1 + number2;
	printEquation(number1, number2, buffer, '+');
	buffer = number1 - number2;
	printEquation(number1, number2, buffer, '-');
	buffer = number2 - number1;
	printEquation(number2, number1, buffer, '-');
	buffer = number1 + number;
	printEquation(number1, number, buffer, '+');
	buffer = number2 + number;
	printEquation(number2, number, buffer, '+');
	buffer = number1 - number;
	printEquation(number1, number, buffer, '-');
	buffer = number2 - number;
	printEquation(number2, number, buffer, '-');
	return 0;
}

double getDouble() {
	while (true) {
		double number;
		cin >> number;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Do input again." << endl;
		}
		else {
			cin.ignore(32767, '\n');
			return number;
		}
	}
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
			cin.ignore(32767, '\n');
			return number;
		}
	}
}

void printEquation(Complex number1, Complex number2, Complex result, char operation) {
	number1.printComplexNumber();
	cout << " " << operation << " ";
	number2.printComplexNumber();
	cout << " = ";
	result.printComplexNumber();
	cout << endl;
}

void printEquation(Complex number1, int number2, Complex result, char operation) {
	number1.printComplexNumber();
	cout << " " << operation << " " << number2 << " = ";
	result.printComplexNumber();
	cout << endl;
}
