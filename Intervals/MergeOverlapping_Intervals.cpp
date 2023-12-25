#include<bits/stdc++.h>
using namespace std;

//Brute force Approach
//Time complexity:O(nlogn)+O(2n);
//Space complexity:O(n) for storing the answer
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(intervals[j][0]<=end){
                end=max(end,intervals[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}


//Optimal Approach
//Time complexity:O(nlogn)+O(n);
//Space complexity:O(n) for storing the answer
vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans=merge_intervals(intervals);
    return 0;
}