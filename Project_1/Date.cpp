
#include "Date.h"
#include <cctype>
#include <cstdlib>



namespace DateUtil {

bool isLeap(const Date& dt) {
    if (dt.y % 4 != 0) return false;
    else if (dt.y % 100 != 0) return true;
    else if (dt.y % 400 == 0) return true;
    return false;
}


int monthLen(const Date& dt){
    switch (dt.m) {
            case 1: return 31;
            case 2: return isLeap(dt) ? 29 : 28;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: return 0;
        };
    }
     


int toSerial(const Date& dt){
    int totalDays = 0;
    //Loop to add all the days from year : [1,dt.y)
    for(int year = 1; year < dt.y; year++){
        Date* datePtr = new Date;
        datePtr->y = year;
        datePtr->m = 1;
        datePtr->d = 1;
        if (isLeap(*datePtr))
            totalDays += 366;
        else
            totalDays += 365;
        delete datePtr;
    }
    //adding all the days from current year
    for(int month = 1; month < dt.m; month++){
        Date* datePtr = new Date;
        datePtr->m = month;
        datePtr->y= dt.y;
        datePtr->d= 1;
        totalDays += monthLen(*datePtr);
        delete datePtr;
    }
    return (totalDays + dt.d);
}



bool parseISO(const std::string& s, Date& out) {
    // Enforce "YYYY-MM-DD" with digits in the correct positions
    if (s.size() != 10 || s[4] != '-' || s[7] != '-') return false;
    for (int i : {0,1,2,3,5,6,8,9}) if (!std::isdigit((unsigned char)s[i])) return false;
    out.y = std::atoi(s.substr(0,4).c_str());
    out.m = std::atoi(s.substr(5,2).c_str());
    out.d = std::atoi(s.substr(8,2).c_str());
    return true;
}

bool isValid(const Date& dt) {
    // Replace the placeholder below.
    if(dt.y < 1 || dt.m < 1 || dt.m > 12 || dt.d < 1) { return false; }
    if(dt.d > monthLen(dt)) { return false; }
    return true;
}

bool sameDay(const Date& a, const Date& b) {
    // Exact same calendar date
    return (a.y == b.y) && (a.m == b.m) && (a.d == b.d);
}

int daysBetween(const Date& a, const Date& b) {
    if(isValid(a) && isValid(b)){
        return abs(toSerial(a) - toSerial(b));
    }
    return -1;
}

} // namespace DateUtil
