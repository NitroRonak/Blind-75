#include<bits/stdc++.h>
using namespace std;

//approach 1
//Time Complexity:O(n*m)
//Space Complexity:O(n)+O(m)
void setToZeros(vector<vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> Row(n);
    vector<int> Col(m);
    for(int i = 0; i < n;i++){
        for(int j=0; j < m;j++){
            if(matrix[i][j]==0){
                Row[i]=1;
                Col[j]=1;
            }
        }
    }
    for(int i = 0; i < n;i++){
        for(int j=0; j < m;j++){
            if(Row[i]==1 || Col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
}

//approach 2
//Time Complexity:O(n*m)
//Space Complexity:O(1)
void setToZeros(vector<vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int col=1;
    for(int i = 0; i < n;i++){
        for(int j=0; j < m;j++){
            if(matrix[i][j]==0){
                //mark i-th row
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col=0;
                }
            }
        }
    }
    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i = 0; i < n;i++){
        for(int j=0; j < m;j++){
            cin>>matrix[i][j];
        }
    }
    setToZeros(matrix);
    for(int i = 0; i < n;i++){
        for(int j=0; j < m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}