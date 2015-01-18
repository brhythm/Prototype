/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chess board
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement,
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 *
 */
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class OneSolution {
    class QueenLocation {
    private:
        int m_row;
        int m_column;

    public:
        QueenLocation(int row, int column) {
            m_row = row;
            m_column = column;
        }

        int getRow() {
            return m_row;
        }
        int getColumn() {
            return m_column;
        }

        bool isConflict(QueenLocation& queenB) {
            if (getColumn() == queenB.getColumn()) {
                return true;
            } else if (getRow() == queenB.getRow()) {
                return true;
            } else if (abs(getColumn() - queenB.getColumn())
                       == abs(getRow() - queenB.getRow())) {
                return true;
            } else {
                return false;
            }
        }
    };

public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > solution;

        vector<bool> isColumnTaken(n, false);
        // location of the queens that have been decided
        vector<QueenLocation> existingQueens;

        if (solveNQueen(0, n, isColumnTaken, existingQueens))
        { //
            constructSolution(solution, existingQueens);
        } //else solution does not exist

        return solution;
    }

    //solve puzzle for this row
    bool solveNQueen(int row, int n, vector<bool>& isColumnTaken,
                     vector<QueenLocation>& existingQueens) {
        if (row == n) {
            //we have placed n queens in all rows
            return true;
        }

        for (int column = 0; column < n; ++column) {
            if (isColumnTaken[column]
                || isConflictWithExistingQueens(row, column, existingQueens)) {
                //not safe to put it in current column, continue
            } else { //it is safe to place a queen here
                QueenLocation newQueen(row, column);
                existingQueens.push_back(newQueen);
                isColumnTaken[column] = true;
                if (solveNQueen(row + 1, n, isColumnTaken, existingQueens)
                    == true) {
                    return true;
                } else {
                    //place the queen here would not lead to solution

                    //revert last step
                    existingQueens.pop_back();
                    isColumnTaken[column] = false;
                    //continue trying next column
                }
            }
        }
        //fail to place new queen in any column
        return false;
    }

    // return whether there is a conflict to place a queen at (row, index)
    bool isConflictWithExistingQueens(int row, int column,
                                      vector<QueenLocation>& existingQueens) {
        QueenLocation queenCandidate(row, column);
        for (unsigned int i = 0; i < existingQueens.size(); ++i) {
            if (queenCandidate.isConflict(existingQueens[i])) {
                return true;
            } //else, continue
        }

        // did not conflict with any existing queens
        return false;
    }

    void constructSolution(vector<vector<string> >&solution,
                           vector<QueenLocation>& existingQueens) {
        printf("Solution %d :\n", solution.size());
        //init board
        int n = existingQueens.size();
        string oneRow(n, '.');
        vector<string> board(n, oneRow);
        for (int i = 0; i < n; ++i) {
            int row = existingQueens[i].getRow();
            int column = existingQueens[i].getColumn();
            board[row].replace(column, 1, "Q");
            printf("%s\n", board[row].c_str());
        }
        solution.push_back(board);
    }
};

//int main() {
//    Solution test;
//    test.solveNQueens(8);
//}

