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
//Time O(N!) => T(n) = nT(n-1)
class Solution {
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

        // location of the queens that have been decided
        vector<QueenLocation> existingQueens;

        solveNQueen(0, n, existingQueens, solution);

        return solution;
    }

    //solve puzzle for this row
    //NOTE:in recursive alg, be careful to use RETURN if you want to collect all solutions
    //a good dfs alg that collect all solutions usually has return type void
    void solveNQueen(int row, int n, vector<QueenLocation>& existingQueens, vector<vector<std::string> >& solution) {
        if (row == n) {
            //we have placed n queens in all rows
            constructSolution(solution, existingQueens);
            return;
        }
        else
        {
            for (int column = 0; column < n; ++column) {
                if (isConflictWithExistingQueens(row, column, existingQueens)) {
                    //not safe to put it in current column, continue
                } else { //it is safe to place a queen here
                    QueenLocation newQueen(row, column);
                    existingQueens.push_back(newQueen);

                    solveNQueen(row + 1, n, existingQueens, solution);
                    // up to now, if the recursive call hit a solution, the solution has been recorded
                    // now let us undo this step, so that we can continue exploring placing the queen in the following columns

                    //revert last step
                    existingQueens.pop_back();
                    //continue trying next column
                }
            }
            //fail to place new queen in any column, return
        }
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
        //init board
        printf("Solution:%d\n", solution.size()+1);
        size_t n = existingQueens.size();
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

int main() {
    Solution test;
    test.solveNQueens(8);
}

