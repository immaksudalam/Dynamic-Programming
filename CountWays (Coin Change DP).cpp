#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define max_w 1000
#define max_n 20

int N, W;
int Coin[max_n];
int memo[max_w][max_n];
int wayOfChanges(int money, int CoinIndex){
    if(money==0)return 1;
    if(memo[money][CoinIndex]!=-1)
        return memo[money][CoinIndex];

    int ways=0;
    for(int i=CoinIndex; i<N; i++){
        if(money >= Coin[i])
            ways += wayOfChanges(money - Coin[i], i);
    }
    return memo[money][CoinIndex]=ways;
}
int main()
{
    cin>>W>>N;
    for(int i=0; i<N; i++)cin>>Coin[i]; 
    memset(memo, -1, sizeof(memo));

    cout<<wayOfChanges(W, 0)<<endl;
    return 0;
}
