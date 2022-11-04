// https://leetcode.com/problems/lru-cache/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
  list<int> dll;
  unordered_map<int, pair<int, list<int>::iterator>> map;
  int cap;

  LRUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    auto it = map.find(key);
    if (it == map.end()) {
      return -1;
    }
    dll.erase((*it).second.second);
    dll.push_back(key);
    auto dllIterator = dll.end();
    dllIterator--;
    map[key] = make_pair((*it).second.first, dllIterator);
    return (*it).second.first;
  }

  void put(int key, int value) {
    auto it = map.find(key);
    if (it != map.end()) {
      dll.erase((*it).second.second);
      dll.push_back(key);
      auto dllIterator = dll.end();
      dllIterator--;
      map[key] = make_pair(value, dllIterator);
    } else {
      if (map.size() == cap) {
        int x = dll.front();
        dll.pop_front();
        map.erase(x);
      }
      dll.push_back(key);
      auto dllIterator = dll.end();
      dllIterator--;
      map[key] = make_pair(value, dllIterator);
    }
  }
};

int main() {
}