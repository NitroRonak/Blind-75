#include<bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
    int carry=b,sum;
    if(a==0) return b;
    if(b==0) return a;
    while(carry!=0){
        sum=a^b;
        carry=(a&b)<<1;
        a=sum;
        b=carry;
    }
    return sum;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<getSum(a,b)<<endl;
    return 0;
}