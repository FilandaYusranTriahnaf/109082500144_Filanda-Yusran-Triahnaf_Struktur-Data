#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    
    int n = 4; 
    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        
        if (findElm(L, x) != nullptr) {
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
    
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    infotype xCari;
    cin >> xCari.nopol;
    
    address P_hasil = findElm(L, xCari);
    if (P_hasil != nullptr) {
        cout << "Nomor Polisi : " << P_hasil->info.nopol << endl;
        cout << "Warna        : " << P_hasil->info.warna << endl;
        cout << "Tahun        : " << P_hasil->info.thnBuat << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }
    
    return 0;
}