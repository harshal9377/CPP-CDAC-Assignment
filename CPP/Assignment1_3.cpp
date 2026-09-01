#include <iostream>
using namespace std;

int main() {

    double temperature[3][3];

    // Input temperatures
    for (int floor = 0; floor < 3; floor++)
    {
        for (int room = 0; room < 3; room++)
        {
            cout << "Enter temperature for Floor "
                 << floor + 1 << ", Room "
                 << room + 1 << ": ";

            cin >> temperature[floor][room];
        }
    }

    // Display table
    cout << "\n\tRoom1\tRoom2\tRoom3" << endl;

    for (int floor = 0; floor < 3; floor++)
    {
        cout << "Floor " << floor + 1 << " : ";

        for (int room = 0; room < 3; room++)
        {
            cout << temperature[floor][room] << "\t";
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temperature[0][0];
    int floor = 0;
    int room = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] > hottest)
            {
                hottest = temperature[i][j];
                floor = i;
                room = j;
            }
        }
    }

    cout << "\nHottest Room : Floor " << floor + 1
         << ", Room " << room + 1
         << " -> " << hottest << "°" << endl;


    // Calculate average temperature
    double sum = 0;
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum = sum + temperature[i][j];
            count++;
        }
    }

    double average = sum / count;

    cout << "Average Temperature : "
         << average << "°" << endl;


    // Count temperatures >= 30
    int countt = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] >= 30)
            {
                countt++;
            }
        }
    }

    cout << "Temperature >= 30°C : "
         << countt << " rooms" << endl;

    return 0;
}