#ifndef dsa_library_h
#define dsa_library_h
using namespace std;
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>


namespace DSA{

    class Linkedlist{
        private:
        struct Node{
            int data;
            Node *next;
            Node(int val):data(val),next(nullptr){};
        };
        Node *head=nullptr;
        void insert(int val);
        public:
        Linkedlist();
        ~Linkedlist();
        void insert(vector<int>&x);
        void deletion(int val);
        void reverse();
        void display();
    };



    class Tree {
    protected:
   
    struct node {
        int data, height = 0;
        bool color;
        node* left;
        node* right,*parent;
       
        node(int val) : data(val),color(true), height(1), left(nullptr), right(nullptr),parent(nullptr){}
    };

    node* root = nullptr;

    public:
    Tree() : root(nullptr) {}

    node* getroot() {
        return root;
        }
    };

    class Traversal:public virtual Tree{
        private:
        void inorder(node *root);
        void postorder(node *root);
        void preorder(node *root);
        public:
        void inorder();
        void postorder();
        void preorder();
    };


    class BinaryTree:public Traversal,public virtual Tree{
        Tree::node *insert(Tree::node *&root);
        bool search(Tree::node *root,int val);
        Tree::node *deletion(Tree::node *root,int key);
        void deleteLastNode(Tree::node *root);
        public:
        void insert();
        bool search(int val);
        void deletion(int key);

        
    };
    class BST:public virtual Traversal,public virtual Tree{
        protected:
        void insert(Tree::node *newNode);
        bool search(Tree::node *root,int val);
        Tree::node *deletion(Tree::node *root,int key);
        Tree::node *findmin(Tree::node *root);
        public:
        void insert(vector<int>x);
        void deletion(int key);
        bool search(int val);
    };
    class AVL:public virtual Traversal,public virtual Tree,public BST{
        protected:
        int getheight(Tree::node *node);
        int getbalance(Tree::node *node);
        Tree::node *deleteNode(Tree::node *node,int val);
        Tree::node *insert(Tree::node *newNode,int val);
        Tree::node *rightrotate(Tree::node *node);
        Tree::node *leftrotate(Tree::node *node);
        int updateHeight(Tree::node* node);
        public:
        void insert(vector<int>x);
        void deletion(int val);
    };
    class RBT: public virtual Traversal,public virtual Tree,public virtual AVL{
        node* rotateLeft(node* x); 
        node* rotateRight(node* x); 
        void fixInsertion(node* z); 
        node* bstInsert(node* root, node* newNode); 
        node* minValueNode(node* n); 
        node* deleteNode(node* root, int val); 
        void replaceNode(node* u, node* v); 
        void fixDeletion(node* x); 

        
        void inorderTraversal(node* root);
        public:
        void insert(int val); 
        void insert(std::vector<int> x);
        void deleteValue(int val); 
        void displayTree();

    };

    class Graph {
    private:
    int V;
    std::vector<std::vector<int>> adjList;
    public:
    Graph(int vertices);
    void addEdge(int u, int v);

    void BFS(int start);

    void DFS(int start);

    void displayGraph();
    };

    class Sorting{
        public:
        static void bubblesort(vector<int> &arr);
        static void insertionsort(vector<int> &x);
        static void mergesort(vector<int> &x);
        static void quicksort(vector<int> &arr);
        static void heapsort(vector<int> &x);
        private:
        static void merge(vector<int>& arr,int left,int mid,int right);
        static int partition(vector<int> &arr,int lb,int ub);
        static void heapify(vector<int> &x,int n, int i);
        static void mergesort(vector<int>&arr,int left,int right);
        static void quicksort(vector<int> &arr,int lb,int ub);
        static void heapsort(vector<int> &x,int n);

    };
}
#endif