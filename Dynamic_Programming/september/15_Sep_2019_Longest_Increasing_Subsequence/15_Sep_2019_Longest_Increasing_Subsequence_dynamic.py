#Dynamic program to implemmtnt LIS problem

#lis returns length of the longest increasing subsequence
#in arr of size n

def lis(arr):
    n = len(arr)

    #Declare the list (array) for LIS and initialize LIS
    #values for all indexes
    lis = [1]*n

    #Computed the optimized LIS in bottom up manner
    for i in range(1,n):
        for j in range(0,i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    #Get the maximum of all LIS values
    maximum = max(lis)

    return maximum

#Driver program to test the above function
arr = [10, 22, 9, 33, 21, 50, 41, 60]
print("Length of LIS is {}".format(lis(arr)))

#code copied and improved from https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/