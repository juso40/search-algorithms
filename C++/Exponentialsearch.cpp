#include <vector>
#include <iostream>
#include <algorithm>  // std::min(x, y)

/*
Exponential search first narrows down the range where our value is,
then uses binary search to find its index.
Requiers a sorted array
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

int exponentialSearch(const std::vector<int> &arr, int to_find){
    int expo = 1;
    int n = arr.size() - 1;
    while (expo < n && arr[expo] < to_find){
        expo *= 2;
    }
    return binarySearch(arr, to_find, expo / 2, std::min(expo, n));
}

int main(){
    std::vector<int> arr = {0, 4, 8, 2, 6, 10, 3, 7, 1, 20, 11};
    std::sort(arr.begin(), arr.end());  // For binary search we need a sorted array

    for (auto v: arr){
        std::cout << v << " | ";
    }

    std::cout << exponentialSearch(arr, 8) << std::endl; 

}