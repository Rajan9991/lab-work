#include <iostream>
#include <vector>

class SortingAlgorithm {
public:
    void sort(std::vector<int>& arr) {
        performSort(arr);
    }

private:
    // Bubble Sort Algorithm
    void performSort(std::vector<int>& arr) {
        int n = arr.size();
        bool swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;

            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) {
                // If no two elements were swapped in the inner loop, the array is already sorted
                break;
            }
        }
    }
};

class SearchAlgorithm {
public:
    int search(const std::vector<int>& arr, int target) {
        return performSearch(arr, target);
    }

private:
    // Binary Search Algorithm
    int performSearch(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Element not found
    }
};

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};

    // Sorting the numbers using bubble sort
    SortingAlgorithm sorter;
    sorter.sort(numbers);

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int target = 8;

    // Searching for the target number using binary search
    SearchAlgorithm searcher;
    int index = searcher.search(numbers, target);

    if (index != -1) {
        std::cout << "Found " << target << " at index " << index << std::endl;
    } else {
        std::cout << target << " not found in the array" << std::endl;
    }

    return 0;
}
