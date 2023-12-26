#include "taxi.h"

Taxi::Taxi(int vehicleCode, int brandCode, std::string registrationNumber,
           std::string chassisNumber, std::string engineNumber, int yearOfManufacture,
           double mileage, int driverCode, std::string lastServiceDate,
           int mechanicCode, std::string specialMarks) :
           vehicleCode(vehicleCode), brandCode(brandCode), registrationNumber(registrationNumber),
           chassisNumber(chassisNumber), engineNumber(engineNumber), yearOfManufacture(yearOfManufacture),
           mileage(mileage), driverCode(driverCode), lastServiceDate(lastServiceDate),
           mechanicCode(mechanicCode), specialMarks(specialMarks) {}

void Taxi::displayInfo() const {
    std::cout << "Vehicle Code: " << vehicleCode << "\n"
              << "Brand Code: " << brandCode << "\n"
              << "Registration Number: " << registrationNumber << "\n"
              << "Chassis Number: " << chassisNumber << "\n"
              << "Engine Number: " << engineNumber << "\n"
              << "Year of Manufacture: " << yearOfManufacture << "\n"
              << "Mileage: " << mileage << "\n"
              << "Driver Code: " << driverCode << "\n"
              << "Last Service Date: " << lastServiceDate << "\n"
              << "Mechanic Code: " << mechanicCode << "\n"
              << "Special Marks: " << specialMarks << std::endl;
}
