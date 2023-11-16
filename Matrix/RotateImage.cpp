#include<bits/stdc++.h>
using namespace std;


//Time Complexity : O(2(n*m))
//Space Complexity: O(1)
void rotate2(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++){
        for(int j=i;j<matrix[0].size();j++){
            int temp=0;
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size()/2;j++){
            int temp=0;
            temp=matrix[i][j];
            matrix[i][j]=matrix[i][matrix.size()-1-j];
            matrix[i][matrix.size()-1-j]=temp;
        }
    }
}

//approach 2
//Time Complexity:O(n*m);
//Space Complexity:O(1)
void rotate1(vector<vector<int>> &matrix){
    int n=matrix.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[n-1-j][i];
            matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
            matrix[j][n-1-i]=temp;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    rotate1(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}