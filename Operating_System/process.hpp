#include<iostream>
#include<iomanip>
using namespace std;

class Process
{
  public:
    string processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;

    Process(string pid, int at, int bt)
    {
        processId=pid;
        arrivalTime=at;
        burstTime=bt;
    }
};

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