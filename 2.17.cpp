#include<stdio.h>
#include<conio.h>

int main()
{
    int i, n;
    long S;
    S = 0;
    i = 1;
    printf("\nNhap n: ");
    scanf("%d", &n);

    while(i <= n)
    {
        S = S + i * i;
        i++;
    }
    printf("i = %d", i);
    printf("\nTong 1^2 + 2^2 + ... + %d^2 la: %ld", n, S);

    


    getch();
    return 0;
}