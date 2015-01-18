/**
 */
//
//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

class Solution {
public://Time O(N^2), this soluiton hit time limit exceeded, don't know why, fuck
    bool isInterleave(string s1, string s2, string s3) {
        int length1 = s1.length();
        int length2 = s2.length();
        int length3 = s3.length();
        
        if (length3 != length1+length2)
        {
            return false;
        }
        bool d[length2+1][length1+1];
        //d[i][j], 0<= i <= length1, 0<= j <=length2
        //define whether s1[0, i-1] and s2[0, j-1] can interleave and form s3[0, i+j-1]
        //i=0 means only takes s2 substr, j = 0 means only take s1 substr
        memset(&d[0][0], false, sizeof(bool)*(length1+1)*(length2+1));

        for (int j=0; j <=length2; ++j) {
            for (int i=0; i<=length1; ++i) {
                if (i ==0 && j == 0) {
                    d[i][j] = true;
                }
                else if (i ==0)
                {
                    d[i][j] = s2[j-1] == s3[j-1] && d[i][j-1] ;
                }
                else if (j == 0)
                {
                    d[i][j] = s1[i-1] == s3[i-1] && d[i-1][j] ;
                }
                else
                {
                    //d[i][j]= s1[i-1] == s3[i+j-1] ? d[i-1][j] : (s2[j-1] == s3[i+j-1] ? d[i][j-1]:false) ;
                    char c3 = s3[i+j-1];
                     d[i][j] = (s1[i-1]== c3 && d[i-1][j]) || (s2[j-1] == c3 && d[i][j-1]);

                }
            }
        }
        return d[length2][length1];
    }
};

//d[i][j], 1<= i <= length1, 1<= j <=length2
//define whether s1[0, i-1] and s2[0, j-1] can interleave and form s3[0, i+j-1]
//d[i][j] = s2[j-1] == s3[j-1] && d[0][j-1]  i=0
//          s1[i-1] == s3[i-1] && d[i-1][0]  j=0
//          s1[i-1] == s3[i+j-1] ? d[i-1][j] : (s2[j-1] == s3[i+j-1] ? d[i][j-1]:false) ; all other i j
//d[0][0] = true

//int main()
//{
//    //string s3("aadbbcbcac");
////    string s3("aadbbbaccc");
////    string s1("aabcc");
////    string s2("dbbca");
//    clock_t begin = clock();
//    
//
//    string s1("cbacbabcbcbbccbacbb");
//    string s2("baccacabaccc");
//    string s3("bcaacabcacbbbcabcccbccbaccbacbb");
//    Solution test;
//    bool result = test.isInterleave(s1, s2, s3);
//    
//    clock_t end = clock();
//    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
//    printf("result is %d\n", result);
//    printf("time :%f\n", elapsed_secs);
//    return 0;
//}



