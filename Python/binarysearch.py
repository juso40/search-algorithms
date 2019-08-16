def binary_search(arr, to_find, start=0, end=None):
    if end is None:
        return binary_search(arr, to_find, 0, len(arr) - 1)

    mid = (start + end) // 2

    if arr[mid] < to_find:
        return binary_search(arr, to_find, mid, end)
    elif arr[mid] > to_find:
        return binary_search(arr, to_find, start, mid)
    elif arr[mid] == to_find:
        return mid

    return -1


if __name__ == "__main__":
    arr = [
        0,
        12,
        8,
        3,
        7,
        92,
        1,
        14
    ]
    arr.sort()
    print(arr)
    print(binary_search(arr, 8))
