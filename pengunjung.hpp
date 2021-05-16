#include <iostream>
#include "pesanKamar.hpp"

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
            system("cls");
            std::cout << "\t\t\tLIST KAMAR\n";
            std::cout << "\n";
            std::cout << "1. Kamar A\n";
            std::cout << "Fasilitas\t\t: Max. 2 orang, Wifi, SPA, Kolam\n";
            std::cout << "\t\t\t  Renang, Sarapan, AC\n";
            std::cout << "Harga/malam\t\t: Rp. 400.000,00\n";
            std::cout << "Jumlah kamar tersedia\t: "; // fungsi hitung kamar A
            std::cout << "\n\n2. Kamar B\n";
            std::cout << "Fasilitas\t\t: Max. 4 orang, Wifi, AC\n";
            std::cout << "Harga/malam\t\t: Rp. 400.000,00\n";
            std::cout << "Jumlah kamar tersedia\t: "; // fungsi hitung kamar B
            std::cout << "\n\nBack to menu (Y/N)? ";
            std::cin >> pilih;
            if (pilih == 'Y' || pilih == 'y'){
                menuPengunjung();
            }
            break;
        case 2:
            pesanKamar();
            break;
        default:
            std::cout << "Masukkan Anda Salah!!\n";
    }
}