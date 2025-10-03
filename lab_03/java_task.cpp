//Пример 1
import java.util.PriorityQueue;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        maxHeap.add(3);
        maxHeap.add(1);
        maxHeap.add(4);
        maxHeap.add(1);
        maxHeap.add(5);
        
        System.out.print("Max-Heap: ");
        while (!maxHeap.isEmpty()) {
            System.out.print(maxHeap.poll() + " ");
        }
        System.out.println();
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        minHeap.add(3);
        minHeap.add(1);
        minHeap.add(4);
        minHeap.add(1);
        minHeap.add(5);
        
        System.out.print("Min-Heap: ");
        while (!minHeap.isEmpty()) {
            System.out.print(minHeap.poll() + " ");
        }
        System.out.println();
    }
}


//Пример 2
import java.util.PriorityQueue;

class Patient implements Comparable<Patient> {
    String name;
    int severity;
    
    public Patient(String name, int severity) {
        this.name = name;
        this.severity = severity;
    }
    
    @Override
    public int compareTo(Patient other) {
        return Integer.compare(other.severity, this.severity);
    }
}

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Patient> emergencyRoom = new PriorityQueue<>();
        
        emergencyRoom.add(new Patient("John", 2));
        emergencyRoom.add(new Patient("Maria", 5));
        emergencyRoom.add(new Patient("Alex", 1));
        emergencyRoom.add(new Patient("Sarah", 8));
        emergencyRoom.add(new Patient("Mike", 3));
        
        System.out.println("Patients by priority:");
        while (!emergencyRoom.isEmpty()) {
            Patient patient = emergencyRoom.poll();
            System.out.println(patient.name + " (severity: " + patient.severity + ")");
        }
    }
}
