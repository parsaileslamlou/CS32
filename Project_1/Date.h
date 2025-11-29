
#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {
    int y{0}, m{0}, d{0};
};

namespace DateUtil {
    // Parse "YYYY-MM-DD" into out; returns true on success (format only).
    bool parseISO(const std::string& iso, Date& out);

    // Validate an actual calendar date (month lengths, leap years).
    bool isValid(const Date& dt);

    // True if a and b are the same calendar day.
    bool sameDay(const Date& a, const Date& b);

    // Nonnegative number of days between a and b; if a>b, swap order.
    int daysBetween(const Date& a, const Date& b);
}

#endif // DATE_H
