#include "mainwindow.h"

#include "database.h"

#include "taxi.h"

#include <QVBoxLayout>

#include <QLabel>

#include <QDebug>

#include <sstream>

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent) {
    setupUiComponents();
    setupConnections();
}

MainWindow::~MainWindow() {

}

void MainWindow::setupUiComponents() {
    QWidget * centralWidget = new QWidget(this);
    QVBoxLayout * layout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    layout -> addWidget(new QLabel("First Name:", this));
    firstNameLineEdit = new QLineEdit(this);
    layout -> addWidget(firstNameLineEdit);

    layout -> addWidget(new QLabel("Last Name:", this));
    lastNameLineEdit = new QLineEdit(this);
    layout -> addWidget(lastNameLineEdit);

    hireButton = new QPushButton("Hire Employee", this);
    layout -> addWidget(hireButton);

    listEmployeesButton = new QPushButton("List Employees", this);
    layout -> addWidget(listEmployeesButton);

    layout -> addWidget(new QLabel("Employee ID:", this));
    employeeIdLineEdit = new QLineEdit(this);
    layout -> addWidget(employeeIdLineEdit);

    layout -> addWidget(new QLabel("Raise Amount:", this));
    raiseAmountLineEdit = new QLineEdit(this);
    layout -> addWidget(raiseAmountLineEdit);

    promoteButton = new QPushButton("Promote Employee", this);
    layout -> addWidget(promoteButton);

    registrationNumberLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Registration Number:", this));
    layout -> addWidget(registrationNumberLineEdit);

    chassisNumberLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Chassis Number:", this));
    layout -> addWidget(chassisNumberLineEdit);

    engineNumberLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Engine Number:", this));
    layout -> addWidget(engineNumberLineEdit);

    yearOfManufactureLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Year of Manufacture:", this));
    layout -> addWidget(yearOfManufactureLineEdit);

    mileageLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Mileage:", this));
    layout -> addWidget(mileageLineEdit);

    driverCodeLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Driver Code:", this));
    layout -> addWidget(driverCodeLineEdit);

    lastServiceDateLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Last Service Date:", this));
    layout -> addWidget(lastServiceDateLineEdit);

    mechanicCodeLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Mechanic Code:", this));
    layout -> addWidget(mechanicCodeLineEdit);

    specialMarksLineEdit = new QLineEdit(this);
    layout -> addWidget(new QLabel("Special Marks:", this));
    layout -> addWidget(specialMarksLineEdit);

    layout -> addWidget(new QLabel("Vehicle Code:", this));
    vehicleCodeLineEdit = new QLineEdit(this);
    layout -> addWidget(vehicleCodeLineEdit);

    layout -> addWidget(new QLabel("Brand Code:", this));
    brandCodeLineEdit = new QLineEdit(this);
    layout -> addWidget(brandCodeLineEdit);

    addTaxiButton = new QPushButton("Add Taxi", this);
    layout -> addWidget(addTaxiButton);

    displayArea = new QTextEdit(this);
    displayArea -> setReadOnly(true);
    layout -> addWidget(displayArea);
}

void MainWindow::setupConnections() {
    if (hireButton && firstNameLineEdit && lastNameLineEdit) {
        connect(hireButton, & QPushButton::clicked, this, & MainWindow::doHire);
    }

    if (promoteButton && employeeIdLineEdit && raiseAmountLineEdit) {
        connect(promoteButton, & QPushButton::clicked, this, & MainWindow::doPromote);
    }

    if (listEmployeesButton) {
        connect(listEmployeesButton, & QPushButton::clicked, this, & MainWindow::listEmployees);
    }

    if (addTaxiButton && registrationNumberLineEdit && chassisNumberLineEdit && engineNumberLineEdit && yearOfManufactureLineEdit && mileageLineEdit && driverCodeLineEdit && lastServiceDateLineEdit && mechanicCodeLineEdit && specialMarksLineEdit) {
        connect(addTaxiButton, & QPushButton::clicked, this, & MainWindow::addTaxi);
    }
}

void MainWindow::doHire() {
    QString firstName = firstNameLineEdit -> text();
    QString lastName = lastNameLineEdit -> text();

    if (firstName.isEmpty() || lastName.isEmpty()) {
        displayArea -> append("Both first name and last name are required.");
        return;
    }

    try {
        employeeDB.addEmployee(firstName.toStdString(), lastName.toStdString());
        displayArea -> append("Hired: " + firstName + " " + lastName);
    } catch (const std::exception & e) {
        displayArea -> append("Failed to hire employee: " + QString::fromStdString(e.what()));
    }
}

void MainWindow::listEmployees() {
    std::stringstream buffer;
    std::streambuf * prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    employeeDB.displayAll();

    std::cout.rdbuf(prevcoutbuf);
    displayArea -> setText(QString::fromStdString(buffer.str()));
}

