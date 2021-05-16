const int max = 5;

struct Stack{
    int member[max];
    int TOP;
};
Stack S;

void createStack(Stack &S){
    S.TOP = -1;
}

void countKamar(){
    std::cout << S.TOP + 1 << "\n";
}

void push(int val){
    if(S.TOP == max-1){
        std::cout << "Kamar sudah penuh";
    } else {
        S.TOP++;
        S.member[S.TOP] = val;
    }
}
