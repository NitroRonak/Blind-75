#include<bits/stdc++.h>
using namespace std;

//Binary Search
int findMin(vector<int>& nums) {
    int start=0;
    int ans=INT_MAX;
    int end=nums.size()-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(nums[start]<=nums[mid]){
            ans=min(ans,nums[start]);
            start=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            end=mid-1;
        }
        
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<findMin(nums)<<endl;
    return 0;
}