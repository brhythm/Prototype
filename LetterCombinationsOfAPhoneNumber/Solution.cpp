/**
 */

//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public://Time O(3^N), N is the length of digits
    vector<string> letterCombinations(string digits) {

        vector<string> result;
        unordered_map<char, vector<char>> phoneNumber;
        string path;
        phoneNumber['2'] = {'a','b','c'};
        phoneNumber['3'] = {'d','e','f'};
        phoneNumber['4'] = {'g','h','i'};
        phoneNumber['5'] = {'j','k','l'};
        phoneNumber['6'] = {'m','n','o'};
        phoneNumber['7'] = {'p','q','r','s'};
        phoneNumber['8'] = {'t','u','v'};
        phoneNumber['9'] = {'w','x','y','z'};
        getCombo(0, digits, phoneNumber, path, result);
        
        return result;
    }
    
    void getCombo(const int start, const string& digits, const unordered_map<char, vector<char>>& phoneNumber, string& path, vector<string>& result)
    {
        if (start == digits.length()) {
            //finish all digits
            result.push_back(path);
            return;
        }
        else
        {//start < digits.length()
            auto letterIter = phoneNumber.find(digits[start]);
            if (letterIter != phoneNumber.end()) {
                string restorePath = path;
                vector<char> letters = (*letterIter).second;
                for (char& letter : letters) {
                    path += letter;
                    getCombo(start+1, digits, phoneNumber, path, result);
                    path = restorePath;
                }
            }
            else
            {
                //skip current letter
                getCombo(start+1, digits, phoneNumber, path, result);
            }
        }
    }
};

//int main()
//{
//    Solution test;
//    vector<string> result = test.letterCombinations("2");
//    return 0;
//}



