#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    // Check arguments
    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor <warn_threshold> "
             << "<critical_threshold> <num_readings>" << endl;

        cout << "Error : Missing arguments." << endl;

        return 1;
    }

    int warnThreshold = atoi(argv[1]);
    int criticalThreshold = atoi(argv[2]);
    int numReadings = atoi(argv[3]);

    // Validate thresholds
    if (warnThreshold >= criticalThreshold)
    {
        cout << "Error : Warning threshold must be less than "
             << "critical threshold." << endl;

        return 1;
    }

    // Validate number of readings
    if (numReadings < 1 || numReadings > 500)
    {
        cout << "Error : Number of readings must be between "
             << "1 and 500." << endl;

        return 1;
    }

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    cout << "Config : Warn=" << warnThreshold
         << "°C Critical=" << criticalThreshold
         << "°C Readings=" << numReadings << endl;

    for (int i = 0; i < numReadings; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warnThreshold)
        {
            normal++;
        }
        else if (temperature < criticalThreshold)
        {
            warning++;
        }
        else if (temperature < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << "Results : Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}