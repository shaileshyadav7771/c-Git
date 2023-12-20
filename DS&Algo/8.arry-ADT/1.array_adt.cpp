#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;  // array HEAP
    int size;
    int length;
};

int main()
{
    struct Array arr;
    printf("Enter size of an array)\n");
    scanf("%d", &arr.size);
    // create a array in HEAP
    arr.A = (int * )malloc(arr.size * sizeof(int));

    arr.length = 0;

    int n, i;

    // read no and assign it to variable n 
    printf("Enter number of no to be inserted\n");
    scanf("%d", &n);
}