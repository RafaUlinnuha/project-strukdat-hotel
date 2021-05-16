const int max = 5;

struct Stack{
    char member[max];
    int TOP;
};
Stack S;

void createStack(Stack &S){
    S.TOP = -1;
}

int countKamar(Stack S){
    if(S.TOP < 0) {
        return 0;
    } else {
        return S.TOP+1;
    }
}

void push(){
    if(S.TOP == max-1){
        std::cout << "Kamar sudah penuh";
    } else {
        S.TOP++;
        std::cout << "No. Kamar\t: ";
        std::cin >> S.member[S.TOP];
    }
}


