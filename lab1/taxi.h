#ifndef TAXI_H
#define TAXI_H

#include <string>
#include <iostream>

class Taxi {
public:
    Taxi(int vehicleCode, int brandCode, std::string registrationNumber,
         std::string chassisNumber, std::string engineNumber, int yearOfManufacture,
         double mileage, int driverCode, std::string lastServiceDate,
         int mechanicCode, std::string specialMarks);

    void displayInfo() const;

    // You can add more functions here to manipulate or access Taxi data

private:
    int vehicleCode;
    int brandCode;
    std::string registrationNumber;
    std::string chassisNumber;
    std::string engineNumber;
    int yearOfManufacture;
    double mileage;
    int driverCode;
    std::string lastServiceDate;
    int mechanicCode;
    std::string specialMarks;
};

#endif 
