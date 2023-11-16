#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
    // Check if current position is out of bounds or the character doesn't match
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
        return false;
    }

    // Check if the entire word is found
    if (k == word.length() - 1) {
        return true;
    }

    // Mark the current cell as visited
    char tmp = board[i][j];
    board[i][j] = ' ';

    // Explore neighboring cells in DFS order (up, down, left, right)
    bool found = dfs(board, word, i - 1, j, k + 1) ||
                 dfs(board, word, i + 1, j, k + 1) ||
                 dfs(board, word, i, j - 1, k + 1) ||
                 dfs(board, word, i, j + 1, k + 1);

    // Restore the original value of the cell
    board[i][j] = tmp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();

    // Iterate through each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the first character matches, start DFS from this cell
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}