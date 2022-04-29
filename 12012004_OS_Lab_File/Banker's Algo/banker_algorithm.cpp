#include<bits/stdc++.h>
using namespace std;

int main()
{
    //taking input
    
    int n, m ;
    cout<<"Enter the number of process : ";
    cin>>n;
    
    cout<<"Number of type of resources : ";
    cin>>m;
    
    vector<int>Available(m , 0); // resources available initially
    vector<vector<int>>Max(n , vector<int>(m , 0)); // max needs of a process
    vector<vector<int>>alloc(n , vector<int>(m , 0)); // resources alloc to a process
    vector<vector<int>>Need(n , vector<int>(m , 0)); // need of a resource
    
    cout<<"\n\nEnter the resources allocated to each process\n\n";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Process "<<i+1<<" : ";
        for(int j = 0 ; j < m ; j++)
            cin>>alloc[i][j];
    }
    
    cout<<"\n\nMax resources needed by each process\n\n";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Process "<<i+1<<" : ";
        for(int j = 0 ; j < m ; j++)
        {
            cin>>Max[i][j];
            Need[i][j] = Max[i][j] - alloc[i][j];
        }
    }
    
    cout<<"\n\nResources Available : ";
    for(int i=0;i<m;i++)
    cin>>Available[i];
    
    vector<int>Work(Available.begin() , Available.end()); // work = available
    vector<bool>Finish(n , false); // finish[i] = false , means ith process is not completed yet
    
    string str = ""; // safe sequence
    
    while(true)
    {
        bool find = false;
        
        for(int i=0;i<n;i++)
        {
            if(Finish[i]==false)
            {
                bool f = true;
                for(int j = 0 ; j < m ; j++) //checking if we can meet the needs of ith process
                {
                    if(Need[i][j] > Work[j])
                    {f = false ; break;}
                }
                
                if(f) // means this process can be executed
                {
                    find = true;
                    str+=to_string(i); // adding process in our safe seq.
                    Finish[i] = true;
                    for(int j = 0 ; j < m ; j++)
                    {
                        Work[j]+=alloc[i][j]; // taking back the resources after successful exec.
                    }
                }
            }
        }
        
        if(!find) // we did not find any process whose needs can be completed
        break;
    }
    
    if(str.size()==n)
    {
        cout<<"\n\nSafe sequence is : ";
        for(auto k : str)
        {
            cout<<"P"<<k<<"->";
        }
    }
    
    else
    {
        cout<<"\n\nSystem not in safe state\nNo safe sequence exist";
    }
    
    return 0;
};