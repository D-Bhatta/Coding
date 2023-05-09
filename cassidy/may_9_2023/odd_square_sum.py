def odd_square_sum(num) -> int:
    """Return the odd square sum of a number."""
    if num == 1:
        return 0
    total = 0
    for index in range(1, num + 1, 2):
        square = index**2
        if square > num:
            return total
        if square < num:
            total += square
    return total
