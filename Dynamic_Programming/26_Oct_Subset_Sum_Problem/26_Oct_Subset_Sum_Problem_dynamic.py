#dynamic subset sum

def isSubsetSum(set,n,sum):
    # The value of subset[i][j] will be  
    # true if there is a 
    # subset of set[0..j-1] with sum equal to i 
    subset = [[False for i in range(sum+1)] for i in range(n + 1)]

    # If sum is 0, then answer is true
    for i in range(n+1):
        subset[i][0] = True
    
    for i in range(n+1):
        for j in range(sum+1):
            if j < set[i-1]:
                subset[i][j] = subset[i-1][j]
            else:
                subset[i][j] = subset[i-1][j] or subset[i-1][j-set[i-1]]
    

    return subset[n][sum]

#driver code
set = [3, 34, 4, 12, 5, 2] 
sum = 9
n =len(set) 
if (isSubsetSum(set, n, sum) == True): 
    print("Found a subset with given sum") 
else: 
    print("No subset with given sum") 