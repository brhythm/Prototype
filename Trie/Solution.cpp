/**
 Design a data structure supporting two operations
 1）    void addWord(string)
 2）    bool search(string)
 
 search(string) can search word and regular expression ( only consider “.”,
 which means any one character)
 
 e.g.
 addWord("rat")
 addWord("cat")
 addWord("bat")
 search("dat") -> false
 search("bat") -> true
 search(".at") -> true
 search("r.t") -> true
 */

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX_SIZE 26
using namespace std;
struct TrieNode
{
    int value;//0~25
    TrieNode* children[MAX_SIZE];
    
    TrieNode (int val)
    :value(val)
    {
        fill(children, children+MAX_SIZE, nullptr);
    }
};

class Trie
{
public://Space O(M) , M is approximately the total lenghs of all words
       //Time O(L), L is the length of the word you are searching for
    Trie()
    {
        root = new TrieNode(-1);//root node is dummy;
    }
    
    ~Trie()
    {
        //TODO cleanup
    }
    void addWord(const string& word)
    {
        TrieNode* head = root;
        for (int i=0; i< word.size(); ++i) {
            int index = word[i]-'a';
            TrieNode* node = head->children[index];
            if (node == nullptr) {
                head->children[index] = new TrieNode(index);
            }//else search for next letter
            head = head->children[index];
        }
    }
    
    // doesWordExist
    // support exact match and
    // approximate match "."
    bool doesWordExist(const string& word)
    {
        return search(root, word);
    }
    
    bool search(TrieNode* head, const string& word)
    {
        if (head == nullptr) {//terminate condition
            return false;
        }
        for (int i=0; i < word.size(); ++i) {
            if (word[i] == '.') {
                bool isFound = false;
                for (int j=0; j < MAX_SIZE; ++j) {
                    if (search(head->children[j], word.substr(i+1, string::npos)))
                    {
                        isFound = true;
                        break;
                    }
                }
                return isFound;
            }
            else
            {
                int index = word[i]-'a';
                TrieNode* node = head->children[index];
                if (node == nullptr) {
                    return false;
                }
                head = head->children[index];
            }
        }
        return true;
    }
    void printAllNode() const
    {
        queue<TrieNode*> current;
        queue<TrieNode*> next;
        current.push(root);
       
        while (!current.empty()) {
            while (!current.empty()) {
                TrieNode* node = current.front();
                current.pop();
                printf("%c ", node->value+'a');
                for (int i=0; i< MAX_SIZE; ++i) {
                    if (node->children[i] != nullptr) {
                        next.push(node->children[i]);
                    }
                }
            }
            printf("\n");
            swap(next, current);
        }
    }
private:
    TrieNode* root;
};

int main()
{
    Trie myTrie;
    vector<string> dictionary = {"rat", "cat", "bat", "love", "i", "u"};
    for (string& word : dictionary) {
        myTrie.addWord(word);
    }
    printf("does word exist ? %d\n", myTrie.doesWordExist("u"));
    return 0;
}




