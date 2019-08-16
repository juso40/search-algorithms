def double_lin_search(arr, to_find):
    start, end = 0, len(arr) - 1

    while start <= end:
        if arr[start] == to_find:
            return start
        elif arr[end] == to_find:
            return end
        start += 1
        end -=1

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
    print(double_lin_search(arr, 8))
