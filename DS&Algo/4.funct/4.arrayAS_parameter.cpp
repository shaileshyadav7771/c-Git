#include<iostream>
using namespace std;

int * fun(int num){

    int *p;
    p = (int *)malloc(sizeof(int)*num);

    return p;
}


int main(){
    int *A;

    A = fun(5);
    //print vale of all element inside A
    for (int i = 0; i < 5; i++) {
    cout << "A[" << i << "] = " << A[i] << endl;

    //free memory

    free(A);
}

}
