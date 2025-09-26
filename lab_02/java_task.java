//1 Пример
class Node {
    int data;
    Node next;
    
    Node(int data) {
        this.data = data;
    }
}

public class Main {
    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
    }
}


//2 пример
class LinkedList {
    class Node {
        int data;
        Node next;
        
        Node(int data) {
            this.data = data;
        }
    }
    
    Node head;
    
    void add(int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(3);
        list.add(2);
        list.add(1);
        
        LinkedList.Node current = list.head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
    }
}
