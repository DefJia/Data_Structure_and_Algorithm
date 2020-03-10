a = [3,4,6,2,45,120,312,543,32,534,7645,1342,1234,32]


def quick_sort(array, l, r):
    if l < r:
        q = partition(array, l, r)
        quick_sort(array, l, q-1)
        quick_sort(array, q+1, r)


def partition(array, l, r):
    # return pivot
    pivot = array[l]
    while l < r:
        while l < r and array[r] >= pivot:
            r -= 1
        if l < r:
            array[l] = array[r]
        while l < r and array[l] <= pivot:
            l += 1
        if l < r:
            array[r] = array[l]
    a[l] = pivot
    return l


if __name__ == "__main__":
    quick_sort(a, 0, len(a)-1)
    print(*a)