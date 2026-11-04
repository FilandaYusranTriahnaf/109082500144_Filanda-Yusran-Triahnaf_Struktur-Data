# <h1 align="center">Laporan Praktikum Modul 6 - Struktur Data</h1>
<p align="center">Filanda Yusran Triahnaf - 109082500144</p>

## Dasar Teori
### A. Doubly Linked List 
Doubly Linked List adalah struktur data linear berupa kumpulan elemen yang saling terhubung di mana setiap elemennya memiliki dua pointer, yaitu next yang mengarah ke elemen berikutnya dan prev yang mengarah ke elemen sebelumnya. 
 

## Guided 

### 1. Doublylist.h

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang{
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist { infotype info; address prev; address next; };
struct list { address first; address last; };

void CreateList(list &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address R, address P);
void insertBefore(list &L, address R, address P);
void printInfo(const list &L);
address findElm(const list &L, const string &kode);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address prec, address &P);
void deleteBefore(list &L, address succ, address &P);
#endif



penjelasan singkat guided 1 :

Berisi berkas header (Doublylist.h) yang mendefinisikan struktur data node (elmlist), tipe data terstruktur infotype (berisi kode, nama, dan tahun barang), penunjuk address, serta mendeklarasikan berbagai prototipe fungsi dan prosedur operasi dasar Doubly Linked List.



### 2. Doublylist.cpp

#include <iostream>
#include <iomanip>
#include "Doublylist.h"
using namespace std;

void CreateList(list &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr; P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}

