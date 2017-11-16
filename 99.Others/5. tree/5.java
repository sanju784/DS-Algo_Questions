/**
 * Check if leaf of binary tree are in same order
 */

import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    public Node(int x)
    {
        data = x;
        left = right = null;
    }

    public boolean isLeaf()
    {
        return (left == null && right == null);
    }
}

class leafOrderTraversal
{
    public static void inorder(Node root)
    {
        if(root != null){
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
        }
    }

    public static boolean isSame(Node root1, Node root2)
    {
        Queue<Node> q1 = new LinkedList<>();
        ArrayList<Node> a1 = new ArrayList<>();
        q1.add(root1);
        while(!q1.isEmpty())
        {
            Node tempNode = q1.poll();
            if(tempNode.left != null) {
                q1.add(tempNode.left);
            }

            if(tempNode.right != null) {
                q1.add(tempNode.right);
            }
            if(tempNode.isLeaf())
            {
                a1.add(tempNode);
            }
        }

        Queue<Node> q2 = new LinkedList<>();
        ArrayList<Node> a2 = new ArrayList<>();
        q2.add(root2);
        while(!q2.isEmpty())
        {
            Node tempNode = q2.poll();
            if(tempNode.left != null) {
                q2.add(tempNode.left);
            }

            if(tempNode.right != null) {
                q2.add(tempNode.right);
            }
            if(tempNode.isLeaf())
            {
                a2.add(tempNode);
            }
        }
        if (a1.size() != a2.size())
        {
            return false;
        }
        for(int i=0;i<a1.size();i++) {
            if(a1.get(i).data != a2.get(i).data)
            {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[])
    {
        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(3);
        root1.left.left = new Node(4);
        root1.right.left = new Node(6);
        root1.right.right = new Node(7);

        Node root2 = new Node(0);
        root2.left = new Node(5);
        root2.right = new Node(8);
        root2.left.right = new Node(4);
        root2.right.left = new Node(6);
        root2.right.right = new Node(7);

        inorder(root1);
        System.out.println();
        inorder(root2);
        System.out.println();
        if(isSame(root1, root2))
        {
            System.out.println("The leaf of 2 trees are same");
        } else {
            System.out.println("The leaf of 2 trees are not same");
        }
    }
}
