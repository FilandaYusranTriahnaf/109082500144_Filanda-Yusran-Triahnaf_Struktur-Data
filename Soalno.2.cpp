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