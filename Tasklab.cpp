#include <bits/stdc++.h>
using namespace std;

class SortingAlgo
{
public:
    // print array
    void printArr(vector<int> &arr)
    {
        for (auto &val : arr)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // bubble sort algorithm
    /*
        vector<int> arr = {5, 2, 8, 1, 9, 3};
        1. first we will iterate over the array uning for loop, At first pass, our whole array comes under the unsorted part.
           We will start by comparing each adjacent pair. Since our array is of length 6, we have 5 pairs to compare.
        2. then we wil check if it is already sorted then we will move ahead
        3. then check if 5 is greter than 2 then we will swap those value
        4. repeat this process untill array is not being sorted
    */

    void bubbleSort(vector<int> &arr)
    {
        int temp;
        int isSorted = 0; // Variable to track if the array is already sorted

        for (int i = 0; i < arr.size() - 1; i++) // For each pass
        {
            isSorted = 1; // Assume the array is already sorted

            for (int j = 0; j < arr.size() - 1 - i; j++) // For comparison in each pass
            {
                if (arr[j] > arr[j + 1]) // Compare adjacent elements
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    isSorted = 0; // If swapping     occurs, the array is not yet sorted
                }
            }

            if (isSorted)
            {
                return; // If no swapping occurs in a pass, the array is already sorted
            }
        }
    }
         /* bubble sort end*/

    // selection sort algorithm
    /*
        vector<int> arr = {8, 0, 7, 1, 3};
        1. first we will iterate over the array uning for loop, At first pass, our whole array comes under the
           unsorted part. We will start by assuming 0 as the min index. Now, we’ll have to check among the remaining
           4 elements if there is still a lesser element than the first one.

        2. And when we compared the element at min index with the element at index 1, we found that 0 is less
           than 8 and hence we update our min index to 1.

        3. And now we keep checking with the updated min. Since 7 is not less than 0, we move ahead.

        4. And now we compared the elements at index 1 and 3, and 0 is still lesser than 1, so we move ahead
           without making any changes.

    */

    void SelectionSort(vector<int> &arr)
    {
        int indexOfMin, temp;

        for (int i = 0; i < arr.size() - 1; i++) // For each pass
        {
            indexOfMin = i; // Assume the current element is the minimum

            for (int j = i + 1; j < arr.size(); j++) // Find the minimum element in the remaining unsorted portion
            {
                if (arr[j] < arr[indexOfMin])
                {
                    indexOfMin = j; // Update the index of the minimum element
                }
            }

            // Swap arr[i] and arr[indexOfMin]
            temp = arr[i];
            arr[i] = arr[indexOfMin];
            arr[indexOfMin] = temp;
        }
    }

    /* selection sort end*/

    // insertion sort

    /*
        1. Start with the second element in the array.
        2. Compare the second element with the first element.
        3. If the second element is smaller, swap them.
        4. Move to the third element.
        5. Compare the third element with the elements to its left in the sorted part of the array.
        6. Shift the elements to the right until the correct position is found for the third element.
        7. Repeat steps 4-6 for the remaining elements in the unsorted part of the array.
        8. Continue until all elements are sorted.
    */
    void insertionSort(vector<int> &arr)
    {
        int key, j;

        for (int i = 1; i <= arr.size() - 1; i++) // Iterate over the array
        {
            key = arr[i]; // Select the key element to be inserted
            j = i - 1;    // Set the initial index of the previous element

            while (j >= 0 && arr[j] > key) // Compare the key with previous elements and shift them to the right if greater
            {
                arr[j + 1] = arr[j]; // Shift elements to the right
                j--;                 // Move to the previous element
            }

            arr[j + 1] = key; // Insert the key element at the correct position in the sorted subarray
        }
    }

    /* insertion sort end*/

