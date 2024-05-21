def closest_pair(arr):
    # 배열을 정렬합니다.
    arr.sort()

    min_distance = float('inf')  # 최소 거리를 무한대로 초기화합니다.
    closest_pair = None  # 가장 가까운 두 항목을 저장할 변수를 초기화합니다.

    # 정렬된 배열에서 인접한 항목을 비교하면서 최소 거리를 찾습니다.
    for i in range(len(arr) - 1):
        distance = arr[i + 1] - arr[i]  # 인접한 항목의 거리를 계산합니다.
        if distance < min_distance:
            min_distance = distance
            closest_pair = (arr[i], arr[i + 1])

    return closest_pair, min_distance

# 예시 배열
arr = [1, 4, 7, 9, 13, 15]

# 가장 가까운 두 항목과 그 거리를 찾습니다.
closest_pair, min_distance = closest_pair(arr)
print("가장 가까운 두 항목:", closest_pair)
print("거리:", min_distance)
