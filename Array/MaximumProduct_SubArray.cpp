#include<bits/stdc++.h>
using namespace std;

//Time Complexity : O(n^2)
//space complexity:O(1);
int maxProduct(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
    int maxProduct=INT_MIN;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int product=1;
            for(int k=i;k<=j;k++){
                product*=nums[k];
            }
            maxProduct=max(maxProduct,product);
        }
    }
    return maxProduct;
}

//Optimal Solution
//Time Complexity : O(n)
//space complexity:O(1);
int maxProduct_OptimalSolution(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
    int maxProduct=INT_MIN;
   
    int preffix=1,suffix=1;
    for(int i=0;i<nums.size();i++){
        if(preffix==0) preffix=1;
        if(suffix==0) suffix=1;
        preffix*=nums[i];
        suffix*=nums[nums.size()-i-1];
        maxProduct=max(maxProduct,max(preffix,suffix));
    }
    return maxProduct;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxProduct_OptimalSolution(nums)<<endl;
    return 0;
}