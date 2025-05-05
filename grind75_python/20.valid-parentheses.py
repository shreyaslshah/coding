#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
# https://leetcode.com/problems/valid-parentheses/description/

# @lc code=start
class Solution:
  def isValid(self, s: str) -> bool:
    stack = []
    for char in s:
      if char == '(' or char == '{' or char == '[':
        stack.append(char)
      elif char == ')':
        if stack and stack[-1] == '(':
          stack.pop()
        else:
          return False
      elif char == '}':
        if stack and stack[-1] == '{':
          stack.pop()
        else:
          return False
      elif char == ']':
        if stack and stack[-1] == '[':
          stack.pop()
        else:
          return False
    return True if not stack else False

    # @lc code=end


# public boolean isValid(String s) {
# 	Stack<Character> stack = new Stack<Character>();
# 	for (char c : s.toCharArray()) {
# 		if (c == '(')
# 			stack.push(')');
# 		else if (c == '{')
# 			stack.push('}');
# 		else if (c == '[')
# 			stack.push(']');
# 		else if (stack.isEmpty() || stack.pop() != c)
# 			return false;
# 	}
# 	return stack.isEmpty();
# }