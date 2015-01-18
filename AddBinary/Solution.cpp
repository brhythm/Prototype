/*
 * Solution.cpp
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	int length = a.size() > b.size() ? a.size():b.size();

    	string result(length, '0');
    	reverse(a.begin(), a.end());
    	reverse(b.begin(), b.end());

    	int carry = 0;
    	for (int i=0; i < length; ++i){
    		int ai = 0;
    		int bi = 0;
    		if ( i < a.size()) {
    			ai = a[i] - '0';//remember this trick
    		}
    		if ( i < b.size())
    		{
    			bi = b[i] - '0';
    		}
    		int tmpSum = ai + bi + carry;
    		carry = tmpSum >> 1;
    		int sum = tmpSum % 2;
    		result[length-1-i] = ('0' + sum);
    	}
    	if (carry == 1) {
    		result.insert(result.begin(), '1');
    	}
    	return result;
    }
};

