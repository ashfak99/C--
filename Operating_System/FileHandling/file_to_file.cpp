#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream src("C:\\Users\\Dell\\C++\\Operating_System\\FCFS.c++", ios::binary);
    if (!src)
    {
        cout<<"File can't be Open.";
        return 1;
    }

    ofstream dest("C:\\Users\\Dell\\C++\\Operating_System\\FileHandling\\output.txt",ios::binary);
    if(!dest)
    {
        cout<<"File can't be Open.";
        return 1;
    }

    dest << src.rdbuf();

    src.close();
    dest.close();

    cout<<"File write successful.";
    
    return 0;
}