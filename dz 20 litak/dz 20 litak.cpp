// dz 20 litak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Airplane {
private:
    string flightNumber;
    string departure;
    string destination;
    string aircraftModel;
    int totalSeats;
    int availableSeats;
    vector<string> passengerList;

public:
    
    Airplane(string number, string dep, string dest, string model, int seats)
        : flightNumber(number), departure(dep), destination(dest), aircraftModel(model), totalSeats(seats), availableSeats(seats) {}

    
    void printInfo() {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure: " << departure << endl;
        cout << "Destination: " << destination << endl;
        cout << "Aircraft Model: " << aircraftModel << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << availableSeats << endl;
        cout << "Passenger List: ";
        for (const string& passenger : passengerList) {
            cout << passenger << ", ";
        }
        cout << endl;
    }

    
    string getFlightNumber() {
        return flightNumber;
    }

    string getDeparture() {
        return departure;
    }

    string getDestination() {
        return destination;
    }

    string getAircraftModel() {
        return aircraftModel;
    }

    int getTotalSeats() {
        return totalSeats;
    }

    int getAvailableSeats() {
        return availableSeats;
    }

    
    void sellTicket(string passengerName) {
        if (availableSeats > 0) {
            passengerList.push_back(passengerName);
            availableSeats--;
            cout << "Ticket sold to " << passengerName << endl;
        }
        else {
            cout << "No available seats!" << endl;
        }
    }

    
    void returnTicket(string passengerName) {
        auto it = find(passengerList.begin(), passengerList.end(), passengerName);
        if (it != passengerList.end()) {
            passengerList.erase(it);
            availableSeats++;
            cout << "Ticket returned by " << passengerName << endl;
        }
        else {
            cout << "Passenger " << passengerName << " not found!" << endl;
        }
    }
};

int main() {
    
    Airplane airplane1("ABC123", "New York", "Los Angeles", "Boeing 737", 150);

    
    cout << "Airplane Information:" << endl;
    airplane1.printInfo();

    
    airplane1.sellTicket("Mykola Garbuz");
    airplane1.sellTicket("Olena Rozsoha");

    
    airplane1.returnTicket("Mykola Garbuz");

    
    cout << "Updated Airplane Information:" << endl;
    airplane1.printInfo();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
