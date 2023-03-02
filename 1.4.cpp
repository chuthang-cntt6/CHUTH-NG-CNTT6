#include <iostream>
using namespace std;


struct Point
{
    float x; 
    float y;
	float z; 
};


void input(Point& p)
{
    cout << "Nhap toa do x: ";
    cin >> p.x;
    cout << "Nhap toa do y: ";
    cin >> p.y;
    cout << "Nhap toa do z: ";
    cin>> p.z;
}


void output(Point p)
{
    cout << "Toa do x: " << p.x << endl;
    cout << "Toa do y: " << p.y << endl;
    cout << "Toa do z: " << p.z << endl;
}


int main()
{
    Point p1;
    input(p1);
    output(p1);

    return 0;
}