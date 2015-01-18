/*
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    static string intToRoman(int num) {
        map<int, string> valueMap;
        //I, II, III, IV, V, VI, VII, VIII, IX, X.
        valueMap.insert(pair<int, string>(1, "I"));
        valueMap.insert(pair<int, string>(5, "V"));
        valueMap.insert(pair<int, string>(10, "X"));
        valueMap.insert(pair<int, string>(50, "L"));
        valueMap.insert(pair<int, string>(100, "C"));
        valueMap.insert(pair<int, string>(500, "D"));
        valueMap.insert(pair<int, string>(1000, "M"));

        string result;
        int digit[] = { 1000, 500, 100, 50, 10, 5, 1 };
        vector<int> digits(digit, digit + 7);
        int index = 0;
        while (num > 0) {
            int diff = num - digits[index];
            if (diff < 0) {
                int roundDown = findXorC(digits[index]);
                if (digits[index] - roundDown <= num) {
                    result.append(valueMap[roundDown]);
                    result.append(valueMap[digits[index]]);
                    num -= (digits[index] - roundDown);
                    index++;
                } else { //fail try a smaller digit
                    index++;
                }
            } else {
                result.append(valueMap[digits[index]]);
                num -= digits[index];
                //don't increment index, continue trying the same digit in next roung
            }
        }
        return result;
    }

    static int findXorC(int prevDigit) {
        if (prevDigit == 1000 || prevDigit == 500)
            return 100;
        else if (prevDigit == 50 || prevDigit == 100)
            return 10;
        else if (prevDigit == 5 || prevDigit == 10)
            return 1;
        else
            return 0; //no round down
    }
};
//
//int main() {
//    string roman = Solution::intToRoman(9); //"CXC", "MCMXCVI", III, IV, IX);
//    cout << roman.c_str() << endl;
//    return 1;
//}

