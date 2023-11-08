#include<bits/stdc++.h>
using namespace std;
//problem statement:
// Given an integer array nums, find the 
// subarray with the largest sum, and return its sum.

//Better Approach
//Time Complexity:O(n^2)
//Space Complexity:O(1) 
int maxSubArray(vector<int>& nums) {
    long long maxSum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        long long sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

//Optimal Solution
//Time Complexity:O(n)
//Space Complexity:O(1)
int maxSubArray_OptimalSolution(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
    int maxSum=INT_MIN;
    int sum=0;
    for(int i=0;i<nums.size();i++){
       sum+=nums[i];
       maxSum=max(maxSum,sum);
       if(sum<0) sum=0;
    }
    return maxSum;
}
int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    cout<<maxSubArray_OptimalSolution(nums)<<endl;
    return 0;
}