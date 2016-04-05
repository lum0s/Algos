#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int n, low, high; 
    long long int mid;
    cin>>n;
    low=0;
    long long p=pow(10,9);
    high=(n<p) ?n :p;
    while((high-low)>1){
        mid=(high+low)/2;
        if((mid*mid)<n){
            low=mid;
        }   
        else{
            high=mid;
        }
    }
    cout<<high;
    return 0;
}

