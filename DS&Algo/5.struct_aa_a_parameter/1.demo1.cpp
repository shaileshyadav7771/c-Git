#include<iostream>
using namespace std;

// ----------------------------------------------------------------

struct Test
{
    int length; // length
    int breadth; // breadth
};


int main(){
    struct Test t = {10,20};
    printf("Length is  : %d\nBreadth is : %d", t.length, t.breadth);

}
