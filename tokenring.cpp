#include <iostream>
#include <vector>
using namespace std;

// Function to simulate leader election using token ring
void tokenRingElection(vector<int> processes, int initiator)
{
    int n = processes.size();
    int token = processes[initiator];  // Start token with initiator's ID
    int current = (initiator + 1) % n; // Next process
    cout << "Election Started by Process " << processes[initiator] << endl;

    // Passing token around the ring
    while (current != initiator)
    {
        cout << "Token passed from Process " << ((current - 1 + n) % n)
             << " to Process " << current << endl;

        cout << "Process " << processes[current] << " received token with ID " << token << endl;

        if (processes[current] > token)
        {
            cout << "Process " << processes[current] << " updates token." << endl;
            token = processes[current];
        }
        else
        {
            cout << "Process " << processes[current] << " does not update token." << endl;
        }
        current = (current + 1) % n; // Move to next process
    }

    cout << "Token returned to initiator Process " << processes[initiator] << endl;
    cout << "Leader is Process " << token << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> processes(n);
    cout << "Enter process IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i];
    }

    int initiator;
    cout << "Enter initiator process index (0 to " << n - 1 << "): ";
    cin >> initiator;

    tokenRingElection(processes, initiator);

    return 0;
}
