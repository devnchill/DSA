/*
Valid Sudoku

You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the
following rules are followed:

    Each row must contain the digits 1-9 without duplicates.
    Each column must contain the digits 1-9 without duplicates.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
without duplicates.

Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<map<char, bool>> subBox(9);
    for (int i = 0; i < board.size(); i++) {
      map<char, bool> rows;
      map<char, bool> cols;
      for (int j = 0; j < board[0].size(); j++) {
        char currRowCell = board[i][j];
        char currColCell = board[j][i];
        int currBoxCellIndex = (i / 3) * 3 + (j / 3);
        if (currRowCell != '.') {
          if (rows[currRowCell] || subBox[currBoxCellIndex][currRowCell])
            return false;
          rows[currRowCell] = true;
          subBox[currBoxCellIndex][currRowCell] = true;
        }
        if (currColCell != '.') {
          if (cols[currColCell])
            return false;
          cols[currColCell] = true;
        }
      }
    }
    return true;
  }
};