void MainWindow::doPromote() {
    if (!employeeIdLineEdit || !raiseAmountLineEdit) {
        displayArea -> append("UI Error: Input fields for promotion are not initialized.");
        return;
    }

    QString employeeIdStr = employeeIdLineEdit -> text().trimmed();
    QString raiseAmountStr = raiseAmountLineEdit -> text().trimmed();

    bool conversionOk;
    int employeeId = employeeIdStr.toInt( & conversionOk);
    if (!conversionOk || employeeId <= 0) {
        displayArea -> append("Invalid Employee ID.");
        return;
    }

    int raiseAmount = raiseAmountStr.toInt( & conversionOk);
    if (!conversionOk || raiseAmount <= 0) {
        displayArea -> append("Invalid Raise Amount.");
        return;
    }

    try {
        Records::Employee & employee = employeeDB.getEmployee(employeeId);
        employee.promote(raiseAmount);

        QString successMessage = QString("Employee ID %1 promoted with raise: $%2")
                                     .arg(employeeId)
                                     .arg(raiseAmount);
        displayArea -> append(successMessage);
    } catch (const std::exception & e) {
        displayArea -> append("Promotion failed: " + QString::fromStdString(e.what()));
    }
}

void MainWindow::addTaxi() {

    if (!vehicleCodeLineEdit) {
        qDebug() << "vehicleCodeLineEdit is not initialized";
    }
    if (!brandCodeLineEdit) {
        qDebug() << "brandCodeLineEdit is not initialized";
    }
    if (!registrationNumberLineEdit) {
        qDebug() << "registrationNumberLineEdit is not initialized";
    }
    if (!chassisNumberLineEdit) {
        qDebug() << "chassisNumberLineEdit is not initialized";
    }
    if (!engineNumberLineEdit) {
        qDebug() << "engineNumberLineEdit is not initialized";
    }
    if (!yearOfManufactureLineEdit) {
        qDebug() << "yearOfManufactureLineEdit is not initialized";
    }
    if (!mileageLineEdit) {
        qDebug() << "mileageLineEdit is not initialized";
    }
    if (!driverCodeLineEdit) {
        qDebug() << "driverCodeLineEdit is not initialized";
    }
    if (!lastServiceDateLineEdit) {
        qDebug() << "lastServiceDateLineEdit is not initialized";
    }
    if (!mechanicCodeLineEdit) {
        qDebug() << "mechanicCodeLineEdit is not initialized";
    }
    if (!specialMarksLineEdit) {
        qDebug() << "specialMarksLineEdit is not initialized";
    }

    if (!vehicleCodeLineEdit || !brandCodeLineEdit || !registrationNumberLineEdit ||
        !chassisNumberLineEdit || !engineNumberLineEdit || !yearOfManufactureLineEdit ||
        !mileageLineEdit || !driverCodeLineEdit || !lastServiceDateLineEdit ||
        !mechanicCodeLineEdit || !specialMarksLineEdit) {
        displayArea -> append("Error: One or more input fields are not initialized.");
        return;
    }

    bool ok;
    int vehicleCode = vehicleCodeLineEdit -> text().toInt( & ok);
    if (!ok) {
        displayArea -> append("Invalid input for Vehicle Code.");
        return;
    }

    int brandCode = brandCodeLineEdit -> text().toInt( & ok);
    if (!ok) {
        displayArea -> append("Invalid input for Brand Code.");
        return;
    }

    QString registrationNumber = registrationNumberLineEdit -> text().trimmed();
    QString chassisNumber = chassisNumberLineEdit -> text().trimmed();
    QString engineNumber = engineNumberLineEdit -> text().trimmed();
    int yearOfManufacture = yearOfManufactureLineEdit -> text().toInt( & ok);
    double mileage = mileageLineEdit -> text().toDouble( & ok);
    int driverCode = driverCodeLineEdit -> text().toInt( & ok);
    QString lastServiceDate = lastServiceDateLineEdit -> text().trimmed();
    int mechanicCode = mechanicCodeLineEdit -> text().toInt( & ok);
    QString specialMarks = specialMarksLineEdit -> text().trimmed();

    if (!ok || yearOfManufacture < 0 || mileage < 0 || driverCode < 0 || mechanicCode < 0) {
        displayArea -> append("Invalid input in one or more fields.");
        return;
    }

    Taxi newTaxi(vehicleCode, brandCode, registrationNumber.toStdString(),
                 chassisNumber.toStdString(), engineNumber.toStdString(),
                 yearOfManufacture, mileage, driverCode,
                 lastServiceDate.toStdString(), mechanicCode,
                 specialMarks.toStdString());
    taxis.push_back(newTaxi);

    displayArea -> append("New taxi added successfully.");
}

void MainWindow::listTaxis() {
    std::stringstream buffer;
    for (const auto & taxi: taxis) {
        taxi.displayInfo();
        buffer << "\n";
    }

    displayArea -> setText(QString::fromStdString(buffer.str()));
}

void MainWindow::doFire() {
    displayArea -> append("Employee fired (placeholder implementation).");
}
