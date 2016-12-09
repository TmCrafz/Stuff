
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

    public int calcSize() {
        int left = 0;
        int right = 0;
        if (nodeLeft != null) {
            left = nodeLeft.calcSize();
        }
        if (nodeRight != null) {
            right = nodeRight.calcSize();
        }
        this.size = left + right + 1;
        return this.size;
    }

    public int smallerCnt(int k) {
        if (k > this.key) {
            int rightSmallerCnt = nodeRight != null ? nodeRight.smallerCnt(k) : 0;
            int leftSmallerCnt = nodeLeft != null ? nodeLeft.size : 0;
            return leftSmallerCnt + rightSmallerCnt + 1;
        }
        if (k < this.key) {
            int leftSmallerCnt = nodeLeft != null ? nodeLeft.smallerCnt(k) : 0;
            return leftSmallerCnt;
        }
        return 0;
    }

    public int higherCnt(int k) {
        if (k < this.key) {
            int leftHigherCnt = nodeLeft != null ? nodeLeft.higherCnt(k) : 0;
            int rightHigherCnt = nodeRight != null ? nodeRight.size : 0;
            return leftHigherCnt + rightHigherCnt + 1;
        }
        if (k > this.key) {
            int rightHigherCnt = nodeRight != null ? nodeRight.higherCnt(k) : 0;
            return rightHigherCnt;
        }

        return 0;
    }
    /*
    private static String nodeToString(Node node, boolean outside) {
        String str = "";
        int leaves = 0;
        // The count of how much Digits we assume the keys have
        int maxDigitNum = 4;
        int keyPos = ((leaves * maxDigitNum + leaves) / 2 ) - (maxDigitNum / 2);
        if (node == null) {
            return "";

        }
        leaves = (int) Math.pow(2, node.getHeight());
        for (int i = 0; i < keyPos; i++) {
            str += " ";
        }
        str += node.key;
        if (outside) {
            str += "\n";
        }
        str += nodeToString(node.nodeLeft, false);
        str += nodeToString(node.nodeRight, outside);
        return str;

    }

    @Override
    public String toString() {
        return nodeToString(this, true);
    }
    */

}