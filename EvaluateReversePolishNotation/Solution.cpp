/*
 * Solution.cpp
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 */
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numbers;
        for ( string token: tokens)
        {
            if (isOperator(token))
            {
                //assert there are 2 digits at least
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();
                int value = calculate(first, second, token);
                numbers.push(value);
            }
            else
            {   //assume this is valid int
                int digits = stoi(token);
                numbers.push(digits);
            }
        }
        return numbers.top();
    }
    int calculate(int first, int second, const string& operand)
    {
        int value = 0;
        if (operand.compare("+") == 0)
        {
            value = first + second;
        }
        else if (operand.compare("-") == 0)
        {
            value = first - second;
        }
        else if (operand.compare("*") == 0)
        {
            value = first*second;
        }
        else
        {//assert ...
            value = first/second;
        }
        return value;
    }

    bool isOperator(const string& token)
    {
        if (token.compare("+") == 0 ||
            token.compare("-") == 0 ||
            token.compare("*") == 0 ||
            token.compare("/") == 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


