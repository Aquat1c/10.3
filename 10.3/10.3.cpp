#include<iostream>
#include<locale>
#include<string>
#include<iomanip>
#include<fstream>
#include <sstream>
#define TESTING

using namespace std;

#pragma pack(push, 1)

struct Bday
{
    int day;
    int month;
    int year;
};

struct Zodiac
{
    string surname;
    string name;
    string zodiac_sign;
};

#pragma pack(pop)

void Create(const string file_name, const int option);
void Print(const string file_name);
void Find(const string file_name);

#ifdef TESTING
int main()
{
    string file_name = "t.txt";

    int MenuItem;

    while (true)
    {
        cout << endl
            << endl
            << endl;
        cout << "Choose an action:" << endl;
        cout << "1 - Enter user information" << endl;
        cout << "2 - Display user information" << endl;
        cout << "3 - Search for a person by month of birthday" << endl;
        cout << "0 - Shut down the program" << endl;
        cout << "Enter:";
        cin >> MenuItem;
        cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(file_name, 1);
            break;
        case 2:
            Print(file_name);
            break;
        case 3:
            Find(file_name);
            break;
        }
        if (MenuItem == 0)
            break;
    }

    return 0;
}
#endif

void Create(const string file_name, int option)
{
    Zodiac S;
    Bday B;

    ofstream f;

    if (option == 1)
        f.open(file_name, ios::out);
    else
        f.open(file_name, ios::app);

    if (!f.is_open())
    {
        cout << "File not open!" << endl;
        return;
    }
    cin.get();

    string keep;

    do
    {
        cout << endl << endl;
        cout << "Surname: "; getline(cin, S.surname);
        f << S.surname << endl;

        cout << "Name: "; getline(cin, S.name);
        f << S.name << endl;

        cout << "Zodiak: "; getline(cin, S.zodiac_sign);
        f << S.zodiac_sign << endl;

        cout << "Enter birthday: "; cin >> B.day;
        f << B.day << endl;

        cout << "Enter the month of birth: "; cin >> B.month;
        f << B.month << endl;

        cout << "Enter the year of birth: "; cin >> B.year;
        f << B.year << endl;

        cin.get();
        cout << "To continue, enter (Y): "; getline(cin, keep); cout << endl;
    } while (keep == "Y");
}

void Print(const string file_name)
{
    ifstream f(file_name, ios::in);

    char line[50];
    string str;

    cout << "==================================================================================================================" << endl;
    cout << "| # |     Surname    |      Name     |  Zodiak  |  Day of birth  | Month of birth | Year of birth |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;

    string lines;
    int n = 0;
    while (getline(f, lines))
    {
        n++;
    }
    f.close();
    f.open(file_name, ios::in);

    int number = 1;

    for (int i = 0; i < n / 6; i++)
    {
        cout << "|" << setw(2) << number++ << setw(2);

        f.getline(line, sizeof(line));
        cout << "|" << setw(10) << line << setw(9);

        f.getline(line, sizeof(line));
        cout << "|" << setw(10) << line << setw(9);

        f.getline(line, sizeof(line));
        cout << "|" << setw(10) << line << setw(9);

        f.getline(line, sizeof(line));
        cout << "|" << setw(10) << line << setw(9);

        f.getline(line, sizeof(line));
        cout << "|" << setw(10) << line << setw(9);

        f.getline(line, sizeof(line));
        cout << "|" << setw(10) << line << setw(9) << "|" << endl;
    }
    cout << "==================================================================================================================" << endl;
}

void Find(const string file_name)
{
    string f_month;
    cout << "Enter the user's date of birthday: "; cin >> f_month;

    char line[50];
    int index = 0;
    ifstream f(file_name, ios::in);

    if (!f.is_open())
    {
        cout << "File not open!" << endl;
        return;
    }

    string lines;
    int n = 0;

    while (getline(f, lines))
    {
        n++;
    }

    f.close();
    f.open(file_name, ios::in);



    for (int i = 0; i < n; i++)
    {
        f.getline(line, sizeof(line));
        if (line == f_month)
        {
            cout << "==================================================================================================================" << endl;
            cout << "| # |     Surname    |      Name     |  Zodiak  |  Day of birth  | Month of birth | Year of birth |" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "|" << setw(2) << 1 << setw(2);
            cout << "|" << setw(10) << line << setw(9);

            f.getline(line, sizeof(line));
            cout << "|" << setw(10) << line << setw(9);

            f.getline(line, sizeof(line));
            cout << "|" << setw(10) << line << setw(9);

            f.getline(line, sizeof(line));
            cout << "|" << setw(10) << line << setw(9);

            f.getline(line, sizeof(line));
            cout << "|" << setw(10) << line << setw(9);

            f.getline(line, sizeof(line));
            cout << "|" << setw(10) << line << setw(9) << "|" << endl;
            cout << "==================================================================================================================" << endl;
            index = i;
        }
    }
    if (!index)
        cout << "User not found" << endl;
}

