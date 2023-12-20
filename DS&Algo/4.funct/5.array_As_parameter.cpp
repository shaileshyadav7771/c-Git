#include<iostream>
using namespace std;

// ----------------------------------------------------------------
//write a program which will take a an array and print length.

void fun(int A[]){
    cout << "--- Receiving as a pointer ---\n";
    // here we'll get pointer size which we already discussed
    // It'll be of 4 bytes irrespective of data types.
    cout << "size of A : " << sizeof(A) << endl;  //
    cout << "size of int : " << sizeof(int) << endl; //
    cout << sizeof(A)/sizeof(int) << endl; //

    // let us print each elements of the array
    for (int i = 0; i <5; i++)
      cout << "Value inside outer loop " << i << A[i] << endl;
}

int main(){
    int A[] = {2,4,6,8,10};
    int n = 5;
    cout << "size of A : " << sizeof(A) << endl;  //20
    cout << "size of int : " << sizeof(int) << endl; //4
    cout << sizeof(A)/sizeof(int) << endl; //5

    // Now let us call the function by passing array A []
    fun(A);
    return 0;

}
