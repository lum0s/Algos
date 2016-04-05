#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair <int,int> > graph[101];
int distanc[101];


void make_graph(){
	int a,b, p[101],m, n;
    for(int i=0; i<=100; i++)
        p[i]=0;
	pair<int,int> temp1;
	
	cin>>n;
	for (int i=0; i<n; i++){
		cin >> a >> b;
        p[a]=1;
		temp1.first=0;
		temp1.second=b;
		graph[a].push_back(temp1);
	}

    cin>>m;
	for (int i=0; i<m; i++){
		cin >> a >> b;
        p[a]=-1;
		temp1.first=0;
		temp1.second=b;
		graph[a].push_back(temp1);
	}
 //   int count=0;
 /*
    for(int i=1; i<100 && p[i]==0; i++){
        for(int j=i+1; j<=i+6 && i+j<=100; j++){
            if(p[j]==1){
                temp1.first=1;
		        temp1.second=graph[j][0].second;
		        graph[i].push_back(temp1);                  
            }
            else if(p[j]==-1){
                temp1.first=1;
		        temp1.second=graph[j][0].second;
		        graph[i].push_back(temp1);                
            }
            else{
                temp1.first=1;
		        temp1.second=j;
		        graph[i].push_back(temp1);                
            }
        }//count++;
    }*/
    for(int i=1; i<100; i++){
    	if(p[i]==0)
    	for(int j=i+1; j<=i+6 && j<=100; j++){
    		temp1.first=1;
			temp1.second=j;
			graph[i].push_back(temp1); 
		}
    }
    //cout<<count;
}


void dijkstra(int source){

	int current_node, dist,next_node, minimum_distance;
	pair<int,int> temp1;
	priority_queue< pair<int,int> > q;

	for(int i=1; i<=100; i++)
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




int main(){
    
    int T=1, source;
 //   cin>>T;
    while(T!=0){
       make_graph();
	   dijkstra(1);
       T--;
       
    }
    cout<<distanc[100]<<endl;
	return 0;
}

