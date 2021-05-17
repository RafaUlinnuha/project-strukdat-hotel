//ada apa aja disini:
void batas();
void menuAwal();
void pesanKamar();
void pesanLagi();
void menuPengunjung();
void backtoMenuPengunjung();
void listKamar();
void menuPegawai();
void idPegawai();
void backtoMenuPegawai();
void update();
void cetakBuktiPesanan(pointer pNew);

/*------------------------------------------UMUM--------------------------------------------*/
void batas(){
    std::cout << "---------------------------------------------------------------------\n";
}

void menuAwal(){
    system("cls");
    int homePilih;
    batas();
    std::cout << "\t\t\tHOTEL DEL LUNA\n";
    batas();
    std::cout << "Selamat datang di Hotel Del Luna\n";
    std::cout << "\n";
    std::cout << "Masuk Sebagai\n"
                 "1. Pengunjung\n"
                 "2. Pegawai\n"
                 "3. Keluar\n";
    batas();
    std::cout << "Masukkan pilihan (1/2/3)\t: ";
    std::cin >> homePilih;
    switch(homePilih){
        case 1:
            menuPengunjung();
            break;
        case 2:
            idPegawai();
            break;
        case 3:
            std::cout << "\n\t\tGOODBYE :)\n";
            exit(0);
        default:
            std::cout << "Input yang anda masukkan salah!!\n";
            menuAwal();
    }
}

void cetakBuktiPesanan(pointer pNew){
    system("cls");
    batas();
    std::cout << "\t\tSelamat, pesanan berhasil dibuat!\n";
    batas();
    std::cout << "Nama\t\t\t: " << pNew->nama << "\n";
    std::cout << "Kamar\t\t\t: " << pNew->kamar << "\n";
    std::cout << "Tanggal Check-in\t: " <<pNew->tanggalCI <<" - 05 - 2021\n";
    std::cout << "Tanggal Check-out\t: " <<pNew->tanggalCO <<" - 05 - 2021\n"; 
    std::cout << "No Kamar\t\t: " << pNew->noKamar <<"\n";
}

void pesanKamar(){
    system("cls");
    pointer pNew;
    listKamar();
    batas();
    std::cout << "\t\t\tPESAN KAMAR\n";
    batas();
    createPesanan(pNew);
    masukkanListPengunjung(pNew);
    cetakBuktiPesanan(pNew);
    pesanLagi();
}

void pesanLagi(){
    char jawab;
    batas();
    std::cout << "Pesan lagi?(Y/N)\t: ";
    std::cin >> jawab;
    if(jawab == 'Y' || jawab == 'y'){
        pesanKamar();
    }
}

/*-----------------------------------PUNYA PENGUNJUNG---------------------------------------*/
void menuPengunjung(){
    system("cls");
    int tamuPilih;
    char pilih;
    batas();
    std::cout << "\t\t\t\tPENGUNJUNG\n";
    batas();
    std::cout << "Menu :\n\n"
                 "1. List Kamar\n"
                 "2. Pesan Kamar\n"
                 "3. Back to Menu\n";
    batas();
    std::cout << "Masukkan pilihan (1/2/3)\t: ";
    std::cin >> tamuPilih;
    switch(tamuPilih){
        case 1:
            listKamar();
            backtoMenuPengunjung();
            break;
        case 2:
            pesanKamar();
            backtoMenuPengunjung();
            break;
        case 3:
            menuAwal();
            break;
        default:
            std::cout << "Input yang anda masukkan salah!!\n";
            backtoMenuPengunjung();
    }
}

void backtoMenuPengunjung(){
    char pilih;
    batas();
    std::cout << "Back to menu (Y/N)?\t";
    std::cin >> pilih;
    if (pilih == 'Y' || pilih == 'y'){
        menuPengunjung();
    } else if (pilih == 'N' || pilih == 'n'){
        exit(0);
    } else {
        std::cout << "Input yang anda masukkan salah!!\n";
    }
}

void listKamar(){
    system("cls");
    batas();
    std::cout << "\t\t\tLIST KAMAR\n";
    batas();
    std::cout << "\n";
    std::cout << "1. Kamar A\n";
    std::cout << "Fasilitas\t\t: Max. 2 orang, Wifi, SPA, Kolam\n";
    std::cout << "\t\t\t  Renang, Sarapan, AC\n";
    std::cout << "Harga/malam\t\t: Rp. 400.000,00\n";
    std::cout << "Jumlah kamar tersedia\t: " << countKamarA();
    std::cout << "\n\n\n2. Kamar B\n";
    std::cout << "Fasilitas\t\t: Max. 4 orang, Wifi, AC\n";
    std::cout << "Harga/malam\t\t: Rp. 400.000,00\n";
    std::cout << "Jumlah kamar tersedia\t: " << countKamarB();
    std::cout << "\n\n";
}

/*------------------------------------PUNYA PEGAWAI-----------------------------------------*/
void menuPegawai(){
    system("cls");
    int pegawaiPilih;
    batas();
    std::cout << "\t\t\t\tPEGAWAI\n";
    batas();
    std::cout << "\nMenu :\n\n"
                 "1. List Pengunjung\n"
                 "2. Pesan Kamar\n"
                 "3. Hapus Pengunjung\n"
                 "4. Back to Menu\n";
    batas();
    std::cout << "Masukkan pilihan (1/2/3/4/5)\t: ";
    std::cin >> pegawaiPilih;
    switch(pegawaiPilih){
        case 1:
            cetakListPengunjung();
            backtoMenuPegawai();
            break;
        case 2:
            pesanKamar();
            backtoMenuPegawai();
            break;
        case 3:
            hapusPengunjung();
            backtoMenuPegawai();
            break;
        case 4:
            menuAwal();
            break;
        default:
            std::cout << "Input yang anda masukkan salah!!\n";
            backtoMenuPegawai();
    }
}

void idPegawai(){
    system("cls");
    int idPeg;
    batas();
    std::cout << "\t\t\t\tPEGAWAI\n";
    batas();
    std::cout << "\n";
    std::cout << "Masukkan ID Pegawai\t: ";
    std::cin >> idPeg;
    if(idPeg == 888/*pegawai->id*/){
        menuPegawai();
    } else {
        std::cout << "ID yang Anda Masukkan Salah!\n";
        menuAwal();
    }
}

void backtoMenuPegawai(){
    char pilih;
    batas();
    std::cout << "Back to menu (Y/N)?\t";
    std::cin >> pilih;
    if (pilih == 'Y' || pilih == 'y'){
        menuPegawai();
    } else if (pilih == 'N' || pilih == 'n'){
        exit(0);
    } else {
        std::cout << "Input yang anda masukkan salah!!\n";
    }
}