//ada apa aja disini:
void batas();
void menuAwal();
void pesanKamar();
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

void cetakBuktiPesanan(pointer pNew){
    batas();
    std::cout << "\t\tSelamat, pesanan berhasil dibuat!\n";
    batas();
    std::cout << "Nama\t\t\t: " << pNew->nama << "\n";
    std::cout << "Kamar\t\t\t: " << pNew->kamar << "\n";
    std::cout << "Tanggal Check-in\t: " << pNew->tanggalCI <<" - " << pNew->bulanCI <<" - " << pNew->tahunCI << "\n";
    std::cout << "Tanggal Check-out\t: " << pNew->tanggalCO <<" - " << pNew->bulanCO <<" - " << pNew->tahunCO << "\n";
    std::cout << "No Kamar\t\t: " << pNew->noKamar;
}

void pesanKamar(){
    system("cls");
    pointer pNew;
    QueuePengunjung Q;
    listKamar();
    batas();
    std::cout << "\t\t\tPESAN KAMAR\n";
    batas();
    createPesanan(pNew);
    cetakBuktiPesanan(pNew);
    masukkanListPengunjung(pNew, Q);
}

/*-----------------------------------PUNYA PENGUNJUNG---------------------------------------*/
void menuPengunjung(){
    system("cls");
    int tamuPilih;
    char pilih;
    batas();
    std::cout << "\tPENGUNJUNG\n";
    batas();
    std::cout << "Menu :\n"
                 "1. List Kamar\n"
                 "2. Pesan Kamar\n"
                 "3. Back to Menu\n";
    std::cout << "Masukkan pilihan : ";
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
            std::cout << "Masukkan Anda Salah!!\n";
            backtoMenuPengunjung();
    }
}

void backtoMenuPengunjung(){
    char pilih;
    std::cout << "\n\nBack to menu (Y/N)? ";
    std::cin >> pilih;
    if (pilih == 'Y' || pilih == 'y'){
        menuPengunjung();
    } else if (pilih == 'N' || pilih == 'n'){
        exit(0);
    } else {
        std::cout << "Masukkan Anda Salah!!\n";
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
    std::cout << "Jumlah kamar tersedia\t: "; countKamarA();
    std::cout << "\n\n2. Kamar B\n";
    std::cout << "Fasilitas\t\t: Max. 4 orang, Wifi, AC\n";
    std::cout << "Harga/malam\t\t: Rp. 400.000,00\n";
    std::cout << "Jumlah kamar tersedia\t: "; countKamarB();
}

/*------------------------------------PUNYA PEGAWAI-----------------------------------------*/
void menuPegawai(){
    system("cls");
    int pegawaiPilih;
    std::cout << "\tPEGAWAI\n";
    std::cout << "\n";
    std::cout << "Menu :\n"
                 "1. List Pengunjung\n"
                 "2. Update Kamar\n"
                 "3. Pesan Kamar\n"
                 "4. Hapus Pengunjung\n"
                 "5. Back to Menu\n";
    std::cout << "Masukkan pilihan (1/2) : ";
    std::cin >> pegawaiPilih;
    switch(pegawaiPilih){
        case 1:
            cetakListPengunjung(Q);
            backtoMenuPegawai();
            break;
        case 2:
            update();
            backtoMenuPegawai();
            break;
        case 3:
            pesanKamar();
            backtoMenuPegawai();
            break;
        case 4:
            //hapus pengunjung
            backtoMenuPegawai();
            break;
        case 5:
            menuAwal();
            break;
        default:
            std::cout << "Masukkan Anda Salah!!\n";
            backtoMenuPegawai();
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
    } else {
        std::cout << "ID yang Anda Masukkan Salah!\n";
    }
}

void backtoMenuPegawai(){
    char pilih;
    std::cout << "\n\nBack to menu (Y/N)? ";
    std::cin >> pilih;
    if (pilih == 'Y' || pilih == 'y'){
        menuPegawai();
    } else if (pilih == 'N' || pilih == 'n'){
        exit(0);
    } else {
        std::cout << "Masukkan Anda Salah!!\n";
    }
}

void update(){
    system("cls");
    int pilih, noKamar;
    std::cout << "\tUPDATE\n";
    std::cout << "1. Kamar A\n";
    std::cout << "2. Kamar B\n";
    std::cout << "Pilih kamar\t: ";
    std::cin >> pilih;

    switch(pilih){
        case 1:
            std::cout << "Masukkan no kamar\t: ";
            std::cin >> noKamar;
            push(noKamar);
            backtoMenuPegawai();
            break;
        case 2: 
            std::cout << "Masukkan no kamar\t: ";
            std::cin >> noKamar;
            pushB(noKamar);
            backtoMenuPegawai();
            break;
        default:
            std::cout << "Masukkan Anda Salah!!\n";
    }
}