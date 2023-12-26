#include <iostream>
#include <string>
#include "database.h"
#include "taxi.h"
#include <vector>

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void addTaxi(vector<Taxi>& taxis);
void displayTaxis(const vector<Taxi>& taxis);

int main(int argc, char** argv) {
    Database employeeDB;
    vector<Taxi> taxis;
    bool done = false;

    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                doHire(employeeDB);
                break;
            case 2:
                doFire(employeeDB);
                break;
            case 3:
                doPromote(employeeDB);
                break;
            case 4:
                employeeDB.displayAll();
                break;
            case 5:
                addTaxi(taxis);
                break;
            case 6:
                displayTaxis(taxis);
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
    return 0;
}

int displayMenu() {
    int selection;
    cout << endl;
    cout << "Employee and Taxi Database" << endl;
    cout << "--------------------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) Add a new taxi" << endl;
    cout << "6) List all taxis" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}

void doHire(Database& inDB) {
    string firstName;
    string lastName;
    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
    try {
        inDB.addEmployee(firstName, lastName);
    } catch (const std::exception& ex) {
        cerr << "Unable to add new employee!" << endl;
    }
}

void doFire(Database& inDB) {
    int employeeNumber;
    cout << "Employee number? ";
    cin >> employeeNumber;
    try {
        Employee& emp = inDB.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " has been terminated." << endl;
    } catch (const std::exception& ex) {
        cerr << "Unable to terminate employee!" << endl;
    }
}

void doPromote(Database& inDB) {
    int employeeNumber;
    int raiseAmount;
    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? ";
    cin >> raiseAmount;
    try {
        Employee& emp = inDB.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    } catch (...) {
        cerr << "Unable to promote employee!" << endl;
    }
}

void addTaxi(vector<Taxi>& taxis) {
    // Add code to input taxi details and create a Taxi object
    // For example:
    int vehicleCode, brandCode, yearOfManufacture, driverCode, mechanicCode;
    string registrationNumber, chassisNumber, engineNumber, lastServiceDate, specialMarks;
    double mileage;

    cout << "Enter vehicle code: ";
    cin >> vehicleCode;
    cout << "Enter brand code: ";
    cin >> brandCode;
    // ... Continue for other fields ...

    Taxi newTaxi(vehicleCode, brandCode, registrationNumber, chassisNumber, engineNumber, 
                 yearOfManufacture, mileage, driverCode, lastServiceDate, 
                 mechanicCode, specialMarks);
    taxis.push_back(newTaxi);
    cout << "Taxi added successfully!" << endl;
}

void displayTaxis(const vector<Taxi>& taxis) {
    cout << "\nListing all taxis:" << endl;
    for (const auto& taxi : taxis) {
        taxi.displayInfo();
    }
}
