#include<bits/stdc++.h>
using namespace std;

//approach 1 using recursion
int solve(int i,vector<int> &coins,int amount){
    //not take
    if(i == 0){
        if(amount%coins[i]==0){
            return amount/coins[i];
        }
        else{
            return 1e9;
        }
    }
    int notTake=0+solve(i-1,coins,amount);
    int take;
    if(coins[i]<=amount){
        take=1+solve(i,coins,amount-coins[i]);
    }
    return min(take,notTake);
}
int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    return solve(n-1, coins, amount);        
}

//approach 2 using memoization
int solve_memoization(int i,vector<int> &coins,int amount,vector<vector<int>> &dp){
    //not take
    if(i == 0){
        if(amount%coins[i]==0){
            return amount/coins[i];
        }
        else{
            return 1e9;
        }
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int notTake=0+solve_memoization(i-1,coins,amount,dp);
    int take=INT_MAX;
    if(coins[i]<=amount){
        take=1+solve_memoization(i,coins,amount-coins[i],dp);
    }
    return dp[i][amount]= min(take,notTake);
}
int coinChange_memoization(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
    int ans= solve_memoization(n-1, coins, amount,dp);
    if(ans>=1e9) return -1;
    else return ans;
            
}

//Tabulation approach :
int coinChange_Tabulation(vector<int> &coins, int amount){
    int n=coins.size();
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0) dp[0][i]=i/coins[0];
        else dp[0][i]=1e9; 
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<=amount;t++){ 
            int notTake=0+dp[i-1][t];
            int take=INT_MAX;
            if(coins[i]<=t){
                take=1+dp[i][t-coins[i]];
            }
            dp[i][t]= min(take,notTake);
        }
    }
    int ans=dp[coins.size()-1][amount];
    if(ans>=1e9) return -1;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cin>>amount;
    cout<<coinChange_Tabulation(coins,amount)<<endl;
    return 0;
}