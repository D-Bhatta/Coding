#naive coin change

# Returns the count of ways we can sum 
# S[0...m-1] coins to get sum n 

def count(s,m,n):
    
    # If n is 0 then there is 1 
    # solution (do not include any coin) 
    if(n == 0):
        return 1
    
    # If n is less than 0 then no 
    # solution exists 
    if(n<0):
        return 0
    
    # If there are no coins and n 
    # is greater than 0, then no 
    # solution exist 
    if(m<=0 and n>=1):
        return 0
    
    # count is sum of solutions (i)  
    # including S[m-1] (ii) excluding S[m-1] 
    return count(s,m-1,n) + count(s,m,n-s[m-1])

#driver program
arr = [1,2,3]
m = len(arr)
print("count: {}".format(count(arr,m,4)))