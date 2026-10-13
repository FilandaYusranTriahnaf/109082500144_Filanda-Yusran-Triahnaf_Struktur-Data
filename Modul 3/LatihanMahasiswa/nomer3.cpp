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