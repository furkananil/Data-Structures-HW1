#include "Gen.hpp"

Gen::Gen(char data) : data(data), next(nullptr), prev(nullptr) {}

char Gen::getData() const {
    return data;
}

void Gen::setData(char data) {
    this->data = data;
}
