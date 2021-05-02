public class Main {   
     public static void main(String[] args) {
         BST tree = new BST();
         int values[] = {8, 7, 2, 4, 10, 12, 7, 3};
         for (int i = 0; i < values.length; i++) {
            tree.insert(values[i]);
        }
        System.out.println("Tree values: ");
        tree.printTree();
        System.out.println("Tree height: " + tree.height());
        System.out.println("Tree DFS false: " + tree.DFS(20));
        System.out.println("Tree DFS true: " + tree.DFS(10));
        System.out.println("Tree BFS false: " + tree.BFS(20));
        System.out.println("Tree BFS true: " + tree.BFS(10));
     }
}
