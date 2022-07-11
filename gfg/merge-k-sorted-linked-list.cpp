// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

/* Function to print nodes in a given linked list */
void printList(Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

};
*/

class Solution {
 public:
  // Function to merge K sorted linked list.
  Node *mergeKLists(Node *arr[], int k) {
    typedef pair<int, Node *> p;
    priority_queue<p, vector<p>, greater<p>> heap;

    for (int i = 0; i < k; i++) {
      heap.push(make_pair(arr[i]->data, arr[i]));
    }

    Node *start = NULL;
    Node *curr = NULL;

    while (!heap.empty()) {
      pair<int, Node *> x = heap.top();
      heap.pop();

      if (!start) {
        start = new Node(x.first);
        curr = start;
      } else {
        curr->next = new Node(x.first);
        curr = curr->next;
      }

      if (x.second->next) {
        heap.push(make_pair(x.second->next->data, x.second->next));
      }
    }

    return start;
  }
};

// { Driver Code Starts.
// Driver program to test above functions
int main() {
  int N;
  cin >> N;
  struct Node *arr[N];
  for (int j = 0; j < N; j++) {
    int n;
    cin >> n;

    int x;
    cin >> x;
    arr[j] = new Node(x);
    Node *curr = arr[j];
    n--;

    for (int i = 0; i < n; i++) {
      cin >> x;
      Node *temp = new Node(x);
      curr->next = temp;
      curr = temp;
    }
    Solution obj;
    Node *res = obj.mergeKLists(arr, N);
    printList(res);
  }

  return 0;
}
// } Driver Code Ends