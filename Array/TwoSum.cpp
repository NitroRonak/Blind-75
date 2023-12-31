#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int temp=target-nums[i];
        if(mp.find(temp)!=mp.end()){
           return {mp[temp],i};             
        }
        mp[nums[i]]=i;
    }
    return {-1,-1};
}
int main()
{
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}