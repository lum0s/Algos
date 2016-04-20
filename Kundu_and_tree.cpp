#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<set>
using namespace std;

    long long int a[100000],size[100000],n,sum=0;
    set <long long int> p;
    set <long long int>::iterator it;

//Initializing the array for the disjoint union set.
void initialize (){
    for(long long int i=0; i<=n; i++){
        a[i] = i ;
        size[i]= 1;
    }
}

//finding root of an element.
long long int root(long long int i){
    while(a[i]!= i){           //chase parent of current element until it reaches root.
        i=a[i];

    }
    return i;
}

/*union function where we connect the elements by changing the root of one of the element */
void union1(long long int A, long long int B){
    long long int root_A = root(A);
    long long int root_B = root(B);
    a[root_A] = root_B;       //setting parent of root(A) as root(B).
}

/*union function to connect two sets based on the size of the sets*/
void weighted_union1(long long int A,long long int B){
    long long int root_A = root(A);
    long long int root_B = root(B);
    if(size[root_A] < size[root_B ]){
        a[root_A] = a[root_B];
        size[root_B] += size[root_A];
    }

    else{
        a[ root_B ] = a[root_A];
        size[root_A] += size[root_B];
    }

}

bool find(long long int A,long long int B){
    if(root(A)==root(B))       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}

void input(){
	long long int x,y;
    char wt;
	for (long long int i=0; i<n-1; i++){
		cin >> x >> y >> wt;
		if(wt=='b'){
            weighted_union1(x,y);
        }
    }
}


long long int no_of_elements(){
    long long int sum=0, sum1=0, sum2=0;
    for(it=p.begin(); it!=p.end();++it){
        long long int big=size[*it];
        sum1+=(big*(big-1)*(big-2))/6;
        sum2+=((big*(big-1))/2)*(n-big) ;
    }
    cout<<sum1<<" "<<sum2<<" "<<(n*(n-1)*(n-2)/6)<<endl;
    sum=(n*(n-1)*(n-2)/6)-sum1-sum2;
    cout<<sum<<endl<<sum%1000000007<<endl;
    return sum;
}


int main() {
    cin>>n;
    initialize();
    input();
    for (long long int i=1; i<=n; i++){
        p.insert(root(i));
    }
    cout<<(no_of_elements())%(1000000007);
    return 0;
}
