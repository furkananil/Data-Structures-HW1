#include "Dna.hpp"
#include <iostream>
#include <fstream>
#include <sstream> 

Dna::Dna() : head(nullptr), tail(nullptr) {}

Dna::~Dna() {
    Kromozom* current = head;
    while (current) {
        Kromozom* temp = current;
        current = current->next;
        delete temp;
    }
}

void Dna::addChromosome(Kromozom* kromozom) {
    if (!head) {
        head = tail = kromozom;
    } else {
        tail->next = kromozom;
        kromozom->prev = tail;
        tail = kromozom;
    }
}

void Dna::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        Kromozom* kromozom = new Kromozom();
        std::istringstream iss(line);
        char gene;
        while (iss >> gene) {
            kromozom->addGene(new Gen(gene));
        }
        addChromosome(kromozom);
    }
    file.close();
}

void Dna::mutateGene(int chromosomeIndex, int geneIndex) {
    Kromozom* current = head;
    for (int i = 0; i < chromosomeIndex && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->mutateGene(geneIndex);
    } else {
        std::cerr << "Error: Chromosome index out of range.\n";
    }
}

void Dna::print() const {
    Kromozom* current = head;
    int chromosomeIndex = 0;
    while (current) {
        std::cout << "Chromosome " << chromosomeIndex << ": ";
        current->print();
        current = current->next;
        chromosomeIndex++;
    }
}

