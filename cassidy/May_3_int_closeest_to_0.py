def round(num: float):
    return (int(((num + (1-(num%1))), (num - (num%1)))[num > 0]), num)[num%1 == 0]