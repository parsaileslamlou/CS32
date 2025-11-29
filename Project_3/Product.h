#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
public:
    Product(std::string name, double price);
    virtual ~Product();

    std::string getName() const;
    double getPrice() const;

    virtual std::string getCategory() const = 0;
    virtual bool matchesKeyword(const std::string& keyword) const = 0;
    virtual void printInfo() const = 0;

protected:
    std::string m_name;
    double m_price;
};
#endif
