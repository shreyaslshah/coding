// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1#

// we are storing two values in each stack element. the value itself and the value of the new min element if it was popped off.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  int minEle;
  stack<int> s;

 public:
  /*returns min element from stack*/
  int getMin() {
    if (s.empty()) {
      return -1;
    } else {
      return minEle;
    }
  }

  /*returns poped element from stack*/
  int pop() {
    if (s.empty()) {
      return -1;
    } else {
      int temp = s.top();
      s.pop();
      if (s.empty()) {
        return temp;
      } else {
        minEle = temp % 1000;
        return temp / 1000;
      }
    }
  }

  /*push element x into the stack*/
  void push(int x) {
    if (s.empty()) {
      minEle = x;
      s.push(x);
    } else {
      if (x < minEle) {
        int temp = x;
        x = x * 1000 + minEle;
        minEle = temp;
        s.push(x);
      } else {
        x = x * 1000 + minEle;
        s.push(x);
      }
    }
  }
};

// { Driver Code Starts.

int main() {
  int q;
  cin >> q;
  Solution ob;
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      // push
      int att;
      cin >> att;
      ob.push(att);
    } else if (qt == 2) {
      // pop
      cout << ob.pop() << " ";
    } else if (qt == 3) {
      // getMin
      cout << ob.getMin() << " ";
    }
  }
  cout << endl;

  return 0;
}
// } Driver Code Ends