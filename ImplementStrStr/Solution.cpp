/**
 */

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//The signature of the function had been updated to return the index instead of the pointer.
#include <stdio.h>
#include <string.h>
#include <iterator>
using namespace std;
//warning, null char is NOT nullptr!!!
//brute force is a bit slow, not accecpted by the website
//Note, SMALL optimization makes a big difference
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (needle == nullptr ||
            haystack == nullptr )
        {
            return -1;
        }
        int stackLength = strlen(haystack);
        int needleLength = strlen(needle);
        if (stackLength < needleLength)
        {
            return -1;
        }
        if(stackLength >0 && needleLength == 0)
        {
            return 0;
        }
        
        char *stackHead = haystack;
        char *needleHead = needle;
        int steps = 0;
        int maxSteps = stackLength - needleLength + 1;
        int resultIndex = -1;
  
        while ( steps < maxSteps) {
            
            while ( *haystack &&
                    *haystack != *needle ){
                ++haystack;
                ++steps;
            }
            if (*haystack == *needle)
            {//first letter match
                char* firstOccur = haystack;
                while ( *needle &&
                       *haystack == *needle) {
                    ++haystack;
                    ++needle;
                }
                if (!*needle)
                {//match needle
                    //printf("%s\n", firstOccur);
                    resultIndex = distance(stackHead, firstOccur);
                    break;
                }
                else
                {//only partial match
                    haystack = ++firstOccur;
                    needle = needleHead;
                    ++steps;
                }
            }//reach the end of haystack
        }
        
        return resultIndex;
        
    }
};
//
//int main ()
//{
//    char haystack[] = "aaa";
//    char needle[] = "a";
//    Solution test;
//    int result = test.strStr(haystack, needle);
//    printf("result:%d\n", result);
//
//}

