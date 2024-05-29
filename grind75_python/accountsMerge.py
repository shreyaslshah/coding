# https://leetcode.com/problems/accounts-merge/description/

from typing import List


class Solution:
  def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
    ans = []
    email_acc = dict()
    visited = [False for _ in range(len(accounts))]

    # consider each name to be an account number
    # create a mapping for email to the account
    for i in range(len(accounts)):
      for j in range(1, len(accounts[i])):
        email = accounts[i][j]
        if email in email_acc:
          email_acc[email].append(i)
        else:
          email_acc[email] = [i]

    def dfs(i, emails):
      visited[i] = True
      for email_idx in range(1, len(accounts[i])):
        email = accounts[i][email_idx]
        emails.add(email)
        for account in email_acc[email]:
          if not visited[account]:
            dfs(account, emails)

    for i in range(len(accounts)):
      if not visited[i]:
        emails = set()
        dfs(i, emails)
        ans.append([accounts[i][0]] + sorted(emails))

    return ans


s = Solution()
print(s.accountsMerge([["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["John",
      "johnsmith@mail.com", "john00@mail.com"], ["Mary", "mary@mail.com"], ["John", "johnnybravo@mail.com"]]))
