const int maxB = 7;

struct KamarB{
    int member[maxB];
    int TOP;
};
KamarB B;

void createKamarB(KamarB &B){
    B.TOP = -1;
}

int countKamarB(){
    return B.TOP + 1;
}

void pushB(int val){
    if(B.TOP == maxB-1){
        std::cout << "kamar penuh";
    }
    else{
        B.TOP++;
        B.member[B.TOP] = val;  
    }
    
}

int noKamarB(){
    return B.member[B.TOP];
}

void popB(){
    int resultElement = noKamarB();
    B.TOP -= 1;
}
