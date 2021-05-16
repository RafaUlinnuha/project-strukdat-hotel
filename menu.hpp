#include <iostream>
#include "pengunjung.hpp"

void menuPegawai(){
    system("cls");
    int pegawaiPilih;
    std::cout << "\tPEGAWAI\n";
    std::cout << "\n";
    std::cout << "Menu :\n"
                 "1. List Pengunjung\n"
                 "2. Update Kamar\n"
                 "3. Pesan Kamar\n"
                 "4. Hapus Pengunjung\n";
    std::cout << "Masukkan pilihan (1/2) : ";
    std::cin >> pegawaiPilih;
    switch(pegawaiPilih){
        case 1:
            //list pengunjung
            break;
        case 2:
            //update kamar
            break;
        case 3:
            //pesan kamar
            break;
        case 4:
            //hapus pengunjung
            break;
        default:
            std::cout << "Masukkan Anda Salah!!\n";
    }
}

void idPegawai(){
    system("cls");
    int idPeg;
    std::cout << "\tPEGAWAI\n";
    std::cout << "\n";
    std::cout << "Masukkan ID Pegawai : ";
    std::cin >> idPeg;
    if(idPeg == 888/*pegawai->id*/){
        menuPegawai();
    } else{
        std::cout << "ID yang Anda Masukkan Salah!\n";
    }
}

void home(){
    system("cls");
    int homePilih;
    std::cout << "\tHOTEL DEL LUNA\n";
    std::cout << "\n";
    std::cout << "Selamat datang di Hotel Del Luna\n";
    std::cout << "\n";
    std::cout << "Masuk Sebagai\n"
                 "1. Pengunjung\n"
                 "2. Pegawai\n";
    std::cout << "Masukkan pilihan (1/2) : ";
    std::cin >> homePilih;
    switch(homePilih){
        case 1:
            menuPengunjung();
            break;
        case 2:
            idPegawai();
            break;
        default:
            std::cout << "Masukkan Anda Salah!!\n";
    }
}