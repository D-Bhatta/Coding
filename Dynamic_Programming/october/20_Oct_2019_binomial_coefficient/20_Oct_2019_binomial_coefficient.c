//naive binomial coeff

#include<stdio.h>

int binomialCoeff(int n, int k){
    //base case
    if(k == 0 || k == n){
        return 1;
    }

    //recur
    return binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k);
}

//driver code
int main()
{
    int n = 5, k = 2;
    printf("The binomial coeff of %d and %d is %d", n,k,binomialCoeff(n,k));
    return 0;

}