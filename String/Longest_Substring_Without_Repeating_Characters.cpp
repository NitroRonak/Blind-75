#include<bits/stdc++.h>
using namespace std;
//Problem Statement:
//Longest Substring Without Repeating Characters

//Time Complexity : O(n);
//space Complexity : O(n);
int lengthOfLongestSubstring(string str){
    int l=0,r=0,n=str.length()-1,ans=0;
    unordered_map<char,int> map;
    for(;r<n;r++){
        map[str[r]]++;
        while(map[str[r]]>1){
            map[str[l]]--;
            l++;
        }
        ans=max(ans,r-l+1);
    }
    return ans;
}
int main()
{
    string str="pwwkew";
    cout<<lengthOfLongestSubstring(str)<<endl;
    return 0;
}