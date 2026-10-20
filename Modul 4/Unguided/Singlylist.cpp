#include "Singlylist.h"

// Inisialisasi list kosong
void createList(List &L) {
    L.First = NULL;
}

// Alokasi elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

// Dealokasi memory elemen
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menampilkan seluruh isi list
void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menambahkan elemen di awal list
void insertFirst(List &L, address P) {
    if (P != NULL) {
        P->next = L.First;
        L.First = P;
    }
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        L.First = L.First->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == NULL) { // Jika hanya ada 1 elemen
            P = L.First;
            L.First = NULL;
        } else {
            address Q = L.First;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    } else {
        P = NULL;
    }
}

// Menghapus elemen setelah node Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

// Menghitung jumlah node/elemen dalam list
int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

// Menghapus seluruh node dalam list
void deleteList(List &L) {
    address P;
    while (L.First != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}