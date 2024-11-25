#include "Kromozom.hpp"
#include <iostream>

Kromozom::Kromozom() : head(nullptr), tail(nullptr), next(nullptr), prev(nullptr) {}

Kromozom::~Kromozom() {
    Gen* current = head;
    while (current) {
        Gen* temp = current;
        current = current->next;
        delete temp;
    }
}

void Kromozom::addGene(Gen* gen) {
    if (!head) {
        head = tail = gen;
    } else {
        tail->next = gen;
        gen->prev = tail;
        tail = gen;
    }
}

void Kromozom::mutateGene(int index) {
    Gen* current = head;
    for (int i = 0; i < index && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->setData('X');
    } else {
        std::cerr << "Error: Gene index out of range.\n";
    }
}

void Kromozom::print() const {
    Gen* current = head;
    while (current) {
        std::cout << current->getData() << " ";
        current = current->next;
    }
    std::cout <<"\n";
}
