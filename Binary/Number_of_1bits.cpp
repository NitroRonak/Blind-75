#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int count=0;
    while(n!=0){
        count+=n&1;
        n>>=1;
    }
    return count;
}
int main()
{
    uint32_t n;
    cin>>n;
    cout<<hammingWeight(n)<<endl;
    return 0;
}