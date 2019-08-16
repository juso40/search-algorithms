#include <vector>
#include <iostream>
#include <algorithm>  // std::sort()

/*
Binary search uses the information that we have of a sorted list.
After each iteration we can ignore half of the list.
If our value is less than the item in the middle of our search interval,
we can narrow it down to the lower half of the search interval, vice versa.
Complexity O(log(n))
*/

int binarySearch(const std::vector<int> &arr, int to_find, int left = 0, int right = -1){
    if (right == -1){
        return binarySearch(arr, to_find, left, arr.size() - 1);
    }

    int mid = (left + right) / 2;

    if (arr[mid] == to_find){
        return mid;
    }
    else if (arr[mid] < to_find){
        return binarySearch(arr, to_find, mid, right);
    }
    else if (arr[mid] > to_find){
        return binarySearch(arr, to_find, left, mid);
    }
    else{
        return -1;  // We could not find the element in the array
    }
}

int main(){
    std::vector<int> arr = {0, 4, 8, 2, 6, 10, 3, 7, 1, 20, 11};
    std::sort(arr.begin(), arr.end());  // For binary search we need a sorted array

    for (auto v: arr){
        std::cout << v << " | ";
    }

    std::cout << binarySearch(arr, 8) << std::endl; 

}
