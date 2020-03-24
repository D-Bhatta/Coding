/* CANDY - Candy I
#ad-hoc-1
Jennifer is a teacher in the first year of a primary school. She has gone for a trip with her class today. She has taken a packet of candies for each child. Unfortunatelly, the sizes of the packets are not the same.

Jennifer is afraid that each child will want to have the biggest packet of candies and this will lead to quarrels or even fights among children. She wants to avoid this. Therefore, she has decided to open all the packets, count the candies in each packet and move some candies from bigger packets to smaller ones so that each packet will contain the same number of candies. The question is how many candies she has to move.

Input specification
The input file consists of several blocks of data. Each block starts with the number of candy packets N(1<= N <=10000) followed by N integers (each less than 1000) in separate lines, giving the number of candies in each packet. After the last block of data there is the number -1.

Output specification
The output file should contain one line with the smallest number of moves for each block of data. One move consists of taking one candy from a packet and putting it into another one. If it is not possible to have the same number of candies in each packet, output the number -1.

Example
Input file:
5
1
1
1
1
6
2
3
4
-1

Output file:
4
-1 */
#include<bits/stdc++.h>
using namespace std;

// candy function(vector, avg)
int candy(vector<int> candy,int avg){
    int sum = 0;
    // find all x:vector > avg, and sum their difference from avg
    for (int x : candy){
        if(x>avg){
            sum += (x-avg);
        }
    }
    // return sum

    return sum;
}

// main function
int main(){
    int n = -1, sum = 0, num = 0, temp = 0, avg = 0, result = 0;
    vector<int> candy_input;
    // infinite loop
    while(true){
        // take input n
        cin >> n;
        // if n == -1, break
        if(n == -1){
            break;
        }
        // store in temp
        temp = n;
        // reinitialize sum with 0
        sum = 0;
        // clear vector
        candy_input.clear();
        // loop till n 
        while(temp>0){
            // store numbers in vector and add to sum
            cin >> num;
            sum +=num;
            candy_input.push_back(num);
            --temp;
        }
        // divide sum by n and if there is a remainder, return -1
        if(sum%n != 0){
            result = -1;
        }
        // else, call candy function and store result
        else{
            // calculate avg
            avg = sum/n;
            result = candy(candy_input, avg);

        }
        // print result
        cout << result << endl;
    }
        
    // return 
    return 0;

}
