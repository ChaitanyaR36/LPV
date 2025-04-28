#include <iostream>
#include <unistd.h> // for sleep
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes (sites): ";
    cin >> n;

    int token = 0; // Token is initially with process 0
    char choice;

    while (true)
    {
        cout << "\nProcess " << token << " has the token." << endl;

        cout << "Process " << token << ": Do you want to enter Critical Section? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Process " << token << " is ENTERING Critical Section..." << endl;
            sleep(2); // simulate some work
            cout << "Process " << token << " is LEAVING Critical Section." << endl;
        }
        else
        {
            cout << "Process " << token << " does NOT enter Critical Section." << endl;
        }

        // Pass the token to next process
        token = (token + 1) % n;
        cout << "Token passed to Process " << token << ".\n";
    }

    return 0;
}
