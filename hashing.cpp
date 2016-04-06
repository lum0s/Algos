#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int main(){
    int a,b;
    string str, temp;
    map<string, int> bag;
    cin>>a>>b;
    for (int i=0; i<a; i++){
        cin>>temp;
        for(int l=0; l<temp.size(); l++){
            for (int j=0, k=0; j<temp.size(); j++){
                if(j==l)
                    continue;
                k++;
                str[k]=temp[j];
            }
            bag[str]=1;
        }
    }
        
    for (int i=0; i<b; i++){
        cin>>temp;
        for(int l=0; l<temp.size(); l++){
            for (int j=0, k=0; j<temp.size(); j++){
                if(j==l)
                    continue;
                k++;
                str[k]=temp[j];
            }
            if(bag.find(str)==bag.end())
                cout<<"NO";
            else
                cout<<"YES";
                
        }
    }
    return 0;
}
