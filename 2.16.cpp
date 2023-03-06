#include<iostream>
#include<stdio.h>
#define MAX 8
using namespace std;
 
int A[MAX][MAX] = { 0 };//Kh?i t?o m?ng gi� tr? 0
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;//S? bu?c di
int n;
 
void xuat() {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++)
 printf("%2d ", A[i][j]);
 cout << endl;
 }
 cout << endl;
}
 
void diChuyen(int x, int y) {
 ++dem;//Tang gi� tr? bu?c di
 A[x][y] = dem;//��nh d?u d� di
 for (int i = 0; i < 8; i++) {
 //Ki?m tra xem m� d� di h?t b�n c? chua
 if (dem == n * n) {
 cout << "Cac buoc di la: \n";
 xuat();
 exit(0);
 }
 
 int u = x + X[i];
 int v = y + Y[i];
 
 if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
 diChuyen(u, v);
 }

 --dem;
 A[x][y] = 0;
}
int main() {
 cout << "Nhap n: ";
 cin >> n;
 int a, b;
 cout << "Nhap vi tri ban dau.\nx: ";
 cin>>a;
 cout << "y: ";
 cin >> b;
 diChuyen(a, b);
 
 cout << "Khong tim thay duong di.";
}