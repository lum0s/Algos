#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//returns the index of the element just less than or equal to the passed element.
int bl_search(int low, int high, long long value, long long p[]){
    if(value>=p[high]){
        return high;
    }
    else if(value<p[low]){
        return -1;
    }
    
    else{
        while(high-low>1){
            int mid=(high+low)/2;
            if(p[mid]>value)
                high=mid;
            else
                low=mid;
        }
        return low;
    }
}

//returns the index of the element just greater than or equal to the passed element.
int br_search(int low, int high, long long value, long long p[]){
    if(value<=p[low]){
        return low;
    }
    
    else if(value>p[high]){
        return -1;
    }
    
    else{            
        while(high-low>1){
            int mid=(high+low)/2;
            if(p[mid]<value)
                low=mid;
            else
                high=mid;
        }
        return high;
    }
}

void triplets(long long A[], long long B[], long long C[], int L, int M, int N){
    /*
    Here we are iterating through the B array. Corresponding to every element in B array, we are identifying the         index of the element just less than or equal to B in A and the index of the element just greater than or             equal to the element in C.    
    Also checking if the lengths of the array are proper
    */
    
    int count=0, l, r;
    for(int j=0; j<M && j<=N-1; j++){        
            int l_index=(j<=L-1)?j:L-1;
            l=bl_search(0, l_index, B[j], A);
            r=br_search(j, N-1, B[j], C);
    //        cout<<l<<r<<endl<<count<<endl;
            if(l!=-1 && r!=-1)
                count+=(l+1)*(N-r);
            }
    cout<<count<<endl;
}


int main(){
    //Just entering numbers in the arrays and calling the triplets function.
    int T, L, M, N;
    cin>>T;
    while(T!=0){
        cin>>L;
        long long A[L];
        for(int i=0; i<L; i++)
            cin>>A[i];
        cin>>M;
        long long B[M];
        for(int i=0; i<M; i++)
            cin>>B[i];
        cin>>N;
        long long C[N];
        for(int i=0; i<N; i++)
            cin>>C[i];
            triplets(A, B, C, L, M, N);
        T--;
    }
    return 0;
}