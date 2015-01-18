/**
 */
//
//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
//
//OJ's undirected graph serialization:
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//Visually, the graph looks like the following:
//
//   1
//  / \
// /   \
//0 --- 2
//     / \
//     \_/
//
//

#include <vector>
#include <unordered_map>

using namespace std;

   //Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> nodeMap;//label-> node address
        UndirectedGraphNode* copiedNode = nullptr;
        if (node != nullptr) {
            copiedNode = new UndirectedGraphNode(node->label);
            nodeMap.insert(make_pair(node->label, copiedNode));
            dfs(node, copiedNode, nodeMap);
        }
        return copiedNode;
        
    }
    
    //WARNING, caller is responsible for allocate copiedNode and put into nodeMap
    void dfs(UndirectedGraphNode* node, UndirectedGraphNode* copiedNode, unordered_map<int, UndirectedGraphNode*>& nodeMap)
    {
        if ( node == nullptr ) {
            return;//TODO is this all of the terminate condition?
        }
        for (UndirectedGraphNode* neighbor : node->neighbors ) {
            auto neighborIter = nodeMap.find(neighbor->label);
            if ( neighborIter == nodeMap.end()) {
            //has never visited this neighbor
                UndirectedGraphNode*  copiedNeighbor = new UndirectedGraphNode(neighbor->label);
                nodeMap.insert(make_pair(neighbor->label, copiedNeighbor));
                copiedNode->neighbors.push_back(copiedNeighbor);
                dfs(neighbor, copiedNeighbor, nodeMap);
            }
            else
            {//this neighbor has been visited from another route
                copiedNode->neighbors.push_back(neighborIter->second);
            }
        }
    }
};

