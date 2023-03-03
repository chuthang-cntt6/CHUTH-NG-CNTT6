#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
#define E(x, i) x.HeSo[i]
struct DonThuc
{
    float HeSo;
    int SoMu;
};
typedef struct DonThuc DONTHUC;
struct DaThuc
{
    float HeSo[MAX];
    int SoMu;
};
typedef struct DaThuc DATHUC;

void KhoiTaoDaThucRong(DATHUC &);
void NhapDaThuc(DATHUC &);
void XuatDaThuc(DATHUC, char[]);


DATHUC TinhHieu2DaThuc(DATHUC, DATHUC);
DATHUC TinhTong2DaThuc(DATHUC, DATHUC);
DATHUC TinhTich2DaThuc(DATHUC, DATHUC);
DATHUC TinhThuong2DaThuc(DATHUC, DATHUC);
DATHUC TinhDaThucDu(DATHUC, DATHUC);
DATHUC TinhDaoHamCap1(DATHUC);
DATHUC TinhDaoHamCapk(DATHUC);
float TinhGiaTri(DATHUC, float);
float TimNghiemDaThucTrongDoanAB(float, float);

DATHUC operator +(DATHUC, DATHUC);
DATHUC operator -(DATHUC, DATHUC);
DATHUC operator *(DATHUC, DATHUC);
DATHUC operator /(DATHUC, DATHUC);


DATHUC TinhDaoHamCap1(DATHUC);
DATHUC TinhDaoHamCapk(DATHUC, int);
float TinhDaoHamCapk(DATHUC, float);

// Dinh nghia ham
void KhoiTaoDaThucRong(DATHUC &dt)
{
    dt.SoMu = 0;
    for (int i = 0; i < MAX; i++)
        dt.HeSo[i] = 0;
}
void NhapDaThuc(DATHUC &dt)
{
    KhoiTaoDaThucRong(dt);
    do
    {
        printf("\nNhap bac da thuc: ");
        scanf("%d", &dt.SoMu);
        if(dt.SoMu < 1)
        {
            printf("\nSo bac cua da thuc phai >= 1. Xin kiem tra lai !");
        }
    }while(dt.SoMu < 1);

    for(int i = dt.SoMu; i >= 0; i--)
    {
        float temp;
        printf("\nNhap he so: ");
        scanf("%f", &temp);
        dt.HeSo[i] = temp;
    }
}

void XuatDaThuc(DATHUC dt, char thongbao[])
{
    printf("%s", thongbao);
    for(int i = dt.SoMu; i > 0; i--)
    {
        if (dt.HeSo[i] != 0)
        {
            printf("%8.3fx^%d + " , dt.HeSo[i], i);
        }
    }
    printf("%8.3f\n", dt.HeSo[0]);
}


// B�i 493: T�nh t?ng 2 da th?c
DATHUC TinhTong2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    // x�t b?c da th?c k?t qu?
    // n?u b?c da th?c a l?n hon b?c da th?c b
    if(a.SoMu > b.SoMu)
    {
        ketqua.SoMu = a.SoMu;  // b?c da th?c k?t qu? l� b?c da th?c a
    }
    else
    {
        ketqua.SoMu = b.SoMu;
    }
    // x�t h? s? da th?c k?t qu?:
    for(int i = 0; i <= ketqua.SoMu; i++)
    {
        ketqua.HeSo[i] = a.HeSo[i] + b.HeSo[i];
    }
    return ketqua;
}

// B�i 494: T�nh hi?u da th?c
DATHUC TinhHieu2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    // x�t b?c da th?c k?t qu?
    // n?u b?c da th?c a l?n hon b?c da th?c b
    if(a.SoMu > b.SoMu)
    {
        ketqua.SoMu = a.SoMu;  // b?c da th?c k?t qu? l� b?c da th?c a
    }
    else
    {
        ketqua.SoMu = b.SoMu;
    }
    // x�t h? s? da th?c k?t qu?:
    for(int i = 0; i <= ketqua.SoMu; i++)
    {
        ketqua.HeSo[i] = a.HeSo[i] - b.HeSo[i];
    }
    return ketqua;
}

// B�i 495: T�nh t�ch 2 da th?c

