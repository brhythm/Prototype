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
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<char> num;
        for (int i=1;i <= n; ++i)
        {
            num.push_back('0'+i);
        }
        
        --k;//ATTENTION! this clear all doubts
        for (int i = 0; i < n; ++i) {
            int numPermutation = factorial(n - 1 - i);
            int index = k / numPermutation;
            result.push_back(num[index]);
            num.erase(num.begin()+index);
            k = k % numPermutation;
        }
        return result;
    }
    
    //this could be optimized by bottom up(remember all subsets)
    int factorial(int n) {
        int product = 1;
        for (int i = 1; i <= n; ++i) {
            product *= i;
        }
        return product;
    }
};


