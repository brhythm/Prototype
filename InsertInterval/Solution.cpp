/**
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
//WARNING, Be careful about using iterators in Alg. If you save the iterator, it might be invalid later when you use it
//If a reallocation happens, all iterators, pointers and references related to the container are invalidated.
class Solution {
public:
    //Time O(N), Space O(N); 
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        Interval guard(INT_MAX, INT_MAX);//len is zero
        intervals.push_back(guard);
        for (vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); ++iter) {
            Interval current = *iter;
            if (newInterval.start > current.end) {
                //newInterval is totally bigger
                result.push_back(current);
            }
            else if (newInterval.end < current.start)
            {   //newInterval is totally smaller
                result.push_back(newInterval);
                result.insert(result.end(), iter, intervals.end());//print current til the last element
                break;
            }
            else
            {   // overlap, merge current into newInterval
                int newStart = min(current.start, newInterval.start);
                int newEnd = max(current.end, newInterval.end);
                newInterval = Interval(newStart, newEnd);
            }
        }
        result.pop_back();//remove guard
        return result;
    }
    
};
// Note , the alg is :
// if newInterval > currentInterval, insert current
// else if newInterval < currentInterval, insert newInterval, insert current until the the last element, terminate
// else, they overlap. Merge current into newInterval
// Since we would only insert newInterval if we find sth larger than it, let's insert a guard node at the end
// to make sure newInterval would be inserted

int main()
{//[[0,2],[3,3],[6,11]], [9,15]
    vector<Interval> intervals;
        intervals.push_back(Interval(0,2));
        intervals.push_back(Interval(3,3));
        intervals.push_back(Interval(6,11));
    
    Interval newInterval(9, 15);
    Solution test;
    vector<Interval> result = test.insert(intervals, newInterval);
    for (Interval& oneInterval: result) {
        printf("[%d,%d],", oneInterval.start, oneInterval.end);
    }
}


