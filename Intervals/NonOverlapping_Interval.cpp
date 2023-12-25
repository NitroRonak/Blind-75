#include<bits/stdc++.h>
using namespace std;
// Given an array of intervals intervals where intervals[i] = 
// [starti, endi],return the minimum number of intervals 
// you need to remove to make the rest of the intervals non-overlapping.

// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

 


//Time complexity:O(nlogn)+O(n);
//space complexity:O(1)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(begin(intervals),end(intervals));
    int cnt=0;
    int i=0;
    int j=1;
    int n=intervals.size();
    while(j<n){
        vector<int> curr_interval=intervals[i];
        vector<int> next_interval=intervals[j];
        int cs=curr_interval[0];
        int ce=curr_interval[1];
        int ns=next_interval[0];
        int ne=next_interval[1];
        if(ce<=ns){ //non overlapping
            i=j;
            j++;
        }
        else if(ce<=ne){ // overlapping
            j++;
            cnt++;
        }
        else if(ce>ne){ //overlapping
            i=j;
            j++;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    return 0;
}