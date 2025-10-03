//Пример 1
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
    std::priority_queue<int> maxHeap;
    
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);
    
    std::cout << "Max-Heap: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);
    
    std::cout << "Min-Heap: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;
    
    return 0;
}


//Пример 2
#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Patient {
    std::string name;
    int severity;
    
    bool operator<(const Patient& other) const {
        return severity < other.severity;
    }
};

int main() {
    std::priority_queue<Patient> emergencyRoom;
    
    emergencyRoom.push({"John", 2});
    emergencyRoom.push({"Maria", 5});
    emergencyRoom.push({"Alex", 1});
    emergencyRoom.push({"Sarah", 8});
    emergencyRoom.push({"Mike", 3});
    
    std::cout << "Patients by priority:\n";
    while (!emergencyRoom.empty()) {
        auto patient = emergencyRoom.top();
        std::cout << patient.name << " (severity: " << patient.severity << ")\n";
        emergencyRoom.pop();
    }
    
    return 0;
}
