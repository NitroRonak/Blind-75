#include<bits/stdc++.h>
using namespace std;
//Problem Statement:
// Given an integer array nums, return an array answer such that answer[i] 
// is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and 
// without using the division operation.

//Brute force approach:
//Time Complexity: O(n^2)
//Space Complexity: O(1) if we do not consider ans vector
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        long long product=1;
        for(int j=0;j<nums.size();j++){
            if(j==i) continue;
            product*=nums[j];
        }
        ans.push_back(product);
    }
    return ans;
}


//optimal approach:
//Time Complexity: O(n)
//Space Complexity: O(1) if we do not consider product vector
vector<int> productExceptSelf_OptimalApproach(vector<int>& nums) {
    int n=nums.size();
    vector<int> product(n);
    product[0]=1;
    for(int i=1;i<nums.size();i++){
        product[i]=product[i-1]*nums[i-1];
    }
    int temp=1;
    for(int i=nums.size()-2;i>=0;i--){
        product[i]*=nums[i+1]*temp;
        temp*=nums[i+1];
    }
    return product;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=productExceptSelf_OptimalApproach(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}