#python program for tabulated fibonacci
def fib(n):

    #array declaration
    f = [0] * (n+1)

    #base case
    f[1] = 1

    #calculating the fibonacci and storing the values
    for i in range(2,n+1):
        f[i] = f[i-1] + f[i-2]
    
    #return the nth fibonacci number
    return f[n]

    def main():
        n = 9
        print("Fibonacci number is {}".format(fib(n)))
    
    if __name__ == "__main__":
        main()