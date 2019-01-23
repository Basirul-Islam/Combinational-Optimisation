#include<iostream>
using namespace std;

int n;
int maxWeight;
int *value;
int **ary;
int *weight;

int choosenObj()
{

   int i = n;
   int j = maxWeight;

    cout << "n: " << n << " " << "Maxwt: "<< maxWeight << endl;

   while(i>0&&j>0)
   {
       if(ary[i][j]==ary[i-1][j])
       {
           //cout << "i = " << 0 << endl;
           i--;
       }
       else{
        cout << "i = " << i << endl;

            i--;
           j=j-weight[i];

       }

       cout << "I is: " << i << " J is: " << j << endl;

   }

    /*
    int x = ary[n][maxWeight];
    for(int j=n; j>=0; j--)
    {
        for(int i=maxWeight; i>=0; i--)
        {
            if(x!=ary[i-1][j])
            {
                cout << "Serial no: " << j << endl;
                x=x-value[i];
            }
        }
    }
    */
}
int main(void)
{

    //int n;
    cout << "No of object: " <<endl;
    cin >> n;

    weight = new int[n+1];
    //int *value;
    value = new int [n+1];
    value[0] = weight[0] = 0;
    cout << "Insert the weight of the objects here: " << endl;
    for(int x=1; x<=n; x++)
        cin >> weight[x];
    cout << "Insert the value of the objects here: " << endl;
    for(int x=1; x<=n; x++)
        cin >> value[x];
    //int maxWeight;
    cout << "Input the Maximum weight can be carried in the Knapsack: " << endl;
    cin >> maxWeight ;
    //int **
    ary = new int*[n+1];
    for(int i = 0; i < n+1; ++i)
    {
        ary[i] = new int[maxWeight+1];
    }

    for(int row=0; row<=n; row++)
    {
        for(int w=0; w<=maxWeight; w++)
        {
            if(row==0 || w==0) ary[row][w] =0;

            else if(weight[row] <= w) ary[row][w] = max(value[row]+ary[row-1][w-weight[row]],ary[row-1][w]);

            else ary[row][w] = ary[row-1][w];
        }
    }
    cout << "maximum weight: " << ary[n][maxWeight] << endl;

    for(int row=0; row<=n; row++)
    {
        for(int w=0; w<=maxWeight; w++)
        {
            cout << ary[row][w] << " " ;
        }
        cout << endl;
    }


     choosenObj();

    return 0;
}

