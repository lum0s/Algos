#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//function to find out the index of the number just greater than or equal to the selected number in the passed array.
int find_index(long long num, long long temp[], int l, int h){
    int mid;
    
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

            else if(temp[mid]==num)
                return mid;

        }       
        if(h-l==-1)
            return l;
        else return -10;
    }
}

/*
int triplets(long long A[], long long B[], long long C[], int L, int M, int N){
    int count=0, j, k;
    for(int i=0; i<L; i++){
        
       //call function to find the index in B where value is just greater than A[i]
       j=find_index(A[i], B, i, M-1);
       cout<<"Value of j"<<j<<endl;
       if(j==-1)continue; 
       //call function to find the index in C where value is just greater than B[j]
       k=find_index(B[j], C, j, N-1);
       cout<<"Value of k"<<k<<endl;
       if(k==-1)continue; 
       count=count+(N-k);
       cout<<"Count for this iteration"<<count<<endl;
    }
    return count;
}
*/

int triplets(long long A[], long long B[], long long C[], int L, int M, int N){
    int count=0, i, j, k;
    for(j=0; j<M; j++){
        cout<<"Value of j"<<j<<endl;
        i=find_index(B[j], A, 0, j);
        cout<<"Value of i"<<i<<endl;
        if(i!=-1){
            k=find_index(B[j], C, j, N-1);
            cout<<"Value of k"<<k<<endl;
            if(k!=-1){
                count=count+(N-k);
                cout<<"Value of k"<<k<<endl;
            }
        }
    }

    return count;

}

int main() {
    int T, N, L, M;
    cin>>T;
    for (int i=0; i<T; i++){
        cin>>L;
        long long A[L];
        for(int j=0; j<L; j++){           
            cin>>A[j]; 
        }
        
        cin>>M;
        long long B[M];
        for(int j=0; j<M; j++){           
            cin>>B[j]; 
        }
        
        cin>>N;
        long long C[N];
        for(int j=0; j<N; j++){           
            cin>>C[j]; 
        }
        
        cout<<triplets(A, B, C, L, M, N);
    }
    
    return 0;
}

