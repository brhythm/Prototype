/**
 * Write a method to sort an array of strings so that all the anagrams are next to each other
 */


#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    class Comparator
    {
    public:
        //return true if str1 is eariler than str2
        bool operator()(const string& str1, const  string& str2)
        {
            string copyStr1 = str1;
            string copyStr2 = str2;
            sort(copyStr1.begin(), copyStr1.end());
            sort(copyStr2.begin(), copyStr2.end());
            return copyStr1.compare(copyStr2) <=0;
        }
    };
    
    void sortStrings(vector<string>& input)
    {
        sort(input.begin(), input.end(), Comparator());
    }
};

int main()
{
    Solution test;
    vector<string> input = {"abc", "listen","cba","silent", "hello"};
    test.sortStrings(input);
    for (string& word : input) {
        printf("%s,", word.c_str());
    }
    return 0;
}


