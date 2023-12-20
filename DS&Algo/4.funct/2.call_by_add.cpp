#include<iostream>
using namespace std;

void swap(int *x ,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a,b;
    a=10;
    b=20;
    // we'll pass address
    swap(&a, &b);
    printf("a value is :%d\n", a);
    printf("b value is :%d\n", b);

    return 0;
}
