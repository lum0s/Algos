#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> adjlist[10000];
int status[10000];
int visited[10000];

bool dfs(int current, int color){

	visited[current]=1;

	if(status[current]==-1){
		status[current]=color;
	}

	for(int i=0; i<adjlist[current].size(); i++)
		if(visited[adjlist[current][i]]!=1){
			if(dfs(adjlist[current][i], (color==1)?0:1)==false)
				return false;
		}
		else{
			if(status[adjlist[current][i]]==color)
				return false;
		}

	return true;


}

int main(){
	int n,a,b;
	for(int i=0; i<10000; i++){
	status[i]=-1;
	visited[i]=0;
}
	cin>>n;
	for(int i=0; i<n;i++){
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	bool check = dfs(1,1);
	if(check==false){
		cout<<"Not a bipartite graph";
	}
	else if(check==true)
		cout<<"Bipartite graph";
	return 0;
}