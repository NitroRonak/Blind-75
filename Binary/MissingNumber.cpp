#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int sum=n*(n+1)/2;
    int sum1=0;
    for(int i:nums){
        sum1+=i;
    }
    return sum-sum1;
}
int main()
{
    vector<int> nums={3,0,1};
    cout<<missingNumber(nums)<<endl;
    return 0;
}