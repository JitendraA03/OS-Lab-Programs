#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
  int maxi=max(a,b);
  while(1){
    if(maxi%a==0 && maxi%b==0)
    return maxi;
    else
    maxi++;
  }
}
struct process {
	int exe,period,priority,exe1,period1;
	char c;
};
 bool period(process p1,process p2){
	return p1.period<p2.period;
}
bool priorit(process p1,process p2){
  return p1.priority<p2.priority;
}
int main(){
    int n,i,j;
    struct process p[100];
    cout<<"Enter the number of processes:";
    cin>>n;
     for(i=0;i<n;i++){
        cout<<"Enter the execution time and period for "<<i+1<<" process:";
        cin>>p[i].exe>>p[i].period;
      }
      sort(p,p+n,period);
      for(i=0;i<n;i++){
           p[i].c=char(97+i);
           p[i].exe1=p[i].exe;
           p[i].period1=p[i].period;
           p[i].priority=p[i].period;
          }
      int ma=p[0].period;
      for(i=1;i<n;i++){
        ma=lcm(ma,p[i].period);
      }
      int time=0,k=0,count;
      vector<char> c;
      while(time<ma){
        for(j=0;j<n;j++){
          if(time==p[j].period){
            p[j].exe1=p[j].exe;
           
            p[j].period+=p[j].period1;
             p[j].priority=p[j].period;
              sort(p,p+n,priorit);
          }
          }
      
        if(p[0].exe1==0){
         p[0].priority=1000+time;
          sort(p,p+n,priorit);
          count=0; 
          for(i=0;i<n;i++){
              if(p[i].exe1==0)
              count++;
          }
          if(count==n)
           c.push_back('0');
           else{
           c.push_back(p[0].c);p[0].exe1--;}
        }
        else{
             p[0].exe1--;
             c.push_back(p[0].c);
        }
        time++;
        }
        cout<<"Gantt chart order:"<<endl;
        int sum=0;
        for(i=0;i<ma;i++){
            cout<<c[i]<<" ";
            if(c[i]!='0')
            sum++;
        }
        double per=(double)sum/ma;
        cout<<"\nCPU utilisation is:"<<per;
        
    }