    // merge sort
    /*
        1.Divide the array into two halves.
        2.Recursively sort the left half of the array.
        3.Recursively sort the right half of the array.
        4.Merge the two sorted halves to create a single sorted array.

        #To merge the two sorted halves:
            1. Create an empty temporary array to store the merged result.
            2. Compare the elements from the left and right halves.
            3. Take the smaller element and place it in the temporary array.
            4. Move to the next element in the respective half.
            5. Repeat steps 3-4 until all elements are processed in either the left or right half.
            6. Copy any remaining elements from the other half to the temporary array.
            7. Copy the merged result from the temporary array back to the original array.
    */
    void merge(vector<int> &arr, int mid, int low, int high)
    {
        int i, j, k, B[100];
        i = low;
        j = mid + 1;
        k = low;

        // Merge the two sorted halves into the temporary array B[]
        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                B[k] = arr[i];
                i++;
                k++;
            }
            else
            {
                B[k] = arr[j];
                j++;
                k++;
            }
        }

        // Copy any remaining elements from the left half to B[]
        while (i <= mid)
        {
            B[k] = arr[i];
            k++;
            i++;
        }

        // Copy any remaining elements from the right half to B[]
        while (j <= high)
        {
            B[k] = arr[j];
            k++;
            j++;
        }

        // Copy the merged result from B[] back to the original array arr[]
        for (int i = low; i <= high; i++)
        {
            arr[i] = B[i];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid = (low + high) / 2;

            // Recursively sort the left half
            mergeSort(arr, low, mid);

            // Recursively sort the right half
            mergeSort(arr, mid + 1, high);

            // Merge the sorted halves
            merge(arr, mid, low, high);
        }
    }

    /* merge sort end*/

    // quick sort algo
    /*
        1.Select a pivot element from the array (usually the first or last element).
        2.Partition the array into two subarrays: elements smaller than the pivot and elements greater than the pivot.
        3.Recursively apply steps 1-2 to the subarrays until the subarrays contain only one element or are empty.
        4.Concatenate the sorted subarrays to obtain the final sorted array.

        #To partition the array:

            1.Set the pivot as the first element (or any other chosen pivot selection method).
            2.Set two pointers: i pointing to the second element and j pointing to the last element.
            3.Move i to the right until an element greater than or equal to the pivot is found.
            4.Move j to the left until an element smaller than or equal to the pivot is found.
            5.If i < j, swap the elements at indices i and j.
            6.Repeat steps 3-5 until i >= j.
            7.Swap the pivot element with the element at index j (the final position of the pivot).
    */
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low]; // Select the pivot element as the first element in the partition
        int i = low + 1;      // Index to traverse from left to right
        int j = high;         // Index to traverse from right to left
        int temp;

        // Perform partitioning
        do
        {
            while (arr[i] < pivot)
            {
                i++; // Move the index to the right until an element greater than or equal to the pivot is found
            }
            while (arr[j] > pivot)
            {
                j--; // Move the index to the left until an element smaller than or equal to the pivot is found
            }
            if (i < j)
            {
                // Swap the elements at indices i and j
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while (i < j);

        // Swap the pivot element with the element at index j (final position of the pivot)
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        return j; // Return the partition index
    }

    void QuickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int partitionIndex;
            partitionIndex = partition(arr, low, high); // Partition the array and get the partition index
            QuickSort(arr, low, partitionIndex - 1);    // Recursively sort the left partition
            QuickSort(arr, partitionIndex + 1, high);   // Recursively sort the right partition
        }
    }

    /* quick sort end*/
};

class SerchingAlgo
{
public:
    // algorithm for linear search

    /* 1. We’ll start with coding the linear search. Create an integer function linearSearch.
          This function will receive the array, its size, and the element to be searched as its parameters.

       2. Run a for loop from its 0 to the last index, checking the if condition at every index whether the element
        at that index equals the search element. If yes, return the index, else continue the search.

       3. If the element could not be found until the last, return -1.

    */

