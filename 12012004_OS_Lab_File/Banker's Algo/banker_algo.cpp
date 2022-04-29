#include<iostream>
using namespace std;

int* sum2D(int**arr,int rows,int cols)/* Passing a 2-D array and Passing number of rows and columns*/
{
    //Created a function to find summ of allocated resources
// We will use this sum later to subtract it from total resources and then finding available resources
int*sum=new int[cols]; // cols=Number of resources , rows= number of processes
for(int i=0;i<cols;i++){
    sum[i]=0;
}
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        sum[j] +=arr[i][j]; // Here sum[j] represents the sum of resources 
    }
}
return sum;
};

bool compareArray(int *arr1, int *arr2 , int n1, int n2){
    //arr1= need array , arr2= available array
    if(n1!=n2){
        return false;
    }
   for(int i=0;i<n1;i++){
       if(arr1[i]>arr2[i]){
           return false;
       }
   }
   return true;
}


int main(){
    int num_of_res;//Taking number of resources as input
    cout<<"Enter number of resources: ";
    cin>>num_of_res;

    int*total_res=new int[num_of_res];//Taking total  instances of resources present as input
    for(int i=0; i<num_of_res;i++){
        cout<<"Enter total for R: "<<i+1<<":";
        cin>>total_res[i];
    }
    int num_of_processes;//Taking number of processes as input
    cout<<"Enter number of processes: ";
    cin>>num_of_processes;

    cout<<"Enter Allocated resources: ";
    int** allocated = new int* [num_of_processes];// created 2-D array where num of processes are rows
    for(int i=0; i< num_of_processes; i++)//and resources are column
    {
        allocated[i]=new int [num_of_res];
    }
    for(int i=0; i< num_of_processes; i++){// for loop for entering values in 2D array
        for(int j=0; j<num_of_res;j++){
    cout<<"Enter amount of R"<<j+1<<"allocated to P"<<i+1<<":";
    cin>>allocated[i][j];
        }
    }
  cout<<"Enter max resources: ";//created 2-D array for max need of resources
  int** max=new int* [num_of_processes];
  for(int i=0; i<num_of_processes;i++){
      max[i]=new int[num_of_res];
  }
  //Entering value for max need array now
  for(int i=0;i<num_of_processes;i++){
      for(int j=0;j<num_of_res;j++){
          cout<<"Enter max amount of R"<<j+1<<"Allocated to P"<<i+1<<":";
          cin>>max[i][j];
      }
  }
 int* totalAllocated= new int[num_of_res];
 totalAllocated= sum2D(allocated,num_of_processes,num_of_res);
int* available = new int[num_of_res];
for(int i=0; i<num_of_res;i++){
    available[i]=total_res[i]-totalAllocated[i];
}
//Now finding need i.e. max-allocated
int **need = new int* [num_of_processes];
for(int i=0;i<num_of_processes;i++){
need[i]=new int[num_of_res];
}
//Entering Values now
for(int i=0;i<num_of_processes;i++){
    for(int j=0;j<num_of_res;j++){
        need[i][j]=max[i][j]-allocated[i][j];
    }
 }
 int *safe_state=new int[num_of_processes];
 int state_index=0;
 bool compare=true;
 bool is_terminated;
 while(compare){
     compare=false;
 for(int i=0;i<num_of_processes;i++){
     is_terminated=false;
     for(int j=0;j< state_index;j++){// checking whether current process is already terminated
       if(state_index==i){
           is_terminated=true;
       }
     }
     if(!is_terminated){
         if(compareArray(need[i], available , num_of_res,num_of_res)){
        safe_state[state_index]=i;
        state_index++;
        for(int j=0; j<num_of_res;j++){
            available[j]+=allocated[i][j];// when process is terminated then allocated resources will be added to available.
        }
        compare=true;
         }
         
     
 }
 }
}
cout<<"\nSafe state: ";
 for(int i=0;i<state_index;i++){
     cout<<"P"<<safe_state[i]+1<<"\t";
 }
if(num_of_processes==state_index){
    cout<<"\nSystem not in deadlock";
}
 else{
    cout<<"Deadlock occured";
}}


