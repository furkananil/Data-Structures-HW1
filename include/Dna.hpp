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

    void kromozomEkle(Kromozom* kromozom);
    void DosyadanOku(const std::string& filename);
    void Mutasyon(int kromozomIndex, int genIndex);
    void Caprazlama(int kromozomIndex1, int kromozomIndex2);
    void otomatikIslemler(const std::string& islemlerDosyasi);
    void EkranaYaz();
};
#endif 
