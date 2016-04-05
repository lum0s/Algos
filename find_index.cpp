#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//function to find out the index of the number just greater than or equal to the selected number in the passed array.
int find_index(long long num, long long temp[], int l, int h){
    int mid;
    
    if(num<temp[l])
        return -2;
    
    else if(num>temp[h])
        return -3;   

    else{
        while(h-l>=0){
            mid=(l+h)/2;
            if (num>temp[mid]){
                l=mid+1;
            }

            else if(num<temp[mid]){
                h=mid-1;
            }

            else if(temp[mid]==num)
                return mid;

        }       
        if(h-l==-1)
            return l;
        else return -10;
    }
}



int main(){
    int n;
    cout<<"input the len of the array"<<endl;
    cin>>n;
    long long A[n];
    for(int i=0; i<n; i++)
        cin>>A[i];
    long long num;
    char ch='y';
    for(int i=0; i<n-1; i++)cout<<A[i]<<" ";
    cout<<endl;
    while(ch=='y') {
        cout<<"Enter number to find the index ";
        cin>>num;
        cout<<find_index(num, A, 0, n-1);
        cout<<"input again ";
        cin>>ch;
    }
    return 0;
}
