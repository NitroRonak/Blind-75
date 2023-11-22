#include<bits/stdc++.h>
using namespace std;

//Recursion approach
//Time complexity:O(2^n*2^m);
//Space complexity:O(n+m);
int solve(int i,int j,string s1,string s2){
    if(i<0 || j<0) return 0;
    if(s1[i]==s2[j]){
        return 1+solve(i-1,j-1,s1,s2);
    }
    else{
        return max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    int n=text1.length();
    int m=text2.length();
    return solve(n-1,m-1,text1,text2);        
}

//Memoization approach
//Time complexity:O(n*m);
//Space complexity:O(n*m)+O(n+m);
int solve_Memoization(int i,int j,string s1,string s2,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=1+solve_Memoization(i-1,j-1,s1,s2,dp);
    }
    else{
        return dp[i][j]=max(solve_Memoization(i-1,j,s1,s2,dp),solve_Memoization(i,j-1,s1,s2,dp));
    }
}
int longestCommonSubsequence_Memoization(string text1, string text2) {
    int n=text1.length();
    int m=text2.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve_Memoization(n-1,m-1,text1,text2,dp);        
}

//Tabulation approach
//Time complexity:O(n*m)
//complexity: O(n*m)
int longestCommonSubsequence_Tabulation(string text1, string text2){
    int n=text1.length();
	int m=text2.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main()
{
    string s1="abc";
    string s2="def";
    cout<<longestCommonSubsequence_Memoization(s1,s2)<<endl;
    return 0;
}