#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair <int,int> > graph[100];
int distanc[100], n;


void make_graph(){
	int a,b, wt;
	pair<int,int> temp1;
	cin>>n;
	for (int i=0; i<n; i++){
		cin >> a >> b >> wt;
		temp1.first=wt;
		temp1.second=b;
		graph[a].push_back(temp1);
		temp1.first=wt;
		temp1.second=a;
		graph[b].push_back(temp1);
	}

}


void dijkstra(){

int source, current_node, dist,next_node, minimum_distance;
	pair<int,int> temp1;
	priority_queue< pair<int,int> > q;

	for(int i=0; i<100; i++)
		distanc[i]=-1;

	cin>>source;
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


int main(){

	make_graph();
	dijkstra();

	for(int i = 0; i < n; i += 1) {
		cout << distanc[i] << " ";
	}
	cout << endl;

	return 0;
}
