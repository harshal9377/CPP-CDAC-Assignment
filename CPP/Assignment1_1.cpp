// Question 1 — IoT Sensor Dashboard

#include <iostream>
using namespace std;

int main()
{
    double temperature;

    cout << "Enter Temperature: ";
    cin >> temperature;

    double f = (temperature * 9 / 5) + 32;
    cout << "Temperature : " << temperature << "°C / "
         << f << "°F" << endl;

    int statuscode;

    if (temperature < 0)
    {
        statuscode = -1;
        cout << "Status: SENSOR_ERROR" << endl;
    }
    else if (temperature < 30)
    {
        statuscode = 0;
        cout << "Status: NORMAL" << endl;
    }
    else if (temperature < 45)
    {
        statuscode = 1;
        cout << "Status: WARNING" << endl;
    }
    else if (temperature < 60)
    {
        statuscode = 2;
        cout << "Status: CRITICAL" << endl;
    }
    else
    {
        statuscode = 3;
        cout << "Status: SHUTDOWN" << endl;
    }

    switch (statuscode)
    {
    case -1:
        cout << "Action: Sensor fault — check wiring" << endl;
        break;

    case 0:
        cout << "Action: No action required" << endl;
        break;

    case 1:
        cout << "Action: Alert sent to supervisor" << endl;
        break;

    case 2:
        cout << "Action: Cooling system triggered" << endl;
        break;

    case 3:
        cout << "Action: Emergency shutdown initiated" << endl;
        break;
    }

    cout << "Reading : "
         << (temperature >= 25 ? "Above Average" : "Below Average")
         << endl;

    return 0;
}