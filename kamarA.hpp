const int max = 5;

struct KamarA{
    int member[max];
    int TOP;
};
KamarA A;

void createKamarA(KamarA &A){
    A.TOP = -1;
}

int countKamarA(){
    return A.TOP + 1;
}

void push(int val){
    if(A.TOP < max-1){
        A.member[A.TOP++] = val;
    }
}

int noKamarA(){
    return A.member[A.TOP];
}

void popA(){
    int resultElement = noKamarA();
    A.TOP -= 1;
}