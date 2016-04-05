/* Kruskal's Algorithm
Used to find the minimal spanning tree out of a graph. I have used a priority queue to sort the edges in ascending order. Subsequently used a Disjoint set union to find the mst. */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

//Initializing the array for the disjoint union set.

void initialize (int Arr[], int N){
    for(int i=0; i<N; i++){
        Arr[i] = i ;
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


bool find(int Arr[], int A,int B){
    if(root(Arr,A)==root(Arr,B))       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}


int main() {
    int N,M,x,y,z, p, sum=0, a[100000];
    priority_queue<pair<int, pair<int,int> > > q;
    pair<int, pair<int, int> > temp;
    initialize(a, 100000);
    cin>>N>>M;
    
    //Putting all elements in the priority queue.
    for(int i=0; i<M; i++){
        cin>>x>>y>>z;
        temp.first=-z;
        temp.second.first=x;
        temp.second.second=y;  
        q.push(temp);
    }
    cin>>p;
    
    //Pop each edge from the queue, check if both vertices are in the mst or not. If not, then add the edge to the mst.
    
    while(!q.empty()){
        temp=q.top();
        q.pop();
    
        if(find(a, (temp.second.first), (temp.second.second))==false){
            union1(a, temp.second.first, temp.second.second);
            sum = sum - temp.first;
        }   
    }
    cout<<sum;
    return 0;
}