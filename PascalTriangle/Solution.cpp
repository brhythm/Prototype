/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pTriangle;
        if (numRows >= 1) {
            //WARNING! learn this syntax to create vector with one element
            pTriangle.push_back(vector<int>(1,1));
            for (int row = 1; row < numRows; ++row) { //row=1~numRow-1,
                vector<int> oneRow;
                pTriangle.push_back(oneRow);
                for (int column = 0; column <= row; ++column) { //column = 0~row
                    int value = getParentValue(pTriangle, row - 1, column - 1)
                            + getParentValue(pTriangle, row - 1, column);
                    pTriangle[row].push_back(value);
                }
            }

        }
       return pTriangle;
    }

    int getParentValue(vector<vector<int> >& pTriangle, int row, int column)
    {//
        if (row < 0 ||
            row > (pTriangle.size()-1) ||
            column < 0 ||
            column > (pTriangle[row].size()-1)) {
            //index out of bound
            return 0;
        }
        else
        {
            return pTriangle[row][column];
        }
    }
};

//int main() {
//    Solution debugObj;
//    vector<vector<int> > triangle = debugObj.generate(6);
//    for (int i=0 ; i < triangle.size(); ++i) {
//        vector<int> row = triangle[i];
//        for (int j=0; j < row.size(); ++j) {
//            cout << triangle[i][j] << ",";
//        }
//        cout << endl;
//    }
//    return 0;
//}

