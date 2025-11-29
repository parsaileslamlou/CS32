#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;


Book::Book(const string& name, double price,const string& author)
    : Product(name, price), m_author(author){}
Book::~Book() {}

string Book::getCategory() const{
    return "Book";
}

string Book::getAuthor() const{
    return m_author;
}

bool Book::matchesKeyword(const std::string& keyword) const{
    string target = getName() + " " + getAuthor();

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

void Book::printInfo() const{
    cout << "Category: " + getCategory() <<
            " | Name: " + getName() <<
            " | Price: " << std::fixed << std::setprecision(2) << getPrice() <<
            " | Author: " << getAuthor() << endl;
}
