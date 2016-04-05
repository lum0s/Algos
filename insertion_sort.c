#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void insertion_sort(int len, int *A){
	int i, j, k, temp;
	for(i=0; i<len; i++){
		//Traversing the entire length of array
		if(A[i+1]<A[i]){
			// if we find an element that is out of its position, search for the correct position of the element and place it there.
			temp=A[i+1];
			j=i-1;
			while(temp<A[j] && j>=0)
				j--;
			k=i;
			while(j!=k){
				A[k+1]=A[k];
				k--;
			A[j+1]=temp;
			}
		}
	}
}



int main() {
	int len;
   	scanf("%d", &len);
   	int A[len], i;
   	for(i = 0; i<len; i++) { 
        scanf("%d", &A[i]); 
	}
	insertion_sort(len, A); 
	for (i=0; i<len; i++)
		printf("%d", A[i]);   
    return 0;
}