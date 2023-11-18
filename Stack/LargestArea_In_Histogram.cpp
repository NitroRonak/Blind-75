#include<bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> &nums){
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i = 0; i < nums.size();i++){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        int res=st.empty()?-1:st.top();
        ans[i]=res;
        st.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> &nums){
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i = nums.size()-1; i >= 0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        int res=st.empty()?nums.size():st.top();
        ans[i]=res;
        st.push(i);
    }
    return ans;
}
int largestArea(vector<int> height){
    vector<int> ps=prevSmaller(height);
    vector<int> ns=nextSmaller(height);
    int maxArea=0;
    for(int i=0;i<height.size();i++){
        int area=(ns[i]-ps[i]-1)*height[i];
        maxArea=max(maxArea,area);
    }
    return maxArea;
}
int main()
{
    vector<int> height{2,4};
    cout<<largestArea(height)<<endl;
    return 0;
}