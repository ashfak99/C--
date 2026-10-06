#include<iostream>
using namespace std;
int i=0;
void print()
{
    if(i>=10) return;
    cout<<i<<endl;
    i++;
    print();
}

int main(int argc, char const *argv[])
{
    print();
    return 0;
}