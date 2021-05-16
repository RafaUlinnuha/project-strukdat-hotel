struct Kamar{
    int nomorKamar;
    Kamar *next;
};

typedef Kamar *pointer;
typedef pointer Stack;

void createStack(Stack& Top){
    Top = nullptr;
};

void createKamar(pointer& kamarBaru, int data) {
  kamarBaru = new Kamar;
  kamarBaru->nomorKamar = data;
  kamarBaru->next = nullptr;
}

void masukkanKamar(Stack& Top, pointer kamarBaru){
    if(Top == nullptr){
        Top = kamarBaru;
    }
    else{
       kamarBaru-> next = Top;
        Top = kamarBaru; 
    }
}

void pakaiKamar(Stack& Top, pointer& delKamar){
    if(Top == nullptr){
        std::cout << "kamar penuh";
    }
    else if(Top->next == nullptr){
        delKamar = Top;
        Top=nullptr;
    }
    else{
        delKamar = Top;
        Top = Top->next;
        delKamar->next = nullptr;
    }
}

int noKamar(Stack Top){
    return Top->nomorKamar;
}

int jumlahKamar(Stack Top){
    pointer phelp = Top;
    int jumlahKamar = 0;
    while(phelp!=nullptr){
        jumlahKamar++;
        phelp= phelp->next;
    }
    return jumlahKamar;
}
