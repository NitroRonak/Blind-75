#include<bits/stdc++.h>
using namespace std;
// Given an array of meeting time intervals consisting of start 
// and end times [[s1,e1],[s2,e2],...] (si < ei), 
// determine if a person could attend all meetings.

bool canAttendMeetings(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    for(int i=1;i<intervals.size();i++){
        vector<int> i1=intervals[i-1];
        vector<int> i2=intervals[i];
        if(i1[1]>i2[0]) return false;

    }
    return true;
}
int main()
{
    vector<vector<int>> intervals{{5,8},{9,15}};
    cout<<canAttendMeetings(intervals)<<endl;
    return 0;
}