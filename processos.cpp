#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

vector<int> tempos_Processos;
int contTempo = 0;

class Process
{
public:
    string nameProcess;
    int timeProcess;
    bool interrupt;
    int duration_interrupt;
    int momentoVolta;
    Process(int _time, bool _interrupt, int _duration, string _nameProcess)
    {
        nameProcess = _nameProcess;
        timeProcess = _time;
        interrupt = _interrupt;
        duration_interrupt = _duration;
    }
    // Construtor para SRT
    Process(int _time, bool _interrupt, int _duration, string _nameProcess, int _momentoVolta)
    {
        nameProcess = _nameProcess;
        timeProcess = _time;
        interrupt = _interrupt;
        duration_interrupt = _duration;
        momentoVolta = _momentoVolta;
    }

    int getTime() const
    {
        return timeProcess;
    }
};

bool ordenaTempo(Process *p1, Process *p2)
{
    return p1->getTime() < p2->getTime();
}

void printCounter(int counter)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "\r" << i + 1 << "s";
        sleep(1);
    }
    cout << endl;
}
// prmeiro entra, primeiro sai
void FCFS(vector<Process *> processos)
{
    int momentInterrupt = 0;
    cout << "                         FCFS" << endl;
    for (size_t i = 0; i < processos.size(); i++)
    {

        if (processos[i]->interrupt)
        {
            // Houve a interrupção
            if ((processos[i]->timeProcess) % 2 == 0)
            {
                momentInterrupt = (processos[i]->timeProcess) / 2;
            }
            else
            {
                momentInterrupt = 1;
            }

            processos[i]->interrupt = false;
            processos[i]->timeProcess = processos[i]->timeProcess - momentInterrupt;
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

// menor tempo executa primeiro
void SJF(vector<Process *> processos)
{
    contTempo = 0;
    int momentInterrupt = 0;
    sort(processos.begin(), processos.end(), ordenaTempo);
    cout << "                         SJF" << endl;

    while (!processos.empty())
    {
        const auto p = processos.front();

        if (p->interrupt)
        {
            // Houve a interrupção
            if ((p->timeProcess) % 2 == 0)
            {
                momentInterrupt = (p->timeProcess) / 2;
            }
            else
            {
                momentInterrupt = 1;
            }

            p->interrupt = false;
            p->timeProcess = p->timeProcess - momentInterrupt;
            processos.insert(processos.begin() + 2, p);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = p->timeProcess;
        }
        cout << "-----------------------------------------------------" << endl;
        cout << p->nameProcess << endl;
        printCounter(momentInterrupt);
        processos.erase(processos.begin() + 0);
    }
}
/*
Menor tempo entra, caso de interrupção, o grau de prioridade está atrelado ao menor tempo
*/
void SRT(vector<Process *> processos)
{
    contTempo = 0;
    sort(processos.begin(), processos.end(), ordenaTempo);
    cout << "                         SRT" << endl;

    for (const auto &p : processos)
    {
        cout << "Durcao " << p->nameProcess << ": " << p->duration_interrupt << endl;
    }
    int momentInterrupt = 0;

    while (!processos.empty())
    {
        const auto p = processos.front();

        if (p->interrupt)
        {
            // Houve a interrupção
            if ((p->timeProcess) % 2 == 0)
            {
                momentInterrupt = (p->timeProcess) / 2;
            }
            else
            {
                momentInterrupt = 1;
            }

            p->interrupt = false;
            p->momentoVolta = contTempo + p->duration_interrupt + momentInterrupt;
            p->timeProcess = p->timeProcess - momentInterrupt;
            processos.insert(processos.end(), p);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = p->timeProcess;
        }
        cout << "-----------------------------------------------------" << endl;
        cout << p->nameProcess << endl;

        for (int i = 0; i < momentInterrupt; i++)
        {

            cout << "\r" << i + 1 << "s";
            contTempo++;
            sleep(1);

            if (contTempo == p->momentoVolta)
            {
                // salvar as informações do processo interrompido forçado
                p->duration_interrupt = 0;
                break;
            }
        }
        cout << "\nTempo Total: " << contTempo;
        cout << endl;

        processos.erase(processos.begin() + 0);
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
        Process *novoProcesso = new Process(tempo, interrupcao, duracao, "P" + to_string(i + 1), 0);
        processos.push_back(novoProcesso);
    }

    // FCFS(processos);
    SJF(processos);
    // SRT(processos);
    return 0;
}
