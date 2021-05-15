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