#include<bits/stdc++.h>
using namespace std;

//Time Complexity:O(nlogn);
//Space Complexity:O(1);
bool isAnagram(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i=0;i<s.length();i++){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true; 
}

//Optimize approach 
//Time Complexity:O(n);
//Space Complexity:O(n);
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false; 
    }
    unordered_map<char,int> mp;
    for(int i=0;i<t.length();i++){
        mp[t[i]]++;
    }
    for(int i=0;i<s.length();i++){
        mp[s[i]]--;
    }
    for(auto it:mp){
        if(it.second>0){
            return false;
        }
    }
    return true;
}
int main()
{
    string s="anagram";
    string t="nagaram";
    cout<<isAnagram(s,t)<<endl;
    return 0;
}