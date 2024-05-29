// https://leetcode.com/problems/fraction-to-recurring-decimal/

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
  int numerator = 2, denominator = 1;

  string ans;

  long n = numerator;
  long d = denominator;

  if (n * denominator < 0) {
    ans.push_back('-');
  }

  n = abs(n);
  d = abs(d);

  ans += to_string(n / d);

  if (n % d == 0) {
    cout << ans << endl;
    return 0;
  }

  ans.push_back('.');

  long remainder = n % d;
  n = remainder * 10;

  unordered_map<long, int> map;

  while (remainder != 0) {
    if (map.find(remainder) == map.end()) {
      ans += to_string((n) / d);
      map.insert({remainder, ans.length() - 1});
    } else {
      int index = map.find(remainder)->second;
      ans.insert(index, "(");
      ans.push_back(')');
      break;
    }
    remainder = n - (d * (n / d));
    n = remainder * 10;
  }

  cout << ans << endl;
}