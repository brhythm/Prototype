/**
 Given a unsorted array. All elements are positive.
 Find contiguous subarray that sum up to a num
 */


vector<int> findSubarray(const vector<int>& input, int target)
{
    vector<int> result;
    if (!input.empty())
    {
        int i=0;
        int j=1;
        int sum = input[i];
        while( j < input.size())
        {
            if (sum == target)
            {
                printf("%d ~ %d\n", input[i], input[j]); 
                break; 
            }
            else if ( sum > target)
            {
                while (i < j && sum > target)
                {
                    sum-= input[i];
                    ++i;
                }
                if ( sum > target )
                {//increment j if got stuck
                    sum += input[j];
                    ++j; 
                }
            }
            else
            {
                sum += input[j];
                ++j;
            }
        }
    }
    return result;
}



