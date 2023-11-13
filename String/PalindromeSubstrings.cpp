#include<bits/stdc++.h>
using namespace std;
//Problem Statement
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

int t[1001][1001];   
bool solve(string &s, int l, int r){
    if(l >= r) 
        return 1;
    if(t[l][r] != -1){
        return t[l][r];
    }
    if(s[l] == s[r]) {
        return t[l][r] = solve(s, l+1, r-1);
    }
    return t[l][r] = false;
}
int countSubstrings(string s) {
    int n = s.length();
    int count=0;
    int maxlen = INT_MIN;
    int startingIndex = 0;
    memset(t, -1, sizeof(t));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            
            if(solve(s, i, j)) {
                count++;
            }
            
        }
    }
    return count;   
}

//----------------------------------------------------------------
int countSubstrings(string s) {
    int n = s.length();
    int count = 0;

    // Create a 2D vector to store whether substrings are palindromic or not
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
        count++;
    }

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
            count++;
        }
    }

    // Check substrings of length 3 or more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
                count++;
            }
        }
    }

    return count;
}
int main()
{
    string s;
    cin>>s;
    cout<<countSubstrings(s)<<endl;
    return 0;
}