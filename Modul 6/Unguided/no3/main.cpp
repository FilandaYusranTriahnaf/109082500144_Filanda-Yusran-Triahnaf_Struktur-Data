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
    
   
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    infotype xHapus;
    cin >> xHapus.nopol;
    
    address P_hapus = findElm(L, xHapus);
    if (P_hapus != nullptr) {
        if (P_hapus == L.First) {
            deleteFirst(L, P_hapus);
        } else if (P_hapus == L.Last) {
            deleteLast(L, P_hapus);
        } else {
            deleteAfter(P_hapus->prev, P_hapus);
        }
        dealokasi(P_hapus);
        cout << "Data dengan nomor polisi " << xHapus.nopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi tersebut tidak ditemukan." << endl;
    }
    
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);
    
    return 0;
}