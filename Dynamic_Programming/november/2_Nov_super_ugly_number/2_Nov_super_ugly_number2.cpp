#include<bits/stdc++.h>

using namespace std;

int ugly(int a[], int size, int n){
    if(n <= 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < size; i++){
        pq.push(a[i]);
    }

    int count = 1, no;

    while (count < n)
    {
        no = pq.top();

        pq.pop();

        if(no != pq.top()){
            count++;

            for(int i = 0; i < size; i++){
                pq.push(no * a[i]);
            }
        }
    }

    return no;
    
}

//driver program
int main(){
    int a[3] = {2,3,5};

    int size = sizeof(a)/sizeof(a[0]);

    cout << "Superugly for n = " << 1000 << " and primes 2,5 is :" << ugly(a,size,1000);

    return 0;
}