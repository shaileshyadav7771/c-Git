#include<iostream>
using namespace std;
using namespace std;

void fun1(int n)
{
    if (n>0)
    {
        // fun is calling itself, so
        fun1(n-1);
        printf("%d\n",  n);
    }
}

//main function
int main()
{
    int x = 3000000;
    //calling functions from main function
    fun1(x);

    return 0;

}

//o/p:
// 3
// 2
// 1
