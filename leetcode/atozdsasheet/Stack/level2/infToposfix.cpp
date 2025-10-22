/*
You are given a string expression representing a valid infix mathematical
expression. Your task is to convert this expression into its equivalent postfix
notation, also known as Reverse Polish Notation (RPN).

The expression may include:

Operands: single lowercase English letters (a to z) or single-digit numbers (0
to 9) Binary operators: +, -, *, /, ^ Parentheses: ( and ) to indicate grouping
and precedence


Operator precedence (from highest to lowest):

^ (exponentiation)
*, / (multiplication and division)
+, - (addition and subtraction)


Associativity:

^ is right-associative
All other operators are left-associative
Parentheses override standard precedence


You must return the corresponding postfix expression as a string.

The result must not contain any spaces or separators between characters.


Examples:
Input: expression = "a+b*c"

Output: "abc*+"

Explanation: Multiplication has higher precedence than addition, so b * c is
evaluated first, then added to a.

Input: expression = "(a+b)*c"

Output: "ab+c*"

Explanation: The parentheses ensure that a + b is evaluated before multiplying
with c.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string infixToPostfix(string s) {
    stack<char> st;
    string res;
    unordered_map<char, int> operatorToPriority;
    operatorToPriority['('] = 0;
    operatorToPriority['+'] = 1;
    operatorToPriority['-'] = 1;
    operatorToPriority['*'] = 2;
    operatorToPriority['/'] = 2;
    operatorToPriority['^'] = 3;
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(s[i]);
        continue;
      }
      if (s[i] == ')') {
        while (st.top() != '(') {
          res.push_back(st.top());
          st.pop();
        }
        st.pop();
      }
      if (operatorToPriority[s[i]]) {
        if (st.empty()) {
          st.push(s[i]);
          continue;
        }
        if (operatorToPriority[s[i]] > operatorToPriority[st.top()]) {
          st.push(s[i]);
        } else {
          res.push_back(st.top());
          st.pop();
          st.push(s[i]);
        }
      } else {
        res.push_back(s[i]);
      }
    }
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
  }
};

int main() {

  Solution s;
  // ab + cd*-
  cout << s.infixToPostfix("a * b^2 - c*d");
  return 0;
}
