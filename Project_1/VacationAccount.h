
#ifndef VACATION_ACCOUNT_H
#define VACATION_ACCOUNT_H

#include <string>
#include "BloodDonation.h"

class VacationAccount {
public:
    explicit VacationAccount(const std::string& donorId);

    ~VacationAccount();
    VacationAccount(const VacationAccount& other);
    VacationAccount& operator=(const VacationAccount& other);

    // Attempts to add a donation; enforces account-level rules.
    // Returns one of: OK, BAD_ID, BAD_AGE, BAD_WEIGHT, BAD_DATE, SAME_DAY, TOO_SOON.
    std::string add(const BloodDonation& donation);

    // Accessors
    const std::string& id() const;
    double balanceHours() const;
    int size() const;
    const BloodDonation* at(int index) const;

private:
    std::string m_id;
    BloodDonation** m_items;
    int m_size;
    int m_capacity;
    double m_hours;

    // Helpers to implement
    void ensureCapacity(int need);
    void clear();
    void deepCopyFrom(const VacationAccount& other);
};

#endif // VACATION_ACCOUNT_H
