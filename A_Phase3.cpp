#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex runwayMutex, towerMutex; // Mutexes for runway and control tower access

/**
 * Function to simulate a plane operation while causing a deadlock.
 * The function locks one resource first, then waits for the other, creating a potential deadlock.
 * @param planeID - Unique ID for the plane.
 * @param isLanding - True if the plane is landing, false if taking off.
 */
void planeOperation(int planeID, bool isLanding) {
    cout << "Plane " << planeID << " is requesting " << (isLanding ? "landing" : "takeoff") << " clearance.\n";

    lock_guard<mutex> lock1(runwayMutex); // Lock runway first
    this_thread::sleep_for(chrono::milliseconds(100)); // Simulate delay
    lock_guard<mutex> lock2(towerMutex); // Lock tower after a delay (risk of deadlock)

    cout << "Plane " << planeID << " has received clearance and is " << (isLanding ? "landing" : "taking off") << ".\n";
}

int main() {
    thread t1(planeOperation, 1, true);
    thread t2(planeOperation, 2, false);
    thread t1(planeOperation, 3, true);
    thread t2(planeOperation, 4, false);

    t1.join();
    t2.join();

    cout << "All operations completed.\n";
    return 0;
}
