/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 */

#include <vector>

using namespace std;
class Solution {
public:
    //Time O(N)
    vector<int> plusOne(vector<int> &digits) {

        vector<int> answer(digits);
        for (int i=digits.size()-1; i >=0; --i){
            int thisDigit = digits[i];
            if ( (thisDigit + 1) != 10) {
                //we are done
                answer[i] = thisDigit+1;
                break;
            }
            else {
                answer[i] = 0;
                //continue plus one for the next bigger digit
            }
        }
        if (answer[0] == 0)
        {
            answer.insert(answer.begin(), 1);
        }
        return answer;
    }
};




