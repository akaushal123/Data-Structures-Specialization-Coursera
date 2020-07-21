# python3
import collections
from sys import stdin
from bisect import bisect_left, bisect_right

START = 1
POINT = 2
END = 3


def points_cover_naive(starts, ends, points):
    assert len(starts) == len(ends)
    count = [0] * len(points)

    for index, point in enumerate(points):
        for start, end in zip(starts, ends):
            if start <= point <= end:
                count[index] += 1

    return count


def points_cover(starts, ends, points):
    cnt = [0] * len(points)
    point_map = collections.defaultdict(set)

    list_point = []
    for x in starts:
        list_point.append((x, START))

    for x in ends:
        list_point.append((x, END))

    for x in range(len(points)):
        point = points[x]
        list_point.append((point, POINT))
        point_map[point].add(x)

    list_point.sort(key=lambda x: (x[0], x[1]))

    segment_count = 0
    for p in list_point:
        if p[1] == START:
            segment_count += 1
        if p[1] == END:
            segment_count -= 1
        if p[1] == POINT:
            indices = point_map[p[0]]
            for i in indices:
                cnt[i] = segment_count

    return cnt


if __name__ == '__main__':
    data = list(map(int, stdin.read().split()))
    n, m = data[0], data[1]
    input_starts, input_ends = data[2:2 * n + 2:2], data[3:2 * n + 2:2]
    input_points = data[2 * n + 2:]

    output_count = points_cover(input_starts, input_ends, input_points)
    print(*output_count)
