#include <iostream>
#include <time.h>
#include <vector>
#include <windows.h>
#include <string>
using namespace std;

// 2 зелёный SetConsoleTextAttribute(hand, 2);
// 6 жёлтый SetConsoleTextAttribute(hand, 6);
// 8 серый SetConsoleTextAttribute(hand, 8);

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

void Check(string& UserInput, int& n)
{
    if (UserInput.size() > n)
    {
        UserInput.erase(n);
    }
    else if (UserInput.size() < n)
    {
        for (int i = UserInput.size(); i < n; i++)
        {
            UserInput += "0";
        }
    }

    return;
}

bool Equality(vector<int>& number, string& UserInput, int& n)
{
    bool equality = true;

    for (int i = 0; i < n; i++)
    {
        if ((UserInput[i] - '0') == number[i])
        {
            SetConsoleTextAttribute(hand, 2);
        }
        else
        {
            bool yellow = false;

            for (int j = 0; j < n; j++)
            {
                if ((UserInput[i] - '0') == number[j])
                {
                    yellow = true;
                }
            }

            if (yellow)
            {
                SetConsoleTextAttribute(hand, 6);
            }
            else
            {
                SetConsoleTextAttribute(hand, 8);
            }
        }

        cout << UserInput[i];
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (number[i] != (UserInput[i] - '0'))
        {
            equality = false;
        }
    }

    return equality;
}

int main()
{
    srand(time(NULL));

    COORD cord;

    vector<int> number;
    int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n, count = 1;
    string UserInput;

    SetConsoleTextAttribute(hand, 15);

    cout << "number length: ";
    cin >> n;

    if (n > 10)
    {
        system("cls");
        n = 10;
        cout << "number length: " << n << endl;
    }
    else if (n < 1)
    {
        system("cls");
        n = 1;
        cout << "number length: " << n << endl;
    }

    while (number.size() != n)
    {
        int temp = rand() % 10;

        if (numbers[temp] != -1)
        {
            number.push_back(numbers[temp]);
            numbers[temp] = -1;
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        cout << number[i];
    }

    cout << endl;*/

    while (true)
    {
        SetConsoleTextAttribute(hand, 15);

        cin >> UserInput;

        for (int i = 0; i < UserInput.size(); i++)
        {
            cord.X = i;
            cord.Y = count;

            SetConsoleCursorPosition(hand, cord);
            cout << " ";
        }

        cord.X = 0;
        cord.Y = count;
        SetConsoleCursorPosition(hand, cord);

        count++;

        Check(UserInput, n);

        if (Equality(number, UserInput, n))
        {
            break;
        }
    }

    SetConsoleTextAttribute(hand, 2);
    cout << endl;
    cout << "victory!";
}