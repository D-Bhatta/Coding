# A naive Python implementation of LIS problem 
  
""" To make use of recursive calls, this function must return 
 two things: 
 1) Length of LIS ending with element arr[n-1]. We use 
 max_ending_here for this purpose 
 2) Overall maximum as the LIS may end with an element 
 before arr[n-1] max_ref is used this purpose. 
 The value of LIS of full array of size n is stored in 
 *max_ref which is our final result """

#global variable to store the maximum
global maximum

def _lis(arr, n):

    #to allow the access of global variable
    global maximum

    #Base case
    if n == 1:
        return 1
    
    #maxEndingHere is the length of LIS ending with arr[-1]
    maxEndingHere = 1

    """Recursively get all LIS ending with arr[0], arr[1], arr[n-2]
        if arr[i-1] < arr[n-1] and maxEndingHere with arr[n-1] needs to be updated then update it"""
    for i in range(1,n):
        res = _lis(arr, i)
        if(arr[i-1]< arr[n-1] and res+1 > maxEndingHere):
            maxEndingHere = res+1
    
    #Compare maxEndingHere with oveerall maximum and update the overall maximum if needed
    maximum = max(maximum, maxEndingHere)

    return maxEndingHere
    #what is hapennign here is a top down approach. The at first n vars are passed to the func. Then recursively we go til the base case, which eturns 1. Then we go to the 2nd case, where the program really starts. We recursively find the LIS(stored in result) and pass it to the func above it. If the res is greater than what the current func has, it is updated. Thus we, in the end, get the maximum LIS

def lis(arr):

    #to allow the access of global variable
    global maximum

    #length of the arr
    n = len(arr)

    #maximum variable holds the result

    maximum = 1

    #The function _lis() stores it's result in maximum
    _lis(arr,n)

    return maximum

#Driver function to test the function

arr = [10, 22, 9, 33, 21, 50, 41, 60]

print("length of lis is ", lis(arr))

#code from https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/