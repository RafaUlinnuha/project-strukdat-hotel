const int max = 5;

struct Stack{
    char member[max];
    int TOP;
};
Stack S;

void createStack(Stack &S){
    S.TOP = -1;
}

void countKamar(){
    std::cout << S.TOP + 1 << "\n";
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