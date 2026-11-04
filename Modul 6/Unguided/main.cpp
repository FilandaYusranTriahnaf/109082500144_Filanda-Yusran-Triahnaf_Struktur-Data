#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    
    int n = 4; 
    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        
        if (findElm(L, x.nopol) != nullptr) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;
            
            address P = alokasi(x);
            insertLast(L, P);
        }
    }
    
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);
    
    return 0;
}