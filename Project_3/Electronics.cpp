#include "Electronics.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

Electronics::Electronics(const string& name, double price, int warrantyMonths)
    : Product(name, price), m_warrantyMonths(warrantyMonths){}
Electronics::~Electronics() {}

string Electronics::getCategory() const{
    return "Electronics";
}

int Electronics::getWarrantyMonths() const{
    return m_warrantyMonths;
}

bool Electronics::matchesKeyword(const string& keyword) const {
    string target = getName() + " " + to_string(getWarrantyMonths()) + " months";

    string keyLower = keyword;
    string targetLower = target;

    for (char& c : keyLower)  c = tolower(c);
    for (char& c : targetLower) c = tolower(c);

    if (keyLower.empty())
        return false;

    bool whiteSpaceOnly = true;
    for(char c: keyLower){
        if(c != ' '){
            whiteSpaceOnly = false;
            break;
        }
    }
    if(whiteSpaceOnly) return false;
    
    return targetLower.find(keyLower) != string::npos; 
}


void Electronics::printInfo() const{
    cout << "Category: " + getCategory() <<
            " | Name: " + getName() <<
            " | Price: " << std::fixed << std::setprecision(2) << getPrice() <<
            " | Warranty: " << getWarrantyMonths() << " months" << endl;
}

