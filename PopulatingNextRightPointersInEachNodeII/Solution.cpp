/*
 * Solution.cpp
 *
 * What if the given tree could be any binary tree?
 * Would your previous solution still work?
 *
 */
#include "stddef.h"
#include <queue>
using namespace std;

 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

class Solution {
public://Yes, this solution still works
       //Time O(N) , space O(N)
    void connect(TreeLinkNode *rootPtr) {

    	if (rootPtr != NULL) {
    		queue<TreeLinkNode*> currentQueue;
    		queue<TreeLinkNode*> nextQueue;

    		currentQueue.push(rootPtr);
			while (!currentQueue.empty()) {
				while (!currentQueue.empty()) {
					TreeLinkNode* currentNode = currentQueue.front();
					currentQueue.pop();
					if (currentQueue.empty()) { //this is the last node at this level
						currentNode->next = NULL;
					} else { //point to the next node at the same level
						currentNode->next = currentQueue.front();
					}
					if (currentNode->left != NULL) {
						nextQueue.push(currentNode->left);
					}
					if (currentNode->right != NULL) {
						nextQueue.push(currentNode->right);
					}
				} //finish all nodes at this level
				swap(currentQueue, nextQueue);
			}
    	}
    }
};
