#include <stdio.h>

int main()
{
    //decalre an Array
    int A[6] = {0,1,2,3,4,5};  //created in stack

    int *p;

    p = new int[5]; // created in HEAP memory.

    //let us intialize value in HEAP memory
    p[0] = 7;
    p[4] = 14;

    for (int i = 0; i <5; i++) {
        printf("%d\n", A[i]);
        printf("%u\n",&A[i]); // printing address
    }

    printf("\n----------------HEAP ptr-------------------\n");

    for (int i = 0; i <5; i++)
        {
            printf("%d\n", p[i]);
            printf("%u\n",&p[i]); // printing address
        }

    //at last let us deallocate HEAP memory.
    delete [] p;

    return 0;

}
