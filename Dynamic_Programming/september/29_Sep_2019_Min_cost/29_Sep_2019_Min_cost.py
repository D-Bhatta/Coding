#naive recursive Min Cost
r = 3
c = 3

# Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C] 
def minCost(cost,m,n):
    if(n<0 or m< 0):
        return -1
    elif (n == 0 and m == 0):
        return cost[m][n]
    else:
        return cost[m][n]+ min( minCost(cost,m-1,n-1),minCost(cost,m-1,n),minCost(cost,m,n-1))


#driver program:
cost = [[1,2,3],
        [4,8,2],
        [1,5,3]]
print("Min Cost: {}".format(cost,2,2))