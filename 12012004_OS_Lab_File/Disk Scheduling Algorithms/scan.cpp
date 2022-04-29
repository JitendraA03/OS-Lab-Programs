#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,ele,head,s=0,last;
    char ch;
    cout<<"Enter the number of blocks for I/O request:";
    cin>>n;
    cout<<"Enter the value of head cylinder:";
    cin>>head;
    cout<<"Enter the movement of disk arm,enter l for left and r for right:";
    cin>>ch;
    cout<<"Enter the value of last cylinder covered by disk arm:";
    cin>>last;
    cout<<"Enter the value of each cylinder:";
    vector<int> q;
    for(i=0;i<n;i++){
       cin>>ele;
       q.push_back(ele);
    }
    sort(q.begin(),q.end());
    if(ch=='l'){
        cout<<"Total cylinder movement:"<<head+q[n-1];
    }
    else
    cout<<"Total cylinder movement:"<<last-head+q[0];
    
}