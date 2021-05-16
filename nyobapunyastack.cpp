#include <iostream>
#include "stackKamar.hpp"
using namespace std;

int main(){
    int nomorKamarA[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int nomorKamarB[10] = {31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    int JenisKamar;
    Stack KamarA, KamarB;
    pointer KamarBaru, delKamar;
    createStack(KamarA);
    createStack(KamarB);

    for(int i = 0; i<10; i++){
        createKamar(KamarBaru, nomorKamarA[i]);
        masukkanKamar(KamarA, KamarBaru);
    }

    for(int i = 0; i<10; i++){
        createKamar(KamarBaru, nomorKamarB[i]);
        masukkanKamar(KamarB, KamarBaru);
    }

    cout << "pesan kamar";
    cout << "pilih Kamar :"; cin >> JenisKamar;
    if(JenisKamar == 1){
        cout <<"jumlah kamar: " << jumlahKamar(KamarA) << endl;
        cout << "nomor Kamar anda : " << noKamar(KamarA) << endl;
        pakaiKamar(KamarA, delKamar);
        cout << noKamar(KamarA) << endl;
        cout << "jumlah kamar: " << jumlahKamar(KamarA) << endl;
    }
    else if(JenisKamar == 2){
        cout <<"jumlah kamar: " << jumlahKamar(KamarB) << endl;
        cout << "nomor Kamar anda : " << noKamar(KamarB) << endl;
        pakaiKamar(KamarB, delKamar);
        cout << noKamar(KamarB) << endl;
        cout <<"jumlah kamar: " << jumlahKamar(KamarB) << endl;
    }
}