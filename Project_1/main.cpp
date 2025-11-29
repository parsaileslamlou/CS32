
#include "VacationAccount.h"
#include <cassert>
#include <iostream>
int main() {
    
    
    VacationAccount acc("123456");
    BloodDonation good("123456", 30, 150.0, "2025-01-01");
    assert(good.validate() == "OK");
    assert(acc.add(good) == "OK");                  // account-level acceptance
    assert(acc.size() == 1);                       // size increments
    assert(acc.balanceHours() == 4.0);             // +4 hours credit
    
    BloodDonation badIdFmt("12A456", 30, 150.0, "2025-01-02");
    assert(badIdFmt.validate() == "BAD_ID");         // invalid ID format
    
    BloodDonation mismatch("654321", 30, 150.0, "2025-07-01");
    assert(mismatch.validate() == "OK");
    assert(acc.add(mismatch) == "BAD_ID");           // account-level id mismatch
    
    BloodDonation sameDay("123456", 30, 150.0, "2025-01-01");
    assert(acc.add(sameDay) == "SAME_DAY");         // duplicate calendar date
    
    BloodDonation tooSoon("123456", 30, 150.0, "2025-06-29");
    assert(tooSoon.validate() == "OK");
    assert(acc.add(tooSoon) == "TOO_SOON");        // < 180 days since last accepted
    
    assert(DateUtil::isValid(Date(2024, 2, 29)) == true);
    assert(DateUtil::isValid(Date(2025, 2, 29)) == false);
    assert(DateUtil::isValid(Date(1900, 2, 29)) == false);
    assert(DateUtil::isValid(Date(2000, 2, 29)) == true);
    assert(DateUtil::isValid(Date(2025, 4, 31)) == false);
    assert(DateUtil::daysBetween(Date(2025, 1, 1), Date(2025, 1, 2)) == 1);
    
    // ---------------- Additional Required Assertions -------------
    
    //check for too old/young
    BloodDonation tooOld("123456", 70, 165.0, "2025-01-01");
    assert(tooOld.validate() == "BAD_AGE");

    BloodDonation tooYoung("123456", 18, 165.0, "2025-07-01");
    assert(tooYoung.validate() == "BAD_AGE");

    //Check for to light/heavy
    BloodDonation tooLight("123456", 30, 90.0, "2025-01-01");
    assert(tooLight.validate() == "BAD_WEIGHT");

    BloodDonation tooHeavy("123456", 30, 290.0, "2025-07-01");
    assert(tooHeavy.validate() == "BAD_WEIGHT");

    //Check for invalid calendar date
    BloodDonation badDate("123456", 30, 165.0, "2025-02-99");
    assert(badDate.validate() == "BAD_DATE");

    //Check if empty account works as expected
    VacationAccount acc2("999999");
    assert(acc2.size() == 0);
    assert(acc2.balanceHours() == 0.0);

    //Check if we can add a donation on empty account
    BloodDonation firstGood("999999", 31, 165.0, "2025-01-01");
    assert(acc2.add(firstGood) == "OK");

    //Check if adding a donation 181 days after works as expected
    BloodDonation nextOk("999999", 31, 165.0, "2025-07-01");
    assert(acc2.add(nextOk) == "OK");

    //Check if size/hours updating correctly
    assert(acc2.size() == 2);
    assert(acc2.balanceHours() == 8.0);

    //Checking if SAME_DAY doesn't alter array
    BloodDonation repeatSameDay("999999", 31, 165.0, "2025-07-01");
    assert(acc2.add(repeatSameDay) == "SAME_DAY");
    assert(acc2.size() == 2);
    assert(acc2.balanceHours() == 8.0);

    //Same thing with TOO_SOON
    BloodDonation tooSoon2("999999", 31, 165.0, "2025-10-01"); // only 92 days later
    assert(acc2.add(tooSoon2) == "TOO_SOON");
    assert(acc2.size() == 2);
    assert(acc2.balanceHours() == 8.0);

    //Checking BAD_ID doesn't alter aswell
    BloodDonation wrongID("000001", 31, 165.0, "2026-01-01");
    assert(acc2.add(wrongID) == "BAD_ID");
    assert(acc2.size() == 2);

    //Check if valid donations work and are appended
    BloodDonation validAgain("999999", 40, 150.0, "2026-01-01");
    assert(acc2.add(validAgain) == "OK");
    assert(acc2.balanceHours() == 12.0);
    assert(acc2.size() == 3);

    // Checking dateutil functions
    assert(DateUtil::daysBetween(Date(2025,1,1), Date(2025,1,2)) == 1);
    assert(DateUtil::daysBetween(Date(2025,1,1), Date(2026,1,1)) > 364);
    
    
    return 0;
    
}
