A priority queue in C++ is an abstract data type that allows for efficient retrieval of the maximum or minimum element based on a priority associated with each element. The standard library in C++ provides a `std::priority_queue` class template that implements a max-heap by default (i.e., the element with the highest priority is at the top).

#### it is internally work as max heap.

#### it has no random access.

#### it has no const iterators.

#### it has no mutable iterators.

#### it has time in Olog(n) when pushing new element.

#### it has no indexing.

#### it has no iterators.

#### it has no copy constructor.

#### it has no copy assignment operator.

#### it has no move constructor.

#### it has no move assignment operator.

#### it has no swap function.

#### it has no begin and end functions.

#### it has no size function.

#### it has no indexing.

#### it has no iterators.

Here is a comprehensive guide to using `std::priority_queue` in C++:

### Basic Usage:

```cpp
#include <queue>
#include <iostream>

int main() {
    std::priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Access the top element
    std::cout << "Top element: " << pq.top() << std::endl;

    // Remove the top element
    pq.pop();

    // Check if the priority queue is empty
    if (pq.empty()) {
        std::cout << "Priority queue is empty." << std::endl;
    }

    return 0;
}
```

### Custom Comparison Function:

You can also use a custom comparison function to define your own priority. For example, to create a min-heap:

```cpp
#include <queue>
#include <iostream>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);

    std::cout << "Top element: " << pq.top() << std::endl;

    pq.pop();

    if (pq.empty()) {
        std::cout << "Priority queue is empty." << std::endl;
    }

    return 0;
}
```

### Extreme Cases:

Priority queues are particularly useful in scenarios where you need to efficiently maintain the maximum or minimum element.

#### Extreme Case 1: Finding the Kth Largest Element:

```cpp
#include <queue>
#include <vector>
#include <iostream>

int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {
    std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 4;

    int kthLargest = findKthLargest(nums, k);

    std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;

    return 0;
}
```

#### Extreme Case 2: Merging Sorted Files:

Suppose you have multiple sorted files, and you want to merge them into a single sorted sequence efficiently. A priority queue can be used for this:

```cpp
#include <queue>
#include <vector>
#include <iostream>

std::vector<int> mergeSortedFiles(const std::vector<std::vector<int>>& sortedFiles) {
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;

    std::vector<int> result;

    // Initialize the priority queue with the first element from each file
    for (int i = 0; i < sortedFiles.size(); ++i) {
        if (!sortedFiles[i].empty()) {
            pq.push({sortedFiles[i][0], {i, 0}});
        }
    }

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int value = current.first;
        int fileIndex = current.second.first;
        int elementIndex = current.second.second;

        result.push_back(value);

        // Move to the next element in the same file
        if (elementIndex + 1 < sortedFiles[fileIndex].size()) {
            pq.push({sortedFiles[fileIndex][elementIndex + 1], {fileIndex, elementIndex + 1}});
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> sortedFiles = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

    std::vector<int> merged = mergeSortedFiles(sortedFiles);

    std::cout << "Merged sorted sequence: ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

In this example, each element in the priority queue is a pair `(value, {fileIndex, elementIndex})`. The priority queue ensures that the smallest element is always at the top. The algorithm continues to pop the smallest element from the priority queue, add it to the result, and then push the next element from the same file onto the priority queue until all files are exhausted.

These examples demonstrate how priority queues can be powerful tools for solving various problems efficiently. The choice of using a max-heap or min-heap depends on the problem requirements.