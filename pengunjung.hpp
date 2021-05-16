#include <iostream>
#include "pesanKamar.hpp"
#include "listKamar.hpp"

void menuPengunjung(){
    system("cls");
    int tamuPilih;
    char pilih;
    std::cout << "\tPENGUNJUNG\n";
    std::cout << "\n";
    std::cout << "Menu :\n"
                 "1. List Kamar\n"
                 "2. Pesan Kamar\n";
    std::cout << "Masukkan pilihan (1/2) : ";
    std::cin >> tamuPilih;
    switch(tamuPilih){
        case 1:
            listKamar();
            std::cout << "\n\nBack to menu (Y/N)? ";
            std::cin >> pilih;
            if (pilih == 'Y' || pilih == 'y'){
                menuPengunjung();
            } else if (pilih == 'N' || pilih == 'n'){
                exit(0);
            } else {
                std::cout << "Masukkan Anda Salah!!\n";
            }
            break;
        case 2:
            pesanKamar();
            break;
        default:
            std::cout << "Masukkan Anda Salah!!\n";
    }
}