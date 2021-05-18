#include <iostream>
#include <conio.h>
#include <windows.h>
#include "kamarA.hpp"
#include "kamarB.hpp"
#include "pesan.hpp"
#include "umum.hpp"

main(){
    KamarA A;
    KamarB B;
    createList();
    createKamarA(A);
    int noA[5] = {5,4,3,2,1};
    for(int i=0; i<5; i++){
        push(noA[i]);
    }
    
    createKamarB(B);
    int noB[7] = {12,11,10,9,8,7,6};
    for(int i=0; i<7; i++){
        pushB(noB[i]);
    }
    menuAwal();
}