/*
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    static int romanToInt(string str) {
        map<string, int> valueMap;
        //I, II, III, IV, V, VI, VII, VIII, IX, X.
        valueMap.insert(pair<string, int>("I", 1));
        valueMap.insert(pair<string, int>("V", 5));
        valueMap.insert(pair<string, int>("X", 10));
        valueMap.insert(pair<string, int>("L", 50));
        valueMap.insert(pair<string, int>("C", 100));
        valueMap.insert(pair<string, int>("D", 500));
        valueMap.insert(pair<string, int>("M", 1000));
        int sum = 0;
        int prevDigit = 2000; //larget than M
        for (int i = 0; i < str.length(); ++i) {
            string currentDigit(&str[i], 1);
            int current = valueMap[currentDigit];
            if (current <= prevDigit) {
                sum += current;
            } else {
                sum -= prevDigit;
                sum += current - prevDigit;
            }
            prevDigit = current;
        }
        return sum;
    }
};

//int main() {
//    int value = Solution::romanToInt("CXC"); //"MCMXCVI");
//    cout << value << endl;
//    return 1;
//}
