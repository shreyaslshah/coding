// https://leetcode.com/problems/fruit-into-baskets/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

  int x = 0;
  int best = 0;
  int current = 0;
  unordered_map<int, int> map;

  for (int i = 0; i < fruits.size(); i++) {
    if (map.count(fruits[i]) == 0 && map.size() < 2) {
      map[fruits[i]] = 1;
      current++;
    } else if (map.count(fruits[i])) {
      map[fruits[i]]++;
      current++;
    } else if (map.count(fruits[i]) == 0 && map.size() == 2) {
      map.erase(fruits[x - 1]);
      map[fruits[x]] = i - x;
      map[fruits[i]] = 1;
      current = i - x + 1;
    }
    if (fruits[x] != fruits[i]) {
      x = i;
    }
    best = max(best, current);
  }

  cout << best << endl;
}