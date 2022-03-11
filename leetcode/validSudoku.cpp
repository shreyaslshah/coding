// https://leetcode.com/problems/valid-sudoku/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<vector<char>> board{{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  typedef unordered_set<int> set;
  typedef tuple<set, set, set> vec;
  typedef unordered_map<char, vec> map;

  map table;
  int bigDibbaCount = 1;
  int smolDibbaCount = 1;

  for (int row = 1; row <= board.size(); row++) {
    for (int col = 1; col <= board[0].size(); col++) {
      if (board[row - 1][col - 1] == '.') {
        if (smolDibbaCount % 27 == 0) {
          bigDibbaCount++;
        } else if (smolDibbaCount % 9 == 0) {
          bigDibbaCount -= 2;
        } else if (smolDibbaCount % 3 == 0) {
          bigDibbaCount++;
        }
        smolDibbaCount++;
        continue;
      }

      if (get<0>(table[board[row - 1][col - 1]]).find(row) == get<0>(table[board[row - 1][col - 1]]).end()) {
        get<0>(table[board[row - 1][col - 1]]).insert(row);
      } else {
        cout << row << " " << col << endl;
        cout << "false";
        return 0;
      }
      if (get<1>(table[board[row - 1][col - 1]]).find(col) == get<1>(table[board[row - 1][col - 1]]).end()) {
        get<1>(table[board[row - 1][col - 1]]).insert(col);
      } else {
        cout << row << " " << col << endl;
        cout << "false";
        return 0;
      }
      if (get<2>(table[board[row - 1][col - 1]]).find(bigDibbaCount) == get<2>(table[board[row - 1][col - 1]]).end()) {
        get<2>(table[board[row - 1][col - 1]]).insert(bigDibbaCount);
      } else {
        cout << row << " " << col << endl;
        cout << "false";
        return 0;
      }

      if (smolDibbaCount % 27 == 0) {
        bigDibbaCount++;
      } else if (smolDibbaCount % 9 == 0) {
        bigDibbaCount -= 2;
      } else if (smolDibbaCount % 3 == 0) {
        bigDibbaCount++;
      }
      smolDibbaCount++;
    }
  }
  cout << "true";
}



// solution

// Three flags are used to check whether a number appear.

// used1: check each row   [row][the number]
// used2: check each column    [column][the number]
// used3: check each sub-boxes    [box][the number]

// class Solution {
//  public:
//   bool isValidSudoku(vector<vector<char>> &board) {
//     int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

//     for (int i = 0; i < board.size(); ++i)
//       for (int j = 0; j < board[i].size(); ++j)
//         if (board[i][j] != '.') {
//           int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
//           if (used1[i][num] || used2[j][num] || used3[k][num])
//             return false;
//           used1[i][num] = used2[j][num] = used3[k][num] = 1;
//         }

//     return true;
//   }
// };