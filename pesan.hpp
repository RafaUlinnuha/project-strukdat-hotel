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
    std::cout << "Nama\t\t\t: "; 
    std::cin >> pNew->nama;
    std::cout << "Kamar (A/B)\t\t: "; 
    std::cin >> pNew->kamar;
    std::cout << "Tanggal Check-in\t: "; 
    std::cin >> pNew->tanggalCI >> pNew->bulanCI >> pNew->tahunCI; 
    std::cout << "Tanggal Check-out\t: ";
   std::cin >> pNew->tanggalCO >> pNew->bulanCO >> pNew->tahunCO; 
    if(pNew->kamar == 'A' || pNew->kamar == 'a'){
        pNew->noKamar = noKamarA();
        popA();
    }
    else if (pNew->kamar == 'B' || pNew->kamar == 'b'){
        pNew->noKamar = noKamarB();
        popB();
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
        std::cout<< "kosong";
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

