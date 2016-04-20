#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair <int,int> > graph[100000];
int vis[100000];


void make_graph(){
	int a,b, wt,n,m;
	pair<int,int> temp1;
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin >> a >> b >> wt;
		temp1.first=wt;
		temp1.second=b;
		graph[a].push_back(temp1);
        temp1.first=wt;
		temp1.second=a;
		graph[b].push_back(temp1);
	}

}




int prim(){
    int source, current_node, dist,next_node, minimum_distance, sum=0;
	pair<int,int> temp1;
	priority_queue< pair<int,int> > q;

	for(int i=0; i<100000; i++)
        vis[i]=0;

    cin>>source;
    temp1.first=0;
    temp1.second=source;
    q.push(temp1);
    while(!q.empty()){
        temp1=q.top();
        q.pop();
        if(vis[temp1.second]==0){
            current_node=temp1.second;
            sum+=-temp1.first;
//            cout<<"yoyo"<<-temp1.first<<temp1.second<<endl;
            vis[temp1.second]=1;
            for(auto neighbour : graph[current_node]){
                temp1.first=-neighbour.first;
                temp1.second=neighbour.second;
                if (vis[neighbour.second]==0){
                    q.push(temp1);
//                    cout<<-temp1.first<<temp1.second<<endl;

                    }
                }
        }
}
    return sum;
}



int main(){

	make_graph();
	cout<<prim();

	return 0;
}
