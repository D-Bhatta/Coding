#Python programme for memoized version of nth fibonacci number

#functtion to calculate nth fibonacci number

def fib(n, lookup):
    #base case
    if n == 0 or n == 1:
        lookup[n] = n
    
    #if the value if not calculated previously then calculate it
    if lookup[n] is None:
        lookup[n] == fib(n-1, lookup) + fib(n-2, lookup)
    
    #return the value corresponding to the value of n
    return lookup[n]


#Driver program to test the above function:
def main():
    n = 34
    #Declaration of lookup table 
    # Handles till n = 100
    lookup = [None]*(101)
    print("fibonacci number is {}".format(fib(n, lookup)))

if __name__ == "__main__":
    main()
