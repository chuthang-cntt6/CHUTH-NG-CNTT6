#include <iostream>
using namespace std;


struct Fraction {
    int whole; 
    float fraction; 
};


void inputFraction(Fraction &f) {
    cout << "Nhap phan nguyen: ";
    cin >> f.whole;
    cout << "Nhap phan thap phan: ";
    cin >> f.fraction;
}


void outputFraction(Fraction f) {
    cout << f.whole << " " << f.fraction << endl;
}

int main() {
    Fraction f;
    inputFraction(f);
    outputFraction(f);
    return 0;
}
