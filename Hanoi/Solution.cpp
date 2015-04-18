/*
 In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes 
 which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom 
 (e g , each disk sits on top of an even larger one) You have the following constraints:
 (A) Only one disk can be moved at a time
 (B) A disk is slid off the top of one rod onto the next rod
 (C) A disk can only be placed on top of a larger disk
 Write a program to move the disks from the first rod to the last using Stacks
 */
#include <algorithm>
#include <assert.h>
#include <stack>
using namespace std;
class Hanoi {
public:
    Hanoi(int n)
    {
        for (int i=n; i >=1; --i) {
            towers[0].push(i);
        }
    }
    void solve3TowerHanoi()
    {
        int n = towers[0].size();
        solve(n, 0, 2);
    }

private:
    //solve hanoi with N disks
    //move these N disks from source to target
    void solve(int n, int source, int target)
    {
        if (n == 1) {
            move(source, target);
        }
        else
        {
            int temp = 0;
            //find temp tower index
            for (int i=0; i < 3; ++i) {
                if (i != source && i != target)
                {
                    temp = i;
                    break;
                }
            }
            solve(n-1, source, temp);
            move(source, target);
            solve(n-1, temp, target);
        }
    }
    
    void move(int source, int target)
    {
        if (!towers[source].empty()) {
            int disk = towers[source].top();
            //printf("move %d from tower %d to tower %d\n", disk, source, target);
            towers[source].pop();
            towers[target].push(disk);
        }//else do nothing
    }
    
private:
    stack<int> towers[3];
};
//Recursive Alg (When there are 3 towers ):
//1) Move n-1 disks from A to B
//2) Move nth disk from A to C
//3) Move n-1 disks from B to C
//
//Time: T(n) = 2T(n-1) + 1
// T(n) = 2^N 
//Note that in step 1 and step 3, there will always be a third tower aviable ,
//which is used as helper tower to store temp disks. We never have to
//worry about the disks we put on temp tower violates the rule(sorted from small to big)
//Look at our algorithm, we put the largest (nth) disk at the bottom.
int main()
{
    Hanoi test(4);
    test.solve3TowerHanoi();
    return 0;
}


