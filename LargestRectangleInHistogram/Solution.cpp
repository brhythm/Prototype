/**
 */
//
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//For example,
//Given height = [2,1,5,6,2,3],
//return 10.

#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    //Time O(N), Space O(N)
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);//push dummy value to force everything in front of it being poped out
        stack<int> barsToExtend;//store index of the bars that could be extended
        int maxArea = 0;
        for (int i=0; i < height.size(); ++i)
        {
            int current = height[i];
            int stackTopHeight = barsToExtend.empty() ? -1 : height[barsToExtend.top()];//bug here, let height 0 be pushed into the stack
            if (current < stackTopHeight)
            {// current bar cut the existing bar groups, pop out bars that are CUT, calculate candidate rectangle
                int candidateHeight = 0;
                while (!barsToExtend.empty() &&
                       height[barsToExtend.top()] > current) {
                    candidateHeight = height[barsToExtend.top()];
                    barsToExtend.pop();
                    //printf("i=%d, top index=%d\n", i , barsToExtend.top());
                    int stackTopIndex = barsToExtend.empty() ? -1 : barsToExtend.top();
                    int candidateWidth =  i - 1 - stackTopIndex; // WARNING bug here.Must use stackTopIndex to calculate width
                    //printf("debug h = %d, w = %d\n", candidateHeight, candidateWidth);
                    //calculate candidate one
                    maxArea = max(maxArea, candidateHeight*candidateWidth);
                }//now stack.top <= current, which means that bar was not cut, could still be extended, leave it in the stack
            }
            //else  current>= stackTopHeight
            barsToExtend.push(i);
        }

        return maxArea;
    }
};
//Note:
//We maintain a stack that has the bars that could be extended
//Only calc rectangle area when a bar is pop out of the stack, because bars in the stack might still be extended further
//push index in the stack s.t. it is easy to calc width
//
//In the alg, every bar MUST be pushed into the stack otherwise that solo bar area would not be calculated
//Push a dummy 0 at the end of height to force everything to be poped out

//int main()
//{
//    //vector<int> height = {0, 9};
//    //vector<int> height= {2,1,5,6,2,3};
//    //vector<int> height = {1};
//    //vector<int> height = {1,2,2};
//    vector<int> height = {0,0,0,0,0,0,0,0,2147483647};
//    Solution test;
//    int result = test.largestRectangleArea(height);
//    printf("max area = %d\n", result);
//    return 0;
//}
