#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int tempoAtual = 0;

class Process
{
public:
    string name;
    int time;
    bool is_interrupted;
    int interruption_time;
    int return_time;
    bool status;

    Process()
    {
    }

    Process(int _time, bool _interrupt, int _duration, string _nameProcess, bool _status)
    {
        name = _nameProcess;
        time = _time;
        is_interrupted = _interrupt;
        interruption_time = _duration;
        status = _status;
    }
    // Construtor para SRT
    Process(int _time, bool _interrupt, int _duration, string _nameProcess, int _momentoVolta, bool _status)
    {
        name = _nameProcess;
        time = _time;
        is_interrupted = _interrupt;
        interruption_time = _duration;
        return_time = _momentoVolta;
        status = _status;
    }

    int getTime() const
    {
        return time;
    }

    int getMomento()
    {
        return return_time;
    }
};

bool timeOrder(Process *p1, Process *p2)
{
    return p1->getTime() < p2->getTime();
}

bool ordenaMomentoVolta(Process *p1, Process *p2)
{
    return p1->getMomento() < p2->getMomento();
}

void printDuracaoInterrupcao(vector<Process *> processos)
{
    for (const auto &p : processos)
    {
        cout << p->name << " --> durcao de interrupcao: " << p->interruption_time << " | Tempo de execucao: " << p->time << endl;
    }
}

void printCounter(int counter)
{
    for (int i = 1; i <= counter; i++)
    {
        cout << "\rExecutando: " << i << "s";
        sleep(1);
        tempoAtual++;
    }
    cout << "\nTerminou em: " << tempoAtual << endl;
}
// prmeiro entra, primeiro sai
void FCFS(vector<Process *> processos)
{
    int momentInterrupt = 0;
    cout << "                         FCFS" << endl;
    printDuracaoInterrupcao(processos);
    for (size_t i = 0; i < processos.size(); i++)
    {

        if (processos[i]->is_interrupted)
        {
            // Houve a interrupção
            if ((processos[i]->time) % 2 == 0)
            {
                momentInterrupt = (processos[i]->time) / 2;
            }
            else
            {
                momentInterrupt = 1;
            }

            Process *novoProcesso = new Process((processos[i]->time - momentInterrupt),
                                                false, processos[i]->interruption_time, processos[i]->name,
                                                (tempoAtual + processos[i]->interruption_time), true);

            processos.push_back(novoProcesso);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processos[i]->time;
        }

        if (tempoAtual < processos[i]->return_time && processos[i]->status)
        {
            // pode estar ocioso
            cout << "-----------------------------------------------------------------" << endl;
            cout << "CPU em estado de ocioso..." << endl;

            printCounter(processos[i]->return_time - tempoAtual + 1);

            cout << "-----------------------------------------------------------------" << endl;
            cout << processos[i]->name << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
        else
        {
            cout << "-----------------------------------------------------------------" << endl;
            cout << processos[i]->name << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
    }
}
// menor tempo executa primeiro
void SJF(vector<Process *> processos)
{
    tempoAtual = 0;
    int momentInterrupt = 0;
    sort(processos.begin(), processos.end(), timeOrder);

    cout << "                         SJF" << endl;
    printDuracaoInterrupcao(processos);
    while (!processos.empty())
    {
        const auto processoAtual = processos.front();

        if (processoAtual->is_interrupted)
        {
            // Houve a interrupção
            if ((processoAtual->time) % 2 == 0)
            {
                momentInterrupt = (processoAtual->time) / 2;
            }
            else
            {
                momentInterrupt = 1;
            }
            Process *novoProcesso = new Process((processoAtual->time - momentInterrupt),
                                                false, processoAtual->interruption_time, processoAtual->name,
                                                (tempoAtual + processoAtual->interruption_time + momentInterrupt), true);
            if (processos.size() == 1)
            {
                processos.insert(processos.end(), novoProcesso);
            }
            else
            {
                processos.insert(processos.begin() + 2, novoProcesso);
            }
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processoAtual->time;
        }

        if (tempoAtual < processoAtual->return_time && processoAtual->status)
        {
            // pode estar ocioso
            cout << "-----------------------------------------------------------------" << endl;
            cout << "CPU em estado de ocioso..." << endl;

            printCounter(processoAtual->return_time - tempoAtual);

            cout << "-----------------------------------------------------------------" << endl;
            cout << processoAtual->name << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
        else
        {
            cout << "-----------------------------------------------------------------" << endl;
            cout << processoAtual->name << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
        processos.erase(processos.begin() + 0);
    }
}

/*
Menor tempo entra, caso de interrupção, o grau de prioridade está atrelado ao menor tempo
*/
void SRT(vector<Process *> processos)
{
    sort(processos.begin(), processos.end(), timeOrder);

    
}

int main()
{
    vector<Process *> processos;

    // for (size_t i = 0; i < 3; i++)
    // {
    //     int duracao = 0;

    //     cout << "Tempo do processo " << i + 1 << "?" << endl;
    //     int tempo;
    //     cin >> tempo;

    //     cout << "P" << i + 1 << " tem interrupcao?" << endl;
    //     cout << "0 - NAO\n1 - SIM" << endl;
    //     bool interrupcao;
    //     cin >> interrupcao;

    //     if (interrupcao)
    //     {
    //         srand(time(NULL));

    //         while (duracao == 0)
    //         {
    //             duracao = rand() % 10;
    //         }
    //     }
    //     Process *novoProcesso = new Process(tempo, interrupcao, duracao, "P" + to_string(i + 1), 0, false);
    //     processos.push_back(novoProcesso);
    // }
    Process *p1 = new Process(8, false, 5, "P" + to_string(1), 0);
    Process *p2 = new Process(4, true, 2, "P" + to_string(2), 0);
    processos.push_back(p1);
    processos.push_back(p2);
    // FCFS(processos);
    // SJF(processos);
    SRT(processos);
    return 0;
}