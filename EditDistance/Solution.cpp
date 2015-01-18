/**
 */

//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word:
//
//a) Insert a character
//b) Delete a character
//c) Replace a character

#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t n1 = word1.size();
        size_t n2 = word2.size();
        if (n1 == 0) {
            return (int)n2;
        }
        if (n2 == 0) {
            return (int)n1;
        }
        int D[n1+1][n2+1];//WARNING, bug here, D[i,0] means delete complete word1, our target is D[n1,n2]
        memset(&D[0][0], 0, (n1+1)*(n2+1)*sizeof(int));
        D[0][0]=0;
        for (int i=1; i <= n1; ++i) {
            D[i][0] = i;//keep deletion
        }
        for (int j=1; j <= n2; ++j) {
            D[0][j] = j;//keep insertion
        }
        for (int i=1; i <= n1; ++i) {
            for (int j=1; j<=n2; ++j) {
                int replace = word1[i-1]==word2[j-1] ? D[i-1][j-1]: (D[i-1][j-1]+1);
                int insert = D[i][j-1]+1;
                int deleted = D[i-1][j]+1;
                D[i][j] = min(replace, min(insert, deleted));
            }
        }
        return D[n1][n2];
    }
};

//int main()
//{
//    string word1 = "a";
//    string word2 = "a";
//    Solution test;
//    printf("%d\n", test.minDistance(word1, word2));
//    return 0;
//}