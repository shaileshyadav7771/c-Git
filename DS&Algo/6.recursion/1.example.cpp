#include<iostream>
using namespace std;
using namespace std;

void fun1(int n)
{
    if (n>0)
    {
        printf("%d\n",  n);
        // fun is calling itself, so
        fun1(n-1);
    }
}

//main function
int main()
{
    int x = 3000;
    //calling functions from main function
    fun1(x);

    return 0;

}

//o/p:
// 3
// 2
// 1
