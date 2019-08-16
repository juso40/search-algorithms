#include <vector>
#include <iostream>

/*
Basically the same as standard linear search,
except that we search from the start and the end
Usefull for unsorted arrays.
*/

int double_linSearch(const std::vector<int> &arr, int to_find){
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end){
        if (arr[start] == to_find){
            return start;
        }
        else if (arr[end] == to_find){
            return end;
        }
        start++;
        end--;
    }
    return -1;  //Could not find value in array
}

int main(){
    std::vector<int> arr = {0, 4, 8, 2, 6, 10, 3, 7, 1, 20, 11};
    std::cout << double_linSearch(arr, 8) << std::endl;
}