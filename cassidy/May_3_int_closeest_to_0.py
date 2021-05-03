def round(num: float):
    if num%1 == 0:
        return num
    if num > 0:
        return int(num - (num%1))
    else:
        return int(num + (1-(num%1)))

