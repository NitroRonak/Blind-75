#include<bits/stdc++.h>
using namespace std;
//Memoization
//Time Complexity :O(n*m)
//space Complexity :O(n*m)+O(n)  
int solve(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
    if(i==nums.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int include=0;
    if(prev==-1 || nums[i]>nums[prev]){
        include=1+solve(i+1,i,nums,dp);
    }
    int exclude=0+solve(i+1,prev,nums,dp);
    return dp[i][prev+1]=max(include,exclude);
}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return solve(0,-1,nums,dp);
}

//Another approach
//Time Complexity :O(n*log(k))
//space Complexity :O(n) n is the size of ans vector
int lengthOfLIS_2(vector<int>& nums) {
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>ans.back()) ans.push_back(nums[i]);
        else{
            auto ind=lower_bound(ans.begin(),ans.end(),nums[i]);
            *ind=nums[i];
        }
    }
    return ans.size();
}
int main()
{
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS_2(nums)<<endl;
    return 0;
}