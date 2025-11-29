
#include "VacationAccount.h"

namespace {
    const int MIN_INTERVAL_DAYS = 180;
    const double HOURS_PER_DONATION = 4.0;
}

VacationAccount::VacationAccount(const std::string& donorId)
: m_id(donorId), m_items(nullptr), m_size(0), m_capacity(0), m_hours(0.0)
{
}

VacationAccount::~VacationAccount() {
    clear();
}


VacationAccount::VacationAccount(const VacationAccount& other)
: m_id(other.m_id), m_items(nullptr), m_size(0), m_capacity(0), m_hours(0.0)
{
    m_hours = other.m_hours;
    deepCopyFrom(other);
}

VacationAccount& VacationAccount::operator=(const VacationAccount& other) {
    if (this != &other) {
        clear();
        m_id = other.m_id;
        deepCopyFrom(other);
    }
    return *this;
}


void VacationAccount::ensureCapacity(int need) {
    if (need <= m_capacity) return;
    BloodDonation** temp_items = new BloodDonation*[need];
       for (int i = 0; i < m_size; i++) temp_items[i] = m_items[i];
    for (int i = m_size; i < need; i++) { temp_items[i] = nullptr; }
       delete[] m_items;
       m_items = temp_items;
       m_capacity = need;
}

void VacationAccount::clear() {
    if(m_items != nullptr){
        for(int i = 0; i < m_capacity; i++){
            delete m_items[i];
            m_items[i] = nullptr;
        }
        delete[] m_items;
    }
    m_items = nullptr;
    m_size = 0;
    m_capacity = 0;
    m_hours = 0.0;
}

void VacationAccount::deepCopyFrom(const VacationAccount& other) {
    if(other.m_size == 0) {
        m_items = nullptr;
        m_size = 0;
        m_capacity = other.m_capacity;
        m_hours = other.m_hours;
    }
    
    m_items = new BloodDonation*[other.m_size];
    m_capacity = other.m_size;
    m_size = other.m_size;
    m_hours = other.m_hours;
    for(int i = 0; i < m_size; i++){
        m_items[i] = new BloodDonation(*other.m_items[i]);
    }
    
}

const std::string& VacationAccount::id() const { return m_id; }
double VacationAccount::balanceHours() const { return m_hours; }
int VacationAccount::size() const { return m_size; }

const BloodDonation* VacationAccount::at(int index) const {
    if (index < 0 || index >= m_size) return nullptr;
    return m_items[index];
}

std::string VacationAccount::add(const BloodDonation& donation) {
    // 1) Independent validation (donation.validate()). If not OK, return that code.
    if(donation.validate() != "OK") { return donation.validate();}
    // 2) Account ID equality: if donation.id() != m_id, return BAD_ID.
    if(donation.id() != m_id) { return Result::BAD_ID; }
    // 3) SAME_DAY: if any accepted donation has the same calendar date, return "SAME_DAY".
    for(int i = 0; i < m_size; i++){
        if(DateUtil::sameDay(m_items[i]->date(), donation.date())) {
            return Result::SAME_DAY;
        }
    }
    //     int daysBetween(const Date& a, const Date& b);
    // 4) TOO_SOON: if daysBetween(lastAccepted, donation.date()) < 180, return "TOO_SOON".

    // TOO_SOON: compare only against the last *accepted* donation
    if (m_size > 0) {
        int diff = DateUtil::daysBetween(m_items[m_size - 1]->date(), donation.date());
        if (diff < MIN_INTERVAL_DAYS) {
            return Result::TOO_SOON;
        }
    }
    
    // 5) On success: deep-copy, append to array, increment hours by +4.0, return OK.
    if(size() + 1 > m_capacity) { ensureCapacity(size() + 1); }
    m_items[size()] = new BloodDonation(donation);
    m_hours += HOURS_PER_DONATION;
    m_size += 1;
    return Result::OK;

}