DATHUC TinhTich2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    // x�t b?c da th?c k?t qu?
    ketqua.SoMu = a.SoMu + b.SoMu; 

    // X�t h? s? da th?c k?t qu?
    int i, j;
    for(i = 0; i <= a.SoMu; i++)
    {
        for(j = 0; j <= b.SoMu; j++)
        {
            ketqua.HeSo[i + j] += a.HeSo[i] * b.HeSo[j];
        }
    }
    return ketqua;
}

/*
   0    1    2    3
   ----------------------
N:  -42    0  -12    1        degree = 3
D:   -3    1    0    0        degree = 1
   d(N) - d(D) = 2, so let's shift D towards right by 2:
N:  -42    0  -12    1
d:    0    0   -3    1
   N(3)/d(3) = 1, so d is unchanged. Now remember that "shifting by 2"
   is like multiplying by x2, and the final multiplication
   (here by 1) is the coefficient of this monomial. Let's store this
   into q:
                               0     1     2
                              ---------------
                          q:   0     0     1
   now compute N - d, and let it be the "new" N, and let's loop
N:  -42    0   -9    0        degree = 2
D:   -3    1    0    0        degree = 1
   d(N) - d(D) = 1, right shift D by 1 and let it be d
N:  -42    0   -9    0
d:    0   -3    1    0        * -9/1 = -9
                          q:   0    -9     1
d:    0   27   -9    0        
   N ? N - d
N:  -42  -27    0    0        degree = 1
D:   -3    1    0    0        degree = 1
   looping again... d(N)-d(D)=0, so no shift is needed; we
   multiply D by -27 (= -27/1) storing the result in d, then
                          q:  -27   -9     1
   and
N:  -42  -27    0    0        -
d:   81  -27    0    0        =
N: -123    0    0    0        (last N)
    d(N) < d(D), so now r ? N, and the result is:
       0   1  2
   -------------
q:   -27  -9  1   ?  x2 - 9x - 27
r:  -123   0  0   ?          -123
*/
// B�i 496: T�nh thuong 2 da th?c


// B�i 498: T�nh d?o h�m c?p 1 da th?c ( chua test)

DATHUC TinhDaoHamCap1(DATHUC dt)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    // b?c c?a da th?c k?t qu?
    ketqua.SoMu = dt.SoMu - 1;

    // h? s? c?a da th?c k?t qu?
    for(int i = dt.SoMu; i >= 0; i--)
    {        
        ketqua.HeSo[i - 1] = dt.HeSo[i] * i;
    }
    return ketqua;
}

// B�i 499: T�nh d?o h�m c?p k c?a da th?c ( chua test)

DATHUC TinhDaoHamCapk(DATHUC dt, int k)
{
    DATHUC ketqua = dt;
    for(int i = 0; i < k; i++)
    {
        ketqua = TinhDaoHamCap1(ketqua);
    }
    return ketqua;
}

// B�i 500: T�nh gi� tr? c?a da th?c t?i x = x0 ( chua test)
float TinhGiaTri(DATHUC dt, float x0) 
{
    float kq = 0;

    for (int i=dt.SoMu; i>=0; i--)
        kq = kq + dt.HeSo[i] * pow(x0, i);

    return kq;
}
int main()
{
    DATHUC kq;
    DATHUC dt1, dt2;
    NhapDaThuc(dt1);
    XuatDaThuc(dt1, "Da thuc 1: ");

    NhapDaThuc(dt2);
    XuatDaThuc(dt2, "Da thuc 2: ");
    XuatDaThuc(TinhTong2DaThuc(dt1, dt2), "Da thuc 1 + Da thuc 2 = ");
    XuatDaThuc(TinhHieu2DaThuc(dt1, dt2), "Da thuc 1 - Da thuc 2 = ");
    XuatDaThuc(TinhTich2DaThuc(dt1, dt2), "Da thuc 1 * Da thuc 2 = ");
    //XuatDaThuc(TinhThuong2DaThuc(dt1, dt2), "Da thuc 1 / Da thuc 2 = ");

    
    XuatDaThuc(TinhDaoHamCap1(dt1), "Dao ham cap 1 = ");

    getch();
    return 0;
}