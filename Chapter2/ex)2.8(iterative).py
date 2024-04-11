#반복구조의 팩토리얼 알고리즘 함수
def factorial(n):
    result = 1
    for k in range(n, 0, -1):
        result *= k
    return result
#함수 구현을 위한 조치
num = int(input("양의 정수를 입력하세요: "))
result = factorial(num)
print(f"{num}의 팩토리얼은 {result}입니다.")
