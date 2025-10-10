/*
51. N-Queens
Hard
Topics
premium lock iconCompanies

The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You
may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space,
respectively.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    /* board is a smth like this
     *  "..Q."
     *  ".Q.."
     *  "Q..."
     *  "...Q"
     */
    // n is no of queens to place on an n X n board
    vector<string> board(n, string(n, '.'));
    backtrack(0, board, res);
    return res;
  }

  void backtrack(int row, vector<string> &board, vector<vector<string>> &res) {
    // row starts from 0 so since it would be equal to length , it means its
    // already placed queens on all rows and now needs to exit
    if (row == board.size()) {
      res.push_back(board);
      return;
    }
    for (int col = 0; col < board.size(); col++) {
      if (isSafe(row, col, board)) {
        board[row][col] = 'Q';
        backtrack(row + 1, board, res);
        board[row][col] = '.';
      }
    }
  }

  bool isSafe(int row, int col, vector<string> &board) {
    // checks for all columns since if a queen is there in same col , it would
    // voilate the rule
    for (int i = row - 1; i >= 0; i--) {
      if (board[i][col] == 'Q')
        return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q')
        return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
      if (board[i][j] == 'Q')
        return false;
    }
    return true;
  }
};
