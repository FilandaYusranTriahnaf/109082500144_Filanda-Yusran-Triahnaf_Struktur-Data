# <h1 align="center">Laporan Praktikum Modul 1 - Struktur Data</h1>
<p align="center">Filanda Yusran Triahnaf - 109082500144</p>

## Dasar Teori

Dalam pemrograman C++, pemahaman mengenai struktur data dasar dan kontrol alur merupakan hal yang sangat krusial. Dua konsep mendasar yang sering digunakan dalam menyelesaikan permasalahan pemrograman adalah *Array* dan *Perulangan For (For Loop)*.

### A. Array
Array adalah kumpulan dari variabel-variabel yang memiliki tipe data sama dan disimpan dalam lokasi memori yang berurutan. Setiap elemen di dalam array dapat diakses menggunakan indeks numerik, di mana indeks pertama dalam bahasa C++ dimulai dari angka 0. Array sangat berguna ketika kita ingin menyimpan dan mengelola sekumpulan data tanpa harus membuat banyak variabel secara terpisah.

### B. For Loop
Perulangan for adalah salah satu bentuk iterasi yang digunakan untuk mengeksekusi blok kode secara berulang selama kondisi tertentu terpenuhi. Perulangan ini biasanya digunakan ketika jumlah iterasi atau pengulangan sudah diketahui secara pasti sebelum eksekusi dimulai.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nHasil Penjumlahan : " << a + b << endl;
    cout << "Hasil Pengurangan : " << a - b << endl;
    cout << "Hasil Perkalian   : " << a * b << endl;
    
    if (b != 0) {
        cout << "Hasil Pembagian   : " << a / b << endl;
    } else {
        cout << "Pembagi tidak boleh nol" << endl;
    }

    return 0;
}

### Output Unguided 1 :

![Output Unguided 1](../Struktur%20Data%20no1.png)


penjelasan unguided 1 :

Program di atas bertujuan untuk melakukan operasi aritmatika dasar (penjumlahan, pengurangan, perkalian, dan pembagian) pada dua buah bilangan bertipe float. Program meminta pengguna memasukkan dua nilai bertipe ⁠float⁠ yang disimpan pada variabel ⁠a⁠ dan ⁠b⁠. Selanjutnya, program mengeksekusi perhitungan aritmatika langsung pada perintah ⁠cout⁠. 



### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

#include <iostream>
#include <string>

using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    string hasil = "";
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka < 0 || angka > 100) {
        cout << "Angka harus di antara 0 sampai 100" << endl;
        return 0;
    }

    if (angka == 0) {
        hasil = "nol";
    } else if (angka == 100) {
        hasil = "seratus";
    } else if (angka < 10) {
        hasil = satuan[angka];
    } else if (angka == 10) {
        hasil = "sepuluh";
    } else if (angka == 11) {
        hasil = "sebelas";
    } else if (angka < 20) {
        hasil = satuan[angka % 10] + " belas";
    } else {
        int puluh = angka / 10;
        int sisa = angka % 10;
        if (sisa == 0) {
            hasil = satuan[puluh] + " puluh";
        } else {
            hasil = satuan[puluh] + " puluh " + satuan[sisa];
        }
    }

    cout << angka << " : " << hasil << endl;

    return 0;
}

### Output Unguided 2 :

![Output Unguided 2](Struktur%20Data%20no2.png)

penjelasan unguided 2 :

Program ini mengonversi input angka bulat dari kisaran 0 hingga 100 menjadi bentuk terbilang/tulisan kata.


### 3. Buatlah program yang dapat memberikan input dan output sbb (pola piramida berulang dengan angka dan karakter

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Karakter * di tengah
        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}

### Output Unguided 3 :

![Output Unguided 3](Struktur%20Data%20no3.png)

penjelasan unguided 3 :

Program ini menerima masukan berupa angka ⁠n⁠ untuk membentuk suatu pola berbentuk piramida terbalik yang simetris. 

## Kesimpulan

Berdasarkan praktikum Modul 1 ini, dapat disimpulkan bahwa:
1. Pemrograman C++ memungkinkan pemrosesan operasi aritmatika pada tipe data float
2. Konversi nilai numerik menjadi teks dapat diselesaikan dengan memadukan struktur data Array sebagai kamus kata dan pengkondisian if-else untuk memilah aturan tata bahasa (satuan, belasan, dan puluhan).
3. Pembuatan pola berupa piramida pada terminal dapat dicapai dengan memanfaatkan perulangan bersarang (nested loop) untuk mengatur posisi spasi, deret angka, dan simbol karakter secara simetris.

