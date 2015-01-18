/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps.
 *  In how many distinct ways can you climb to the top?
 *
 */
#include <vector>
using namespace std;
class Solution {
public:
    //We use DP here, space complexity is O(N),
    //Some disgusting people use O(1) memory
    int climbStairs(int n) {
        vector<int> D(n+1);//we only use D[1] ~ D[n]
        D[1] = 1;
        D[2] = 2;
        for (int i=3; i<=n; ++i) {
            D[i] = D[i-2] + D[i-1];
        }
        return D[n];
    }
};




