/**
 */

//Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given:
//start = "hit"
//end = "cog"
//dict = ["hot","dot","dog","lot","log"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//
//Note:
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//
//
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

//Time O(min(26*N, dic.size) ), where n is the length of word
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int shortestPath = 0;
        bool isFound = false;
        //dict.insert(end);//maybe unnecessary
        
        queue<string> current;
        current.push(start);
        queue<string> next;
        
        int level = 1;
        while (!isFound && !current.empty()) {
            while (!current.empty()) {
                string word = current.front();
                current.pop();
                if (word.compare(end) == 0) {
                    shortestPath = level;
                    isFound = true;
                    break;//terminate algorithm
                }
                for (int i=0; i< word.length(); ++i) {
                    for (char c='a'; c <= 'z'; ++c) {
                        if (c == word[i]) {
                            continue;
                        }
                        string nextTransform(word);
                        nextTransform[i]= c;
                        if (dict.find(nextTransform)!= dict.end()) {
                            next.push(nextTransform);
                            dict.erase(nextTransform);//this word has been put into our graph, remove it from set
                        }
                    }
                }
            }
            swap(current, next);
            ++level;
        }
        
        return shortestPath;
    }
};


//WARNING, when you construct the tree, keep in mind that there should be no duplicate node in the tree
//because the path that go thorugh duplicate nodes will never be optimal
//int main()
//{
//    string start("hit");
//    string end("cog");
//    unordered_set<string> dict({"hot","dot","dog","lot","log"});
//    Solution test;
//    int result = test.ladderLength(start, end, dict);
//    printf("result = %d\n", result);
//    
//    return 0;
//}

