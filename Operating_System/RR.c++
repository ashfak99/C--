#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
#include<algorithm>
#include "process.hpp"

using namespace std;

class RRProcess : public Process{
    public:
        int remainingTime;
        int firstArrivalTime=-1;

        RRProcess(string pid, int at, int bt) : Process(pid,at,bt)
        {
            remainingTime=bt;
        }
};

bool comperatorArrivalTime(RRProcess& p1, RRProcess& p2)
{
    if(p1.arrivalTime==p2.arrivalTime)
        return p1.burstTime<p2.burstTime;
    return p1.arrivalTime<p2.arrivalTime;
}

bool comperatorCompletionTime(RRProcess& p1, RRProcess& p2)
{
    return p1.completionTime<p2.completionTime;
}

void RoundRobin(vector<RRProcess>& processes, int q)
{
    int n=processes.size();
    sort(processes.begin(), processes.end(), comperatorArrivalTime);

    queue<RRProcess*> circularQueue;

    int i=0, completed=0;
    int cpuTime=0;

    while (completed<n)
    {
        while (i<n && processes[i].arrivalTime<=cpuTime)
        {
            circularQueue.push(&processes[i]);
            i++;
        }
        
        if(circularQueue.empty())
        {
            if(i>=n) break;
            cpuTime=processes[i].arrivalTime;
            circularQueue.push(&processes[i]);
            i++;
        }

        RRProcess* p = circularQueue.front();
        circularQueue.pop();

        if (p->firstArrivalTime==-1)
        {
            p->firstArrivalTime=cpuTime;
        }

        int run = min(q, p->remainingTime);
        cpuTime+=run;
        p->remainingTime -= run;

        if(p->remainingTime==0)
        {
            p->completionTime=cpuTime;
            p->turnaroundTime=p->completionTime - p->arrivalTime;
            p->waitingTime = p->turnaroundTime - p->burstTime;
            p->responseTime = p->firstArrivalTime - p->arrivalTime;
            completed++;
        }
        else{
            circularQueue.push(p);
        }
    }
}

void printBanner(string& title)
{
    cout << "\n\n";
    cout << "\033[1m\033[36m";                    
    cout << "  +=============================================================+\n";
    cout << "  |  " << setw(58) << left << title << "|\n";
    cout << "  +=============================================================+\n";
    cout << "\033[0m\n";                         
}

void printProcess(const vector<RRProcess>& processes)
{
    string algoName = "Round Robin (RR) ";
    printBanner(algoName);                      

    cout << left
         << setw(10) << "PID"
         << setw(14) << "Arrival"
         << setw(12) << "Burst"
         << setw(16) << "Completion"
         << setw(16) << "Turnaround"
         << setw(12) << "Waiting"
         << setw(12) << "Response Time" << "\n";
    cout << string(92, '-') << "\n";

    int n = (int)processes.size();
    for (int i = 0; i < n; i++) {
        cout << left
             << setw(10) << processes[i].processId
             << setw(14) << processes[i].arrivalTime
             << setw(12) << processes[i].burstTime
             << setw(16) << processes[i].completionTime
             << setw(16) << processes[i].turnaroundTime
             << setw(12) << processes[i].waitingTime
             << setw(12) << processes[i].responseTime << "\n";
    }

    cout << string(92, '-') << "\n";

    double sumTAT = 0, sumWT = 0, sumRT = 0;
    for (const auto& p : processes) {
        sumTAT += p.turnaroundTime;
        sumWT  += p.waitingTime;
        sumRT  += p.responseTime;
    }

    cout << fixed << setprecision(2)
         << "Avg TAT = " << sumTAT / n
         << "   |   Avg WT = " << sumWT / n
         << "   |   Avg RT = " << sumRT / n << "\n";
}

int main(int argc, char const *argv[])
{
    vector<RRProcess> processes;

    int n;
    cout<<"Enter the number of Processes: ";
    cin>>n;

    int q;
    cout<<"Enter the quantum unit : ";
    cin>>q;

    for(int i=0; i<n; i++)
    {
        string pid;
        int at, bt;

        cout<<"Please enter the pid, at, bt : ";
        cin>>pid>>at>>bt;

        processes.push_back(RRProcess(pid, at,bt));
    }

    RoundRobin(processes, q);

    sort(processes.begin(), processes.end(), comperatorCompletionTime);

    printProcess(processes);
    return 0;
}