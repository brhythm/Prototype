/*
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code,
 * print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * WARNING!! do it again, try to understand this solution
 * C++中^运算表示的是二进制的异或运算
 *
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        const size_t size = 1 << n; // 2^n
        result.reserve(size);
        for (size_t i = 0; i < size; ++i)
            result.push_back(binary_to_gray(i));
        return result;
    }
private:
    static unsigned int binary_to_gray(unsigned int n) {
        //keep the highest bit, use ^ all the rest of bits
        return n ^ (n >> 1);
    }
};





