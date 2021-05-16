const int maxB = 7;

struct KamarB{
    int memberB[maxB];
    int TOPB;
};
KamarB B;

void createKamarB(KamarB &B){
    B.TOPB = -1;
}

void countKamarB(){
    std::cout << B.TOPB + 1<< "\n";
}

void pushB(int val){
    if(B.TOPB == maxB-1){
        std::cout << "Kamar sudah penuh";
    } else {
        B.TOPB++;
        B.memberB[B.TOPB] = val;
    }
}
