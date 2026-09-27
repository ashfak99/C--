#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int matrixChainMultiplication(vector<int>& p)
{
    int n=p.size();

    vector<vector<int>> m(n,vector<int>(n,0));

    for(int l=2; l<n; l++)
    {
        for(int i=0; i<n-l; i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i; k<=j-1; k++)
            {
                int  cost = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];

                if(cost<m[i][j])
                {
                    m[i][j]=cost;
                }
            }
        }
    }

    return m[0][n-2];
}

int main(int argc, char const *argv[])
{
    vector<int> inputs;
    int n;
    cout<<"How many element in the Matrix Chain Order : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cout<<"Enter the Matrix Chain Order Element : ";
        cin>>temp;
        inputs.push_back(temp);
    }
    int result=matrixChainMultiplication(inputs);
    cout<<"Minimum Number of Multiplicaton : "<<result;
    return 0;
}