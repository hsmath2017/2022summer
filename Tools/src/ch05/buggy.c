#include <stdio.h>
#include <stdlib.h>
int* buggy_fn();

int main(int argc,char* argv[]){
    int array_size=atoi(argv[1]);
    int* array;
    array=buggy_fn(array_size);
    int index;
    for(index=0;index<array_size;index++){
        printf("array[index] = %d\n",array[index]);
    }
    return 0;
}