<img width="1920" height="1080" alt="nomer 1" src="https://github.com/user-attachments/assets/3b0e26e1-ff61-4c88-b004-53269eae63b4" />
# <h1 align="center">Laporan Praktikum Modul 3 - Struktur Data</h1>
<p align="center">Filanda Yusran Triahnaf - 109082500144</p>

## Dasar Teori
### A. Abstract Data Type (ADT)
ADT (Abstract Data Type) adalah tipe data yang didefinisikan oleh pengguna, yang menggabungkan tipe data operasi (fungsi/prosedur) yang dapat dilakukan terhadap tipe data tersebut. Konsep ini merupakan konsep abstrak karena pengguna cukup tau apa yang dilakukan oleh sioperasi tersebut, tanpa perlu tahu bagaimana cara kerjanya di dalam.

Dalam bahasa C++, ADT dibuat dengan struct. Operasi-operasinya dibuat dalam bentuk fungsi dan prosedur. Biasanya ADT dipisahkan menjadi tiga file:

File header (.h) berisi definisi tipe (struct) dan deklarasi fungsi/prosedur.
File implementasi (.cpp) berisi isi dari fungsi/prosedur yang dideklarasikan di header.
File utama (main.cpp) program utama yang menggunakan ADT tersebut.

Pemisahan ini membuat kode lebih rapi, terstruktur,dan dapat dipakai ulang di program lain. Selain itu, pada ADT sering digunakan parameter by reference (&) agar perubahan nilai di dalam prosedur ikut mengubah variabel aslinya, serta pointer untuk mengakses dan mengubah isi variabel melalui alamat memorinya.
 

## Guided 

### 1. Mahasiswa.h

#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif

penjelasan singkat guided 1 :

File header ini menjelaskan ADT mahasiswa berupa struct dengan variabel nim (array char), nilai1, dan nilai2. File ini juga mendeklarasikan prosedur inputMhs untuk mengisi data mahasiswa (dengan parameter by reference &) dan fungsi rata2 untuk menghitung rata-rata nilai. Baris #ifndef, #define, dan #endif mencegah header terinclude lebih dari 1 kali.

### 2. Mahasiswa2.cpp

#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}

penjelasan singkat guided 2 :

File ini berisi implementasi dari dua operasi yang dideklarasikan di header. Prosedur inputMhs meminta pengguna memasukkan NIM, nilai1, dan nilai2 lalu menyimpannya ke variabel m.

### 3. Mahasiswa3.cpp

#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main () {
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}

penjelasan singkat guided 3 :

File ini adalah program utama (main). Di dalamnya dibuat variabel mhs bertipe mahasiswa, lalu dipanggil inputMhs(mhs) untuk mengisi data, dan hasil rata2(mhs) ditampilkan di terminal sebagai rata-rata nilai. File ini memakai ADT dengan menginclude mahasiswa.h.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.   

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa data[10];   
    int n;

    cout << "Jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) n = 10;
    if (n < 1) n = 1;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> data[i].nama;
        cout << "NIM    : ";
        cin >> data[i].nim;
        cout << "UTS    : ";
        cin >> data[i].uts;
        cout << "UAS    : ";
        cin >> data[i].uas;
        cout << "Tugas  : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "\n===== DATA MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << data[i].nama << endl;
        cout << "NIM         : " << data[i].nim << endl;
        cout << "UTS         : " << data[i].uts << endl;
        cout << "UAS         : " << data[i].uas << endl;
        cout << "Tugas       : " << data[i].tugas << endl;
        cout << "Nilai Akhir : " << data[i].nilaiAkhir << endl;
    }

    return 0;
}


### Output Unguided 1 :




<img width="1920" height="1080" alt="nomer 1" src="https://github.com/user-attachments/assets/d7d9789f-1133-4e8c-8183-765d22754df5" />




penjelasan unguided 1 :

Program ini menyimpan data maksimal 10 mahasiswa menggunakan array bertipe struct Mahasiswa yang berisi nama, nim, uts, uas, tugas, dan nilaiAkhir. Pengguna memasukkan jumlah mahasiswa, lalu mengisi data tiap mahasiswa dengan perulangan for. Nilai akhir tidak diinput, tetapi dihitung oleh fungsi hitungNilaiAkhir dengan rumus 0.3*uts + 0.4*uas + 0.3*tugas. Setelah terisi, program menampilkan seluruh data beserta nilai akhirnya.


### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”  

//Pelajaranno2.h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif 

//Pelajaranno2.cpp
#include "Pelajaranno2.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//main.cpp
#include <iostream>
#include "Pelajaranno2.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

### Output Unguided 2 :



<img width="1920" height="1080" alt="nomer2" src="https://github.com/user-attachments/assets/9076a3eb-7f83-494f-aed2-d9c2cf641e48" />


penjelasan unguided 2 :

Program ini membuat ADT pelajaran yang terdiri dari tiga file. Header berisi struct pelajaran (namaMapel dan kodeMapel) dan deklarasi fungsi create_pelajaran dan prosedur tampil_pelajaran. File .cpp berisi implementasinya: create_pelajaran membuat dan mengembalikan data pelajaran dari nama dan kode yang diberikan, sedangkan tampil_pelajaran mencetak datanya ke terminal. Pada main, dibuat pelajaran “Struktur Data” dengan kode “STD”, lalu ditampilkan dan muncul output nama pelajaran : Struktur Data dan nilai : STD.


### 3. Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer 

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int *ptr1, *ptr2;   

    cout << "Array A sebelum ditukar:" << endl;
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:" << endl;
    tampilArray(B);

    tukarPosisi(A, B, 1, 1);

    cout << "\nArray A setelah tukar posisi [1][1]:" << endl;
    tampilArray(A);
    cout << "\nArray B setelah tukar posisi [1][1]:" << endl;
    tampilArray(B);

    ptr1 = &A[0][0];
    ptr2 = &B[2][2];

    cout << "\nSebelum tukar pointer: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Sesudah tukar pointer: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    cout << "\nArray A akhir:" << endl;
    tampilArray(A);
    cout << "\nArray B akhir:" << endl;
    tampilArray(B);

    return 0;
}

### Output Unguided 3 :




<img width="1920" height="1080" alt="nomer3" src="https://github.com/user-attachments/assets/e7149abb-93d1-46d9-b54f-2a8cf795ff53" />



penjelasan unguided 3 :

Program ini memakai dua array 2D integer berukuran 3x3 (A dan B) dan dua pointer integer. Fungsi tampilArray menampilkan isi array dengan perulangan bersarang. Fungsi tukarPosisi menukar isi A dan B pada baris dan kolom tertentu memakai variabel temp. Fungsi tukarPointer menukar nilai dari variabel yang ditunjuk oleh dua pointer, yaitu ptr1 yang menunjuk ke A[0][0] dan ptr2 yang menunjuk ke B[2][2]. Karena pointer mengakses alamat asli, nilai di array A dan B ikut berubah setelah penukaran.



## Kesimpulan

Berdasarkan praktikum Modul 3 ini, dapat disimpulkan bahwa:
1. ADT (Abstract Data Type) menggabungkan tipe data dan operasinya sehingga program menjadi lebih terstruktur, rapi, dan mudah digunakan kembali.
2. Pemisahan program menjadi file header (.h), implementasi (.cpp), dan main (.cpp) membuat kode lebih mudah digunakan/ di edit.
3. struct dan array dapat digunakan untuk menyimpan banyak data 
4. Parameter by reference dan pointer dapat melakukan perubahan nilai variabel secara langsung melalui alamat memorinya.