void insertFirst(list &L, address P) {
    if (!P) return;
    P->prev = nullptr; P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(list &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

// Menyisipkan P tepat setelah R.
void insertAfter(list &L, address R, address P) {
    if (!R || !P) return;
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

// Menyisipkan P tepat sebelum R.
void insertBefore(list &L, address R, address P) {
    if (!R || !P) return;
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}

void printInfo(const list &L) {
    address P = L.first;
    if (!P) {
        cout << "List kosong.\n";
        return;
    }
    
    cout << "+---------------------------------+\n";
    cout << "| Kode    | Nama    | Tahun |\n";
    cout << "+---------------------------------+\n";
    while (P) {
        cout << "| " << left << setw(6) << P->info.kode
             << " | " << setw(10) << P->info.nama
             << " | " << setw(5)  << P->info.tahun << " |\n";
        P = P->next;
    }
    cout << "+---------------------------------+\n";
}

address findElm(const list &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(list &L, address &P) {
    if (!L.first) { P = nullptr; return; }
    P = L.first;
    if (L.first == L.last) { L.first = nullptr; L.last = nullptr; }
    else {
        L.first = L.first->next;
        L.first->prev = nullptr;
    }
    P->prev = P->next = nullptr;
}

void deleteLast(list &L, address &P) {
    if (!L.last) { P = nullptr; return; }
    P = L.last;
    if (L.first == L.last) { L.first = nullptr; L.last = nullptr; }
    else {
        L.last = L.last->prev;
        L.last->next = nullptr;
    }
    P->prev = P->next = nullptr;
}

// Menghapus node tepat setelah prec.
void deleteAfter(list &L, address prec, address &P) {
    P = nullptr;
    if (!prec || !prec->next) return;
    P = prec->next;
    prec->next = P->next;
    if (P->next) P->next->prev = prec;
    else L.last = prec;
    P->prev = P->next = nullptr;
}

// Menghapus node tepat sebelum succ.
void deleteBefore(list &L, address succ, address &P) {
    P = nullptr;
    if (!succ || !succ->prev) return;
    P = succ->prev;
    succ->prev = P->prev;
    if (P->prev) P->prev->next = succ;
    else L.first = succ;
    P->prev = P->next = nullptr;
}




penjelasan singkat guided 2 :

Berisi berkas implementasi (Doublylist.cpp) yang menjabarkan isi fungsi dan prosedur dari header, meliputi alokasi memori, dealokasi, berbagai metode penambahan data (insert first, last, after, before), pencarian elemen, hingga prosedur penghapusan node.


### 3. main.cpp

#include <iostream>
#include "Doublylist.h"
using namespace std;

void tampilkanJudul(const string &judul) {
    cout << "\n=================================\n";
    cout << judul << '\n';
    cout << "=================================\n";
}

int main() {
    list L;
    CreateList(L);

    infotype barang1 = {"B001", "Laptop", 2020};
    infotype barang2 = {"B002", "Monitor", 2022};
    infotype barang3 = {"B003", "Keyboard", 2023};
    infotype barang4 = {"B004", "Mouse", 2024};

    address P = nullptr;
    address posisi = nullptr;

    cout << "DEMONSTRASI OPERASI DOUBLY LINKED LIST\n";
    cout << "Data yang digunakan: B001, B002, B003, dan B004\n";

    tampilkanJudul("[1] INSERT FIRST");
    cout << "Menambahkan B002 di awal list.\n";
    insertFirst(L, alokasi(barang2));
    printInfo(L);

    tampilkanJudul("[2] INSERT LAST");
    cout << "Menambahkan B004 di akhir list.\n";
    insertLast(L, alokasi(barang4));
    printInfo(L);

    tampilkanJudul("[3] INSERT AFTER");
    cout << "Menambahkan B003 setelah B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertAfter(L, posisi, alokasi(barang3));
    }
    printInfo(L);

    tampilkanJudul("[4] INSERT BEFORE");
    cout << "Menambahkan B001 sebelum B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertBefore(L, posisi, alokasi(barang1));
    }
    printInfo(L);

    tampilkanJudul("[5] FIND ELEMENT");
    cout << "Mencari barang dengan kode B003.\n";
    posisi = findElm(L, "B003");
    if (posisi != nullptr) {
        cout << "Data ditemukan:\n";
        cout << " Kode : " << posisi->info.kode << '\n';
        cout << " Nama : " << posisi->info.nama << '\n';
        cout << " Tahun : " << posisi->info.tahun << '\n';
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanJudul("[6] DELETE AFTER");
    cout << "Menghapus node setelah B002 (B003).\n";
    posisi = findElm(L, "B002");
    deleteAfter(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[7] DELETE BEFORE");
    cout << "Menghapus node sebelum B004 (B002).\n";
    posisi = findElm(L, "B004");
    deleteBefore(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[8] DELETE FIRST");
    cout << "Menghapus node pertama.\n";
    deleteFirst(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[9] DELETE LAST");
    cout << "Menghapus node terakhir.\n";
    deleteLast(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("SELESAI");
    cout << "Kondisi list: "
         << (L.first == nullptr && L.last == nullptr ? "kosong.\n" : "masih berisi data.\n");

    return 0;
}



penjelasan singkat guided 3 :

Berisi program utama (main.cpp) yang mendemonstrasikan eksekusi dan pengujian seluruh fungsi serta prosedur Doubly Linked List secara berurutan mulai dari pemasukan data hingga penghapusan node.




## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”, Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”. 

Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;
struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;
struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
address findElm(List L, string nopol);
void insertLast(List &L, address P);
void printInfo(List L);

#endif

Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

main.cpp
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




### Output Unguided 1 :


<img width="1920" height="1080" alt="no1" src="https://github.com/user-attachments/assets/75a30f06-ade3-4217-b69f-3fee76163b3b" />




penjelasan unguided 1 :

Program menerima masukan data kendaraan secara berurutan dan menggunakan fungsi findElm untuk mencegah duplikasi nomor polisi, kemudian menyimpannya menggunakan operasi insertLast dan mencetaknya menggunakan printInfo.




### 2.Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address 

Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;
struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
address findElm(List L, infotype x); 
void insertLast(List &L, address P);
void printInfo(List L);

#endif

Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}


address findElm(List L, infotype x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

main.cpp
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



### Output Unguided 2 :

<img width="1920" height="1080" alt="no2" src="https://github.com/user-attachments/assets/f43b7798-9037-426e-9366-ebf5f74bc2c1" />



penjelasan unguided 2 :

Program menambahkan fitur pencarian data (findElm) berbasis objek infotype untuk mencari keberadaan nomor polisi tertentu dan menampilkan informasi detail atribut kendaraan apabila ditemukan.



### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete. - procedure deleteFirst( input/output L : List,  P : address ) - - procedure deleteLast( input/output L : List,  P : address ) procedure deleteAfter( input Prec : address,  input/output P : address ) 

Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;
struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
address findElm(List L, infotype x);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

void printInfo(List L);

#endif

Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Implementasi deleteFirst[cite: 4]
void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.First;
        L.First = P->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.Last;
        L.Last = P->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}


void deleteAfter(address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}

void printInfo(List L) {
    address P = L.Last;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

main.cpp
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




### Output Unguided 3 :

<img width="1920" height="1080" alt="no3" src="https://github.com/user-attachments/assets/5e00ba7c-19d3-4b7a-8ec8-68f6b578b26e" />




penjelasan unguided 3 :

Program mengintegrasikan fungsi pencarian dengan prosedur penghapusan (deleteFirst, deleteLast, atau deleteAfter) secara kondisional tergantung letak node target, lalu membersihkan memori dengan dealokasi dan menampilkan sisa data.
  




## Kesimpulan

Doubly Linked List merupakan struktur data sangat efektif untuk pengelolaan data dua arah karena memiliki pointer next dan prev pada setiap node-nya.
