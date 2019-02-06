#include<iostream>
using namespace std;
int M,N;
int** dp;
int *coin;
int way;
int Coin(int i, int amount)
{
    if(i>=N)
    {
        if(amount == M) return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int ret1 = 0;
    int ret2 = 0;

    if(amount + coin[i] <= M) ret1 = Coin(i,amount + coin[i]);
    ret2 = Coin(i+1,amount);
    way = ret1+ret2;
    dp[i][amount] = ret1||ret2;

    return dp[i][amount];
}
int main(void)
{
    cout << "Enter the No of coin & amount: ";
    cin >> N >> M;
    dp = new int*[N];
    for(int i = 0; i < N; ++i)
    dp[i] = new int[M+1];

    for(int i = 0; i < N; i++)
        for(int j = 0; j<M+1; j++)
        dp[i][j] = -1;

    coin = new int[N];
    cout << "Enter the values of coin: ";
    for(int i =0;i<N ;i++)
    {
        cin >> coin[i];
    }

    if(Coin(0,0)==1) cout <<"True" << endl;
    else cout << "False" << endl;
    cout << "Total Way = " << way << endl;
   return 0;
}
