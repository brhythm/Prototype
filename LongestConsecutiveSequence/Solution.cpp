/**
 */

//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity.

#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, pair<int, int>> seqMap;//num -> (head. tail)
        // head of sequence, default = num
        // tail of sequence, default = num
    
        int maxSequence = INT_MIN;
        for (int element: num) {
            if (seqMap.find(element) == seqMap.end()) {

                int currentHead = element;
                int currentTail = element;
                auto prevNumIter = seqMap.find(element-1);
                if (prevNumIter != seqMap.end()) {
                    //prev number exists in our map
                    //update currentHead
                    currentHead = (*prevNumIter).second.first;
                }//else prev number does not exist in our map
                
                //printf("debug1: elem = %d, maxSeq = %d\n", element, maxSequence);
                auto nextNumIter = seqMap.find(element+1);
                if (nextNumIter != seqMap.end()) {
                    //next number exists in our map
                    //update currentTail
                    currentTail = (*nextNumIter).second.second;
                }//else next number does not exist, do nothing
                
                seqMap[element] = make_pair(currentHead, currentTail);
                maxSequence = max(maxSequence, currentTail-currentHead+1);
                
                //now the currentTail, currentHead are fetched, we must also update the follwoing
                //head/tail critical values
                seqMap[currentTail].first = currentHead;//update current.tail head
                seqMap[currentHead].second = currentTail;//update current.head tail
            }
        }
        return maxSequence;
        
    }
};


//int main()
//{
//    //vector<int> array = {100, 4, 200, 1, 3, 2};
//    vector<int> array={0,3,7,2,5,8,4,6,0,1};
//    Solution test;
//    int result = test.longestConsecutive(array);
//    printf("result = %d\n", result);
//    return 0;
//}


