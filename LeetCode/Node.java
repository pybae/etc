public class Node {
    public int value;
    public Node next;

    public Node(int value, Node next) {
        this.value = value;
        this.next  = next;
    }

    public Node(int value) {
        this.value = value;
        this.next  = null;
    }

    public boolean hasNext() {
        return this.next != null;
    }

    public String toString () {
        return String.valueOf(value);
    }

    public static void reverse(Node head) {
        if (head.next == null) {
            return;
        }

        Node curr = head;
        Node prev = null;

        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

    }

    public static void reverseRecursively(Node head) {
        if (!head.hasNext()) {
            return;
        }
        reverse(head.next);
        head.next.next = head;
        head.next = null;
        head = head.next;
    }

    public static void main(String[] args) {
        Node a = new Node(10);
        Node b = new Node(9, a);
        Node c = new Node(8, b);
        Node d = new Node(7, c);
        Node e = new Node(6, d);
        Node f = new Node(5, e);
        Node g = new Node(4, f);
        Node h = new Node(3, g);

        Node curr = h;
        while (curr.hasNext()) {
            System.out.println(curr);
            curr = curr.next;
        }

        reverseRecursively(h);
        System.out.println();

        curr = a;
        while (curr.hasNext()) {
            System.out.println(curr);
            curr = curr.next;
        }
    }
}
