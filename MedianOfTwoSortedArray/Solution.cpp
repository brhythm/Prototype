//There are two sorted arrays A and B of size m and n respectively.
//Find the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).
#include <algorithm>
#include <cmath>
using namespace std;

//TODO Do it again!!!!
class Solution {
public:
double findMedianSortedArrays(int A[], int m, int B[], int n) {
     if((n+m)%2 ==0)
     {
       return (GetMedian(A,m,B,n, (m+n)/2) + GetMedian(A,m,B,n, (m+n)/2+1))/2.0;
     }
     else
       return GetMedian(A,m,B,n, (m+n)/2+1);
   }
      int GetMedian(int a[], int n, int b[], int m, int k)
       {
            if (n <= 0) return b[k-1];
            if (m <= 0) return a[k-1];
            if (k <= 1) return min(a[0], b[0]);
            if (b[m/2] >= a[n/2])
            {
                 if ((n/2 + 1 + m/2) >= k)
                      return GetMedian(a, n, b, m/2, k);
                 else
                      return GetMedian(a + n/2 + 1, n - (n/2 + 1), b, m, k - (n/2 + 1));
            }
            else
            {
                 if ((m/2 + 1 + n/2) >= k)
                      return GetMedian( a, n/2,b, m, k);
                 else
                      return GetMedian( a, n, b + m/2 + 1, m - (m/2 + 1),k - (m/2 + 1));
            }
       }

};


//
//If (m+n)/2 > k && a[m/2-1] > b[n/2-1] , drop Section 2
//If (m+n)/2 > k && a[m/2-1] < b[n/2-1] , drop Section 4
//If (m+n)/2 < k && a[m/2-1] > b[n/2-1] , drop Section 3
//If (m+n)/2 < k && a[m/2-1] < b[n/2-1] , drop Section 1
//
//int main()
//{
//    Solution test;
//    vector<int> array1 = {1};
//    vector<int> array2 = {1};
//    double result =test.findMedianSortedArrays(&array1[0], array1.size(), &array2[0], array2.size());
//    printf("result = %f\n", result);
//    return 0;
//}
