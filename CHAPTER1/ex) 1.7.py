def gcd(a, b):
    """유클리드 알고리즘을 사용하여 두 수의 최대공약수를 구하는 함수"""
    while b != 0:
        a, b = b, a % b
    return a

# 예시
num1 = 48
num2 = 18
result = gcd(num1, num2)
print("두 수의 최대공약수:", result)
