# python3

from random import randint


def partition3(array, left, right):
    pivot = array[left]
    l = i = left
    r = right
    while i<=r:
        if array[i] < pivot:
            array[i], array[l] = array[l], array[i]
            i += 1
            l += 1
        elif array[i] > pivot:
            array[i], array[r] = array[r], array[i]
            r -= 1
        else:
            i += 1
    return l, r


def randomized_quick_sort(array, left, right):
    if left >= right:
        return
    k = randint(left, right)
    array[left], array[k] = array[k], array[left]
    m1, m2 = partition3(array, left, right)
    randomized_quick_sort(array, left, m1 - 1)
    randomized_quick_sort(array, m2 + 1, right)


if __name__ == '__main__':
    input_n = int(input())
    elements = list(map(int, input().split()))
    assert len(elements) == input_n
    randomized_quick_sort(elements, 0, len(elements) - 1)
    print(*elements)
