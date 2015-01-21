/**
*/

//Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given:
//start = "hit"
//end = "cog"
//dict = ["hot","dot","dog","lot","log"]
//Return
//[
// ["hit","hot","dot","dog","cog"],
// ["hit","hot","lot","log","cog"]
// ]
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public://TODO not sure whether this is the correct version or not!!
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        //dict.insert(end);//maybe unnecessary
        
        queue<string> current;
        current.push(start);
        queue<string> next;
        
        vector<vector<string>> solution;
        
        unordered_map<string, string> parentWord;//node -> parentNode
        string emptyString("");
        parentWord.insert(make_pair(start, emptyString));
        
        while (!current.empty()) {
            while (!current.empty()) {
                string word = current.front();
                current.pop();
                //no need to check whether word equals to 'end', cos we never put that into our queue
                bool isEndFound = false;
                for (int i=0; !isEndFound && i< word.length(); ++i) {
                    for (char c='a'; c <= 'z'; ++c) {
                        if (c == word[i]) {
                            continue;
                        }
                        string nextTransform(word);
                        nextTransform[i]= c;
                        if (dict.find(nextTransform)!= dict.end()) {
                            //never visit his word
                            if (nextTransform.compare(end) == 0) {
                                //found out that nextTransform is already 'end', construct solution IMMEDIATELY
                                //we don't want to push it into next then construct solution when it got poped out
                                //because the unordered_map we use don't support duplicate keys
                                //but this 'end' should have multiple parent node, which leads to multiple solution
                                //
                                //we have to use unorder_multimap if we backtrack from 'end'. We get around this by
                                //backtrack from the last word before end,
                                //
                                //note that we never remove 'end' from dict, so multiple solution could be found
                                //construct one solution
                                vector<string> oneSolution;
                                oneSolution.push_back(nextTransform);//this is 'end'
                                oneSolution.push_back(word);
                                
                                string oneWord = parentWord[word];
                                while (!oneWord.empty()) {
                                    oneSolution.push_back(oneWord);
                                    oneWord = parentWord[oneWord];
                                }
                                reverse(oneSolution.begin(), oneSolution.end());
                                //finish construct one solution
                                solution.push_back(oneSolution);
                                
                                //backtrack
                                isEndFound = true;//break out of the outer loop
                                break;//break out of the inner loop, stop checking nextTransform
                            }
                            else
                            {
                                next.push(nextTransform);
                                parentWord.insert(make_pair(nextTransform, word));
                                dict.erase(nextTransform);//this word has been put into our graph, remove it from set
                            }

                        }
                    }
                }
            }
            swap(current, next);
        }
        
        return solution;
    }
};

//Here, since we need to gather all solutions, definitely we would need backtrack, we is usually easy to do in DFS.
//However, why we don't want to use DFS in this problem ??
//Because we construct the tree on the fly. When drawing the graph using BFS, it is gauranteed that all nodes that has distance 1 to start
//would be on level 1 of the tree. On the other hand, if we draw the graph using DFS, it is not gauranteed. e.g. hit ->hot->hat
//when hat could be either on level 2 or level 3, DFS might put it on level 3, which will not lead to optimal result.
//
//use hash to store the unique parent node for each word

int main()
{
    string start("hit");
    string end("cog");
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    Solution test;
    vector<vector<string>> solution = test.findLadders(start, end, dict);
    for (auto oneSolution: solution) {
        printf("[");
        for (auto oneString: oneSolution) {
            printf("%s", oneString.c_str());
        }
        printf("]\n");
    }
    
    return 0;
}

