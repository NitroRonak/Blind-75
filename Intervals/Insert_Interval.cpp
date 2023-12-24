#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Time complexity:O(n^2);
void insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
   int i=0;
   while(i<intervals.size()){
       if(intervals[i][1]<newInterval[0]){
           i++;
       }
       else if(intervals[i][0]>newInterval[1]){
           intervals.insert(intervals.begin()+i,newInterval);
           return;
       }
       else{
           newInterval[0]=min(newInterval[0],intervals[i][0]);
           newInterval[1]=max(newInterval[1],intervals[i][1]);
           intervals.erase(intervals.begin()+i);
       }
   }
   intervals.push_back(newInterval);
}

//optimal approach
//Time complexity:O(n);
vector<vector<int>> insert_Optimal(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int i=0;
    vector<vector<int>> result;
    int n=intervals.size();
    while(i<n){
        //interval where we are standing its ending
        //point less than new interval starting point
        //push the current interval to result array
        if(intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
        }
        //interval where we are standing its starting
        //point greater than new interval ending point
        else if(intervals[i][0]>newInterval[1]){
            break;
        }
        //merge the interval
        else{
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
        }
        i++;
    }
    result.push_back(newInterval);
    while(i<n){
        result.push_back(intervals[i]);
        i++;
    }
    return result; 
}
int main()
{
    vector<vector<int>> intervals{{1,3},{6,9}};
    vector<int> newIntervals{2,5};
    insert(intervals,newIntervals);
    for(int i=0;i<intervals.size();i++){
        for(int j=0;j<intervals[i].size();j++){
            cout<<intervals[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}