#include "windows.h" 
#include <iostream>
#include <math.h>
#include <limits>
#include<iomanip>
#include<cmath>
#include<string>
#include <sstream>
using namespace std;


double a = 0.0;
double b = 0.0;
int x = 0;
int z = 0;
int operationNumber = 0;
bool loop = true;

string result = "";

void  printMenu()
{
    cout << "Witaj w moim kalkulatorze!" << endl;
    cout << "wpisz typ operacji:" << endl;
    cout << "dodwanie - 1" << endl;
    cout << "odejmowanie - 2" << endl;
    cout << "mnozenie - 3" << endl;
    cout << "dzielenie - 4" << endl;
    cout << "potegowanie - 5" << endl;
    cout << "silnia - 6" << endl;
    cout << "zmiana na system binarny - 7" << endl;
    cout << "zmiana na system oktalny - 8" << endl;
    cout << "zmiana na system heksadycemalny - 9" << endl;
    cout << "wyjscie z programu  - 10" << endl;
}

void badData()
{
    cout << "podano nieprawidlowa wartosc!" << endl << "sprobuj ponownie:" << endl;
    cin.clear();
    cin.ignore(999, '\n');
}

void waitOnMenu()
{
    for (int i = 7; i != 0; i--)
    {
        cout << "program przejdzie do menu za: " << i << endl;
        Sleep(1000);
    }
}

void showResultDouble(string textOne,string textLast)
{
    cout << textOne << endl;
    while (1)
    {
        if (cin >> a && cin >> b)
        {
            cout << textLast;
            switch (operationNumber)
            {
                case 1:
                    cout << a + b << endl;
                    break;
                case 2:
                    cout << a - b << endl;
                    break;
                case 3:
                    cout << a * b << endl;
                case 4:
                    cout << a / b << endl;
                    break;
            }
            waitOnMenu();
            break;
        }
        else
        {
            badData();
            continue;
        }
    }
}

void showResultInt(string textOne, string textLast)
{
    cout << textOne << endl;
    while (1)
    {
        if (cin >> x && cin >> z)
        {
            cout << textLast;
            switch (operationNumber)
            {
                case 5:
                    cout << pow(x, z) << endl;
                    break;
            }
            waitOnMenu();
            break;
        }
        else
        {
            badData();
            continue;
        }
    }
}

void calculateSystem(int num, int system)
{
    result = ""; // reseting data after last usage 
    if (system == 2 || system == 8)
    {
        while (num > 0)
        {
            switch (system)
            {
            case 2:
                result += to_string(num % system);
                break;
            case 8:
                result.insert(0, to_string(num % system));
                break;
            }
            num = num / system;
        }
    }
    else
    {
        while (num != 0)
        {
            int s = num % 16;
            if (s < 10)
                result +=char(s + 48); // asci table 
            else
                result +=char(s + 55); // asci table 
            num = num / 16;
        }
        reverse(result.begin(), result.end());
    }
    cout << result << endl;
}

int silnia(int s) {
    if (s == 0)
        return 1;
    int w = silnia(s - 1) * s;
    return w;
}

void calculateResult(string textOne, string textLast)
{
    cout << textOne << endl;
    while (1)
    {
        if (cin >> x)
        {
            cout << textLast;
            switch (operationNumber)
            {
                case 6:
                    cout << silnia(x) << endl;
                    break;
                case 7:
                    calculateSystem(x, 2);
                    break;
                case 8:
                    calculateSystem(x, 8);
                    break;
                case 9:
                    calculateSystem(x, 16);
                    break;
            }
            waitOnMenu();
            break;
        }
        else
        {
            badData();
            continue;
        }
    }
}


int main()
{

    while (loop)
    {
        system("CLS");
        printMenu();
        if (cin >> operationNumber)
        {
            switch (operationNumber)
            {
                case 1:
                    showResultDouble("wybrano dodawanie podaj 2 liczby rzeczywiste:", "wynik dodawania = ");
                    break;

                case 2:
                    showResultDouble("wybrano odejmowanie  podaj 2 liczby rzeczywiste:", "wynik odejmowania  = ");
                    break;
                
                case 3:
                    showResultDouble("wybrano mnozenie  podaj 2 liczby rzeczywiste:", "wynik mnozenia  = ");
                    break;

                case 4:
                    showResultDouble("wybrano dzielenie  podaj 2 liczby rzeczywiste:", "wynik dzielenia  = ");
                    break;

                case 5:
                    showResultInt("wybrano potegowanie pod pierw podstawe potem wykladnik","wynik potegowania = ");
                    break;

                case 6:
                    calculateResult("podaj liczbe z ktorej ma byc policzona silnia","wynik = ");
                    break;

                case 7:
                    calculateResult("podaj liczbe do zmiany na system dwojkowy ", "wynik = ");
                    break;
                case 8:
                    calculateResult("podaj liczbe do zmiany na system osemkowy ", "wynik = ");
                    break;
                case 9:
                    calculateResult("podaj liczbe do zmiany na system szesnastkowy ", "wynik = ");
                    break;
                case 10:
                    loop = false;
                    cout << "dowidzenia!" << endl;
                    break;

                default:
                    cout << "podano nieobslugiwana liczbe!" << endl;
                    waitOnMenu();
                    break;
            }
        }
        else
        {
            badData();
            waitOnMenu();
        }
        cin.clear();
        cin.ignore(999, '\n');
    }
}
