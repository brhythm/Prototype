#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

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
    int totalNQueens(int n) {
        int solutionCount = 0;

        // location of the queens that have been decided
        vector<QueenLocation> existingQueens;

        solveNQueen(0, n, existingQueens, solutionCount);

        return solutionCount;
    }

    //solve puzzle for this row
    //NOTE:in recursive alg, be careful to use RETURN if you want to collect all solutions
    //a good dfs alg that collect all solutions usually has return type void
    void solveNQueen(int row, int n, vector<QueenLocation>& existingQueens, int& solutionCount) {
        if (row == n) {
            solutionCount++;
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

                    solveNQueen(row + 1, n, existingQueens, solutionCount);
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

};

//int main() {
//    Solution test;
//    printf("Total number of solution is : %d\n",test.totalNQueens(8));
//}




