#include<bits/stdc++.h>

using namespace std;

int superUgly(int n, int primes[], int k){
    vector<int> nextMultiple(primes, primes+k);

    int multiple_of[k];

    memset(multiple_of,0,sizeof(multiple_of));

    set<int> ugly;

    ugly.insert(1);

    while (ugly.size() != n)
    {
        int next_ugly_num = *min_element(nextMultiple.begin(), nextMultiple.end());

        ugly.insert(next_ugly_num);

        for(int j = 0; j < k; j++){
            if(next_ugly_num == nextMultiple[j]){
                multiple_of[j]++;

                set<int>::iterator it = ugly.begin();

                for(int i = 1; i <= multiple_of[j]; i++){
                    it++;
                }

                nextMultiple[j] = primes[j] * (*it);

                break;
            }
        }
    }

    set<int>::iterator it = ugly.end();

    it--;

    return *it;
    
}

//driver code
int main(){
    int primes[] = {2,5};

    int k = sizeof(primes)/sizeof(primes[0]);

    int n = 5;

    cout << "Superugly for n = " << n << " and primes 2,5 is :" << superUgly(n,primes,k);

    return 0;
}