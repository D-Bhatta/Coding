import pytest
from binary_palidrome import is_binary_palindrome


@pytest.mark.parametrize(
    "index, is_bin, num, bin_repr",
    [
        (1, True, 3, 11),
        (2, True, 5, 101),
        (3, True, 7, 111),
        (4, True, 9, 1001),
        (5, True, 15, 1111),
        (6, True, 17, 10001),
        (7, True, 21, 10101),
        (8, True, 27, 11011),
        (9, True, 31, 11111),
        (10, True, 33, 100001),
        (11, True, 45, 101101),
        (12, True, 51, 110011),
        (13, True, 63, 111111),
        (14, False, 4, 100),
        (15, False, 8, 1000),
        (16, False, 12, 1100),
        (17, False, 13, 1101),
        (18, False, 16, 10000),
        (19, False, 28, 11100),
        (20, False, 29, 11101),
        (21, False, 48, 110000),
        (22, False, 49, 110001),
        (23, False, 35, 100011),
    ],
)
def test_is_binary_palindrome(index: int, is_bin: bool, num: int, bin_repr: int):
    assert (
        is_binary_palindrome(num) == is_bin
    ), f"Test failed at Test-{index} for {bin_repr}"
