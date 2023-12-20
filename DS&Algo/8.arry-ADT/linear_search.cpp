#include<stdio.h>

struct Array {
    int A[10];
    int size;
    int length;
};

int LinearSearch(struct Array arr, int key){
    printf("--- Searching for no :  %d ---\n", key);

    for(int i=0; i<arr.length; i++){

        if(key == arr.A[i]){
            return printf("Found at : %d index\n", i);
        }
    }
    return -1;
}


int main(){
    struct Array array = {{1,2,3,4,5}, 10, 5};
    LinearSearch(array, 55);

}
