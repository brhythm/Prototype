/**
 */

//Implement pow(x, n).

#include <cstdio>

class Solution {
public:
    double pow(double x, int n) {
        //warning, handle corner case
        if (n < 0) {
            return 1.0 / power(x, -n);
        }
        else
        {
            return power(x,n);
        }
    }
    
    double power(double x, int n)
    {
        if ( n == 0 ) {
            return 1;
        }
        double temp = pow(x, n/2);
        if ( n % 2 == 0) {
            return temp*temp;
        }
        else
        {
            //double remainder = pow(x, n%2);
            //else n%2 == 1
            return temp*temp*x;
        }
    }
};

//x^n = x^n/2 * x^n/2 * x^n%2