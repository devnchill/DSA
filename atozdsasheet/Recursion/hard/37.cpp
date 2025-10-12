/*
37. Sudoku Solver
Hard
Topics
premium lock iconCompanies
Hint

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3
sub-boxes of the grid.

The '.' character indicates empty cells.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { backtrack(board); }

private:
  bool backtrack(vector<vector<char>> &board) {
    vector<char> possibilities = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == '.') {
          for (int k = 0; k < 9; k++) {
            if (isValid(board, i, j, possibilities[k])) {
              board[i][j] = possibilities[k];
              if (backtrack(board))
                return true;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  bool isValid(vector<vector<char>> &board, int i, int j, char c) {
    for (auto it : board[i]) {
      if (it == c)
        return false;
    }
    for (int rows = 0; rows < board.size(); rows++) {
      if (board[rows][j] == c)
        return false;
    }
    int boxRowStartNo = (i / 3) * 3;
    int boxColStartNo = (j / 3) * 3;
    for (int row = boxRowStartNo; row < boxRowStartNo + 3; row++) {
      for (int col = boxColStartNo; col < boxColStartNo + 3; col++) {
        if (board[row][col] == c)
          return false;
      }
    }
    return true;
  }
};
