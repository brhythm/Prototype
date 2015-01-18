/*
 * Solution.cpp
 *
 * Given an array S of n integers, are there elements a, b, c in S
 * such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *
 * The solution set must not contain duplicate triplets.
 *
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 *  (-1, 0, 1)
 *  (-1, -1, 2)
 *
 */
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
//WARNING, this problem cannot pass without optimization, even if your time is already O(N^2)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > solution;
        if (num.size() >= 3) {
            sort(num.begin(), num.end());

            //here it depends on whether there are more negative number
            //or more positive number
            //assume there are x negative number
            //Time O(X(N)) ~ O(N^2)
            for (int i = 0; num[i] <= 0; ++i) {
                //optimization
                if (i >=1 && num[i] == num[i-1]) {
                    continue;
                }

                int j = i + 1;
                int k = num.size() - 1;
                while (j < k) {
                    int localSum = num[i] + num[j] + num[k];
                    if (localSum == 0) {
                        int array[] = { num[i], num[j], num[k] };
                        vector<int> oneSolution(array,
                                array + sizeof(array) / sizeof(array[0]));
                        solution.push_back(oneSolution);
                        //warning, don't forget to update index
                        ++j;
                        --k;
                    } else if (localSum > 0) {
                        --k;
                        //optimization
                        if (num[k] == num[k+1]) {
                            --k;
                        }
                    } else {        //localSum < 0
                        ++j;
                        //optimization
                         if (num[j] == num[j-1]) {
                            ++j;
                        }
                    }
                }
            }
            //warning, this problem requires no duplicate
            sort(solution.begin(), solution.end());
            solution.erase(unique(solution.begin(), solution.end()),
                    solution.end());
        }
        return solution;
    }
};

int main() {
    int array[] = { -7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9,
            11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7,
            -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14,
            9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2,
            14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8,
            10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5,
            -11, 1, 3, -6 };
    std::vector<int> num(array, array + sizeof(array) / sizeof(array[0]));

    Solution testSolution;
    std::vector<std::vector<int> > solution = testSolution.threeSum(num);

    for (int i = 0; i < solution.size(); ++i) {
        printf("[");
        for (int j = 0; j < 3; ++j) {
            printf("%d,", solution[i][j]);
        }
        printf("]\n");
    }
}
