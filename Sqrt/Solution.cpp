/**
 */

//Implement int sqrt(int x).
//Compute and return the square root of x.



class Solution {
public:
    int sqrt(int x) {
        if (x < 2) {
            return x;//cos sqr(1)==1, sqr(0)==0, without this check, mid might be zero.
        }
        int start = 0;
        int end = x/2+1;
        while (start <= end) {
            int mid = (start + end)/2;
            int temp = x / mid;//WARNING, to prevent overflow
            if (temp < mid) {
                end = mid-1;
            }
            else if (temp > mid) {
                start = mid+1;
            }
            else
            {
                return mid;
            }
        }
        //if we come here, start must be end +1
        //give an estimate
        return (start+end)/2;
    }
};
//Note , square root of x falls into [0, x/2+1]
//binary search for root of x