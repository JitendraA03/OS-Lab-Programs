#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,ele,head,s=0,r;
    cout<<"Enter the number of blocks for I/O request:";
    cin>>n;
    cout<<"Enter the value of head pointed by disk arm:";
    cin>>head;
    cout<<"Enter the value of each block:";
    vector<int> q;
    for(i=0;i<n;i++){
       cin>>ele;
       q.push_back(ele);
    }
    q.push_back(head);
    sort(q.begin(),q.end());
    for(i=0;i<q.size();i++){
        if(q[i]==head){
           r=i;
           break;
        }
    }
    while(!q.empty()){
        if(r==0){
            s+=q[q.size()-1]-q[0];
            break;
            
        }
        else if(r==q.size()-1){
            s+=q[r]-q[0];
            break;
        }
        else if(abs(q[r]-q[r+1]) < abs(q[r]-q[r-1]))
        {
            s+=q[r+1]-q[r];
            q.erase(q.begin()+r);
            
        }
        else{
              s+=q[r]-q[r-1];
            q.erase(q.begin()+r);
            r--;

        }


    }
    
    cout<<"Total head movement of cylinders:"<<s; 
}