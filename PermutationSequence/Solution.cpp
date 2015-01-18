/*
 * Solution.cpp
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * Given n and k, return the kth permutation sequence.
 */
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string solution(n, '0'); //init to 00000
        char buffer[2];
        int remainK = k;
        for (int i = 0; i < n; ++i) {
            if (remainK == 0) {
                remainK = k;
            }
            int numPermutation = factorial(n - 1 - i);
            int currentDigit = ceil((double) remainK / (double) numPermutation);
            sprintf(buffer, "%d", currentDigit);
            solution.replace(i, 1, buffer);
            remainK = (remainK) % numPermutation;
        }
        return solution;
    }

    int factorial(int n) {
        int product = 1;
        for (int i = 1; i <= n; ++i) {
            product *= i;
        }
        return product;
    }
};

