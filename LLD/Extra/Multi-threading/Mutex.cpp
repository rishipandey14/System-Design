#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

// Mutex (Mutual Exclusion) is a synchronization primitive that prevents race conditions
// when multiple threads access shared resources simultaneously. It ensures that only one
// thread can execute critical code at a time. We use it to protect shared data from
// concurrent access, preventing data corruption and ensuring thread-safe operations.

mutex carMutex; // Declare a mutex to protect the shared car resource

// Function that simulates a driver using the car
void driveCar(string driverName) {
    unique_lock<mutex> carLock(carMutex); // Lock the mutex - only one thread proceeds, others wait
    cout << driverName << " is driving.." << endl; // Critical section: only one driver at a time
    this_thread::sleep_for(chrono::seconds(2)); // Simulate driving for 2 seconds
    cout << driverName << "is done driving." << endl; // Print when this driver is finished
    carLock.unlock(); // Explicitly release the mutex so other waiting threads can acquire it
}

int main() {
    thread t1(driveCar, "Tom"); // Create thread 1 - Tom tries to drive
    thread t2(driveCar, "Jerry"); // Create thread 2 - Jerry tries to drive

    t1.join(); // Wait for Tom's thread to complete execution
    t2.join(); // Wait for Jerry's thread to complete execution
}