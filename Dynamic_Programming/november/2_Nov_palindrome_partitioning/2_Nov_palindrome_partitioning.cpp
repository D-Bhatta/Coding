#include<bits/stdc++.h>

using namespace std;

int minPalPartition(char * str){

    int n = strlen(str);

    int c[n];

    bool p[n][n];

    int i,j,k,l;

    for(i = 0; i < n; i++){
        p[i][i] = true;
    }

    for(l = 2; l <= n; l++){
        for(i = 0; i < n-l+1; i++){
            j = i+l-1;

            // If L is 2, then we just need to compare two characters. Else 
            // need to check two corner characters and value of P[i+1][j-1] 
            if(l == 2){
                p[i][j] = (str[i] == str[j]);
            }
            else
            {
                p[i][j] = (str[i] == str[j]) && p[i+1][j-1];
            }
            
        }
    }
    for(i = 0; i < n; i++){
        if(p[0][i] == true){
            c[i] = 0;
        }
        else
        {
            c[i] = INT16_MAX;
            for(j = 0; j < i; j++){
                if(p[j+1][i] == true && i+c[j] <c[i]){
                    c[i] = 1+c[j];
                }
            }
        }
        
    }
    return c[n-1];
}

int main(){
    char str[] = "ababbbabbababa";
    cout << "Min cuts needed for Palindrome Partitioning is :" << minPalPartition(str);

    return 0;
}