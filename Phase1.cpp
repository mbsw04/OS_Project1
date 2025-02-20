#include <iostream>
#include <thread>
#include <vector>

using namespace std;

/**
 * Function to simulate a plane's operation (landing or takeoff).
 * @param planeID - Unique ID for the plane.
 * @param isLanding - True if the plane is landing, false if taking off.
 */
void planeOperation(int planeID, bool isLanding) {
    if (isLanding) {
        cout << "Plane " << planeID << " is requesting to land...\n";
    } else {
        cout << "Plane " << planeID << " is requesting to take off...\n";
    }
}

int main() {
    const int numPlanes = 5; // Number of planes
    vector<thread> planes;

    // Create threads for each plane operation
    for (int i = 0; i < numPlanes; ++i) {
        bool isLanding = (i % 2 == 0);
        planes.push_back(thread(planeOperation, i + 1, isLanding));
    }

    // Wait for all threads to finish
    for (auto& plane : planes) {
        plane.join();
    }

    cout << "All operations completed.\n";
    return 0;
}
