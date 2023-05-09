import pytest
from odd_square_sum import odd_square_sum


odd_squares: list[int] = [
    1,
    9,
    25,
    49,
    81,
    121,
    169,
    225,
    289,
    361,
    441,
    529,
    625,
    729,
    841,
    961,
    1089,
    1225,
    1369,
    1521,
    1681,
    1849,
    2025,
    2209,
    2401,
    2601,
    2809,
    3025,
    3249,
    3481,
    3721,
    3969,
    4225,
    4489,
    4761,
    5041,
    5329,
    5625,
    5929,
    6241,
    6561,
    6889,
    7225,
    7569,
]


def gen_breakpoints(odds: list[int]) -> list[int]:
    """Generate breakpoints for testing."""
    breakpoints: list[int] = []
    for num in odds:
        last_place: int = num % 10
        break_point: int = num + (10 - last_place)
        if num == 1:
            break_point = 1
        breakpoints.append(break_point)
    return breakpoints


def gen_sums(odds: list[int]) -> list[int]:
    """Generate sum results for testing."""
    sums: list[int] = [0]
    accumulated: int = 1
    for num in odds:
        if num == 1:
            continue
        accumulated += num
        sums.append(accumulated)
    return sums


_breakpoints = gen_breakpoints(odds=odd_squares)
_sums = gen_sums(odds=odd_squares)

test_data = list(zip(_breakpoints, _sums))


@pytest.mark.parametrize("break_point, total", test_data)
def test_odd_square_sum(break_point: int, total: int):
    assert (
        odd_square_sum(break_point) == total
    ), f"The sum is incorrect at breakpoint {break_point}."

def test_odd_square_sum_v2():
    assert odd_square_sum(1) == 0
    assert odd_square_sum(2) == 1
    assert odd_square_sum(9) == 1
    assert odd_square_sum(10) == 10
    assert odd_square_sum(44) == 35
