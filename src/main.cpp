#include <iostream>
#include "Dna.hpp"

int main() {

    Dna* dna = new Dna();

    dna->DosyadanOku("Dna.txt");

    int secim;
    do {
        std::cout << "\n------------------------------------\n";
        std::cout << "|     1- Caprazlama                |\n";
        std::cout << "|     2- Mutasyon                  |\n";
        std::cout << "|     3- Otomatik Islemler         |\n";
        std::cout << "|     4- Ekrana Yaz                |\n";
        std::cout << "|     5- Cikis                     |\n";
        std::cout << "------------------------------------\n";
        std::cout << "Secimiziniz :\n";

        std::cin >> secim;

        switch (secim) {
        case 1:
            int kromozomIndex1, kromozomIndex2;
            std::cout << "Birinci kromozom numarasini giriniz: ";
            std::cin >> kromozomIndex1;
            std::cout << "Ikinci kromozom numarasini giriniz: ";
            std::cin >> kromozomIndex2;
            dna->Caprazlama(kromozomIndex1, kromozomIndex2);

            std::cout << "\n=Caprazlama islemi tamamlandi. Yeni kromozomlar olusturuldu!=\n";
            break;
        case 2: {
            int kromozomIndex, genIndex;
            std::cout << "Kromozom numarasini giriniz: ";
            std::cin >> kromozomIndex;
            std::cout << "Gen numarasini giriniz: ";
            std::cin >> genIndex;
            dna->Mutasyon(kromozomIndex, genIndex);
            std::cout << "\n=Mutasyon islemi basariyla tamamlandi!=\n";
            break;
        }
        case 3:
            dna->otomatikIslemler("Islemler.txt");
            break;
        case 4:
            dna->EkranaYaz();
            break;
        case 5:
            std::cout << "\n=========Cikis yapiliyor.==========\n";
            delete dna; // tahsil edilen alan geri iade edildi.
            break;
        default:
            std::cout << "=Gecersiz secim!=\n";
            break;
        }
    } while (secim != 5);

    return 0;
}
