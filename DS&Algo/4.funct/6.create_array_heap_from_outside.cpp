#include<iostream>
using namespace std;

// ----------------------------------------------------------------
//Create an array inside a HEAP memory from outside function.

int * fun(int size){
    //let create an array inside HEAP memory baseed on the size passed from main/outside fun..
    int * p;
    p = new int[size];
    //let us intialize it's value ...
    for (int i =0; i < size; i++){
        p[i] = i+1;
    }
    return p;
}

int main(){
    int * ptr;
    int sz = 5;
    ptr = fun(sz);
    // now we are accessing value here so let us print all the values..
    cout << "----Accessing inside Main Loop from Heap using Pointer..----" << endl;
    for(int i = 0; i < sz; i++)
        cout << ptr[i] << endl;
    // deallocate the memory
    delete[] ptr;
    return 0;
}
