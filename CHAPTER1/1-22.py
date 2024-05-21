class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None

    def is_empty(self):
        return len(self.items) == 0

def reverse_string(input_string):
    stack = Stack()
    reversed_string = ""

    # 입력 문자열을 스택에 넣기
    for char in input_string:
        stack.push(char)

    # 스택에서 문자를 pop하여 역순으로 출력 문자열 생성
    while not stack.is_empty():
        reversed_string += stack.pop()

    return reversed_string

# 사용자로부터 문자열 입력 받기
input_string = input("문자열을 입력하세요: ")

# 문자열을 역순으로 출력
print("입력한 문자열을 역순으로 출력:", reverse_string(input_string))
