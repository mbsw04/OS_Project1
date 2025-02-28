#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main() {
    const char* atcPipe = "atc_pipe";
    const char* aircraftPipe = "aircraft_pipe";

    // Create named pipes if they don't exist
    mkfifo(atcPipe, 0666);
    mkfifo(aircraftPipe, 0666);

    // Open ATC pipe for writing (send clearance)
    ofstream atcOut(atcPipe);
    if (!atcOut) {
        cerr << "Error opening ATC pipe for writing!" << endl;
        return 1;
    }

    string message = "ATC Tower: Permission granted to land.";
    cout << "ATC Tower: Sending clearance..." << endl;
    atcOut << message << endl;
    atcOut.close(); // Close after writing

    // Open aircraft pipe for reading response
    ifstream aircraftIn(aircraftPipe);
    if (!aircraftIn) {
        cerr << "Error opening Aircraft pipe for reading!" << endl;
        return 1;
    }

    string response;
    getline(aircraftIn, response);
    cout << "ATC Tower received: " << response << endl;
    aircraftIn.close(); // Close after reading

    return 0;
}
