#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,ele,head,s=0;
    cout<<"Enter the number of blocks for I/O request:";
    cin>>n;
    cout<<"Enter the number of head number:";
    cin>>head;
    cout<<"Enter the number of each cylinder:";
    queue<int> q;
    for(i=0;i<n;i++){
        cin>>ele;
        q.push(ele);
    }
    while(!q.empty()){
        int r=q.front();
        s+=abs(r-head);
        head=r;
        q.pop();
    }
    cout<<"Total head movement of cylinders:"<<s; 
}