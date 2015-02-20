/*
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */
#include <vector>


using namespace std;

class Solution {
public:
    //Must know how to analyze run time:
    //T(n) = nT(n-1)=n(n-1)T(n-2) =n!
    //Also, we are generating permuations for n, which is n! 
    vector<vector<int> > permute(vector<int> &num) {
        vector<int> candidate;
        vector<vector<int> > solution;
        printOneDigit(num, 0, candidate, solution);

        return solution;
    }

    //it is gauranteed that all digits in candidate appears before index
    void printOneDigit(vector<int> &num, int index,
                       vector<int>& candidate,
                       vector<vector<int> >& solution)
   {
        if (candidate.size() == num.size()) {
            //we have printed n digits
            solution.push_back(candidate);
            return;
        }
        else
        {
           for (int i = index; i < num.size(); ++i) {
                vector<int> restoredCandidate = candidate;

                swap(num[index], num[i]);
                candidate.push_back(num[index]);
                printOneDigit(num, index+1, candidate, solution);
                // backtrack
                candidate = restoredCandidate;
                swap(num[index], num[i]);
            }
        }
    }

};






