#include<bits/stdc++.h>
using namespace std;

// Given an integer n, return an array ans of length n + 1 such 
// that for each i (0 <= i <= n), ans[i] is the number of 1's 
// in the binary representation of i.

// Example 1:
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

//Time complexity of this approach is O(n*log(m))
//space complexity is O(1)
vector<int> countBits(int n) {
    vector<int> ans;
        for (int i = 0; i <= n; i++) {
        int count = 0;
        int num = i;
        while (num != 0) {
            num = num & (num - 1);
            count++;
        }
        ans.push_back(count);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = countBits(n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}