//merging communities hackerrank disjoint-set.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

    int a[100000],size[100000];

//Initializing the array for the disjoint union set.
void initialize (int Arr[], int size[], int N){
    for(int i=0; i<N; i++){
        Arr[i] = i ;
        size[i]= 1;
    }
}

//finding root of an element.
int root(int Arr[],int i){
    while(Arr[i]!= i){           //chase parent of current element until it reaches root.
        i=Arr[i];

    }
    return i;
}

/*union function where we connect the elements by changing the root of one of the element */
void union1(int Arr[], int A, int B){
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    Arr[root_A] = root_B;       //setting parent of root(A) as root(B).
}

/*union function to connect two sets based on the size of the sets*/
void weighted_union1(int Arr[],int size[],int A,int B){
    int root_A = root(a,A);
    int root_B = root(a,B);
    if(size[root_A] < size[root_B ]){
        Arr[root_A] = Arr[root_B];
        size[root_B] += size[root_A];
    }

    else{
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }

}

bool find(int Arr[], int A,int B){
    if(root(Arr,A)==root(Arr,B))       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}


int main() {
    int n,q,x,y,s;
    char ch;
    cin>>n>>q;
    initialize(a,size,n);
    for (int i=0; i<q; i++){
        cin>>ch;
        if (ch=='M'){
            cin>>x>>y;
            if(!find(a,x,y))
                weighted_union1(a,size,x,y);
        }
        else if(ch=='Q'){
            cin>>s;
            cout<<size[root(a,s)]<<endl;
        }
    }
    return 0;
}
