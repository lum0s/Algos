#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int total_len;

void swap(int a, int b, int *A){
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}


void partition(int l, int r, int * A){
	if(r-l>0){
		int p=A[r], i, flag=0, first;
		for (i=l; i<r; i++){
			if (A[i]>p){
				if (flag==0){ 
					first=i;
					flag=1;
				}
			}
			else if(A[i]<p && flag==1){
				swap(first, i, A);
				first++;
			}
		}

		if(flag==1)
			swap(first, r, A);
		else
			first = r;

		for(i = 0; i<total_len; i++) { 
	       printf("%d ", A[i]); 
		}
		printf("\n");
		partition(l, first-1, A);
		partition(first+1, r, A);
	}

}

int main() {
	int len;
   	scanf("%d", &len);
   	total_len=len;
   	int A[len], i;
   	for(i = 0; i<len; i++) { 
        scanf("%d", &A[i]); 
	}
	partition(0, len-1, A);    
    return 0;
}