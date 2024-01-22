// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <vector>
#include "employee.h"   
#include "taxi.h"      
#include "database.h"   

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *hireButton;
    QPushButton *fireButton;
    QPushButton *promoteButton;
    QPushButton *listEmployeesButton;
    QPushButton *addTaxiButton;
    QPushButton *listTaxisButton;

    QLineEdit *employeeIdLineEdit;
    QLineEdit *raiseAmountLineEdit;
    QLineEdit *vehicleCodeLineEdit;
    QLineEdit *brandCodeLineEdit;
    QLineEdit *registrationNumberLineEdit;
    QLineEdit *chassisNumberLineEdit;
    QLineEdit *engineNumberLineEdit;
    QLineEdit *yearOfManufactureLineEdit;
    QLineEdit *mileageLineEdit;
    QLineEdit *driverCodeLineEdit;
    QLineEdit *lastServiceDateLineEdit;
    QLineEdit *mechanicCodeLineEdit;
    QLineEdit *specialMarksLineEdit;


    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QTextEdit *displayArea;

    Records::Database employeeDB;
    std::vector<Taxi> taxis;
    void doHire();
    void doFire();
    void doPromote();
    void listEmployees();
    void addTaxi();
    void listTaxis();
    void setupUiComponents();
    void setupConnections();
};

#endif // MAINWINDOW_H
