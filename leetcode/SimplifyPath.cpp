//  https://leetcode.com/problems/simplify-path/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
  string path = "";

  deque<string> qu;

  int i = 0;
  string str = "";
  while (i < path.length()) {
    while (path[i] == '/') {
      i++;
    }
    if (i != path.length()) {
      str = "";
      while (path[i] != '/' && i != path.length()) {
        str.push_back(path[i]);
        i++;
      }
      if (str == ".") {
      } else if (str == "..") {
        if (!qu.empty()) {
          qu.pop_back();
        }
      } else if (str != "") {
        qu.push_back(str);
      }
    }
  }

  string ans = "";

  if(qu.empty()){
    cout<<"/";
  }

  for (auto it = qu.begin(); it != qu.end(); ++it)
    ans = ans + "/" + *it;

  cout << ans;
}
