#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void partition(int ar_size, int * ar) {

    int p =ar[0];
    int t1[ar_size], t2[ar_size];
    int i, j=0,k=0;
    
    for (i=1; i<ar_size; i++){
        if (ar[i]>p)
            t2[j++]=ar[i];
        else if (ar[i]<p)
            t1[k++]=ar[i];
    }
   
   i=0; 
    
    while (i!=k){
        ar[i]=t1[i];
        i++;
    }
    
    ar[i++]=p;
    j=0;
    while(i<ar_size){
        ar[i]=t2[j];
        i++;
        j++;
    }

    for (i=0; i<ar_size; i++){
        printf("%d", ar[i]);
  //      printf("hi");
    }
 }

int main() {
   
   int _ar_size;
   scanf("%d", &_ar_size);
   int _ar[_ar_size], _ar_i;
   for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
}

partition(_ar_size, _ar);
   
   return 0;
}