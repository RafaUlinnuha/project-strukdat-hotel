#include <iostream>
#include "kamarA.hpp"
#include "kamarB.hpp"
#include "pesan.hpp"
#include "umum.hpp"

main(){
    KamarA A;
    KamarB B;
    QueuePengunjung Q;
    createList(Q);
    createKamarA(A);
    int noA[5] = {1,2,3,4,5};
    for(int i=0; i<5; i++){
        push(noA[i]);
    }
    
    createKamarB(B);
    int noB[7] = {6,7,8,9,10,11,12};
    for(int i=0; i<7; i++){
        pushB(noB[i]);
    }
    menuAwal();
}