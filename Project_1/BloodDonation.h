
#ifndef BLOOD_DONATION_H
#define BLOOD_DONATION_H

#include <string>
#include "Date.h"

namespace Result {
    static const std::string OK = "OK";
    static const std::string BAD_ID = "BAD_ID";
    static const std::string BAD_AGE = "BAD_AGE";
    static const std::string BAD_WEIGHT = "BAD_WEIGHT";
    static const std::string BAD_DATE = "BAD_DATE";
    static const std::string TOO_SOON = "TOO_SOON";
    static const std::string SAME_DAY = "SAME_DAY";
}

class BloodDonation {
public:
    BloodDonation(const std::string& idStr,
                  int ageYears,
                  double weightLb,
                  const std::string& dateISO);

    // Accessors
    const std::string& id() const;
    int age() const;
    double weight() const;
    const Date& date() const;

    // Validate independent of account history; see spec for exact rules.
    // Return one of Result::OK, BAD_ID, BAD_AGE, BAD_WEIGHT, BAD_DATE.
    std::string validate() const;

    void print() const {}

private:
    std::string m_id; // must be exactly 6 digits
    int m_age;
    double m_weight;
    Date m_date;
};

#endif // BLOOD_DONATION_H
