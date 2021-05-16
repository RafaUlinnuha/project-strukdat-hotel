const int max = 5;

struct Stack{
    char member[max];
    int TOP;
};
Stack S;

void createStack(Stack &S){
    S.TOP = -1;
}

bool isEmpty(Stack S){
    if(S.TOP < 0) {
        return true;
    } else {
        return false;
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

void countKamar(){
    std::cout << S.TOP + 1;
}


