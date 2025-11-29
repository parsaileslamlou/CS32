#ifndef CLOTHING_H
#define CLOTHING_H
#include "Product.h"

class Clothing : public Product {
public:
    Clothing(const std::string& name, double price, const std::string& size);
    virtual ~Clothing();

    std::string getCategory() const override;
    bool matchesKeyword(const std::string& keyword) const override;
    void printInfo() const override;

    std::string getSize() const;
private:
    std::string m_size;
};
#endif
