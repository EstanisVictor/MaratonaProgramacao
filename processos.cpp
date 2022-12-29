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

    int getMomento()
    {
        return momentoVolta;
    }
};

bool ordenaTempo(Process *p1, Process *p2)
{
    return p1->getTime() < p2->getTime();
}

bool ordenaMomentoVolta(Process *p1, Process *p2)
{
    return p1->getMomento() < p2->getMomento();
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
    vector<Process *> fila_prioridades;
    for (const auto &p : processos)
    {
        cout << "Durcao " << p->nameProcess << ": " << p->duration_interrupt << endl;
    }
    int momentInterrupt = 0;

    while (!processos.empty())
    {
        bool processoInterrompido = false;
        const auto processoAtual = processos.front();

        if (processoAtual->interrupt)
        {
            // Houve a interrupção
            if ((processoAtual->timeProcess) % 2 == 0)
            {
                momentInterrupt = (processoAtual->timeProcess) / 2;
            }
            else
            {
                momentInterrupt = 1;
            }

            processoAtual->interrupt = false;
            processoAtual->momentoVolta = contTempo + processoAtual->duration_interrupt + momentInterrupt;
            processoAtual->timeProcess = processoAtual->timeProcess - momentInterrupt;
            fila_prioridades.push_back(processoAtual);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processoAtual->timeProcess;
        }
        cout << "-----------------------------------------------------" << endl;
        cout << processoAtual->nameProcess << endl;

        for (int i = 0; i < momentInterrupt; i++)
        {
            cout << "\r" << i + 1 << "s";
            contTempo++;
            sleep(1);

            for (size_t j = 0; j < fila_prioridades.size(); j++)
            {
                if (fila_prioridades[j]->momentoVolta == contTempo)
                {
                    processoInterrompido = true;
                    sort(fila_prioridades.begin(), fila_prioridades.end(), ordenaMomentoVolta);
                    break;
                }
            }

            if (processoInterrompido)
            {
                // salvar as informações do processo interrompido forçado
                processoAtual->momentoVolta = contTempo + (momentInterrupt - i + 1);
                processoAtual->timeProcess = (momentInterrupt - i + 1);
                fila_prioridades.push_back(processoAtual);
                // adicionando o processo de prioridade maior, para voltar a executar
                processos.insert(processos.begin() + 1, fila_prioridades.front());
                // removendo o primeiro elemento da fila de prioridades
                fila_prioridades.erase(fila_prioridades.begin() + 0);
                break;
            }
        }
        cout << "\nTempo Total: " << contTempo;
        cout << endl;

        processos.erase(processos.begin() + 0);
    }

    while (!fila_prioridades.empty())
    {
        const auto processoAtual = fila_prioridades.front();
        cout << "-----------------------------------------------------" << endl;
        cout << processoAtual->nameProcess << endl;
        for (int i = 0; i < momentInterrupt; i++)
        {
            cout << "\r" << i + 1 << "s";
            contTempo++;
            sleep(1);
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

            while (duracao == 0)
            {
                duracao = rand() % 10;
            }
        }
        Process *novoProcesso = new Process(tempo, interrupcao, duracao, "P" + to_string(i + 1), 0);
        processos.push_back(novoProcesso);
    }

    // FCFS(processos);
    // SJF(processos);
    SRT(processos);
    return 0;
}
