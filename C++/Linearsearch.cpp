#include <vector>
#include <iostream>

int linearSearch(const std::vector<int> &arr, int to_find){  // Returns the index of the element, if not found returns -1.
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == to_find){
            return i;  // index found
        }
    }
    return -1;  // Element is not in the array
}

int main(){
    std::vector<int> arr = {0, 4, 8, 2, 6, 10, 3, 7, 1, 20, 11};
    std::cout << linearSearch(arr, 8) << std::endl;

}