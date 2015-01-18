/**
 */

//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array A = [1,1,1,2,2,3],
//
//Your function should return length = 5, and A is now [1,1,2,2,3].

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) {
            return n;
        }
        
        int index = 0;
        bool isDuplicate = false;
        vector<int> array(A, A + n);
        
        A[index] = array[0];
        for (int i=1; i < n; ++i) {
           // printf("element i = %d\n", array[i]);
            if (array[i] == A[index]) {
                if (!isDuplicate) {
                    isDuplicate = true;
                    A[++index] = array[i];
                    //printf("debug1 duplicate %d, %d\n", array[i], index);
                }//else duplicate, skip array[i]
            }
            else
            {//a new number
                A[++index] = array[i];
                isDuplicate = false;
               // printf("debug2 new %d, %d\n", array[i], index);
            }
        }
        return index+1;
    }
};

//int main()
//{
//   // int A[] = {1,2,2};
//   // int A[] = {1,1,1,2,2,3};
//    int A[] = {1,1,1,2,2,2,3,3};
//   // printf("%d, %d\n", sizeof(A), sizeof(A[0]));
//    Solution test;
//    int result = test.removeDuplicates(&A[0], 8);
//    cout << result << endl;
//    for (int i=0; i < result; ++i) {
//        cout << A[i] << ",";
//    }
//    return 0;
//}

