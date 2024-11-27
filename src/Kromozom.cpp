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

void Kromozom::genEkle(Gen* gen) {
    if (!head) {
        head = tail = gen;
    } else {
        tail->next = gen;
        gen->prev = tail;
        tail = gen;
    }
}

void Kromozom::Mutasyon(int index) {
    Gen* current = head;
    for (int i = 0; i < index && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->setData('X');
    } else {
        std::cerr << "Mutasyon Hatasi : index tasma hatasi\n";
    }
}

Gen* Kromozom::getHead() const {
    return head;
}

Gen* Kromozom::getTail() const {
    return tail;
}
