#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    const char* atcPipe = "atc_pipe";
    const char* aircraftPipe = "aircraft_pipe";

    // Open ATC pipe for reading
    ifstream atcIn(atcPipe);
    if (!atcIn) {
        cerr << "Error opening ATC pipe!" << endl;
        return 1;
    }

    // Read message from ATC
    string message;
    getline(atcIn, message);
    cout << "Aircraft received: " << message << endl;
    atcIn.close();  // Close after reading

    // Open aircraft pipe for writing response
    ofstream aircraftOut(aircraftPipe);
    if (!aircraftOut) {
        cerr << "Error opening Aircraft pipe!" << endl;
        return 1;
    }

    string response = "Aircraft: Acknowledged. Landing now.";
    cout << "Aircraft: Sending response..." << endl;
    aircraftOut << response << endl;
    aircraftOut.close(); // Close after writing

    return 0;
}
