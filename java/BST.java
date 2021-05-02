import java.lang.Math;
import java.util.Queue;

import javax.lang.model.util.ElementScanner6;

public class BST {
    // NODE CLASS
    class Node {
        int data;
        Node left, right;
        public Node(int value) {
            data = value;
            left = right = null;
        }
    }

    // VARIABLES

    private Node root;

    // PUBLIC METHODS

    // constructor 
    BST() { root = null; }
    // modifiers
    public void insert(int value) { root = insert(value, root); }
    // observers
    public int height() { return height(root); }
    public void printTree() { printTree(root); }
    public boolean BFS(int value) {
        Queue<Node> q;
        q.add(root);

        while (q.size > 0) {
           Node n_front = q.remove();

           if (n_front.data == value)
                return true;
            
            if (n_front.left != null)
                q.add(n_front.left);
            if (n_front.right != null)
                q.add(n_front.right);
        }
        return false;
    }
    public boolean DFS(int value) { return DFS(value, root); }

    // PRIVATE METHODS

    // modifiers

    private Node insert(int value, Node n) {
        if (n == null) {
            n = new Node(value);
            return n;
        }
        else if (value < n.data) {
            n.left = insert(value, n.left);
            n = balance(value, n);
        }
        else if (value > n.data) {
            n.right = insert(value, n.right);
            n = balance(value, n);
        }
        return n;
    }

    private Node balance(int value, Node n) {
        int l_height = height(n.left);
        int r_height = height(n.right);
        int balance_factor = l_height - r_height;

        if ((balance_factor > 1) && (value < n.left.data)) {
            return rightRotate(n);
        }
        else if ((balance_factor > 1) && (value > n.left.data)) {
            n.left = leftRotate(n.left);
            return rightRotate(n);
        }
        else if ((balance_factor < -1) && (value < n.right.data)) {
            n.right = rightRotate(n.right);
            return leftRotate(n);
        }
        else if ((balance_factor < -1) && (value > n.right.data)) {
            return leftRotate(n);
        }
        else
            return n;
    }

    private Node leftRotate(Node n) {
        Node swap = n.right;
        n.right = swap.left;
        swap.left = n;
        return swap;
    }

    private Node rightRotate(Node n) {
        Node swap = n.left;
        n.left = swap.right;
        swap.right = n;
        return swap;
    }

    // observers

    private int height(Node n) {
        if (n == null)
            return 0;
        else
            return 1 + Math.max(height(n.left), height(n.right));            
    }

    private void printTree(Node n) {
        if (n != null) {
            printTree(n.left);
            System.out.print(n.data + " ");
            printTree(n.right);
        }
    }

    private boolean DFS(int value, Node n) {
        if (n == null)
            return false;
        
        if (n.data == value)
            return true;

        boolean recursive_left = DFS(value, n.left);
        if (recursive_left == true)
            return true;
        
        boolean recursive_right = DFS(value, n.right);
        return resursive_right;
    } 
}
