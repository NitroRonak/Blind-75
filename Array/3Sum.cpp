#include<bits/stdc++.h>
using namespace std;
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


vector<vector<int>> find_3SumArrays(vector<int> a){
    set<vector<int>> st;
    for(int i=0;i<a.size();i++){
        set<int> hashset;
        for(int j=i+1;j<a.size();j++){
            int k=-(a[i]+a[j]);
            if(hashset.find(k)!=hashset.end()){
                vector<int> temp={a[i],a[j],k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
// Reason: Here, we are mainly using 3 nested loops. And 
// inserting triplets into the set takes O(log(no. of unique triplets)) 
// time complexity. But we are not considering the time complexity 
// of sorting as we are just sorting 3 elements every time.

// Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.

//----------------------------------------------------------------
//optimal solution
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
            else if(sum<0) j++;
            else k--;
        }
    }
    return ans;
}
//Time complexity: O(n^2)+nlog(n);
//space complexity: O(1) if we dont consider the ans vector beacuse we are only using that return ans
int main()
{
    return 0;
}