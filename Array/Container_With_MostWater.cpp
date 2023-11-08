#include<bits/stdc++.h>
using namespace std;
//Problem Statement:
// You are given an integer array height of length n. There are n 
// vertical lines drawn such that the two endpoints of the ith 
// line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, 
// such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

//Optimal solution
//Time Complexity:O(n)
//Space Complexity:O(1)
int maxArea(vector<int>& height) {
    int l=0;
    int r=height.size()-1;
    int maxWaterContainer=0;
    while(l<r){
        int lh=height[l];
        int rh=height[r];
        int min_h=min(lh,rh);
        maxWaterContainer=max(maxWaterContainer,min_h*(r-l));
        if(lh<rh) l++;
        else r--;
    }
    return maxWaterContainer;
}
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height)<<endl;
    return 0;
}