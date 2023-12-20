#include<iostream>
using namespace std;

// ----------------------------------------------------------------

struct Rectangle
{
    int length; // length
    int breadth; // breadth
};

struct Rectangle * func(){
    struct Rectangle * pointer;
    pointer = new Rectangle;
    // intialize pointer values..
    pointer -> length = 10;
    pointer -> breadth = 20;
    return pointer;
}

int main()
{
    //call function and take return in pointer..
    struct  Rectangle * poi_mai = func();
    printf("Length of Rectangle : %d\nBreadth of rectangle is : %d\n", poi_mai->length, poi_mai -> breadth);

    return 0;

}
