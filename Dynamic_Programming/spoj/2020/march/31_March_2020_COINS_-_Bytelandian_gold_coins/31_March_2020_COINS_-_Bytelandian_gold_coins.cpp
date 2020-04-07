/* COINS - Bytelandian gold coins
#dynamic-programming
In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input
The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.

Output
For each test case output a single line, containing the maximum amount of American dollars you can make.

Example
Input:
12
2

Output:
13
2
You can change 12 into 6, 4 and 3, and then change these into $6+$4+$3 = $13. If you try changing the coin 2 into 3 smaller coins, you will get 1, 0 and 0, and later you can get no more than $1 out of them. It is better just to change the 2 coin directly into $2. */

/* Conceptually:
    get a number,
    find number of $$ you can get for it.
    to get $$, div a number by 2,3,4 and add all non-zero solutions.
    each non-zero soln should also be divided to into smaller chunks, recursively to get
    max amt.
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long h;
// prefetch function(map)
int prefetch(unordered_map<h,h>& map, h x){
    // if x == 1001
    if(x==1001){
        return 0;
    }
    // return
    // check if x == 0
    if(x == 0){
        return 0;
    }
    // recursively add to hashmap from 10 million
        // divide by 2,3,4
        h i = x/2;
        h j = x/3;
        h k = x/4;
        // if not in hashmap, call prefetch
        if(map.find(i) != map.end()){
            i = map[i];
        }
        else{
            prefetch(map,i);
            i = map[i];
        }
        if(map.find(j) != map.end()){
            j = map[j];
        }
        else{
            prefetch(map,j);
            j = map[j];
        }
        if(map.find(k) != map.end()){
            k = map[k];
        }
        else{
            prefetch(map,k);
            k = map[k];
        }
        // add results
        h results = i+j+k;
        // store in hashmap
        if(results < x){
            map[x] = x;
        }
        else{
            map[x] = results;
        }
        // go to next item
        prefetch(map,x+1);
    return 0;
}

int prefetch_million(unordered_map<h,h>& map, h x){
    
    // check if x == 0
    if(x == 0){
        return 0;
    }
    // recursively add to hashmap from 10 million
        // divide by 2,3,4
        h i = x/2;
        h j = x/3;
        h k = x/4;
        // if not in hashmap, call prefetch
        if(map.find(i) != map.end()){
            i = map[i];
        }
        else{
            prefetch_million(map,i);
            i = map[i];
        }
        if(map.find(j) != map.end()){
            j = map[j];
        }
        else{
            prefetch_million(map,j);
            j = map[j];
        }
        if(map.find(k) != map.end()){
            k = map[k];
        }
        else{
            prefetch_million(map,k);
            k = map[k];
        }
        // add results
        h results = i+j+k;
        // store in hashmap
        if(results < x){
            map[x] = x;
        }
        else{
            map[x] = results;
        }
    return 0;
}
    
// coins function(map, num)
h coins(unordered_map<h,h>& map, h x){
    if(map.find(x)!= map.end()){
        return map[x];
    }
    // divide by 2,3,4
    h i = x/2;
    h j = x/3;
    h k = x/4;
    // cout << i << "i\n" << j << "j\n" << k << "k\n";
    // if not in hashmap, call coins
    if(map.find(i) != map.end()){
            i = map[i];
        }
        else{
            i = coins(map,i);
        }
        if(map.find(j) != map.end()){
            j = map[j];
        }
        else{
            j = coins(map,j);
        }
        if(map.find(k) != map.end()){
            k = map[k];
        }
        else{
            k = coins(map,k);
        }
    // add results
    h result = i+j+k;
    if(result < x){
        result = x;
    }
    // return result
    return result;
}

// main function
int main(){
    h n;
    // prefetch hashmap of results till 10 million and store in dp
        // create hashmap
        unordered_map<h,h> map;
        // manually store results till 12
        map[0] = 0;
        map[1] = 1;
        map[2] = 2;
        map[3] = 3;
        map[4] = 4;
        map[5] = 5;
        map[6] = 6;
        map[7] = 7;
        map[8] = 8;
        map[9] = 9;
        map[10] = 10;
        map[11] = 11;
        map[12] = 13;

        // call prefetch(map)
        // TODO: fix prefetch
        prefetch(map,13);
        prefetch_million(map,100000000);
        /* unordered_map<h,h>::iterator it = map.begin();
        while(it!=map.end()){
            cout << it->first << "  " << it->second << endl;
            ++it;
        } */

    // loop until input
    while(cin >> n){
        // call function coins(num, map) and store result
        h result = coins(map,n);
        // print result
        cout << result << endl;
    }

    // return 
    return 0;
}
