#include <iostream>
#include <math.h>

using namespace std;

int main() {
    const double g = 9.8;
    const double PI = 3.1415;
    double V;
    double a;
    double L;
    setlocale(LC_ALL, "RUS");
    do
    {
        cout << "������� �������� ������: ";
        cin >> V;
        if (cin.fail())
        {
            cout << "������ �����: �������� ������ ���� ������.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            fflush(stdin);
        }
        else

            if (V <= 0)
            {
                cout << "������ �����: �������� �� ����� ���� ������ 0.\n";
                cin.clear();
                fflush(stdin);
            }
    } while (V <= 0);

    do
    {
        cout << "������� ���� �����: ";
        cin >> a;
        if (cin.fail())
        {
            cout << "������ �����: ���� ������ ���� ������.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            fflush(stdin);
        }
        else

            if (a <= 0 || a> 90)
            {
                cout << "������ �����: ���� �� ����� ���� ������ 0 ��� ������ 90.\n";
                cin.clear();
                fflush(stdin);
            }
    } while (a <= 0 || a > 90);


    L = (pow(V, 2) * sin(2 * ((a / 180) * PI))) / g;

    cout << "��������� ����� ���� ����������:" << L;

}
