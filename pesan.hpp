struct Pengunjung{
    char kamar;
    std::string nama;
    int noKamar, tanggalCO, bulanCO, tanggalCI, bulanCI, tahunCI, tahunCO;
    Pengunjung *next;
    //prioritynya tanggal check-out, tanggal lebih awal maka disimpan didepan 
};

typedef Pengunjung* pointer;

struct QueuePengunjung{
    pointer head;
    pointer tail;
};

QueuePengunjung Q;

void createList(QueuePengunjung& Q){
    Q.head = nullptr;
    Q.tail = nullptr;
}

void createPesanan(pointer &pNew){
    pNew = new Pengunjung;
    char pilihPesan;
    std::cout << "Nama\t\t\t: "; 
    std::cin >> pNew->nama;
    std::cout << "Kamar (A/B)\t\t: "; 
    std::cin >> pNew->kamar;
    if(pNew->kamar == 'A' || pNew->kamar == 'a'){
        pNew->noKamar = noKamarA();
        popA();
    } else if (pNew->kamar == 'B' || pNew->kamar == 'b'){
        pNew->noKamar = noKamarB();
        popB();
    } else {
        std::cout << "Masukkan Anda Salah!!\n";
        exit(0);
    }
    std::cout << "Tanggal Check-in\t: "; 
    std::cin >> pNew->tanggalCI >> pNew->bulanCI >> pNew->tahunCI; 
    std::cout << "Tanggal Check-out\t: ";
    std::cin >> pNew->tanggalCO >> pNew->bulanCO >> pNew->tahunCO; 
    if(pNew->tanggalCI > 31 || pNew->tanggalCO > 31 || pNew->tanggalCI < 1 || pNew->tanggalCO < 1 || pNew->bulanCI >12 || pNew->bulanCO >12 || pNew->bulanCI < 1 || pNew->bulanCO < 1 || pNew->tahunCI < 2021 || pNew->tahunCO < 2021){
        std::cout << "Tanggal yang anda masukkan salah!\n";
        std::cout << "Pesan ulang (Y/N)? ";
        std::cin >> pilihPesan;
        if(pilihPesan == 'y' || pilihPesan == 'Y'){
            createPesanan(pNew);
        }
        else{
            exit(0);
        }
    }
    pNew->next = nullptr;
}

void masukkanListPengunjung(pointer& pNew,QueuePengunjung Q){ //enqueue
    pointer pRev = nullptr;
    pointer pHelp = Q.head;
    if(Q.head == nullptr && Q.tail == nullptr){
        Q.head = pNew;
        Q.tail = pNew; 
    }
    else{
        while(pNew->tanggalCO >= pHelp->tanggalCO){
            if(pNew->next == nullptr)
                break;
            pRev = pHelp;
            pHelp = pHelp->next;
        }
        if(pHelp==Q.head && pNew->tanggalCO < pHelp->tanggalCO){
            pNew->next = pHelp;
            Q.head = pNew;
        }
        else if(pHelp==Q.tail && pNew->tanggalCO > pHelp->tanggalCO){
            pHelp->next = pHelp;
            Q.tail = pNew;
        }
        else{
            pRev->next = pNew;
            pNew->next = pHelp;
        }
        
    }
}

void cetakListPengunjung(QueuePengunjung Q){
    pointer pHelp = Q.head;
    if(Q.head == nullptr && Q.tail == nullptr){
        std::cout<< "Kosong";
    }
    int no = 1;
    while (pHelp != nullptr){
    std::cout << no << "\tNama\t:" <<pHelp->nama << "\n";
    std::cout << "Kamar\t\t: " << pHelp->kamar << "\n";
    std::cout << "No Kamar\t: " << pHelp->noKamar << "\n"; 
    std::cout << "Tanggal Check-in\t: " <<pHelp->tanggalCI <<" - " << pHelp->bulanCI <<" - " << pHelp->tahunCI << "\n";
    std::cout << "Tanggal Check-out\t: " <<pHelp->tanggalCO <<" - " << pHelp->bulanCO <<" - " << pHelp->tahunCO << "\n"; 
    pHelp = pHelp->next;
    no++;
    }
}

void hapusPengunjung(QueuePengunjung Q) {
    pointer delElement;
    if(Q.head != nullptr){
        std::cout << "Pengunjung dengan data :\n";
        std::cout << "Nama\t:" <<Q.head->nama << "\n";
        std::cout << "Kamar\t\t: " << Q.head->kamar << "\n";
        std::cout << "No Kamar\t: " << Q.head->noKamar << "\n"; 
        std::cout << "Tanggal Check-in\t: " <<Q.head->tanggalCI <<" - " << Q.head->bulanCI <<" - " << Q.head->tahunCI << "\n";
        std::cout << "Tanggal Check-out\t: " <<Q.head->tanggalCO <<" - " << Q.head->bulanCO <<" - " << Q.head->tahunCO << "\n";
    }
    if(Q.head == nullptr){
        delElement = nullptr;
    } else if(Q.head->next == nullptr){
        delElement = Q.head;
        Q.head = nullptr;
        Q.tail = nullptr;
    } else{
        delElement = Q.head;
        Q.head = Q.head->next;
        delElement->next = nullptr;
    }
    std::cout << "Sudah tidak ada / berhasil terhapus!\n";
}