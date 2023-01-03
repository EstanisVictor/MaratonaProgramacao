#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int tempoAtual = 0;

class Process
{
public:
    string nameProcess;
    int timeProcess;
    bool interrupt;
    int duration_interrupt;
    int momentoVolta;
    bool status;

    Process()
    {
    }

    Process(int _time, bool _interrupt, int _duration, string _nameProcess, bool _status)
    {
        nameProcess = _nameProcess;
        timeProcess = _time;
        interrupt = _interrupt;
        duration_interrupt = _duration;
        status = _status;
    }
    // Construtor para SRT
    Process(int _time, bool _interrupt, int _duration, string _nameProcess, int _momentoVolta, bool _status)
    {
        nameProcess = _nameProcess;
        timeProcess = _time;
        interrupt = _interrupt;
        duration_interrupt = _duration;
        momentoVolta = _momentoVolta;
        status = _status;
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

void printDuracaoInterrupcao(vector<Process *> processos)
{
    for (const auto &p : processos)
    {
        cout << p->nameProcess << " --> durcao de interrupcao: " << p->duration_interrupt << " | Tempo de execucao: " << p->timeProcess << endl;
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

            Process *novoProcesso = new Process((processos[i]->timeProcess - momentInterrupt),
                                                false, processos[i]->duration_interrupt, processos[i]->nameProcess,
                                                (tempoAtual + processos[i]->duration_interrupt), true);

            processos.push_back(novoProcesso);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processos[i]->timeProcess;
        }

        if (tempoAtual < processos[i]->momentoVolta && processos[i]->status)
        {
            // pode estar ocioso
            cout << "-----------------------------------------------------------------" << endl;
            cout << "CPU em estado de ocioso..." << endl;

            printCounter(processos[i]->momentoVolta - tempoAtual + 1);

            cout << "-----------------------------------------------------------------" << endl;
            cout << processos[i]->nameProcess << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
        else
        {
            cout << "-----------------------------------------------------------------" << endl;
            cout << processos[i]->nameProcess << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
    }
}

// menor tempo executa primeiro
void SJF(vector<Process *> processos)
{
    tempoAtual = 0;
    int momentInterrupt = 0;
    sort(processos.begin(), processos.end(), ordenaTempo);

    cout << "                         SJF" << endl;
    printDuracaoInterrupcao(processos);
    while (!processos.empty())
    {
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
            Process *novoProcesso = new Process((processoAtual->timeProcess - momentInterrupt),
                                                false, processoAtual->duration_interrupt, processoAtual->nameProcess,
                                                (tempoAtual + processoAtual->duration_interrupt + momentInterrupt), true);
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
            momentInterrupt = processoAtual->timeProcess;
        }

        if (tempoAtual < processoAtual->momentoVolta && processoAtual->status)
        {
            // pode estar ocioso
            cout << "-----------------------------------------------------------------" << endl;
            cout << "CPU em estado de ocioso..." << endl;

            printCounter(processoAtual->momentoVolta - tempoAtual);

            cout << "-----------------------------------------------------------------" << endl;
            cout << processoAtual->nameProcess << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
        else
        {
            cout << "-----------------------------------------------------------------" << endl;
            cout << processoAtual->nameProcess << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }
        processos.erase(processos.begin() + 0);
    }
}

void printCounterSRT(int counter, vector<Process *> &fila_prioridades, Process *processoAtual, vector<Process *> &processos)
{
    auto processoPrioridade = new Process();
    int indiceProcessoPrioridade = 0;
    bool processoInterrompido = false;

    for (int i = 1; i <= counter; i++)
    {
        // verificação para ver se é o momento de interromper
        if (!fila_prioridades.empty())
        {
            for (size_t j = 0; j < fila_prioridades.size(); j++)
            {
                if (fila_prioridades[j]->momentoVolta == tempoAtual)
                {
                    processoInterrompido = true;
                    processoPrioridade = fila_prioridades[j];
                    indiceProcessoPrioridade = j;
                    break;
                }
            }
        }

        if (processoInterrompido)
        {
            // salvar as informações do processo interrompido forçado
            processoAtual->timeProcess = processoAtual->timeProcess - i;
            processoAtual->momentoVolta = tempoAtual + processoAtual->duration_interrupt + i;
            fila_prioridades.push_back(processoAtual);
            // adicionando o processo de prioridade maior, para voltar a executar
            processos.insert(processos.begin() + 1, processoPrioridade);
            // removendo o primeiro elemento da fila de prioridades
            fila_prioridades.erase(fila_prioridades.begin() + indiceProcessoPrioridade);
            break;
        }

        cout << "\rExecutando: " << i << "s";
        sleep(1);
        tempoAtual++;
    }
    cout << "\nTerminou em: " << tempoAtual << endl;
}

/*
Menor tempo entra, caso de interrupção, o grau de prioridade está atrelado ao menor tempo
*/
void SRT(vector<Process *> processos)
{
    tempoAtual = 0;
    int momentInterrupt = 0;
    vector<Process *> fila_prioridades;
    auto processoPrioridade = new Process();
    int indiceProcessoPrioridade = 0;

    sort(processos.begin(), processos.end(), ordenaTempo);
    cout << "                         SRT" << endl;

    printDuracaoInterrupcao(processos);

    while (!processos.empty())
    {
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
            Process *novoProcesso = new Process((processoAtual->timeProcess - momentInterrupt),
                                                false, processoAtual->duration_interrupt, processoAtual->nameProcess,
                                                (tempoAtual + processoAtual->duration_interrupt + momentInterrupt), true);
            fila_prioridades.push_back(novoProcesso);
        }
        else
        {
            // Não houve interrupção, vai executar o tempo total do processo
            momentInterrupt = processoAtual->timeProcess;
        }

        if (tempoAtual < processoAtual->momentoVolta && processoAtual->status)
        {
            // pode estar ocioso
            cout << "o-----------------------------------------------------------------" << endl;
            cout << "CPU em estado de ocioso..." << endl;

            printCounter(processoAtual->momentoVolta - tempoAtual);

            processos.insert(processos.begin() + 1, processoAtual);
        }
        else
        {
            cout << "p-----------------------------------------------------------------" << endl;
            cout << processoAtual->nameProcess << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounterSRT(momentInterrupt, fila_prioridades, processoAtual, processos);
        }
        processos.erase(processos.begin() + 0);
    }

    while (!fila_prioridades.empty())
    {
        const auto processoAtual = fila_prioridades.front();

        if (tempoAtual < processoAtual->momentoVolta && processoAtual->status)
        {
            // pode estar ocioso
            cout << "q-----------------------------------------------------------------" << endl;
            cout << "CPU em estado de ocioso..." << endl;

            printCounter(processoAtual->momentoVolta - tempoAtual);

            fila_prioridades.insert(fila_prioridades.begin() + 1, processoAtual);
        }
        else
        {
            cout << "r-----------------------------------------------------------------" << endl;
            cout << processoAtual->nameProcess << " comeca a executar no tempo: " << tempoAtual << endl;
            printCounter(momentInterrupt);
        }

        fila_prioridades.erase(fila_prioridades.begin() + 0);
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
        Process *novoProcesso = new Process(tempo, interrupcao, duracao, "P" + to_string(i + 1), 0, false);
        processos.push_back(novoProcesso);
    }

    // FCFS(processos);
    // SJF(processos);
    SRT(processos);
    system("pause");
    return 0;
}