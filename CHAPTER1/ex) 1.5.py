def find_divisors(number):
    # 주어진 수의 약수를 찾는 함수
    divisors = []
    for i in range(1, number + 1):
        if number % i == 0:
            divisors.append(i)
    return divisors

def find_gcd(a, b):
    # 주어진 두 수의 최대공약수를 찾는 함수
    divisors_a = find_divisors(a)
    divisors_b = find_divisors(b)
    
    common_divisors = []
    for divisor in divisors_a:
        if divisor in divisors_b:
            common_divisors.append(divisor)
    
    return max(common_divisors)

# 두 수 입력 받기
num1 = int(input("첫 번째 수 입력: "))
num2 = int(input("두 번째 수 입력: "))

# 최대공약수 계산 및 출력
gcd = find_gcd(num1, num2)
print("두 수의 최대공약수:", gcd)
