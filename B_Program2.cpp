#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main() {
    const char* atcPipe = "atc_pipe";
    const char* aircraftPipe = "aircraft_pipe";

    // Ensure pipes exist
    mkfifo(atcPipe, 0666);
    mkfifo(aircraftPipe, 0666);

    // Open ATC pipe for reading (receive clearance)
    ifstream atcIn(atcPipe);
    if (!atcIn) {
        cerr << "Error opening ATC pipe for reading!" << endl;
        return 1;
    }

    string message;
    getline(atcIn, message);
    cout << "Aircraft received: " << message << endl;
    atcIn.close(); // Close after reading

    // Open aircraft pipe for writing response
    ofstream aircraftOut(aircraftPipe);
    if (!aircraftOut) {
        cerr << "Error opening Aircraft pipe for writing!" << endl;
        return 1;
    }

    string response = "Aircraft: Acknowledged. Landing now.";
    cout << "Aircraft: Sending response..." << endl;
    aircraftOut << response << endl;
    aircraftOut.close(); // Close after writing

    return 0;
}
