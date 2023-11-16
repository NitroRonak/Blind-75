#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty() || matrix[0].empty()) {
        return ans;
    }
    int top = 0, left = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; ++i) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        // Traverse right column
        for (int i = top; i <= bottom; ++i) {
            ans.push_back(matrix[i][right]);
        }
        right--;
        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<int> ans=spiralOrder(matrix);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}