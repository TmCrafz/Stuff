
public class BinaryTree {

    public static void main(String[] args) {
        int[] keys = new int[args.length];
        for (int i = 0; i < args.length; i++) {
            keys[i] = Integer.parseInt(args[i]);
        }
        Node binaryTree = new Node(keys[0]);
        for (int i = 1; i != keys.length; i++) {
            binaryTree.insert(keys[i]);
        }
        System.out.println("Height: " + binaryTree.getHeight());
        System.out.println("Size: " + binaryTree.calcSize());
        System.out.println("Smaller Cnt: " + binaryTree.smallerCnt(16));
        //System.out.println(binaryTree);
    }

}