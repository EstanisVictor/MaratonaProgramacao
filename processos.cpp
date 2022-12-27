#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

vector<int> tempos_Processos;

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
    for (int i = 0; i < counter; i++)
    {
        cout << "\r" << i + 1 << "s";
        sleep(1);
    }
    cout << endl;
}

void FCFS(vector<Process *> processos)
{
    int momentInterrupt = 0;
    cout << "                         FCFS" << endl;
    for (size_t i = 0; i < processos.size(); i++)
    {

        if (processos[i]->interrupt)
        {
            // Houve a interrupção
            momentInterrupt = (processos[i]->timeProcess) / 2;
            processos[i]->interrupt = false;
            processos[i]->timeProcess = (processos[i]->timeProcess) / 2;
            processos.push_back(processos[i]);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processos[i]->timeProcess;
        }

        cout << "-----------------------------------------------------" << endl;
        cout << processos[i]->nameProcess << endl;
        printCounter(momentInterrupt);
    }
}

vector<Process *> ordenaVetorMenorTempo(vector<Process *> processos)
{
    vector<Process *> fila_processos;

    for (size_t i = 0; i < processos.size(); i++)
    {
        for (size_t j = 0; j < processos.size(); j++)
        {
            if (processos[j]->timeProcess == tempos_Processos[i])
            {
                fila_processos.push_back(processos[j]);
            }
        }
    }
    return fila_processos;
}

void SJF(vector<Process *> processos)
{

    sort(tempos_Processos.begin(), tempos_Processos.end());
    processos = ordenaVetorMenorTempo(processos);
    cout << "                         SJF" << endl;
    for (const auto &p : processos)
    {

        cout << "-----------------------------------------------------" << endl;
        cout << p->nameProcess << endl;
        printCounter(p->timeProcess);
    }
}

void SRT(vector<Process *> processos)
{
    sort(tempos_Processos.begin(), tempos_Processos.end());
    processos = ordenaVetorMenorTempo(processos);
    int momentoInterrupcao = 0;
    queue<int> fila_voltas;
    for (const auto &p : processos)
    {

        if (p->interrupt)
        {
            momentoInterrupcao = (p->timeProcess) / 2;
            // Momento em que o processo de maior prioridade voltará
            fila_voltas.push(momentoInterrupcao + p->duration_interrupt);
        }

        cout << "-----------------------------------------------------" << endl;
        cout << p->nameProcess << endl;

        if (fila_voltas.empty())
        {
            // tempo normal do processo
            printCounter(p->timeProcess);
        }
        else
        {
            // tempo até onde o processo irá executar
            printCounter(fila_voltas.front());
            fila_voltas.pop();
            
        }

        
    }
}
int main()
{
    vector<Process *> processos;

    for (size_t i = 0; i < 3; i++)
    {
        int duracao = 0;

        cout << "Tempo do processo " << i + 1 << "?" << endl;
        int tempo;
        cin >> tempo;
        tempos_Processos.push_back(tempo);

        cout << "P" << i + 1 << " tem interrupcao?" << endl;
        cout << "0 - NAO\n1 - SIM" << endl;
        bool interrupcao;
        cin >> interrupcao;

        if (interrupcao)
        {
            srand(time(NULL));
            duracao = rand() % 10;
        }

        Process *p = new Process(tempo, interrupcao, duracao, "P" + to_string(i + 1));

        processos.push_back(p);
    }

    //  FCFS(processos);
    SJF(processos);
    SRT(processos);
    return 0;
}
