#include "Clothing.h"
#include "Book.h"
#include "Electronics.h"
#include <iostream>
using namespace std;


#include "Clothing.h"
#include "Book.h"
#include "Electronics.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    Product* p1 = new Clothing("Hoodie", 29.99, "M");
    Product* p2 = new Book("The AI Era", 12.50, "J. Doe");
    Product* p3 = new Electronics("Bluetooth Speaker", 59.99, 24);
    
    Product* p4 = new Clothing("Shirt", 18.05, "L");
    Product* p5 = new Book("C++ Programming", 10.50, "I. Parsa");
    Product* p6 = new Electronics("Iphone 17", 1300.00, 8);

    //checks both true and false case of matchesKeyword function for Clothing
    assert(p1->matchesKeyword("hOoDiE m") == true);
    assert(p1->matchesKeyword("hOoE L") == false);
    assert(p1->matchesKeyword("") == false);
    assert(p1->matchesKeyword(" ") == false);
    
    //checks both true and false case of matchesKeyword function for Clothing
    assert(p2->matchesKeyword("The Ai era j. DOE") == true);
    assert(p2->matchesKeyword("") == false);
    assert(p2->matchesKeyword(" ") == false);
    assert(p2->matchesKeyword("DE Monkey 12") == false);
    
    //checks both true and false case of matchesKeyword function for Electronics
    assert(p3->matchesKeyword("BluETOOTH spEAKER 24 monthS") == true);
    assert(p3->matchesKeyword("") == false);
    assert(p3->matchesKeyword(" ") == false);
    assert(p3->matchesKeyword("Bluetooth Speaker") == true);
    assert(p3->matchesKeyword("  Speaker") == false);

    assert(p4->matchesKeyword("Shirt l") == true);
    assert(p4->matchesKeyword("Shirt M") == false);
    assert(p4->matchesKeyword("") == false);
    assert(p4->matchesKeyword(" ") == false);
    
    //checks both true and false case of matchesKeyword function for Clothing
    assert(p5->matchesKeyword("C++ ProgrammIng I. PARSA") == true);
    assert(p5->matchesKeyword("") == false);
    assert(p5->matchesKeyword(" ") == false);
    assert(p5->matchesKeyword("C++ ProgrammIng I. ") == true);
    
    //checks both true and false case of matchesKeyword function for Electronics
    assert(p6->matchesKeyword("IpHoNE 17 8 mONThs") == true);
    assert(p6->matchesKeyword("") == false);
    assert(p6->matchesKeyword(" ") == false);
    assert(p6->matchesKeyword("  17") == false);
    assert(p6->matchesKeyword("Iphone 17 8") == true);
    
    //virtual methods called from base class pointer
    assert(p1->getName() == "Hoodie");
    assert(p6->getPrice() == 1300.00);
    assert(p2->getCategory() == "Book");
    
    p1->printInfo();
    p2->printInfo();
    p3->printInfo();
    
    p4->printInfo();
    p5->printInfo();
    p6->printInfo();
    
    delete p1;
    delete p2;
    delete p3;
    
    delete p4;
    delete p5;
    delete p6;
    
    return 0;
}



