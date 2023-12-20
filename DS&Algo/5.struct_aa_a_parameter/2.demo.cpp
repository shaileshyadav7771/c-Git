#include<iostream>
using namespace std;

// ----------------------------------------------------------------

struct Rectangle
{
    int length; // length
    int breadth; // breadth
};

void func(struct Rectangle t2){
    t2.length = 77;
    t2.breadth= 1;
    printf("Length of Rectangle : %d\nBreadth of rectangle is : %d\n", t2.length, t2.breadth);
}

int main()
{
    struct Rectangle t1 = {10,20};  // struct is optional in c++
    func(t1);
    printf("---- Inside main loop ----\n");
    printf("Length of Rectangle : %d\nBreadth of rectangle is : %d\n", t1.length, t1.breadth);

    return 0;

}
