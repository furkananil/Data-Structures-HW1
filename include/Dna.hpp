#ifndef DNA_HPP
#define DNA_HPP

#include <string>
#include "Kromozom.hpp"

class Dna {
private:
    Kromozom* head; 
    Kromozom* tail; 

public:
    Dna();
    ~Dna();

    void addChromosome(Kromozom* kromozom);
    void readFromFile(const std::string& filename);
    void mutateGene(int chromosomeIndex, int geneIndex);
    void print() const;
    void crossOver(int chromIndex1, int chromIndex2);
    void otomatikIslemler(const std::string& islemlerDosyasi);
    void writeToScreen();
};

#endif 
