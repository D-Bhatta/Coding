""" COINS - Bytelandian gold coins
#dynamic-programming
In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input
The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.

Output
For each test case output a single line, containing the maximum amount of American dollars you can make.

Example
Input:
12
2

Output:
13
2
You can change 12 into 6, 4 and 3, and then change these into $6+$4+$3 = $13. If you try changing the coin 2 into 3 smaller coins, you will get 1, 0 and 0, and later you can get no more than $1 out of them. It is better just to change the 2 coin directly into $2. """
# prefetch function(map)
def prefetch(hashmap,x):
    """ recursively add to hashmap from 1000 """
    if x == 1001:
        return 0
    if x == 0:
        return 0
    # divide by 2,3,4
    i = x//2
    j = x//3
    k = x//4
    # if not in hashmap, call prefetch
    if i in hashmap:
        i = hashmap[i]
    else:
        prefetch(hashmap,i)
        i = hashmap[i]
    if j in hashmap:
        j = hashmap[j]
    else:
        prefetch(hashmap,j)
        j = hashmap[j]
    if k in hashmap:
        k = hashmap[k]
    else:
        prefetch(hashmap,k)
        k = hashmap[k]
    # add results
    result = i + j + k
    # store in hashmap
    if result < x:
       hashmap[x] = x
    else:
        hashmap[x] = result
    if x+1 == 1001:
        return
    prefetch(hashmap, x+1)
    
def prefetch_millions(hashmap,x):
    """ recursively add to hashmap from 10 million """
    if x == 0:
        return 0
    # divide by 2,3,4
    i = x//2
    j = x//3
    k = x//4
    # if not in hashmap, call prefetch
    if i in hashmap:
        i = hashmap[i]
    else:
        prefetch(hashmap,i)
        i = hashmap[i]
    if j in hashmap:
        j = hashmap[j]
    else:
        prefetch(hashmap,j)
        j = hashmap[j]
    if k in hashmap:
        k = hashmap[k]
    else:
        prefetch(hashmap,k)
        k = hashmap[k]
    # add results
    result = i + j + k
    # store in hashmap
    if result < x:
       hashmap[x] = x
    else:
        hashmap[x] = result
    
# coins function(map, num)
def coins(hashmap, x):
    if x in hashmap:
        return hashmap[x]
    # divide by 2,3,4
    i = x//2
    j = x//3
    k = x//4
    # if not in hashmap, call coins
    if i in hashmap:
        i = hashmap[i]
    else:
        i = coins(hashmap,i)
    if j in hashmap:
        j = hashmap[j]
    else:
        j = coins(hashmap,j)
    if k in hashmap:
        k = hashmap[k]
    else:
        k = coins(hashmap,k)
    # add results
    result = i + j + k
    if result<x:
        return x
    # return result
    else:
        return result

# main function
def main():
    # prefetch hashmap of results till 10 million and store in dp
    # create hashmap
    hashmap = {}
    # manually store results till 12
    hashmap[0] = 0
    hashmap[1] = 1
    hashmap[2] = 2
    hashmap[3] = 3
    hashmap[4] = 4
    hashmap[5] = 5
    hashmap[6] = 6
    hashmap[7] = 7
    hashmap[8] = 8
    hashmap[9] = 9
    hashmap[10] = 10
    hashmap[11] = 11
    hashmap[12] = 13
    
    # call prefetch(map)
    # for 1000s
    prefetch(hashmap,13)
    # for millions
    prefetch_millions(hashmap, 100000000)
    # loop for input
    while(True):
        # take input
        x = input()
        if x == '':
            break
        x = int(x)
        
        # call function coins(num, map) and store result
        result = coins(hashmap,x)
        # print result
        print(result)
    # return 
    return 0

main()


