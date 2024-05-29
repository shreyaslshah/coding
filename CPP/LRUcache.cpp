// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
 private:
  list<int> ll;
  unordered_map<int, pair<int, list<int>::iterator>> map;
  int capacity;

 public:
  // Constructor for initializing the cache capacity with the given value.
  LRUCache(int cap) {
    capacity = cap;
  }

  // Function to return value corresponding to the key.
  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    } else {
      auto it = map[key].second;
      ll.erase(it);
      ll.push_back(key);
      map[key].second = --ll.end();
      return map[key].first;
    }
  }

  // Function for storing key-value pair.
  void set(int key, int value) {
    if (map.find(key) != map.end()) {
      auto it = map[key].second;
      ll.erase(it);
      ll.push_back(key);
      map[key] = make_pair(value, --ll.end());
    } else if (map.find(key) == map.end() and map.size() == capacity) {
      map.erase(ll.front());
      ll.erase(ll.begin());
      ll.push_back(key);
      map[key] = make_pair(value, --ll.end());
    } else if (map.find(key) == map.end() and map.size() != capacity) {
      ll.push_back(key);
      map[key] = make_pair(value, --ll.end());
    }
  }
};

// { Driver Code Starts.

int main() {
  int capacity;
  cin >> capacity;
  LRUCache *cache = new LRUCache(capacity);

  int queries;
  cin >> queries;
  while (queries--) {
    string q;
    cin >> q;
    if (q == "SET") {
      int key;
      cin >> key;
      int value;
      cin >> value;
      cache->set(key, value);
    } else {
      int key;
      cin >> key;
      cout << cache->get(key) << " ";
    }

    cout << endl;
  }
  return 0;
}
// } Driver Code Ends