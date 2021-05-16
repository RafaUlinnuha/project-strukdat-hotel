struct Pengunjung{
    char kamar;
    std::string tanggal, nama;
    int jumlah;
    Pengunjung *next;
};

typedef Pengunjung *pointer;
typedef pointer List;

void createList(List &First){
    First = nullptr;
}

void createPengunjung(pointer &pNew){
    pNew = new Pengunjung;
    std::cout << "Nama\t\t: "; 
    std::cin >> pNew->nama;
    std::cout << "Kamar\t\t: "; 
    std::cin >> pNew->kamar;
    std::cout << "Tanggal\t\t: "; 
    std::cin >> pNew->tanggal;
    std::cout << "Jumlah Kamar\t: "; 
    std::cin >> pNew->jumlah;
    pNew->next = nullptr;
}

void traversalPengunjung(List First){
    system("cls");
    if(First == nullptr){
        std::cout << "List kosong\n";
    } else {
        List pHelp = First;
        std::cout << "\t\tSelamat, pesanan berhasil dibuat!\n";
        std::cout << "---------------------------------------------------------------------\n";
        std::cout << "Nama\t: " << pHelp->nama << "\n";
        std::cout << "Kamar\t: " << pHelp->kamar << "\n";
        std::cout << "Tanggal\t: " <<pHelp->tanggal << "\n";
        std::cout << "Jumlah\t: " << pHelp->jumlah << "\n";
    }
} 

void pesanKamar(){
    system("cls");
    pointer pNew;
    List First;

    std::cout << "\tPESAN KAMAR\n";
    createPengunjung(pNew);
    traversalPengunjung(First);
}