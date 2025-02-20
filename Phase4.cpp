#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex runwayMutex, towerMutex; // Mutexes for runway and control tower access

/**
 * Function to safely acquire both runway and tower locks to prevent deadlocks.
 * Uses lock() to ensure safe multi-lock acquisition.
 * @param planeID - Unique ID for the plane.
 * @param isLanding - True if the plane is landing, false if taking off.
 */
void planeOperation(int planeID, bool isLanding) {
    cout << "Plane " << planeID << " is requesting " << (isLanding ? "landing" : "takeoff") << " clearance.\n";

    // Lock both resources safely using lock()
    lock(runwayMutex, towerMutex);
    lock_guard<mutex> lock1(runwayMutex, adopt_lock);
    lock_guard<mutex> lock2(towerMutex, adopt_lock);

    cout << "Plane " << planeID << " has received clearance and is " << (isLanding ? "landing" : "taking off") << ".\n";
}

int main() {
    thread t1(planeOperation, 1, true);
    thread t2(planeOperation, 2, false);

    t1.join();
    t2.join();

    cout << "All operations completed.\n";
    return 0;
}
