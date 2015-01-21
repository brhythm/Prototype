/*
 * Solution.cpp
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */

#include <string>
#include <stack>
#include <sstream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        stack<int> digitStack;
        while(n != 0)
        {
            int division = n / 10;
            int remainder = n %10;
            n = division;
            digitStack.push(remainder);
        }

        stringstream ss;
        int count = 1;
        int prev = digitStack.top();
        int current = prev;
        digitStack.pop();
        while(!digitStack.empty())
        {
            current = digitStack.top();
            digitStack.pop();
            if (current == prev)
            {
                ++count;
            }
            else
            {//current != prev, print count, digit
                ss << count;
                count = 1;
                ss << prev;
            }
            prev = current;
        }
        ss << count;
        ss << current;
        return ss.str();
    }
};

//int main()
//{
//    int n = 1;
//    Solution test;
//    string result = test.countAndSay(n);
//    printf("result is %s\n", result.c_str());
//    return 0;
//}
//

