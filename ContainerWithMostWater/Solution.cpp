/**
 */

//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container.

#include <vector>

using namespace std;
class Solution {
public:
    //Time O(N)
    int maxArea(vector<int> &height) {
        int maxVolume = 0;
        if (height.size() > 0) {
            int start = 0;
            int end = height.size()-1;
            while (start < end) {
                int height = min(height[start], height[end]); 
                int width = end-start;
                maxVolume = max(height*width, maxVolume);
                if (height[start] < height[end]) {
                    while (start <= end &&
                           height[start] <= height)
                        ++start;
                }
                else
                {
                    while (start <= end &&
                            height[end] <= height)
                    --end;
                }
            }
        }
        return maxVolume;
    }
};

//Note, this problem is different from largest rectangle from histogram. This problem only requires selecting two lines to form a container.
//It does not matter whether there is any shorter bar in between here. Thus scanning from two end to middle is OK,
//But largest rectangle requires considering everything between the two boarders, thus more complicated
