#include <stdio.h>
#include <stdlib.h>


int main(){
    int *p,*q;

    p =(int *)malloc(5* sizeof(int));
    p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;

    // Print the memory address of p
    printf("Memory address of p: %p\n", (void *)&p);

    // Print the memory addresses of individual elements in p
    for (int i = 0; i < 5; i++) {
        printf("Memory address of p[%d]: %p\n", i, (void *)&p[i]);
      };

    // we need to store more than 5 elements in the array.
    // so for this we nned to create an array of bigger size.. and copy existing elements of old array into new..

    q = (int * )malloc(10* sizeof(int));

    // Print the memory address of p
    printf("------------------------------------\n");
    printf("Memory address of q: %p\n", (void *)&q);

    // Print the memory addresses of individual elements in p
    for (int i = 0; i < 10; i++) {
        printf("Memory address of q[%d]: %p\n", i, (void *)&q[i]);
      };

    // perform copy operation from old to new array..
    for(int i = 0; i < 10; i++)
        {
            q[i] = p[i];
        }

    //cross checking q value again
    printf("--------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("values in q[i] : %d \n",q[i]);
      };

};
