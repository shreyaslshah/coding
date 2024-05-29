// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseWords(string s)
{
  int i=0;
  string ans;
  while(i<s.size()){
    string word;
    while(s[i]!='.' and i!=s.size()){
      word.push_back(s[i++]);
    }
    i++;
    ans = word + "." + ans;
  }
  ans.pop_back();
  return ans;
}

int main()
{
  string s = "i.like.this.program.very.much";
  string ans = reverseWords(s);
  cout<<ans<<endl;
}