#include <vector>
#include <iostream>
#include <cmath>  // std::sqrt(x)
#include <algorithm>  // std::min(x, y)

/*
Requiers a sorted array
Instead of doing a linear sort we just jump in bigger steps ahead.
While our item is lower than the value we search for, jump.
Once our item is bigger, use linear seach from the last jump step.
Complexity O(sqrt(n))
*/

int jumpSearch(const std::vector<int> &arr, int to_find){
    int n = arr.size();
    int step = std::sqrt(n);
    int step_locked = step;

    int prev;
    while (arr[std::min(step, n) -1] < to_find){
        prev = step;
        step += step_locked;
        if (prev >= n){
            return -1;  // Could not find the value in the array
        }
    }

    while (arr[prev] < to_find){
        prev++;
        if (prev == std::min(step, n)){
            return -1;
        }
    }
    
    if (arr[prev] == to_find){
        return prev;
    }

    return -1;
}

int main(){
    std::vector<int> arr = {0, 4, 8, 2, 6, 10, 3, 7, 1, 20, 11};
    std::sort(arr.begin(), arr.end());  // For binary search we need a sorted array

    for (auto v: arr){
        std::cout << v << " | ";
    }

    std::cout << jumpSearch(arr, 8) << std::endl; 

}