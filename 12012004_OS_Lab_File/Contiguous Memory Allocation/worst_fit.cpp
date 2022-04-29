#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j,c,k,q,p;
    cout<<"Enter the number of blocks and number of processes:";
    cin>>n>>m;
    vector<int> block(n),process(m),res;
    vector<bool> flag(n,false);
    cout<<"Enter the number of blocks which are already occupied:";
    cin>>q;
    if(q>0){
    cout<<"Enter the values of blocks which are occupied:";
    for(i=0;i<q;i++){
        cin>>p;
        flag[p-1]=true;
    }}
    cout<<"Enter the block sizes for "<<n<<" blocks:";
    for(i=0;i<n;i++){
        cin>>block[i];
    }
    cout<<"Enter the process sizes for "<<m<<" processes:";
     for(i=0;i<m;i++){
        cin>>process[i];
    }
   
    for(i=0;i<m;i++){
        c=-1;
        k=INT_MIN;
        for(j=0;j<n;j++){
           if(process[i]<=block[j] && block[j]>k){
           c=j;
           k=block[j];
        }}
        res.push_back(c);
        if(c!=-1)
        block[c]-=process[i];
         
    }
     cout<<"Block number 0 will indicate that process cannot be allocated"<<endl;
    for(i=0;i<m;i++){
        cout<<"Process "<<i+1<<" will be at block number:"<<res[i]+1<<endl;
    }
}