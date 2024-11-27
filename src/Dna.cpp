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
    std::cout << "\n===!Kromozomlar ve Genler silindi!===\n\n";
}

void Dna::kromozomEkle(Kromozom* kromozom) {
    if (!head) {
        head = tail = kromozom;
    } else {
        tail->next = kromozom;
        kromozom->prev = tail;
        tail = kromozom;
    }
}

void Dna::DosyadanOku(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Dosya Hatasi : Dosya acilmadi; " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        Kromozom* kromozom = new Kromozom();
        std::istringstream iss(line);
        char gene;
        while (iss >> gene) {
            kromozom->genEkle(new Gen(gene));
        }
        kromozomEkle(kromozom);
    }
    file.close();
}

void Dna::Mutasyon(int kromozomIndex, int genIndex) {
    Kromozom* current = head;
    for (int i = 0; i < kromozomIndex && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->Mutasyon(genIndex);
    } else {
        std::cerr << "Mutasyon Hatasi : Kromozom index tasma hatasi.\n";
    }
}

void Dna::Caprazlama(int kromozomIndex1, int kromozomIndex2) {
    Kromozom* first = head;
    Kromozom* second = head;

    for (int i = 0; i < kromozomIndex1 && first; ++i) {
        first = first->next;
    }
    for (int i = 0; i < kromozomIndex2 && second; ++i) {
        second = second->next;
    }

    if (!first || !second) {
        std::cerr << "Caprazlama Hatasi : Kromozom index tasma hatasi.\n";
        return;
    }

    int firstLength = 0, secondLength = 0;
    Gen* temp = first->getHead();
    while (temp) {
        firstLength++;
        temp = temp->next;
    }

    temp = second->getHead();
    while (temp) {
        secondLength++;
        temp = temp->next;
    }

    int firstMid = firstLength / 2;
    int secondMid = secondLength / 2;

    Kromozom* newChrom1 = new Kromozom();
    Kromozom* newChrom2 = new Kromozom();

    temp = first->getHead();
    for (int i = 0; i < firstMid; ++i) {
        newChrom1->genEkle(new Gen(temp->getData()));
        temp = temp->next;
    }

    temp = second->getHead();
    for (int i = 0; i < secondMid; ++i) {
        temp = temp->next;
    }
    if (secondLength % 2 == 1) {  
        temp = temp->next; 
    }
    while (temp) {
        newChrom1->genEkle(new Gen(temp->getData()));
        temp = temp->next;
    }

    temp = first->getHead();
    for (int i = 0; i < firstMid; ++i) {
        temp = temp->next;
    }

    if (firstLength % 2 == 1) {  
        temp = temp->next;  
    }
    while (temp) {
        newChrom2->genEkle(new Gen(temp->getData()));
        temp = temp->next;
    }

    temp = second->getHead();
    for (int i = 0; i < secondMid; ++i) {
        newChrom2->genEkle(new Gen(temp->getData()));
        temp = temp->next;
    }

    kromozomEkle(newChrom1);
    kromozomEkle(newChrom2);
}

void Dna::otomatikIslemler(const std::string& islemlerDosyasi) {
    std::ifstream file(islemlerDosyasi);
    if (!file) {
        std::cerr << "Dosya Hatasi : Islemler.txt dosyasi acilamadi.\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        char islem;
        int chromIndex1, chromIndex2;

        ss >> islem >> chromIndex1 >> chromIndex2;

        if (islem == 'C') {
            Caprazlama(chromIndex1, chromIndex2);
        } else if (islem == 'M') {
            Mutasyon(chromIndex1, chromIndex2); 
        } else {
            std::cerr << "Bilinmeyen islem: " << islem << std::endl;
        }
    }
    std::cout << "\n=Otomatik Islemler basariyla tamamlandi!=\n";
}

void Dna::EkranaYaz() {
    Kromozom* temp = head;
    while (temp) {
       
        Gen* firstGene = temp->getHead();
        if (!firstGene) {
            temp = temp->next;
            continue;
        }
        char firstChar = firstGene->getData();

        if (firstChar == 'A') {
            std::cout << firstChar << " ";
            temp = temp->next;
            continue;
        }

        Gen* current = temp->getTail();
        bool found = false;

        while (current) {
         
            if (current->getData() < firstChar) {
                std::cout << current->getData() << " ";
                found = true;
                break;
            }
            current = current->prev;
        }
        if (!found) {
            std::cout << firstChar << " ";
        }

        temp = temp->next;
    }
    std::cout << std::endl;
}




















