
public class Node {

    public Node nodeLeft;
    public Node nodeRight;
    public int key;
    public int size;

    public Node() {

    }

    public Node(int key) {
        this.key = key;
    }

    public void insert(int key) {
        if (key < this.key) {
            if (nodeLeft == null) {
                nodeLeft = new Node(key);
            }
            else {
                nodeLeft.insert(key);
            }
        }
        else {
            if (nodeRight == null) {
                nodeRight = new Node(key);
            }
            else {
                nodeRight.insert(key);
            }
        }
    }

    public int getHeight() {
        int lengthLeft = 0;
        int lengthRight = 0;
        if (nodeLeft != null) {
            lengthLeft = nodeLeft.getHeight() + 1;
        }
        if (nodeRight != null) {
            lengthRight = nodeRight.getHeight() + 1;
        }
        return Math.max(lengthLeft, lengthRight);
    }


}