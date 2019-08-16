"""
Simple linear search, useful for unsorted lists
"""


def linear_search(arr, to_find):
    for index, value in enumerate(arr):
        if value == to_find:
            return index
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
    print(linear_search(arr, 8))
