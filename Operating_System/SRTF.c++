#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>

using namespace std;

class Process{
  public:
    string processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int firstRunTime;
    int responseTime;

    Process(string pid, int at, int bt)
    {
        processId=pid;
        arrivalTime=at;
        burstTime=bt;
        remainingTime=bt;
        firstRunTime=-1;
        completionTime=0;
        turnaroundTime=0;
        waitingTime=0;
    }
};

struct comperatorRemainingTime{
    bool operator()(const Process* p1, const Process* p2) const{
        if(p1->remainingTime==p2->remainingTime)
            return p1->arrivalTime>p2->arrivalTime;
        return p1->remainingTime>p2->remainingTime;
    }
};

bool cmpArrivalTime(Process& p1, Process& p2)
{
    if(p1.arrivalTime==p2.arrivalTime)
        return p1.burstTime<p2.burstTime;
    return p1.arrivalTime<p2.arrivalTime;
}

bool cmpBurstTime(Process& p1, Process& p2)
{
    if(p1.burstTime==p2.burstTime)
        return p1.arrivalTime<p2.arrivalTime;
    return p1.burstTime<p2.burstTime;
}

bool cmpCT(const Process& p1, const Process& p2) {
    return p1.completionTime < p2.completionTime;
}

void shortestRemainingTimeFirst(vector<Process>& processes)
{
    int n = processes.size();
    sort(processes.begin(), processes.end(), cmpArrivalTime);

    priority_queue<Process*, vector<Process*>, comperatorRemainingTime> processQueue;

    int i=0;
    int cpuTime=0;
    int completed=0;
    while (completed<n)
    {
        while (i<n && processes[i].arrivalTime<=cpuTime)
        {
            processQueue.push(&processes[i]);
            i++;
        }
        if(processQueue.empty())
        {
            cpuTime+=processes[i].arrivalTime;
            continue;
        }

        Process* p =processQueue.top();

        if (p->firstRunTime==-1)
        {
            p->firstRunTime=cpuTime;
        }
        
        cpuTime+=1;

        p->remainingTime-=1;

        if (p->remainingTime==0)
        {
            processQueue.pop();
            p->completionTime = cpuTime;
            p->turnaroundTime = p->completionTime - p->arrivalTime;
            p->waitingTime = p->turnaroundTime - p->burstTime;
            p->responseTime = p->firstRunTime - p->arrivalTime;
            completed++;
        }
    }
}

void printBanner(const string& title)
{
    cout << "\n\n";
    cout << "\033[1m\033[36m";                    
    cout << "  +=============================================================+\n";
    cout << "  |  " << setw(58) << left << title << "|\n";
    cout << "  +=============================================================+\n";
    cout << "\033[0m\n";                         
}

void printProcess(const vector<Process>& processes)
{
    const string algoName = "Shortest Remaining Time First (SRTF) ";
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
    int n;
    cout<<"Number of Processes : ";
    cin>>n;

    vector<Process> processes;

    for(int i=0; i<n; i++)
    {
        string pid;
        int at, bt;
        cout<<"Enter process id, arrival time, burst time of processes : ";
        cin>>pid>>at>>bt;

        processes.push_back(Process(pid,at,bt));
    }
    
    shortestRemainingTimeFirst(processes);
    sort(processes.begin(), processes.end(), cmpCT);
    printProcess(processes);
    return 0;
}