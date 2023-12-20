#include<iostream>
using namespace std;

int main(){
    int a=77;
    // above is int

    int &r = a;

    cout << "value of a is " << a << endl;
    cout << "value of r is " << r << endl;

    // if we change value of r
    int b = 97;
    r = b;
    cout << "value of r is " << r << endl;
    cout << "value of a is " << a << endl;


    return 0;


}
