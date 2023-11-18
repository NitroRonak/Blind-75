#include<bits/stdc++.h>
using namespace std;
//approach 1
//Time Complexity:O(n^2)
//Space Complexity:O(1)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for(auto c:nums1){
        int next=0;
        for(int j=0;j<nums2.size();j++){
            if(nums2[j]==c){
                break;
            }
            next++;
        }
        bool isNext=false;
        for(int k=next;k<nums2.size();k++){
            if(nums2[k]>c){
                isNext=true;
                ans.push_back(nums2[k]);
                break;
            }
        }
        if(!isNext){
            ans.push_back(-1);
        }
    }
    return ans;
}

//approach 2
//Time Complexity:O(n)
//Space Complexity:O(n)
vector<int> NextGreater(vector<int> nums1,vector<int> nums2){
    stack<int> st;
    unordered_map<int,int> ump;
    vector<int> ans;
    for(int i = nums2.size()-1; i >=0;i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }
        int res=st.empty() ? -1 : st.top();
        ump[nums2[i]]=res;
        st.push(nums2[i]);
    }
    for(int it:nums1){
        ans.push_back(ump[it]);
    }
    return ans;
}
int main()
{
    vector<int> nums1{4,2,1};
    vector<int> nums2{1,2,3,4};
    vector<int> ans=NextGreater(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}