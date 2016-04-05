#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair <int,int> > graph[100005];
int distanc[100005], n;

void dijkstra(int source){

	int current_node, dist,next_node, minimum_distance;
	pair<int,int> temp1;
	priority_queue< pair<int,int> > q;

	for(int i=0; i<n+2; i++)
		distanc[i]=-1;

	temp1.first=0;
	temp1.second=source;
	q.push(temp1);

	while(!q.empty()){
		temp1=q.top();
		q.pop();		
		current_node=temp1.second;
		minimum_distance=-temp1.first;

		if(distanc[current_node]==-1){
			distanc[current_node]=minimum_distance;					

			for(auto neighbour : graph[current_node]){
				dist=neighbour.first;
				next_node=neighbour.second;

				if(distanc[next_node]==-1){
					temp1.first=-(dist+minimum_distance);
					temp1.second=next_node;
					q.push(temp1);
				}
			}
		}
	}

}


/* 
We are modifying the graph as we go along. Using the standard graph, we first the shortest path from base to every other element. Now we create a new node and connect this node to every element in 'a' with the weight equal to the shortest path of that element from base. So in a way we are substituting the root with the new node.

Then we apply dijkstra using this new node as source. 

Next we create a new node and connect all elements in b with this node with weight equal to the shortest path from the previously created node to that element in 'b'. 

Next we apply dijkstra from this new node to the final point. 

In a way we again substituted the previous node with this new node. 

*/


void make_graph(){
    int m,a,b,u,v,w, j;
    pair<int,int> temp;
    cin>>n>>m>>a>>b;
    int first[n], second[n];
    
    for (int i=0; i<a; i++)
        cin>>first[i];
    
    for(int i=0; i<b; i++)
        cin>>second[i];
    
   
    for (int i=0; i<m; i++){
        cin>>u>>v>>w;
        temp.first=w;
        temp.second=v;
        graph[u].push_back(temp);
        temp.second=u;
        graph[v].push_back(temp);
    }
    
    dijkstra(0);
    
    for(int j=0; j<a; j++){
        temp.first=distanc[first[j]];
        temp.second=first[j];
        graph[n].push_back(temp);
    }
    
    dijkstra(n);
    
    for (int j=0; j<b; j++){
        temp.first=distanc[second[j]];
        temp.second=second[j];
        graph[n+1].push_back(temp);        
    }
    
    dijkstra(n+1);
    cout<<distanc[n-1];
}

int main(){
    make_graph();
	return 0;
}


