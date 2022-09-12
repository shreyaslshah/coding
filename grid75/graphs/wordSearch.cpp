// https://leetcode.com/problems/word-search/

#include <bits/stdc++.h>
using namespace std;

// TLE but correct
class Solution {
 public:
  bool isValid(int i, int j, vector<vector<char>>& board) {
    return (i >= 0 and j >= 0 and i < board.size() and j < board[0].size());
  }
  void dfs(int i, int j, unordered_set<int> visited, string word, vector<vector<char>>& board, int wordIdx, bool* ans) {
    if (*ans == true) return;
    visited.insert((i)*board[0].size() + (j));
    if (wordIdx == word.size()) {
      *ans = true;
      return;
    }
    if (isValid(i + 1, j, board) and board[i + 1][j] == word[wordIdx] and visited.find((i + 1) * board[0].size() + (j)) == visited.end() and *ans==false) {
      dfs(i + 1, j, visited, word, board, wordIdx + 1, ans);
    }
    if (isValid(i - 1, j, board) and board[i - 1][j] == word[wordIdx] and visited.find((i - 1) * board[0].size() + (j)) == visited.end() and *ans==false) {
      dfs(i - 1, j, visited, word, board, wordIdx + 1, ans);
    }
    if (isValid(i, j + 1, board) and board[i][j + 1] == word[wordIdx] and visited.find((i)*board[0].size() + (j + 1)) == visited.end() and *ans==false) {
      dfs(i, j + 1, visited, word, board, wordIdx + 1, ans);
    }
    if (isValid(i, j - 1, board) and board[i][j - 1] == word[wordIdx] and visited.find((i)*board[0].size() + (j - 1)) == visited.end() and *ans==false) {
      dfs(i, j - 1, visited, word, board, wordIdx + 1, ans);
    }
  }
  bool exist(vector<vector<char>>& board, string word) {
    for (int a = 0; a < board.size(); a++) {
      for (int b = 0; b < board[0].size(); b++) {
        if (board[a][b] == word[0]) {
          int wordIdx = 1;
          unordered_set<int> visited;
          bool ans = false;
          dfs(a, b, visited, word, board, wordIdx, &ans);
          if (ans) {
            return ans;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};

  cout << s.exist(board, "ABCESEEEFS") << endl;
}