#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v[100000];

void input(){
    int n,a,b;
    cin>>n;
    for(int i=1; i<n;i++){
        cin>>a>>b;        
        v[a].push_back(b);
    }
}

/*
While on a particular level, we sum all the v[current].size() values so that we get the number of elements in the next level. Then we save it in the b_count variable. Now while on a level, we decrement the b_count variable, every time we pop an element. When b_count becomes 0 we know that we have to go on to the next level. 

Now since we have distinguished between levels, rest is simple mathematics.
*/

void bfs(){
    queue<int> q;
    int source, current,count=0, b_count=1,a=0, sum=0;
    source=1;
    q.push(source);
    while(!q.empty()){
        current=q.front();
        q.pop();
        
        if(b_count!=0){
            count = count + v[current].size();
            a=a^current;
        }
        
        b_count--;
        
        if(b_count==0){
            b_count=count;
            count=0;           
            sum=sum+a;
            a=0;
        }
        
        for (int i=0; i<v[current].size(); i++){
            q.push(v[current][i]);
        }
    }
    cout<<sum;
}
int main() {
    input();   
    bfs();
    return 0;
}

