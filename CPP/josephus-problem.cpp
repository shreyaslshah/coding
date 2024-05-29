// https://practice.geeksforgeeks.org/problems/josephus-problem/1

// { Driver Code Starts
// Initial Template for C

#include <stdio.h>

// } Driver Code Ends
// User function Template for C

int solve(int n, int k) {
  if (n == 1) return 0;

  return (solve(n - 1, k) + k)%(n);
}

int josephus(int n, int k)
{
   return solve(n, k) + 1;
}



// { Driver Code Starts.

int main() {
  int n, k;
  scanf("%d%d", &n, &k);  // taking input n and k

  // calling josephus() function
  printf("%d\n", josephus(n, k));

  return 0;
}  // } Driver Code Ends