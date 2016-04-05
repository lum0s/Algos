#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long total_len;

void swap(long long a, long long b, long long *A){
    long long temp;
    temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}


//function to sort the aray

void partition(int l, int r, long long * A){
/*
    r is the right index of the array
    l is the left index of the array
    first represents the first element that is larger that the pivot element
    flag is set when an element that is larger than the pivot element is found in the array

*/
    
    if(r-l>0){
        long long p=A[r]; 
        long long i, flag=0, first;
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
/*
        for(i = 0; i<total_len; i++) { 
           printf("%d ", A[i]); 
        }
        printf("\n");
*/
        partition(l, first-1, A);
        partition(first+1, r, A);
    }

}




//function to find the index of the passed number

int find_index(long long num, long long temp[], long l, long h){
    long long mid;
    
    if(num<temp[l])
        return l;
    
    else if(num>temp[h])
        return -1;   

    else{
        while(h-l>=0){
            mid=(l+h)/2;
            if (num>temp[mid]){
                l=mid+1;
            }

            else if(num<temp[mid]){
                h=mid-1;
            }

            else if(temp[mid]==num){
                int k=mid;
                while(temp[k-1]==num && k-1>=l)
                    k--;
                return k;
            }
        }       
        if(h-l==-1)
            return l;
        else return -10;
    }
}


//function to form triplets from the passed array
void triplets(long long A[], long long n){
    long long count=0;
    for(long long i=0; i<n-2; i++)
        for(long long j=i+1; j<n-1; j++){
            long long k=find_index(A[i]+A[j], A, j+1, n-1);
//            cout<<"Ha"<<k<<endl;
            if(k==-1){
                //sum of the first two sides is greater than the third side always
                count=count+n-j-1;
            }
            else
                count=count+k-j-1;
//            cout<<"Hi"<<count<<endl;
    }
    cout<<count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long n, count=0;
    cin>>n;
    total_len=n;
    long long A[n];
    for(long long i=0; i<n; i++)
        cin>>A[i];
    partition(0, n-1, A);
    triplets(A, n);
    return 0;
}


