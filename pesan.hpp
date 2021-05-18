void setcolor (unsigned short color);
void backtoMenuAwal();
void menuAwal();
void batas();
void pesanKamar();

struct Pengunjung{
    char kamar;
    std::string nama;
    int noKamar, tanggalCO, tanggalCI;
    Pengunjung *next;
    //prioritynya tanggal check-out, tanggal lebih awal maka disimpan didepan 
};

typedef Pengunjung* pointer;
typedef pointer list;
list First;

void createList(){
    First = nullptr;
}

void createPesanan(pointer &pNew){
    pNew = new Pengunjung;
    char pilihPesan;
    std::cout << "Nama\t\t\t: ";
    std::getline(std::cin>>std::ws, pNew->nama);
    std::cout << "Kamar (A/B)\t\t: "; 
    std::cin >> pNew->kamar;
    if(pNew->kamar == 'A' || pNew->kamar == 'a'){
        if(countKamarA() == 0){
            std::cout << "Jenis kamar yang anda pilih tidak ada! pilih kamar lain!\n";
            std::cout << "Kembali ke menu awal(Y/N)?\t";
            std::cin >> pilihPesan;
            if(pilihPesan =='y' || pilihPesan=='Y'){
            menuAwal();
            }
            else{
                exit(0);
            } 
        }
        else{
            pNew->noKamar = noKamarA();
            popA(); 
        }
    }

    else if (pNew->kamar == 'B' || pNew->kamar == 'b'){
        if(countKamarB() == 0){
            std::cout << "Jenis kamar yang anda pilih sudah penuh! pilih kamar lain!\n";
            std::cout << "kembali ke menu awal(Y/N)?\t";
            std::cin >> pilihPesan;
            if(pilihPesan =='y' || pilihPesan=='Y'){
            menuAwal();
            }
            else{
                exit(0);
            }
        } 
        else{
            pNew->noKamar = noKamarB();
            popB();
        }
        
    }
    else{
        setcolor(4);
        std::cout << "Input yang anda masukkan salah, kembali ke menu awal!\n";
        setcolor(7);
        backtoMenuAwal();
    }

    std::cout << "Tanggal Check-in\t: "; 
    std::cin >> pNew->tanggalCI; 
    std::cout << "Tanggal Check-out\t: ";
    std::cin >> pNew->tanggalCO;
    if(pNew->tanggalCO < pNew->tanggalCI){
        batas();
        setcolor(4);
        std::cout << "input tanggal salah, kembali ke menu awal!\n";
        setcolor(7);
        if(pNew->kamar == 'A' || pNew->kamar == 'a'){
            push(pNew->noKamar);
        }
        else{
            pushB(pNew->noKamar);
        }
        backtoMenuAwal();
    }
    pNew->next = nullptr;
}

void masukkanListPengunjung(pointer& pNew){ //enqueue
    pointer pHelp = First;
    pointer prev = nullptr;
    
    if(First == nullptr){
        First = pNew;
    }
    else{
        while(pNew->tanggalCO >= pHelp->tanggalCO){
            if(pHelp->next == nullptr)
                break;
            prev = pHelp;
            pHelp = pHelp->next;
        }
        if(pHelp==First && pNew->tanggalCO <= pHelp->tanggalCO){
            pNew->next = pHelp;
            First = pNew;
        }
        else if(pHelp->next == nullptr && pNew->tanggalCO > pHelp->tanggalCO){
            pHelp->next = pNew;
        }
        else{
            prev->next = pNew;
            pNew->next = pHelp;
        }
        
    }
}

void cetakListPengunjung(){
    system("cls");
    batas();
    std::cout << "\t\t\tList Pengunjung\n";
    batas();
    pointer pHelp = First;
    if(First == nullptr){
        std::cout << "tidak ada pengunjung :(\n";
    }
    int no = 1;
    while (pHelp != nullptr){
    std::cout << no << ".\tNama\t\t\t: " <<pHelp->nama << "\n";
    std::cout << "\tKamar\t\t\t: " << pHelp->kamar << "\n";
    std::cout << "\tNo Kamar\t\t: " << pHelp->noKamar << "\n"; 
    std::cout << "\tTanggal Check-in\t: " <<pHelp->tanggalCI <<" - 05 - 2021\n";
    std::cout << "\tTanggal Check-out\t: " <<pHelp->tanggalCO <<" - 05 - 2021\n\n"; 
    pHelp = pHelp->next;
    no++;
    }
}

void hapusPengunjung(){
    system("cls");
    batas();
    std::cout << "\t\t\tHapus Pengunjung\n";
    batas();
    pointer delElement, prev = nullptr;
    pointer pHelp = First;
    pointer pHelp2 = First;
    
    if(First == nullptr){
        std::cout << "tidak ada pengunjung :(\n";
    }
    else{
        std::string nama;
        int no = 1;
        while(pHelp!= nullptr && pHelp->tanggalCO == First->tanggalCO){
            std::cout << no << ".\tNama\t\t\t: " <<pHelp->nama << "\n";
            std::cout << "\tKamar\t\t\t: " << pHelp->kamar << "\n";
            std::cout << "\tNo Kamar\t\t: " << pHelp->noKamar << "\n"; 
            std::cout << "\tTanggal Check-in\t: " <<pHelp->tanggalCI <<" - 05 - 2021\n";
            std::cout << "\tTanggal Check-out\t: " <<pHelp->tanggalCO <<" - 05 - 2021\n\n";
            pHelp = pHelp->next;
            no++;
        }

        std::cout << "Masukkan nama pelanggan yang ingin dihapus: ";
        std::getline(std::cin >> std::ws, nama);
        if(pHelp2->nama == nama){
            First = pHelp2->next;
            delElement = pHelp2;
            batas();
            setcolor(2);
            std::cout << "Data pelanggan berhasil terhapus!\n";
            setcolor(7);
        }
        else{
            while(pHelp2 != nullptr && pHelp2->nama != nama){
                prev = pHelp2;
                pHelp2 = pHelp2->next;
            }
            if(pHelp2 == nullptr){
                setcolor(4);
                std::cout << "Pengunjung dengan nama " << nama << " tidak ada";
                hapusPengunjung();
                setcolor(7);
            }
            prev->next = pHelp2->next;
            delElement = pHelp2;
            batas();
            setcolor(2);
            std::cout << "Data pelanggan berhasil terhapus!\n";
            setcolor(7);
        }
        if(delElement->kamar == 'A' || delElement->kamar == 'a'){
            push(delElement->noKamar);
        }
        else{
            pushB(delElement->noKamar);
        }
    }
}