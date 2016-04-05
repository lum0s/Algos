#include<stdio.h>

int printfunc(int *A){
		int i;
		for (i=0; i<10; i++){
		printf("%d \n", A[i]);
	}
	return 0;
}


int merge(int *a, int l1, int r1, int l2, int r2){
	int i=l1, j=l2, k=0, T[10];
	

	while(i<=r1 && j<=r2){
		if(a[i]>a[j])
			T[k++]=a[j++];
		else 
			T[k++]=a[i++];
	}

	while (i<=r1)
		T[k++]=a[i++];
	while (j<=r2)
		T[k++]=a[j++];

	for (i=l1, k=0; i<=r2; i++, k++){
		a[i]=T[k];
	}

	return 0;
}

int sort_array(int * a, int l, int r){
	if (r-l>=1){
		sort_array(a, l, (l+r)/2);
		sort_array(a, ((l+r)/2) +1, r);
		merge(a, l, ((l+r)/2),(((l+r)/2)+1), r);
	}

	/*if (r-l==1){
		if (a[r]<a[l]){
			int temp=a[r];
			a[r]=a[l];
			a[l]=temp;
		}
	}*/
	return 0;
}


int main(){
	int T[10];
	int A[10] = {23, 21, 22, 1, 98, 66, 75, 46};
	sort_array(A, 0, 9);
	printfunc(A);
	return 0;
}
