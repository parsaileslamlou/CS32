#include "Product.h"
#include <iostream>

Product::Product(std::string name, double price)
    : m_name(name), m_price(price) {}
Product::~Product() {}

std::string Product::getName() const { return m_name; }
double Product::getPrice() const { return m_price; }
