#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

class Process
{
public:
    string processId;
    int arrivalTime, burstTime;
    int completionTime, turnAroundTime, waitingTime;

    Process(string pid, int at, int bt)
        : processId(pid), arrivalTime(at), burstTime(bt),
          completionTime(0), turnAroundTime(0), waitingTime(0) {}  
};


struct CompareBurst {
    bool operator()(const Process* a, const Process* b) const {
        if (a->burstTime == b->burstTime)
            return a->arrivalTime > b->arrivalTime;
        return a->burstTime > b->burstTime;
    }
};

bool cmpAT(const Process& p1, const Process& p2) {
    if (p1.arrivalTime == p2.arrivalTime)
        return p1.burstTime < p2.burstTime;
    return p1.arrivalTime < p2.arrivalTime;
}

bool cmpCT(const Process& p1, const Process& p2) {
    return p1.completionTime < p2.completionTime;
}

void shortestJobFirst(vector<Process>& processes)
{
    int n = (int)processes.size();
    if (n == 0) return;                                    

    sort(processes.begin(), processes.end(), cmpAT);

    priority_queue<Process*, vector<Process*>, CompareBurst> pq;

    int i = 0;
    int cpuTime = 0;
    int completed = 0;

    while (completed < n)
    {
        
        while (i < n && processes[i].arrivalTime <= cpuTime) {
            pq.push(&processes[i]);
            i++;
        }

        
        if (pq.empty()) {
            cpuTime = processes[i].arrivalTime;
            continue;
        }

        Process* p = pq.top(); 
        pq.pop();                   
        cpuTime += p->burstTime;

        p->completionTime = cpuTime;
        p->turnAroundTime = p->completionTime - p->arrivalTime;
        p->waitingTime    = p->turnAroundTime - p->burstTime;

        completed++;
    }
}

void printProcess(const vector<Process>& processes)      
{
    cout << left
         << setw(10) << "PID"
         << setw(14) << "Arrival"
         << setw(12) << "Burst"
         << setw(16) << "Completion"
         << setw(16) << "Turnaround"
         << setw(12) << "Waiting" << "\n";
    cout << string(80, '-') << "\n";

    int n = (int)processes.size();
    for (int i = 0; i < n; i++) {
        cout << left
             << setw(10) << processes[i].processId
             << setw(14) << processes[i].arrivalTime
             << setw(12) << processes[i].burstTime
             << setw(16) << processes[i].completionTime
             << setw(16) << processes[i].turnAroundTime
             << setw(12) << processes[i].waitingTime << "\n";
    }

    double sumTAT = 0, sumWT = 0;
    for (const auto& p : processes) { sumTAT += p.turnAroundTime; sumWT += p.waitingTime; }
    cout << string(80, '-') << "\n";
    cout << fixed << setprecision(2)
         << "Avg TAT = " << sumTAT / n << "   |   Avg WT = " << sumWT / n << "\n";
}

int main()
{
    int n;
    cout << "Number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 1; i <= n; i++) {
        string pid; int at, bt;
        cout << "Process " << i << " (pid at bt): ";
        cin >> pid >> at >> bt;
        processes.emplace_back(pid, at, bt);
    }

    shortestJobFirst(processes);
    sort(processes.begin(), processes.end(), cmpCT);
    printProcess(processes);
    return 0;
}