#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>  // for std::put_time

void update() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
    while (true) {
        std::time_t now = std::time(0);                    // Get current time
        std::tm* localtm = std::localtime(&now);           // Convert to local time
        std::cout << "Current Time: " 
                  << std::put_time(localtm, "%Y-%m-%d %H:%M:%S") 
                  << std::endl;
        update();                                          // Wait for 1 second
    }
    return 0;
}
