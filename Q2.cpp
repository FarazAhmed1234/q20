#include <iostream>
using namespace std;

class Temp {
private:
    double Temperature[7];
    static double total;
    double average,temp;

public:
    void getData();
    void calculateAvgTemp();
    void calHighestLowestTemp();
};

// Initialize the static variable
double Temp::total = 0;

void Temp::getData() {
    for (int i = 0; i < 7; i++) { // Index starts from 0 to 6
        while (true) {
            cout << "Enter the Temperature for day " << (i + 1) << ": ";
        
            cin >> temp;

            if (temp < -100 || temp > 60.0) {
    
                cout << "Invalid Input. Please enter a temperature between -100 and 60 degrees Celsius." << endl;
            } else {
                Temperature[i] = temp;
                total += temp; // Accumulate the total
                break;
            }
        }
    }
}

void Temp::calculateAvgTemp() {
    average = total / 7;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "The average temperature for the week is: " << average << "°C" << endl;
}

void Temp::calHighestLowestTemp() {
    double maxTemp = Temperature[0];
    double minTemp = Temperature[0];
    
    // Find highest and lowest temperatures
    for (int i = 1; i < 7; i++) {
        if (Temperature[i] > maxTemp) {
            maxTemp = Temperature[i];
        }
        if (Temperature[i] < minTemp) {
            minTemp = Temperature[i];
        }
    }
    
    // Output the highest temperature
    cout << "Day(s) with the highest temperature (" << maxTemp << "°C): ";
    for (int i = 0; i < 7; i++) {
        if (Temperature[i] == maxTemp) {
            cout << "Day " << (i + 1) << " ";
        }
    }
    cout << endl;
    
    // Output the lowest temperature
    cout << "Day(s) with the lowest temperature (" << minTemp << "°C): ";
    for (int i = 0; i < 7; i++) {
        if (Temperature[i] == minTemp) {
            cout << "Day " << (i + 1) << " ";
        }
    }
    cout << endl;
}

int main() {
    Temp obj;
    obj.getData();
    obj.calculateAvgTemp();
    obj.calHighestLowestTemp();
    return 0;
}

