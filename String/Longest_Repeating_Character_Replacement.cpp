#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int n=s.length();
    int l=0;
    int r=0;
    int ans=0;
    int maxCount=0;
    unordered_map<char,int> charCount;
    for(;r<n;r++){
        // Update the count of the current character in the window
        charCount[s[r]]++;
        // Update the maximum count of repeating characters
        maxCount=max(maxCount,charCount[s[r]]);
         // Check if the window size can be expanded to cover more repeating characters
        while((r-l+1)-maxCount>k){
            charCount[s[l]]--;
            l++;
        }
        ans=max(ans,r-l+1);
    }
    return ans;
}
int main()
{
    string s;
    int k;
    cin>>s>>k;
    cout<<characterReplacement(s,k)<<endl;
    return 0;
}