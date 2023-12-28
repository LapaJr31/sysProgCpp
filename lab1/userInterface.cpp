#include <iostream>
#include <string>
#include <vector>
#include "database.h"
#include "taxi.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void addTaxi(vector<Taxi*>& taxis);
void displayTaxis(const vector<Taxi*>& taxis);

int main(int argc, char** argv) {
    Database* employeeDB = new Database(); 
    vector<Taxi*> taxis;

    bool done = false;
    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                doHire(*employeeDB);
                break;
            case 2:
                doFire(*employeeDB);
                break;
            case 3:
                doPromote(*employeeDB);
                break;
            case 4:
                employeeDB->displayAll();
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

    delete employeeDB; 
    for (auto taxi : taxis) {
        delete taxi; 
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
    cout << "---> ";
    cin >> selection;
    return selection;
}

void doHire(Database& inDB) {
    string firstName, lastName;
    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
   
    cout << "Employee " << firstName << " " << lastName << " hired." << endl;
}

void doFire(Database& inDB) {
    int employeeNumber;
    cout << "Employee number? ";
    cin >> employeeNumber;
    
    cout << "Employee " << employeeNumber << " fired." << endl;
}

void doPromote(Database& inDB) {
    int employeeNumber, raiseAmount;
    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "Raise amount? ";
    cin >> raiseAmount;
    
    cout << "Employee " << employeeNumber << " promoted with raise of " << raiseAmount << "." << endl;
}

void addTaxi(vector<Taxi*>& taxis) {
    int vehicleCode, brandCode, yearOfManufacture, driverCode, mechanicCode;
    double mileage;
    string registrationNumber, chassisNumber, engineNumber, lastServiceDate, specialMarks;

    cout << "Enter vehicle code: ";
    cin >> vehicleCode;
    cout << "Enter brand code: ";
    cin >> brandCode;
    cout << "Enter registration number: ";
    cin >> registrationNumber;
    cout << "Enter chassis number: ";
    cin >> chassisNumber;
    cout << "Enter engine number: ";
    cin >> engineNumber;
    cout << "Enter year of manufacture: ";
    cin >> yearOfManufacture;
    cout << "Enter mileage: ";
    cin >> mileage;
    cout << "Enter driver code: ";
    cin >> driverCode;
    cout << "Enter last service date: ";
    cin >> lastServiceDate;
    cout << "Enter mechanic code: ";
    cin >> mechanicCode;
    cout << "Enter special marks: ";
    cin >> specialMarks;

    Taxi* newTaxi = new Taxi(vehicleCode, brandCode, registrationNumber, chassisNumber, 
                             engineNumber, yearOfManufacture, mileage, driverCode, 
                             lastServiceDate, mechanicCode, specialMarks);
    taxis.push_back(newTaxi);
    cout << "New taxi added." << endl;
}

void displayTaxis(const vector<Taxi*>& taxis) {
    cout << "\nListing all taxis:" << endl;
    for (const auto& taxi : taxis) {
        taxi->displayInfo(); 
    }
}


