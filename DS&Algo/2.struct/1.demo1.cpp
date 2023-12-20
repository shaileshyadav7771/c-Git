#include<iostream>
using namespace std;

struct Rectangle {
    int length;       //4 byte
    int breadth;      //4byte
    char total;       //4 byte instead of 1 byte (Padding)
};

int main(){
    // assigning value to length and breadth
    struct Rectangle r1={10,20};

    printf("%d\n", sizeof(r1)); //8 byte

    //Accessing elemnets from struct
    cout << "value of length is : "  << r1.length << endl;
    cout << "value of breadth is : "  << r1.breadth << endl;
    cout << "Total is : "  << r1.total;


}
