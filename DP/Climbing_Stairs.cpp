#include<bits/stdc++.h>
using namespace std;

//Time Complexity:O(2^n)
//space complexity:O(n);
// int climbStairs(int n) {
//     if(n==0 || n==1) return 1;
//     int l=climbStairs(n-1);
//     int r=climbStairs(n-2);
//     return l+r;        
// }

//Tabulation approach:
int climbStairs(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        int l=dp[i-1];
        int r=dp[i-2];
        dp[i]=l+r;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    return 0;
}