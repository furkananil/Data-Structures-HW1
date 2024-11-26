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

    void addGene(Gen* gen);
    void mutateGene(int index);
    void print() const;
    Gen* getHead() const;
};

#endif 
