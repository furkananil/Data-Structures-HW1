#include <iostream>
#include "Dna.hpp"

int main() {
    Dna dna;
    dna.readFromFile("Dna.txt");

    int secim;
    do {
        std::cout << "------------------------------------\n";
        std::cout << "|     1- Caprazlama                |\n";
        std::cout << "|     2- Mutasyon                  |\n";
        std::cout << "|     3- Otomatik Islemler         |\n";
        std::cout << "|     4- Ekrana Yaz                |\n";
        std::cout << "|     5- Cikis                     |\n";
        std::cout << "------------------------------------\n";
        std::cout << "Secimiziniz ;\n";

        std::cin >> secim;

        switch (secim) {
        case 1:
            int chromIndex1, chromIndex2;
            std::cout << "Birinci kromozom numarasini giriniz: ";
            std::cin >> chromIndex1;
            std::cout << "Ikinci kromozom numarasini giriniz: ";
            std::cin >> chromIndex2;
            dna.crossOver(chromIndex1, chromIndex2);

            std::cout << "Caprazlama islemi tamamlandi. Yeni kromozomlar olusturuldu.\n";
            dna.print();
            break;
        case 2: {
            int chromIndex, genIndex;
            std::cout << "Kromozom numarasini giriniz: ";
            std::cin >> chromIndex;
            std::cout << "Gen numarasini giriniz: ";
            std::cin >> genIndex;
            dna.mutateGene(chromIndex, genIndex);

            std::cout << "\n";
            break;
        }
        case 3:
            break;
        case 4:
            break;
        case 5:
            std::cout << "Cikis yapiliyor.\n";
            break;
        default:
            std::cout << "Gecersiz secim!\n";
            break;
        }
    } while (secim != 5);

    return 0;
}
