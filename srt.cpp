#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

class Process
{
public:
    string name;
    int burst_time;
    int arrival_time;
    int time_spent;
    bool has_interruption;
    bool is_interrupted;
    int return_time;

    Process(string _name, int _arrivalTime, int _time, int _timeSpent, bool _hasInterruption, bool _isInterrupted, int _returnTime)
    {
        name = _name;
        burst_time = _time;
        arrival_time = _arrivalTime;
        time_spent = _timeSpent;
        has_interruption = _hasInterruption;
        is_interrupted = _isInterrupted;
        return_time = _returnTime;
    }

    int getTime() const
    {
        return burst_time;
    }
};

bool timeOrder(Process *p1, Process *p2)
{
    return p1->getTime() < p2->getTime();
}

int find_process(vector<Process *> processes, int *current_time)
{
    for (int i = 0; i < processes.size(); i++)
    {
        if (processes[i]->arrival_time <= *current_time && processes[i]->return_time <= *current_time)
        {
            return i;
        }
    }

    return 0;
}

int find_fast_process(vector<Process *> processes, int *current_time, Process *current_process, int time)
{
    for (size_t i = 0; i < processes.size(); i++)
    {
        if (processes[i]->arrival_time < *current_time && processes[i]->burst_time - processes[i]->time_spent < current_process->burst_time - time && processes[i]->return_time <= *current_time)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<Process *> processes;

    processes.push_back(new Process("P1", 0, 6, 0, false, false, 0));
    processes.push_back(new Process("P2", 0, 5, 0, true, false, 0));
    processes.push_back(new Process("P3", 0, 7, 0, false, false, 0));

    // processes.push_back(new Process("P1", 0, 1, 0));
    // processes.push_back(new Process("P2", 0, 2, 0));
    // processes.push_back(new Process("P3", 0, 3, 0));
    // processes.push_back(new Process("P4", 0, 4, 0));
    // processes.push_back(new Process("P5", 0, 5, 0));
    // processes.push_back(new Process("P6", 0, 6, 0));
    // processes.push_back(new Process("P7", 16, 1, 0));
    // processes.push_back(new Process("P8", 16, 2, 0));
    // processes.push_back(new Process("P9", 16, 3, 0));
    // processes.push_back(new Process("P10", 16, 4, 0));
    // processes.push_back(new Process("P11", 27, 1, 0));
    // processes.push_back(new Process("P12", 27, 2, 0));
    // processes.push_back(new Process("P13", 27, 3, 0));

    sort(processes.begin(), processes.end(), timeOrder);

    int current_time = 0;
    int countEstadoOcioso = 1;

    while (!processes.empty())
    {
        sort(processes.begin(), processes.end(), timeOrder);
        int index = find_process(processes, &current_time);
        Process *p = processes.at(index);
        processes.erase(processes.begin() + index);

        if (p->is_interrupted && p->return_time > current_time)
        {
            cout << "\rOcioso: " << current_time << "s";

            sleep(1);
            current_time++;
            processes.push_back(p);
            countEstadoOcioso++;

            if (current_time == p->return_time)
            {
                cout << endl;
            }

            continue;
        }

        if (p->arrival_time > current_time)
        {
            cout << "processo nao esta pronto" << endl;

            sleep(1);
            current_time++;
            processes.push_back(p);

            continue;
        }

        if (p->time_spent > 0)
        {
            cout << "-----------------------------------------------------------------" << endl;
            cout << p->name << " comeca a executar no tempo: " << current_time << endl;
        }

        for (size_t tempo = p->time_spent; tempo <= p->burst_time; tempo++)
        {
            sort(processes.begin(), processes.end(), timeOrder);

            int faster_index = find_fast_process(processes, &current_time, p, tempo);

            if (faster_index == -1)
            {
            }
            else
            {
                processes.push_back(new Process(p->name, p->arrival_time, p->burst_time, tempo, p->has_interruption, p->is_interrupted, p->return_time));

                cout << "\n"
                     << p->name << " interrompido!!" << endl;

                cout << "Tempo restante: " << current_time - tempo << endl;

                break;
            }

            if (tempo == 0)
            {
                cout << "-----------------------------------------------------------------" << endl;
                cout << p->name << " comeca a executar no tempo: " << current_time << endl;
                current_time++;
                continue;
            }

            if (tempo == p->burst_time)
            {
                cout << "\rExecutando: " << tempo << "s" << endl;
                sleep(1);
                cout << "Processo: " << p->name << " terminou em " << current_time << endl;
                continue;
            }

            // mudar o tempo depois

            if (p->burst_time % 2 == 0)
            {
            }
            else
            {
            }

            if (p->has_interruption && tempo == 2)
            {

                cout << "\rExecutando: " << tempo << "s" << endl;
                sleep(1);

                int duration = 4;
                cout << "*****************************************************************" << endl;
                cout << "Processo esta interrompido por " << tempo << "s" << endl;
                cout << "Processo vai retornar aos " << current_time + duration << "s" << endl;
                cout << "*****************************************************************" << endl;

                Process *processoSalvo = new Process(p->name, p->arrival_time, p->burst_time, tempo, false, true, current_time + duration);

                processes.push_back(processoSalvo);

                break;
            }

            cout << "\rExecutando: " << tempo << "s";
            sleep(1);
            current_time++;
        }
    }
    cout << "Tempo total: " << current_time << "s" << endl;
    return 0;
}