    void linearSearch(vector<int> &arr, int findElement)
    {
        int found = 0; // Variable to track if the element is found
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == findElement)
            {
                found = 1; // Set found to 1 if the element is found
                break;     // Exit the loop since the element is found
            }
        }

        if (found)
        {
            cout << findElement << " is found" << endl; // Element is found in the array
        }
        else
        {
            cout << findElement << " is not found" << endl; // Element is not found in the array
        }
    }

    //linear search end


    // #binary search
    /*                            1. Create a function named binarySearch and pass the same three parameters as we did in linear search. Here, we will maintain three integer variables low, mid, and high. Low  stores are the beginning of the search space, and high stores the end. Mid stores the middle element of our search space, which is   mid = (low+high)/2.

       2. Check whether the mid element equals the search element. If yes, return mid, else if the mid element is greater than the search element, then the search element must lie on the left side of the current space and high becomes mid-1, else if the mid element is less than the search element, then we’ll shift to the right side, and low becomes mid+1.

       3. This way, we reduce our search space into half every time we repeat step 2. Now our new mid becomes (low+high)/2, and we repeat step 2. And keep repeating until either we find the search element or the low becomes greater than the high.
    */

    void binarySearch(vector<int> &arr, int findElement)
    {
        int low, mid, high;
        low = 0;
        high = arr.size() - 1;
        int found = 0; // Variable to track if the element is found

        // Keep searching until low <= high
        while (low <= high)
        {
            mid = (low + high) / 2; // Calculate the mid index

            if (arr[mid] == findElement)
            {
                found = 1; // Set found to 1 if the element is found
            }

            if (arr[mid] < findElement)
            {
                low = mid + 1; // Adjust the low index if the element is in the right half
            }
            else
            {
                high = mid - 1; // Adjust the high index if the element is in the left half
            }
        }

        if (found)
        {
            cout << findElement << " is found" << endl; // Element is found in the array
        }
        else
        {
            cout << findElement << " is not found" << endl; // Element is not found in the array
        }
    }

    //binary search end

    // Dfs

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
    {
        // Mark the current node as visited
        visited[node] = true;
        cout << node << " ";

        // Traverse all adjacent nodes of the current node
        for (int i = 0; i < graph[node].size(); i++)
        {
            int adjacentNode = graph[node][i];
            // If the adjacent node is not visited, recursively call dfs on it
            if (!visited[adjacentNode])
            {
                dfs(graph, visited, adjacentNode);
            }
        }
    }

    void dfsTraversal(vector<vector<int>> &graph, int startNode)
    {
        int numNodes = graph.size();
        vector<bool> visited(numNodes, false);

        // Call dfs on the start node
        dfs(graph, visited, startNode);
    }

    //dfs end
};
int main()
{
    vector<int> arr = {5, 2, 8, 1, 9, 3};

    // Sorting class object
    SortingAlgo sort;

    cout << "Bubble sort running" << endl;
    sort.bubbleSort(arr); // bubble sort function called
    sort.printArr(arr);   // print array

    cout << "Selction sort running" << endl;
    sort.SelectionSort(arr); // selection sort function called
    sort.printArr(arr);      // print array

    cout << "Insertion sort running" << endl;
    sort.insertionSort(arr); // insertion sort function called
    sort.printArr(arr);      // print array

    cout << "Merge sort running" << endl;
    sort.mergeSort(arr, 0, arr.size() - 1); // merge sort function called
    sort.printArr(arr);                     // print array

    cout << "Quick sort running" << endl;
    sort.QuickSort(arr, 0, arr.size() - 1); // merge sort function called
    sort.printArr(arr);                     // print array

    // searching class object
    SerchingAlgo search;
    int findElement = 9;

    cout << "Linear search running" << endl;
    search.linearSearch(arr, findElement); // bubble sort function called

    cout << "Binary search running" << endl;
    search.binarySearch(arr, findElement); // bubble sort function called


    /* inputs for dfs*/
    int numNodes = 7;
    int numEdges = 7;

    vector<vector<int>> graph(numNodes);

    // Define the edges of the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {4, 6}
    };

    //Add the edges to the graph
    for (const auto& edge : edges)
    {
        int node1 = edge.first;
        int node2 = edge.second;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode = 0;

    cout << "DFS traversal starting from node " << startNode << ": ";
    search.dfsTraversal(graph, startNode);

    /* dfs end */



    return 0;
}
