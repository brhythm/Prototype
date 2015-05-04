class MaxHeap
{
public:
    MaxHeap()
    :heapSize(0) 
    {
        elements.push_back(-1);//dummy
        //real elements starts from index 1
        buildMaxHeap();
    }

    //Time: O(lgN)
    void push(int value)
    {
        ++heapSize;
        elements.push_back(value);
        int index=heapSize;//index = [1, n]
        while (index >1  &&
               elements[index/2] < elements[index] )
        {
            swap(elements[index/2], elements[index]);
            index = index/2;
        } 
    }
    //O(1)
    int top() const
    {
        if (heapSize == 0)
        {
            throw runtime_error("Error: heap empty");
        }
        return elements[1];
    }
   
   //Time:O(lgN) 
    void pop()
    {
        if (heapSize == 0)
        {
            throw runtime_error("Error: heap empty");
        }
        swap(elements[heapSize--], elements[1]);
        maxHeapify(1);
        elements.pop_back();//remove last element, which is the largest
    }

private:
    //O(N)
    void buildmaxHeap()
    {
        for (int i=heapSize/2; i>=1; --i)
        {
            maxHeapify(i);
        }
    }

    //Time O(lgN)
    //heapify from the element at given index
    //index =[1,n]
    void maxHeapify(int index)
    {
        int leftIndex = index*2;
        int rightIndex = index*2+1;
        int largest = index;
        if (leftIndex <= heapSize && 
            elements[leftIndex] > elements[largest] )
        {
            largest = leftIndex;
        }
        if (rightIndex <= heapSize &&
            elements[rightIndex] > elements[largest])
        {
            largest = rightIndex;
        }
        if (largest != index)
        {
            swap(elements[index], elements[largest]);
            maxHeapify(largest);
        }//else done
    }

private:
   int heapSize;
   vector<int> elements;
}
