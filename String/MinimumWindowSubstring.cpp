#include<bits/stdc++.h>
using namespace std;

//Problem Statement
// Given two strings s and t of lengths m and n respectively, 
// return the minimum window substring of s such that every 
// character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.

string minWindow(string s, string t) {
        int l=0,r=0,n=s.length(),m=t.length(),miniWindow=INT_MAX;
        int start_i=0;
        map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }   
        int count=mp.size();
        for(;r<n;r++){
            mp[s[r]]--;
            if(mp[s[r]]==0){
                count--;
            }
            while (count == 0) {
                int currentWindow = r - l + 1;
                miniWindow = min(miniWindow, currentWindow);
                start_i = (miniWindow == currentWindow) ? l : start_i;

                mp[s[l]]++;
                if (mp[s[l]] > 0) count++;
                l++;
            }

        }
        return miniWindow==INT_MAX?"":s.substr(start_i,miniWindow);
    }
int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t)<<endl;
    return 0;
}