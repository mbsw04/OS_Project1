#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    const char* atcPipe = "atc_pipe";
    const char* aircraftPipe = "aircraft_pipe";

    // Open ATC pipe for writing
    ofstream atcOut(atcPipe);
    if (!atcOut) {
        cerr << "Error opening ATC pipe!" << endl;
        return 1;
    }

    // Send landing clearance
    string message = "ATC Tower: Permission granted to land.";
    cout << "ATC Tower: Sending clearance..." << endl;
    atcOut << message << endl;
    atcOut.close();  // Close after writing

    // Open aircraft pipe for reading response
    ifstream aircraftIn(aircraftPipe);
    if (!aircraftIn) {
        cerr << "Error opening Aircraft pipe!" << endl;
        return 1;
    }

    // Read response from aircraft
    string response;
    getline(aircraftIn, response);
    cout << "ATC Tower received: " << response << endl;

    aircraftIn.close(); // Close after reading
    return 0;
}
