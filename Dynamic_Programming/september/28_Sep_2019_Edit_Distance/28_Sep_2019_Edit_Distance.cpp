//naive solution to Edit Distance

#include<bits/stdc++.h>
using namespace std;

//utility function to find min of 3 numbers

int min(int x, int y, int z)
{
    return min(min(x,y),z);
}


//the edit distance function
int editDist(string str1, string str2, int m, int n){

    //if first string is empty the only option is to insert all characters of second string into first
    if(m == 0) return n;

    //if second string is empty the only option is to remove all the characters of the first string
    if(n==0) return m;

    //if if last characters are the same then move onto the nect character: get the count for them
    if(str1[m-1] == str2[n-1]){
        return editDist(str1,str2, m-1, n-1);
    }

    /* 
    if last characters aren't the same
    consider all theree operations on the last character of str1
    recursively compute the min cost of all 3 
    and take the min
    */
    return 1 + min( editDist(str1,str2,m,n-1), editDist(str1,str2,m-1,n), editDist(str1, str2, m-1, n-1));
}

//driver code

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << "Num = " << editDist(str1, str2, str1.length(), str2.length()));

    return 0;
}