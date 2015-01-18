/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * */
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        if ( n < 1) {
            ;//do nothing
        }
        else if ( n == 1) {
            solution.push_back("()");
        }
        else {
            vector<string> subStringSet = generateParenthesis(n-1);
            for (int i=0; i < subStringSet.size(); ++i) {
                string insertInMiddle= string("(") + subStringSet[i] + string(")");
                solution.push_back(insertInMiddle);

                string insertAtHead = string("()") + subStringSet[i];
                string insertAtTail = subStringSet[i] + string("()");
                if (insertAtHead.compare(insertAtTail) != 0 ) {
                    //insert both head and tail
                    solution.push_back(insertAtTail);
                }//skip inserting head
               solution.push_back(insertAtHead);
             }
        }
        return solution;
    }
};

//int main() {
//    bool isCorrect = true;
//    string myOutput[] = {"(((())))","((()))()","()((()))","((())())","(())()()","()(())()","(()(()))","()(())()","()()(())","((()()))","(()())()","()(()())","(()()())","()()()()"};
//    string expectedOutput[] = {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"};
//
//    int number = 14;
//    for (int i=0; i < number; ++i) {
//        int j=0;
//        for (; j < number ; ++j) {
//            if ( expectedOutput[i].compare(myOutput[j]) == 0)
//                 break;
//        }
//        if (expectedOutput[i].compare(myOutput[j]) != 0) {
//            isCorrect = false;
//            printf("Not found in my solution: %s\n",expectedOutput[i].c_str());
//            //"(())(())" this solution cannot be constructed by concat susbstring with tail/head/middle
//        }
//    }
//}

