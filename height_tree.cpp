#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> adjlist[100000];
int s[100001]={};
int max1=0, min1=100000;

void dfs(int parent, int current, int current_height){
//    cout<<current<<adjlist[current].size()<<endl;
    for(int i=0; i<adjlist[current].size(); i++){
        if(adjlist[current][i]==parent)
            continue;
//        cout<<"aba"<<endl;
        dfs(current, adjlist[current][i], current_height+1);
    }
//    cout<<"yo"<<endl;
    if(adjlist[current].size()==1 && adjlist[current][0]==parent){
//        s[current]=current_height;
 //       cout<<current_height<<endl;
        if(current_height<min1)min1=current_height;
        if(current_height>max1)max1=current_height;
    }
}

int main() {
  int n,r,a,b;  
    cin>>n>>r;
//    cout<<s[0]<<endl;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
//    cout<<s[0]<<endl;

    dfs(0, r, 1);
/*    int min=100000, highest=1;
    for(int i=1; i<100; i++){
        if(s[i]<min && s[i]!=0)min=s[i];
        if(s[i]>s[highest])highest=i;
    }
    */
  //  cout<<s[highest]<<" "<<min;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<max1<<" "<<min1;
    return 0;
}

