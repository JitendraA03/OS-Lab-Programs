#include<bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &s){
    s[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i : adj[src]){
            if(!visited[i] and iscycle(i,adj,visited,s))
            return true;
        
        if(s[i])
        return true;
    }}
    s[src]=false;
    return false;
}
int main(){
    int n,r,i,l,j;
    int x,y;
    cout<<"Enter number of processes:";
    cin>>n;
    cout<<"Enter number of different single instance resoureces:";
    cin>>r;
    vector<vector<int>> adj(n+r);
     while(1){
        cout<<"Enter the value of request edge:";
        cin>>x>>y;
        adj[x].push_back(y);
        cout<<"Enter 0 if all values are assigned to request edge else enter 1:";
        cin>>l;
        if(l==0)
        break;
    }
     while(1){
        cout<<"Enter the value of assignment edge:";
        cin>>x>>y;
        adj[x].push_back(y);
        cout<<"Enter 0 if all values are assigned to request edge else enter 1:";
        cin>>l;
        if(l==0)
        break;
    }
    cout<<"In adjacency list all numbers from 0 to "<<n-1<<" represents process and numbers from "<<n<<" to "<<n+r-1<<" represents resources"<<endl;
    cout<<"Processes requesting for resources"<<endl;
     for(i=0;i<n;i++){
        cout<<i<<"->";
        for(j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Resources assigned to resources"<<endl;
     for(i=n;i<n+r;i++){
        cout<<i<<"->";
        for(j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    bool c=false;
    vector<int> s(n+r,0);
    vector<bool> visited(n+r,false);
    for(i=0;i<n+r;i++){
    if(!visited[i] && iscycle(i,adj,visited,s))
    c=true;}
    if(c)
    cout<<"Deadlock is present";
    else
    cout<<"Deadlock is absent";
}