#include<iostream>
using namespace std;

int main(){
    int a=10;
    // above is int
    printf("%d\n",a );

    int A[5] = {0,1,2,3,4};

    int *p;

    p = A;

    for(int i=0; i<5 ; i++)
       cout << p[i] << " - " << A[i] << endl;

    return 0;


}
