//dynamic word wrap solution

#include<bits/stdc++.h>

using namespace std;

#define INF INT_MAX

int printSolution(int p[], int n);

// l[] represents lengths of different words in input sequence.  
// For example, l[] = {3, 2, 2, 5} is for a sentence like  
// "aaa bb cc ddddd". n is size of l[] and M is line width  
// (maximum no. of characters that can fit in a line)  
void wordWrap(int l[], int n, int line_width){
    // For simplicity, 1 extra space is used in all below arrays  
  
    // extras[i][j] will have number of extra spaces if words from i  
    // to j are put in a single line 
    int extras[n+1][n+1];

    // lc[i][j] will have cost of a line which has words from  
    // i to j  
    int lc[n+1][n+1];

     // c[i] will have total cost of optimal arrangement of words  
    // from 1 to i
    int c[n+1];

    int p[n+1];

    int i, j;

    // calculate extra spaces in a single line. The value extra[i][j]  
    // indicates extra spaces if words from word number i to j are  
    // placed in a single line  
    for(i = 1; i <= n; i++){
        //for same word extra space is the difference  between it's width and the line width
        extras[i][i] = line_width - l[i-1];
        for(j = i+1; j <= n; j++){
            //extra space is extra space left by the previous word minus the length of this word minus 1
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
        }
    }

    // Calculate line cost corresponding to the above calculated extra  
    // spaces. The value lc[i][j] indicates cost of putting words from  
    // word number i to j in a single line  
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            //if there is no spcae, can't put the word there
            if(extras[i][j] < 0){
                lc[i][j] = INF;
            }
            //if it's the last wors, there is no line cost
            else if (j == n && extras[i][j] >= 0){
                    lc[i][j] = 0;
                }
                else
                {//lince cost = extras**2
                    lc[i][j] = extras[i][j]*extras[i][j];
                }   
        }
    }
    // Calculate minimum cost and find minimum cost arrangement.  
    // The value c[j] indicates optimized cost to arrange words  
    // from word number 1 to j. 
    c[0] = 0;
    for(j = 1; j <= n; j++){
        c[j] = INF;
        for(i = 1; i <= j; i++){
            if(c[i-1] != INF && lc[i][j] != INF && (c[i-1] + lc[i][j] < c[j])){
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    printSolution(p,n);

}

int printSolution (int p[], int n){
    int k;
    if(p[n] == 1){
        k = 1;
    }
    else{
        k = printSolution(p, p[n]-1) + 1;
    }
    cout << "Line number "<< k << " : From word no. "<< p[n] << " to " << n << endl;
    return k;
}

//driver code
int main(){
    int l[] = {3, 2, 2, 5};  
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    wordWrap(l,n,M);
    return 0;
}