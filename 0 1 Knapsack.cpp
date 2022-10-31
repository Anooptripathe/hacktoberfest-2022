#include<iostream>
#include<vector>
using namespace std;

int solveMem(vector<int>&weight , vector<int>&value ,int index , int capacity,vector<vector<int>>dp){
 // approach brute force 
// take subsets and find the sum and their max
    
// base case 
// if only onre item to steal , the just compare the wieghts

if(index == 0){
    if(weight[0]<= capacity){
        return value[0];
    }
    else{
        return 0;
    }
}
if(dp[index][capacity] != -1){
    return dp[index][capacity];
}



int include = 0;
if(weight[index]<=capacity){
     include = value[index] + solveMem(weight,value ,index-1 ,capacity-weight[index],dp);

}

int exclude = 0 + solveMem(weight,value,index-1,capacity,dp);

dp[index][capacity]= max(exclude,include);

return dp[index][capacity];


}



int main(){
    
   vector<int>weights;
   vector<int>values;

   int capacity;
   cout<<"Enter the capacity: "<<endl;
   cin >> capacity;


   int n ; 
   cout<<"enter the no. of items"<<endl;
   cin>>n;

cout<<"ENter the values for weights"<<endl;
for(int i = 0 ; i < n;i++){
    int a;
    cin>>a;
    weights.push_back(a);
}

cout<<"ENter the values for values"<<endl;
for(int i = 0 ; i < n;i++){
    int a;
    cin>>a;
    values.push_back(a);
}
cout<<endl;

// ////////////////////////////////////

vector<vector<int>> dp(n,vector<int>(capacity+1,-1));

cout<< solveMem(weights,values ,n-1 ,capacity,dp)<<endl;
    return 0;
}
