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

void Dna::crossOver(int chromIndex1, int chromIndex2) {
    Kromozom* first = head;
    Kromozom* second = head;

    // İlk ve ikinci kromozomları bul
    for (int i = 0; i < chromIndex1 && first; ++i) {
        first = first->next;
    }
    for (int i = 0; i < chromIndex2 && second; ++i) {
        second = second->next;
    }

    if (!first || !second) {
        std::cerr << "Error: Chromosome index out of range.\n";
        return;
    }

    // İlk ve ikinci kromozomların uzunluklarını bul
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

    // Orta noktaları belirle (tek veya çift uzunluk durumunu kontrol et)
    int firstMid = firstLength / 2;
    int secondMid = secondLength / 2;

    // Yeni kromozomları oluştur
    Kromozom* newChrom1 = new Kromozom();
    Kromozom* newChrom2 = new Kromozom();

    // İlk kromozomun sol kısmını ekle
    temp = first->getHead();
    for (int i = 0; i < firstMid; ++i) {
        newChrom1->addGene(new Gen(temp->getData()));
        temp = temp->next;
    }

    // İkinci kromozomun sağ kısmını ekle
    temp = second->getHead();
    for (int i = 0; i < secondMid; ++i) {
        temp = temp->next;
    }
    if (secondLength % 2 == 1) {  // Eğer ikinci kromozomun gen sayısı tekse
        temp = temp->next;  // Ortadaki gen atlanacak
    }
    while (temp) {
        newChrom1->addGene(new Gen(temp->getData()));
        temp = temp->next;
    }

    // İlk kromozomun sağ kısmını ekle
    temp = first->getHead();
    for (int i = 0; i < firstMid; ++i) {
        temp = temp->next;
    }

    // Tek sayılı kromozom için ortadaki gen atlanacak
    if (firstLength % 2 == 1) {  // Eğer ilk kromozomun gen sayısı tekse
        temp = temp->next;  // Ortadaki gen atlanacak
    }
    while (temp) {
        newChrom2->addGene(new Gen(temp->getData()));
        temp = temp->next;
    }

    // İkinci kromozomun sol kısmını ekle
    temp = second->getHead();
    for (int i = 0; i < secondMid; ++i) {
        newChrom2->addGene(new Gen(temp->getData()));
        temp = temp->next;
    }

    // Yeni kromozomları bağlı listeye ekle
    addChromosome(newChrom1);
    addChromosome(newChrom2);
}

void Dna::otomatikIslemler(const std::string& islemlerDosyasi) {
    std::ifstream file(islemlerDosyasi);
    if (!file) {
        std::cerr << "Error: Islemler.txt dosyasi açılamadi.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        char islem;
        int chromIndex1, chromIndex2;

        ss >> islem >> chromIndex1 >> chromIndex2;

        if (islem == 'C') {
            // Çaprazlama işlemi
            crossOver(chromIndex1, chromIndex2);
        } else if (islem == 'M') {
            // Mutasyon işlemi
            mutateGene(chromIndex1, chromIndex2);  // Daha önce tanımladığımız fonksiyonu kullanıyoruz
        } else {
            std::cerr << "Bilinmeyen islem: " << islem << std::endl;
        }
    }

    std::cout << "Islemler tamamlandi!\n";
}



















