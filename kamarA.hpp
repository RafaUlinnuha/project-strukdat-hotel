const int max = 5;

struct KamarA{
    int member[max];
    int TOP;
};
KamarA A;

void createKamarA(KamarA &A){
    A.TOP = -1;
}

void countKamarA(){
    std::cout << A.TOP + 1 << "\n";
}

void push(int val){
    if(A.TOP == max-1){
        std::cout << "Kamar sudah penuh";
    } else {
        A.TOP++;
        A.member[A.TOP] = val;
    }
}
