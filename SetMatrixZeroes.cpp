// https://leetcode.com/problems/set-matrix-zeroes/

// The idea is that we can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero. This means for every cell instead of going to M+NM+N cells and setting it to zero we just set the flag in two cells.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// int main() {
//   vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

//   int flag;
//   unordered_set<int> set;
//   for (int i = 0; i < matrix.size(); i++) {
//     flag = 0;
//     for (int j = 0; j < matrix[0].size(); j++) {
//       if (matrix[i][j] == 0) {
//         flag = 1;
//         set.insert(j);
//       }
//     }
//     if (flag) {
//       for (int k = 0; k < matrix[0].size(); k++) {
//         matrix[i][k] = 0;
//       }
//     }
//   }
//   for (auto it = set.begin(); it != set.end(); it++) {
//     for (int i = 0; i < matrix.size(); i++) {
//       matrix[i][*it] = 0;
//     }
//   }
//   for (int i = 0; i < matrix.size(); i++) {
//     for (int j = 0; j < matrix[0].size(); j++) {
//       cout << matrix[i][j] << " ";
//     }
//     cout << endl;
//   }
// }

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

  int firstRowZero = 0;
  int firstColZero = 0;

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
        if (i == 0)
          firstRowZero = 1;
        if (j == 0)
          firstColZero = 1;
      }
    }
  }

  // rows
  for (int i = 1; i < matrix.size(); i++) {
    if (matrix[i][0] == 0) {
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[i][j] = 0;
      }
    }
  }

  // cols
  for (int i = 1; i < matrix[0].size(); i++) {
    if (matrix[0][i] == 0) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][i] = 0;
      }
    }
  }

  if (firstRowZero) {
    for (int i = 0; i < matrix[0].size(); i++) {
      matrix[0][i] = 0;
    }
  }
  if (firstColZero) {
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i][0] = 0;
    }
  }

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}