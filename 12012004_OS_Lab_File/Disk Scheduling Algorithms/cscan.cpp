#include<bits/stdc++.h>
using namespace std;
int movtoleft(vector<int> q,int head){
    for(int i=0;i<q.size();i++){
        if(q[i]>head)
        return q[i];
    }
}
int movtoright(vector<int> q,int head){
    for(int i=0;i<q.size();i++){
        if(q[i]<head)
        return q[i];
    }
}
int main(){
    int n,i,ele,head,s=0,last,left=0,right=0;
    char ch;
    cout<<"Enter the number of blocks for I/O request:";
    cin>>n;
    cout<<"Enter the value of head cylinder:";
    cin>>head;
    cout<<"Enter the value of last cylinder covered by disk arm:";
    cin>>last;
    cout<<"Enter the movement of disk arm,enter l for left and r for right:";
    cin>>ch;
    cout<<"Enter the value of each cylinder:";
    vector<int> q;
    for(i=0;i<n;i++){
       cin>>ele;
       q.push_back(ele);
    }
    sort(q.begin(),q.end());
    if(ch=='l'){
        left=head+last+head-movtoleft(q,head);
        cout<<"Total cylinder movement:"<<left;
    }
    else{
        right=last+last-head+movtoright(q,head);
         cout<<"Total cylinder movement:"<<right;

    }
   
    
}