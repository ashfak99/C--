#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream file("C:\\Users\\Dell\\C++\\Operating_System\\FCFS.c++");
    if(!file)
    {
        cout<<"File can't be open";
        return 0;
    }
    cout<<file.rdbuf();
    return 0;
}