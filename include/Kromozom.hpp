#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "Gen.hpp"

class Kromozom {
private:
    Gen* head;
    Gen* tail;

public:
    Kromozom* next; 
    Kromozom* prev;
    Kromozom();
    ~Kromozom();

    void genEkle(Gen* gen);
    void Mutasyon(int index);
    Gen* getHead() const;
    Gen* getTail() const;
};
#endif 
