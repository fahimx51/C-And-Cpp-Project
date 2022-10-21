#include <iostream>
#include <chrono>
#include <thread>
#define cycle 60
using namespace std;

int main()
{
    while (1)
    {
        int hour, min, sec;
        cout << "\n\nenter hour, minute and second : ";
        cin >> hour >> min >> sec;
        int h = 0, m = 0, s = 0;

        for (;;)
        {
            cout << "\n\n\n######## STOP WATCH ########\n\n\n";

            printf("\t%.2d:%.2d:%.2d\n", h, m, s);

            cout << "\n\n\n############################\n\n\n";

            if (h == hour && m == min && s == sec)
            {
                cout << "----- Time is over -----\n\n\n\n";
                break;
            }

            cout << "\033[2J\033[1;1H";
            // cout << string(22, '\n');

            s++;
            this_thread::sleep_for(chrono::seconds(1));

            if (s == cycle)
            {
                m++;
                s = 0;
            }
            if (m == cycle)
            {
                h++;
                m = 0;
            }
        }
    }

    return 0;
}