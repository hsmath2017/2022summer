#include<stdio.h>
int *buggy_fn(int array_size){
    int index,array[array_size];
    for(index=0;index<array_size;index++){
        array[index]=index;
    }
    int* retval;
    retval=array;
    for(index=0;index<array_size;index++){
        printf("retval[index] = %d\n", retval[index]);
    }
    return retval;
}