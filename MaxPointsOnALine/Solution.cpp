/**
 * Given n points on a 2D plane,
 *  find the maximum number of points that lie on the same straight line.
 */

#include <vector>
#include <unordered_map>
#include <climits>
 // Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

using namespace std;

class Solution {
public:
    //Time O(N^2) Space O(N)
    int maxPoints(vector<Point> &points) {
        if (points.empty())
        {
            return 0;
        }
        int globalMax =1;//BUG here, if there is only one point, max is 1
        unordered_map<double, int> slopeMap;
        for (int i=0; i < points.size(); ++i)
        {// for each node
            int duplicateCount= 0;
            int localMax = 1;
            slopeMap.clear();
            // iterate every other node
            for (int j=0; j < points.size(); ++j)
            {
                int count =0;
                if (j == i)
                {
                    continue;
                }
                if (points[i].x == points[j].x &&
                    points[i].y == points[j].y)
                {// other node is duplicate with this node
                    ++duplicateCount;//Bug here about how to add duplicate to localMax
                    ++localMax;
                }
                else if (points[i].x == points[j].x)
                {//vertical k = max_double
                    count = ++slopeMap[INT_MAX];
                    localMax = max(localMax, count+ 1/*this node*/ + duplicateCount/*duplicate this*/);
                 }
                else
                {
                    double k = (double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x);
                    count = ++slopeMap[k];
                    localMax = max(localMax, count+ 1/*this node*/ + duplicateCount/*duplicate this*/);
                }
                globalMax= max(globalMax, localMax);
            }
        }
        return globalMax;
    }
};

/*Note:
 *  y = kx + b, k is slope, b is intercept
 *  1) Intuitive way: Get every pair of nodes ( C 2 N = O(N^2)), calculate k,b. So we get N^2 straight lines
 *  for each line, check whether the rest of n-2 nodes are on this line (O(N)),
 *  maintain a global max
 *  Overall Time: O(N^3), Space O(1)
 *
 *  One question here is when we get N^2 straight lines, why not get the (k,b) pair with most duplicate,
 *  that line would be the line with most points on it , right ?
 *  Yes, that will work. But once we get the maxLineCount, we have to convert it to maxPointsOnLine.
 *  e.g. Two points on line : C2 2 = 1
 *       Three points on line: C2 3 = 3
 *       Four points on line: C2 4 = 6
 *       You are give the value on the right side, have to figure out left side,not easy
 *       Overall Time : O(N^2), Space O(N^2)
 *  2) For each node, calculate K (slope) with every other node O(N)
 *     k = (y2-y1)/(x2-x1), get maxSlopeCount, i.e. same k means on the same line
 *
 *      maintain global max
 *    Overall: Time O(N^2) Space O(N)
 *
 *  Corner case:
 *  vertical line: k = unlimit
 *  duplicate nodes
*/
