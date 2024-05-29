// https://leetcode.com/problems/spiral-matrix/submissions/


// answer worked on leetcode but not on gfg

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int c = matrix[0].size();
  int r = matrix.size();
  vector<int> ans;
  int rowElements = c;
  int colElements = r;
  int i = 0;
  int j = 0;

  while (ans.size() != (r * c)) {

    // for when only a single element has to be added, we will end up popping it and enter an infinite loop, so just add it and return the ans
    if(rowElements ==1 and colElements ==1){
      ans.push_back(matrix[i][j]);
      return ans;
    }

    for (int a = 0; a < rowElements; a++) {
      ans.push_back(matrix[i][j]);
      j++;
    }
    j--;
    ans.pop_back();

    for (int a = 0; a < colElements; a++) {
      ans.push_back(matrix[i][j]);
      i++;
    }
    i--;
    ans.pop_back();

    for (int a = 0; a < rowElements; a++) {
      ans.push_back(matrix[i][j]);
      j--;
    }
    j++;
    ans.pop_back();

    for (int a = 0; a < colElements; a++) {
      ans.push_back(matrix[i][j]);
      i--;
    }
    i++;
    ans.pop_back();

    rowElements -= 2;
    colElements -= 2;
    i++;
    j++;
  }

  // for single line matrices
  while(ans.size()>(r*c)){
    ans.pop_back();
  }
  return ans;
}

int main() {
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> arr = spiralOrder(mat);
  for (auto x : arr)
    cout << x << " ";
}