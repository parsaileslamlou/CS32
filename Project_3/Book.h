#ifndef BOOK_H
#define BOOK_H
#include "Product.h"

class Book : public Product {
public:
    Book(const std::string& name, double price, const std::string& author);
    virtual ~Book();

    std::string getCategory() const override;
    bool matchesKeyword(const std::string& keyword) const override;
    void printInfo() const override;
    
    std::string getAuthor() const;
    
private:
    std::string m_author;
};
#endif
