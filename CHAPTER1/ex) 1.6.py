def find_divisors(n):
    """주어진 수의 약수를 찾는 함수"""
    divisors = []
    for i in range(1, n + 1):
        if n % i == 0:
            divisors.append(i)
    return divisors

def gcd(a, b):
    """두 수의 최대공약수를 찾는 함수"""
    # 각 수의 약수 리스트를 구함
    divisors_a = find_divisors(a)
    divisors_b = find_divisors(b)
    
    # 두 수의 약수 리스트에서 공통된 요소를 찾음
    common_divisors = set(divisors_a) & set(divisors_b)
    
    # 공통된 요소 중에서 가장 큰 값을 반환
    if len(common_divisors) > 0:
        return max(common_divisors)
    else:
        return None

# 예시
a = 30
b = 18
result = gcd(a, b)
print("두 수의 최대공약수:", result)
