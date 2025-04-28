#include <iostream>
#include <vector>
using namespace std;

void bullyElection(vector<int> processes, int initiator)
{
    int n = processes.size();
    vector<bool> alive(n, true); // Assume all processes are alive

    cout << "Process " << processes[initiator] << " initiates election." << endl;
    bool leaderFound = false;
    int leader = -1;

    // Initiator sends election message to all higher-ID processes
    for (int i = initiator + 1; i < n; i++)
    {
        if (alive[i])
        {
            cout << "Process " << processes[initiator]
                 << " sends election message to Process " << processes[i] << endl;
        }
    }

    // Check if any higher ID process responds
    for (int i = initiator + 1; i < n; i++)
    {
        if (alive[i])
        {
            cout << "Process " << processes[i]
                 << " responds to election message." << endl;
            leaderFound = true;
            bullyElection(processes, i); // Higher process takes over election
            return;
        }
    }

    // If no higher process responds, initiator becomes leader
    if (!leaderFound)
    {
        leader = processes[initiator];
        cout << "Process " << leader << " becomes the Leader." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> processes(n);
    cout << "Enter process IDs (in increasing order):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i];
    }

    int initiator;
    cout << "Enter initiator process index (0 to " << n - 1 << "): ";
    cin >> initiator;

    bullyElection(processes, initiator);

    return 0;
}
