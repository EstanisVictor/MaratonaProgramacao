#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

queue<string> queue_process;

class Process
{
public:
    string nameProcess;
    int timeProcess;
    bool interrupt;
    int duration_interrupt;
    Process(int _time, bool _interrupt, int _duration, string _nameProcess)
    {
        nameProcess = _nameProcess;
        timeProcess = _time;
        interrupt = _interrupt;
        duration_interrupt = _duration;
    }
};

void printCounter(int counter)
{
    for (size_t i = 0; i < counter; i++)
    {
        cout << "\r" << i + 1 << "s";
        sleep(1);
    }
    cout << endl;
}

void FCFS(vector<Process *> processes)
{
    int momentInterrupt = 0;

    for (size_t i = 0; i < processes.size(); i++)
    {

        if (processes[i]->interrupt)
        {
            // Houve a interrupção
            momentInterrupt = (processes[i]->timeProcess) / 2;
            processes[i]->interrupt = false;
            processes[i]->timeProcess = (processes[i]->timeProcess) / 2;
            processes.push_back(processes[i]);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processes[i]->timeProcess;
        }

        cout << "-----------------------------------------------------" << endl;
        cout << processes[i]->nameProcess << endl;
        printCounter(momentInterrupt);
    }
}

int main()
{
    vector<Process *> processes;

    for (size_t i = 0; i < 3; i++)
    {
        int duration = 0;

        cout << "Tempo do processo " << i + 1 << "?" << endl;
        int addTime;
        cin >> addTime;

        cout << "P" << i + 1 << " tem interrupcao?" << endl;
        cout << "0 - NAO\n1 - SIM" << endl;
        bool interuptQuestion;
        cin >> interuptQuestion;

        if (interuptQuestion)
        {
            srand(time(NULL));
            duration = rand() % 10;
        }

        Process *p = new Process(addTime, interuptQuestion, duration, "P" + to_string(i + 1));

        processes.push_back(p);
    }

    FCFS(processes);

    return 0;
}
