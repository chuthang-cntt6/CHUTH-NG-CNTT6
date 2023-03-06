#include<iostream>  
using namespace std;
int main()   
{    
    int n;
    while(true) {
        int giaithua = 1;
        cout << "Nhap so n: ";
        cin >> n;
         
       
        if(n < 0) {
            cout << "  So am khong co giai thua" << endl;
            break;
        }
 
        if ( n > 0) {
            for(int i = 1; i <=n; i++) {
                giaithua = giaithua * i;
            }
        }
        cout << "  Giai thua cua " << n << " la: " << giaithua << endl;
 
    }
    return 0;  
}