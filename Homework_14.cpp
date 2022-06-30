
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int choise = 0;
    int num_0 = 0;
    int num_1 = 0;
    cout << "choose task:\n1 - perfect numbers\n2 - fibanachi numbers\n3 - Christmas-tree\n0 - exit\n";
    cin >> choise;
    if (choise == 1)
    {
        for (int i = 0; i < 10000000; i++)
        {
            num_0 = 0;
            for (int mull = 1; mull < i; mull++)
            {
                if (i % mull == 0)
                {
                    num_0 += mull;
                }
            }
            if (i == num_0)
            {
                cout << i << "\n";
            }
        }
    }
    else if (choise == 2)
    {
        for (int i = 1; i < 10000000; num_1 = num_0, num_0 = i, i = num_0 + num_1)
        {
            cout << num_0 << "\n";
        }
    }
    else if (choise == 3)
    {
        HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Enter amount of tiers on Christmas tree\n";
        cin >> num_0;
        cout << "Enter height of each tier:\n";
        cin >> num_1;
        SetConsoleTextAttribute(hand, 10);
        for (int tier = 0; tier < num_0 * num_1 + num_1; tier++)
        {
            for (int stage = 0; stage < num_1 * num_1; stage++)
            {
                if (stage >= num_1 * (num_1 / 2) - tier / num_1 - tier % num_1 && stage <= num_1 * (num_1 / 2) + tier / num_1 + tier % num_1 && tier < num_0 * num_1)
                {
                    cout << "<>";
                }
                else if (tier >= num_0 * num_1 && stage >= num_1 * (num_1 / 2) - num_1 / 3 && stage <= num_1 * (num_1 / 2) + num_1 / 3)
                {
                    SetConsoleTextAttribute(hand, 4);
                    cout << "||";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << "\n";
        }
        SetConsoleTextAttribute(hand, 7);
    }
    else if (choise == 0)
    {
        exit(1);
    }
    cout << "\n\nInput any symbol and press 'Enter'\n";
    cin >> choise;
    main();
}