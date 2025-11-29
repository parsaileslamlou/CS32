#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include "Product.h"

class Electronics : public Product {
public:
    Electronics(const std::string& name, double price, int warrantyMonths);
    virtual ~Electronics();

    std::string getCategory() const override;
    bool matchesKeyword(const std::string& keyword) const override;
    void printInfo() const override;

    int getWarrantyMonths() const;
private:
    int m_warrantyMonths;
};
#endif
