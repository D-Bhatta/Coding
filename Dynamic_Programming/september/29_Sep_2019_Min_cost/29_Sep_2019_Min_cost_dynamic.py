#dynamic implementation of minCost 
r = 3
c = 3

def min_cost(cost, m, n):
    tc = [[0 for x in range(c)] for x in range(r)]
    tc[0][0] = cost[0][0]

    #init first col and row of tc
    for i in range(m+1):
        tc[i][0] = tc[i-1][0] + cost[i][0]
    for j in range(m+1):
        tc[0][j] = tc[0][j-1] + cost[0][j]
    

    #construvt in bottom up manner:
    for i in range(1,m+1):
        for j in range(1,n+1):
            tc[i][j] = min(tc[i-1][j-1],tc[i-1][j],tc[i][j-1]) + cost[i][j]
    
    return tc[m][n]


cost=[[1,2,3],[4,8,2],[1,5,3]]

print("Min Cost = {}".format(min_cost(cost,2,2)))