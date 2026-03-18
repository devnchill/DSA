// Given a list of accounts where each element accounts[i] is a list of strings,
// where the first element accounts[i][0] is a name, and the rest of the
// elements are emails representing emails of the account.
//
// Now, we would like to merge these accounts. Two accounts definitely belong to
// the same person if there is some common email to both accounts. Note that
// even if two accounts have the same name, they may belong to different people
// as people could have the same name. A person can have any number of accounts
// initially, but all of their accounts definitely have the same name.
//
// After merging the accounts, return the accounts in the following format: the
// first element of each account is the name, and the rest of the elements are
// emails in sorted order. The accounts themselves can be returned in any order.
//
//
//
// Example 1:
//
// Input: accounts =
// [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output:
// [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email
// "johnsmith@mail.com". The third John and Mary are different people as none of
// their email addresses are used by other accounts. We could return these lists
// in any order, for example the answer [['Mary', 'mary@mail.com'], ['John',
// 'johnnybravo@mail.com'],
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
// would still be accepted. Example 2:
//
// Input: accounts =
// [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
// Output:
// [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
//
//
// Constraints:
//
// 1 <= accounts.length <= 1000
// 2 <= accounts[i].length <= 10
// 1 <= accounts[i][j].length <= 30
// accounts[i][0] consists of English letters.
// accounts[i][j] (for j > 0) is a valid email.

#include <bits/stdc++.h>
using namespace std;

// METHOD 1 DFS (Gives TLE)
// class Solution {
// private:
//   void dfs(unordered_set<string> &visited,
//            unordered_map<string, vector<string>> adj, vector<string>
//            &component, string email) {
//     visited.insert(email);
//     component.push_back(email);
//     for (string &neighbor : adj[email]) {
//       if (!visited.count(neighbor))
//         dfs(visited, adj, component, neighbor);
//     }
//   }
//
// public:
//   vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
//     unordered_map<string, vector<string>> adj;
//     unordered_map<string, string> email_to_name;
//     for (int i = 0; i < accounts.size(); i++) {
//       string name = accounts[i][0];
//       for (int j = 1; j < accounts[i].size(); j++) {
//         email_to_name[accounts[i][j]] = name;
//       }
//     }
//     for (int i = 0; i < accounts.size(); i++) {
//       string base_email = accounts[i][1];
//       adj[base_email];
//       for (int j = 2; j < accounts[i].size(); j++) {
//         adj[base_email].push_back(accounts[i][j]);
//         adj[accounts[i][j]].push_back(base_email);
//       }
//     }
//     unordered_set<string> visited;
//     vector<vector<string>> components;
//     for (auto &e : adj) {
//       string email = e.first;
//       if (!visited.count(email)) {
//         vector<string> component;
//         dfs(visited, adj, component, email);
//         sort(component.begin(), component.end());
//         string name = email_to_name[email];
//         component.insert(component.begin(), name);
//         components.push_back(component);
//       }
//     }
//     return components;
//   }
// };

// METHOD 2

class Solution {
public:
  unordered_map<string, string> parent;

  string find(string x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(string a, string b) {
    string pa = find(a);
    string pb = find(b);
    if (pa != pb)
      parent[pb] = pa;
  }

  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    unordered_map<string, string> email_to_name;
    for (auto &acc : accounts) {
      string name = acc[0];
      for (int i = 1; i < acc.size(); i++) {
        parent[acc[i]] = acc[i];
        email_to_name[acc[i]] = name;
      }
    }

    for (auto &acc : accounts) {
      string base = acc[1];
      for (int i = 2; i < acc.size(); i++) {
        unite(base, acc[i]);
      }
    }

    unordered_map<string, vector<string>> groups;
    for (auto &p : parent) {
      string email = p.first;
      string root = find(email);
      groups[root].push_back(email);
    }

    vector<vector<string>> result;
    for (auto &g : groups) {
      vector<string> emails = g.second;
      sort(emails.begin(), emails.end());
      string name = email_to_name[emails[0]];
      emails.insert(emails.begin(), name);
      result.push_back(emails);
    }

    return result;
  }
};
