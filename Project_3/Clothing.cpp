#include "Clothing.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

Clothing::Clothing(const string& name, double price,const string& size)
    : Product(name, price), m_size(size){}
Clothing::~Clothing() {}

string Clothing::getCategory() const{
    return "Clothing";
}

string Clothing::getSize() const{
    return m_size;
}


bool Clothing::matchesKeyword(const std::string& keyword) const{
    string target = getName() + " " + getSize();

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

void Clothing::printInfo() const{
    cout << "Category: " + getCategory() <<
            " | Name: " + getName() <<
            " | Price: " << std::fixed << std::setprecision(2) << getPrice() <<
            " | Size: " << getSize() << endl;
}
