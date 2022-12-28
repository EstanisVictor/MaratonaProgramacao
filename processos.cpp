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
};

void printCounter(int counter)
{
    for (int i = 0; i < counter; i++)
    {
        contTempo++;
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

    cout << "                         SRT" << endl;

    for (const auto &p : processos)
    {
        cout << "Durcao " << p->nameProcess << ": " << p->duration_interrupt << endl;
    }
    int momentoInterrupcao = 0;
    queue<Process *> fila_prioridades;

    for (const auto &p : processos)
    {
        if (p->interrupt)
        {
            momentoInterrupcao = (p->timeProcess) / 2;
            p->interrupt = false;
            p->momentoVolta = momentoInterrupcao + p->duration_interrupt;
            p->timeProcess = momentoInterrupcao;
            fila_prioridades.push(p);
        }
        else
        {
            momentoInterrupcao = p->timeProcess;
        }

        if (!fila_prioridades.empty())
        {
            if ((contTempo + p->timeProcess) > fila_prioridades.front()->momentoVolta)
            {
                if (!(contTempo == fila_prioridades.front()->momentoVolta))
                {
                    // Exec até o momento de volta do proximo processo
                    cout << "----------------------------------------------------" << endl;
                    cout << p->nameProcess << endl;
                    printCounter(fila_prioridades.front()->duration_interrupt);
                }

                if ((contTempo + p->timeProcess) - fila_prioridades.front()->momentoVolta > 0)
                {
                    p->timeProcess = (contTempo + p->timeProcess) - fila_prioridades.front()->momentoVolta;
                    fila_prioridades.push(p);
                }

                while (!fila_prioridades.empty())
                {
                    cout << "----------------------------------------------------" << endl;
                    cout << fila_prioridades.front()->nameProcess << endl;
                    printCounter(fila_prioridades.front()->timeProcess);
                    fila_prioridades.pop();
                }
            }
            else
            {
                cout << "----------------------------------------------------" << endl;
                cout << p->nameProcess << endl;
                printCounter(momentoInterrupcao);
            }
        }
        else
        {
            // Exec tempo normal do processo
            cout << "----------------------------------------------------" << endl;
            cout << p->nameProcess << endl;
            printCounter(momentoInterrupcao);
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
        Process *novoProcesso = new Process(tempo, interrupcao, duracao, "P" + to_string(i + 1), 0);
        processos.push_back(novoProcesso);
    }

    //  FCFS(processos);
    // SJF(processos);
    SRT(processos);
    return 0;
}
