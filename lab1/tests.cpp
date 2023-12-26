#include "gtest/gtest.h"
#include "database.h"
#include "taxi.h"

// Test the doHire function
TEST(DatabaseTest, TestDoHire) {
    Database db;
    doHire(db);
    // Check that the database size increased by 1
    ASSERT_EQ(1, db.size());
}

// Test the doFire function
TEST(DatabaseTest, TestDoFire) {
    Database db;
    doHire(db);
    doFire(db);
    // Check that the database size is 0 after firing the employee
    ASSERT_EQ(0, db.size());
}

// Test the doPromote function
TEST(DatabaseTest, TestDoPromote) {
    Database db;
    doHire(db);
    Employee& emp = db.getEmployee(0);
    int oldRank = emp.getRank();
    doPromote(db);
    // Check that the employee's rank increased
    ASSERT_GT(emp.getRank(), oldRank);
}

// Test the addTaxi function
TEST(TaxiTest, TestAddTaxi) {
    vector<Taxi> taxis;
    addTaxi(taxis);
    // Check that the taxi vector size increased by 1
    ASSERT_EQ(1, taxis.size());
}

// Test the displayTaxis function
TEST(TaxiTest, TestDisplayTaxis) {
    vector<Taxi> taxis;
    addTaxi(taxis);
    // We can't directly test the output of displayTaxis, but we can at least call it to ensure it doesn't crash
    displayTaxis(taxis);
    SUCCEED();
}