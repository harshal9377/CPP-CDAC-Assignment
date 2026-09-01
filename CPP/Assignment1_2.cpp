// Problem 2 — Sensor Log Buffer

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N;

    cout << "Enter number of readings: ";
    cin >> N;

    double readings[100];

    int errorCount = 0;
    int normalCount = 0;
    int warningCount = 0;
    int criticalCount = 0;
    int shutdownCount = 0;

    for (int i = 0; i < N; i++)
    {
        cout << "Enter reading " << i << ": ";
        cin >> readings[i];
    }

    double sum = 0;
    double min = 0;
    double max = 0;
    int validCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            errorCount++;
            continue;
        }

        cout << readings[i] << "  ";

        if (validCount == 0)
        {
            min = readings[i];
            max = readings[i];
        }
        else
        {
            if (readings[i] < min)
                min = readings[i];

            if (readings[i] > max)
                max = readings[i];
        }

        sum += readings[i];
        validCount++;

        if (readings[i] < 30)
        {
            normalCount++;
        }
        else if (readings[i] < 45)
        {
            warningCount++;
        }
        else if (readings[i] < 60)
        {
            criticalCount++;
        }
        else
        {
            shutdownCount++;
        }
    }

    cout << endl;

    bool foundCritical = false;

    for (int i = 0; i < N; i++)
    {
        if (readings[i] >= 45)
        {
            cout << "First CRITICAL : Index " << i
                 << " -> " << readings[i] << "°C" << endl;

            foundCritical = true;
            break;
        }
    }

    if (!foundCritical)
    {
        cout << "First CRITICAL : None" << endl;
    }

    double average = 0;

    if (validCount > 0)
    {
        average = sum / validCount;
    }

    cout << fixed << setprecision(2);

    cout << "Readings entered : " << N << endl;
    cout << "Valid readings   : ";

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
            continue;

        cout << readings[i] << "  ";
    }

    cout << endl;

    cout << "Skipped (errors) : " << errorCount << endl;

    if (validCount > 0)
    {
        cout << "Min : " << min << "°C"
             << "    Max : " << max << "°C"
             << "    Avg : " << average << "°C" << endl;
    }

    cout << "Normal: " << normalCount
         << "   Warning: " << warningCount
         << "   Critical: " << criticalCount
         << "   Shutdown: " << shutdownCount << endl;

    return 0;
}