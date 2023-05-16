def is_palindrome(num: str) -> bool:
    start, end = 0, len(num) - 1
    while True:
        if start >= end:
            return True
        if num[start] != num[end]:
            return False
        start += 1
        end -= 1


def is_binary_palindrome(num: int) -> bool:
    return is_palindrome(bin(num)[2:])
