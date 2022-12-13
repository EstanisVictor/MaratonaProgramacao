#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
        int time;
        bool interrupt;
        int duration_interrupt;
    Process(int _time, bool _interrupt, int _duration){
        time = _time;
        interrupt = _interrupt;
        duration_interrupt = _duration;
    }
};

int main()
{
    vector<Process*> processos;


    for (size_t i = 0; i < 3; i++)
    {
        int duracao = 0;

        cout << "Tempo do processo " << i+1 << endl; 
        int addTime;
        cin >> addTime;

        cout << "Interrupcao P" << i+1 << endl;
        bool interup;
        cin >> interup;

        if(interup){
            srand(time(NULL));
            duracao = rand()%10;
        }

        Process *p = new Process(addTime, interup, duracao);

        processos.push_back(p);
    }
    
    for (size_t i = 0; i < processos.size(); i++)
    {
        
    }
    

    return 0;
}
