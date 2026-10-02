#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x=3;
    for (int i = 0; i < 10; i++)
    {
        cout<<"\nPrint: "<<x;
         x<<=1;
    }
    return 0;
}