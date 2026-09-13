#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Process{
    public:
        string processId;
        int arrivalTime;
        int burstTime;
        int completionTime;
        int turnAroundTime;
        int waitingTime;
    Process(string pid, int at, int bt)
    {
        processId=pid;
        arrivalTime=at;
        burstTime=bt;
    }
};

bool cmp(Process P1, Process P2)
{
    if(P1.arrivalTime==P2.arrivalTime)
        return P1.burstTime<P2.burstTime;
    
    return P1.arrivalTime<P2.arrivalTime;
}

void printProcess(vector<Process>& processes)
{
    float avgTAT=0,avgWt=0;

    for(Process p : processes)
    {
        avgTAT+=p.turnAroundTime;
        avgWt+=p.waitingTime;
    }

    avgTAT/=processes.size();
    avgWt/=processes.size();

    cout<<"Pid\tAT\tBT\tCT\tTAT\tWT\n";
    for(Process p : processes)
    {
        cout<<p.processId<<"\t"<<p.arrivalTime<<"\t"<<p.burstTime<<"\t"<<p.completionTime<<"\t"<<p.turnAroundTime<<"\t"<<p.waitingTime<<"\n";
    }

    cout<<"\nAverage TurnAroundTime : "<<avgTAT;
    cout<<"\nAverage WaitingTime : "<<avgWt;
}

void FCFS(vector<Process>& processes)
{
    sort(processes.begin(), processes.end(), cmp);
    int n=processes.size();

    processes[0].completionTime=processes[0].arrivalTime+processes[0].burstTime;
    processes[0].turnAroundTime=processes[0].completionTime-processes[0].arrivalTime;
    processes[0].waitingTime=processes[0].turnAroundTime-processes[0].burstTime;

    for(int i=1; i<n; i++)
    {
        processes[i].completionTime=processes[i-1].completionTime+processes[i].burstTime;
        processes[i].turnAroundTime=processes[i].completionTime-processes[i].arrivalTime;
        processes[i].waitingTime=processes[i].turnAroundTime-processes[i].burstTime;
    }

    printProcess(processes);
}

int main()
{
    int n;
    cout<<"Please enter the number of processes : ";
    cin>>n;

    vector<Process> processes;

    for(int i=0; i<n; i++)
    {
        string pid;
        int at,bt;
        cout<<"Please Enter the Process Id, Arrival Time, Burst Time : ";
        cin>>pid>>at>>bt;
        processes.push_back(Process(pid,at,bt));
    }

    FCFS(processes);
    return 0;
}