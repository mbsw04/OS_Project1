#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex runwayMutex; // Mutex for controlling runway access

/**
 * Function to simulate a plane landing or taking off.
 * Ensures only one plane can use the runway at a time.
 * @param planeID - Unique ID for the plane.
 * @param isLanding - True if the plane is landing, false if taking off.
 */
void planeOperation(int planeID, bool isLanding) {
    cout << "Plane " << planeID << " is requesting to " << (isLanding ? "land" : "take off") << "...\n";
    
    lock_guard<mutex> lock(runwayMutex); // Ensure exclusive access to the runway
    cout << "Plane " << planeID << " is using the runway to " << (isLanding ? "land" : "take off") << "...\n";
    
    this_thread::sleep_for(chrono::seconds(1)); // Simulate runway usage

    cout << "Plane " << planeID << " has completed its operation and cleared the runway.\n";
}

int main() {
    const int numPlanes = 5;
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
