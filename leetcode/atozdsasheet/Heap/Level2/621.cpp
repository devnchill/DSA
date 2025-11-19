/*
621. Task Scheduler
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of CPU tasks, each labeled with a letter from A to Z, and
a number n. Each CPU interval can be idle or allow the completion of one task.
Tasks can be completed in any order, but there's a constraint: there has to be a
gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The
same applies to task B. In the 3rd interval, neither A nor B can be done, so you
idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle ->
idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3
intervals. This leads to idling twice between repetitions of these tasks.

Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> m;
    priority_queue<int> p;
    int res = 0;
    for (auto &val : tasks)
      m[val]++;
    for (auto &val : m)
      p.push(val.second);
    while (!p.empty()) {
      vector<int> list;
      for (int i = 0; i < n + 1; i++) {
        if (p.empty() && list.size() == 0)
          // no task left return res
          return res;
        if (p.empty()) {
          res++;
          continue;
        }
        int freq = p.top();
        p.pop();
        if (freq > 1)
          // will do this task after this cycle
          list.push_back(freq - 1);
        // +1 for finishing curr task
        res++;
      }
      // push remaining task back into heap
      // question is do i push list only when heap gets empty ? or every loop ?
      for (int val : list)
        p.push(val);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<char> tasks = {'A', 'B', 'C', 'C'};
  s.leastInterval(tasks, 1);
  return 0;
}
