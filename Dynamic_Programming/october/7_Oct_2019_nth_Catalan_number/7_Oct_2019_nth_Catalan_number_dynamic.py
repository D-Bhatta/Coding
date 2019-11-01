#dynamic implementation of catalna

def catalan(n):
    if(n == 0 or n == 1):
        return 1
    
    table = [0 for i in range(n+1)]

    table[0] = 1
    table[1] = 1

    for i in range(2,n+1):
        table[i] = 0
        for j in range(i):
            table[i] = table[i] + table[j] * table[i-j-1]
    
    return table[n]

#driver code
for i in range(11):
    print(" {}".format(catalan(i)))