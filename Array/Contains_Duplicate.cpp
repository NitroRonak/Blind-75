#include<bits/stdc++.h>
using namespace std;
//Problem Statement:
// Given an integer array nums, return true if any value appears at least 
// twice in the array, and return false if every element is distinct.

//Brute force approach
//Time Complexity: O(n^2)
//Space Complexity: O(1)
bool containsDuplicate(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int count=0;
        for(int j=i;j<nums.size();j++){
            if(nums[i]==nums[j]){
                count++;
            }
            if(count>=2){
                return true;
            } 
        }
    }
    return false;
}

//Optimal solution
//Time Complexity: O(n)
//Space Complexity: O(n)
bool containsDuplicate_Optimal(vector<int>& nums) {
    set<int> s;
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i])!=s.end()){
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<containsDuplicate(nums)<<endl;
    cout<<containsDuplicate_Optimal(nums)<<endl;
    return 0;
}