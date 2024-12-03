#include "dsa_library.h"
#include <iostream>

namespace DSA{
    Linkedlist::Linkedlist():head(nullptr){}

    Linkedlist::~Linkedlist(){
        while(head){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void DSA::Linkedlist ::insert(int val){
        Node *new_Node = new Node(val);
        if(!head){
            head = new_Node;
        }
        else{
            Node *temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_Node;
        }
    }
    void Linkedlist::insert(vector<int> &x){
        for(int i : x){
        Linkedlist::insert(i);
        }
    }
    void Linkedlist::deletion(int val) {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }


        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;

        while (current && current->data != val) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << "Value " << val << " not found in the list.\n";
            return;
        }
        prev->next = current->next;
        delete current;
    }
    void Linkedlist::reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next; 
            current->next = prev; 
            prev = current;      
            current = next;      
        }
        head = prev; 
    }
    void Linkedlist::display(){
        Node *temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }

    void Sorting::bubblesort(vector<int>&arr){
        int n = arr.size();
        for(int i = 0;i<n-1;++i){
            for(int j = 0;j<n-1-i;++j){
                if (arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    void Sorting::mergesort(vector<int> &arr,int left,int right){
        if(left <right){
            int mid = left +(right-left)/2;

            mergesort(arr,left,mid);
            mergesort(arr,mid+1,right);

            merge(arr,left,mid,right);

        }
    }

    void Sorting::merge(vector<int>&arr,int left,int mid,int right){
        int n1 = mid -left +1;
        int n2 = right - mid;
        vector<int> leftarr(n1),rightarr(n2);
        for(int i =0;i<n1;++i){
            leftarr[i] = arr[left+i];
        }
        for(int j = 0; j<n2;++j){
            rightarr[j] = arr[mid+j+1];
        }
        int i = 0, j = 0, k = left;
        while(i<n1 && j<n2){
            if(leftarr[i] <= rightarr[j]){
                arr[k++] = leftarr[i++];
            }
            else{
                arr[k++] = rightarr[j++];
            }
        }
        while(i<n1){
            arr[k++] = leftarr[i++];
        }
        while(j<n2){
            arr[k++] = rightarr[j++];
        }
    }
    void Sorting::quicksort(vector<int>& arr, int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);  
        quicksort(arr, lb, loc - 1);  
        quicksort(arr, loc + 1, ub);  
    }
}

int Sorting::partition(vector<int>& arr, int lb, int ub) {
    int pivot = arr[lb]; 
    int start = lb;
    int end = ub;

    while (start < end) {
       
        while (arr[start] <= pivot) {
            start++;
        }

       
        while (arr[end] > pivot) {
            end--;
        }

        
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }

    
    swap(arr[lb], arr[end]);

    return end; 
}

    void DSA::Sorting::heapsort(vector<int>& x, int n) {
    // Build the max-heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(x, n, i);
    }

    
    for (int i = n - 1; i > 0; --i) {  \
        swap(x[0], x[i]);
        
        heapify(x, i, 0);
    }
}

void DSA::Sorting::heapify(vector<int>& x, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    
    if (left < n && x[left] > x[largest]) {
        largest = left;
    }

    
    if (right < n && x[right] > x[largest]) {
        largest = right;
    }

    
    if (largest != i) {
        swap(x[i], x[largest]);
        heapify(x, n, largest);  
    }
}

    void DSA::Sorting::insertionsort(vector<int>& x) {
        int n = x.size();
        for (int i = 1; i < n; ++i) {
            int key = x[i];
            int j = i - 1;
            while (j >= 0 && x[j] > key) {
                x[j + 1] = x[j];
                --j;
            }
            x[j + 1] = key; 
        }
    }
    void DSA::Sorting::mergesort(vector<int> &x){
        int n = x.size();
        mergesort(x,0,n-1);
    }
    void DSA::Sorting::quicksort(vector<int> &x){
        int n = x.size()-1;
        quicksort(x,0,n);
    }
    void DSA::Sorting::heapsort(vector<int> &x){
        int n = x.size();
        heapsort(x,n);
    }
    BinaryTree::node* BinaryTree::insert(Tree::node *&root) {
     int x;
        cout << "Enter the data (or press -1 to stop): ";
        cin >> x;

        if (x == -1) {
            return nullptr;  
        }

        Tree::node* newNode = new node(x);

        cout << "Enter the data for " << x << " Left child: ";
        newNode->left = insert(newNode->left);  

        cout << "Enter the data for " << x << " Right child: ";
        newNode->right = insert(newNode->right); 

        return newNode;
}
    void DSA::BinaryTree::insert(){
        if (root == nullptr) {
            cout << "Inserting the root node." << endl;
            root = insert(root); 
        }
    }
    bool DSA::BinaryTree::search(Tree::node *root,int val){
        if(root==nullptr){
            return false;
        }
        if(root->data==val){
            return true;
        }
        return search(root->left,val) || search(root->right,val);
    }
    bool DSA::BinaryTree::search(int val){
        return search(root,val);
    }
    BinaryTree::node* BinaryTree::deletion(Tree::node *root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Perform level-order traversal to find the node to delete
    queue<node*> q;
    q.push(root);
    node* temp = nullptr;  // Define temp as a node pointer
    node* toDelete = nullptr;

    // Keep track of the last node
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        // If we find the node to be deleted, mark it
        if (temp->data == key) {
            toDelete = temp;
        }

        // Add left and right children to the queue
        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }

    // If node to be deleted is found
    if (toDelete != nullptr) {
        // Replace the node's data with the last node's data
        int lastNodeData = temp->data;
        deleteLastNode(root);  // This method needs to be defined
        toDelete->data = lastNodeData;  // Replace the data in the node
    }

    return root;
}

// Define the deleteLastNode method
    void DSA::BinaryTree::deleteLastNode(node* root) {
        if (root == nullptr) return;

    queue<node*> q;
    q.push(root);
    node* temp = nullptr;

    // Traverse the tree level by level and find the last node
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->left) {
            if (temp->left->left == nullptr && temp->left->right == nullptr) {
                delete temp->left;
                temp->left = nullptr;
                return;
            } else {
                q.push(temp->left);
            }
        }

        if (temp->right) {
            if (temp->right->left == nullptr && temp->right->right == nullptr) {
                delete temp->right;
                temp->right = nullptr;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}
    void DSA::BinaryTree::deletion(int key){
        deletion(getroot(),key);
    }
    void DSA::BST::insert(Tree ::node *newNode){
        if(getroot()==nullptr){
            root = newNode;
        }
        else{
            Tree::node * temp = getroot();
            while(temp!=nullptr){
                if(newNode->data ==temp->data){
                    cout << "No Duplicate Values:";
                }
                else if(newNode->data < temp->data && temp->left == nullptr){
                    temp->left = newNode;
                    break;
                }
                else if(newNode->data < temp->data){
                    temp = temp->left;
                }
                else if(newNode->data > temp->data && temp->right == nullptr){
                    temp->right = newNode;
                    break;
                }
                else if(newNode->data > temp->data){
                    temp = temp->right;
                }

            }
        }
    }
    void DSA::BST::insert(vector<int>x){
        for(int i : x){
            node *newnode = new node(i);
            insert(newnode); 
        }
    }

    bool DSA::BST::search(Tree::node *root,int val){
        if(root==nullptr){
            return false;
        }
        else if(root->data==val){
            return true;
        }
        else if(val<root->data){
            return search(root->left,val);
        }
        else{
            return search(root->right,val);
        }
    }
    bool DSA::BST::search(int val){
        return search(getroot(),val);
    }
    
    BST::node * BST::deletion(Tree::node *root,int key){
        if (!root) return root; // If the tree is empty

        if (key < root->data) {
            root->left = deletion(root->left, key);
        } else if (key > root->data) {
            root->right = deletion(root->right, key);
        } else {
            // Node with only one child or no child
            if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            node* temp = findmin(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deletion(root->right, temp->data);
        }
        return root;
    
    }
    BST::node* BST::findmin(node *root){
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }
    AVL::node* AVL::insert(node *node,int val){
        if(node==nullptr){
            return new struct node(val);
        }
        if(val < node->data){
            node->left=insert(node->left,val);
        }
        else if(val > node->data){
            node->right=insert(node->right,val);
        }
        else{
            cout << "No Duplicate values";
            return node;
        }
        node->height=updateHeight(node);
        int bal = getbalance(node);
        if (bal > 1 && val < node->left->data)
            return rightrotate(node);

        // Right-Right case
        if (bal < -1 && val > node->right->data)
            return leftrotate(node);

        // Left-Right case
        if (bal > 1 && val > node->left->data) {
            node->left = leftrotate(node->left);
            return rightrotate(node);
        }

        // Right-Left case
        if (bal < -1 && val < node->right->data) {
            node->right = rightrotate(node->right);
            return leftrotate(node);
        }
        return node;

    }
    AVL::node *AVL::deleteNode(node *node,int val){
        if (node == nullptr)
            return node;

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Tree::node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Tree::node* temp =findmin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        node->height = updateHeight(node);

        int bal = getbalance(node);

        if (bal > 1 && getbalance(node->left) >= 0)
            return rightrotate(node);
 
        if (bal > 1 && getbalance(node->left) < 0) {
            node->left = leftrotate(node->left);
            return rightrotate(node);
        }

        if (bal < -1 && getbalance(node->right) <= 0)
            return leftrotate(node);

        if (bal < -1 && getbalance(node->right) > 0) {
            node->right = rightrotate(node->right);
            return leftrotate(node);
        }

        return node;
    }
    
    int::DSA::AVL:: getheight(node *node){
        return node==nullptr? 0 : node->height;
    }
    int DSA::AVL::getbalance(node *node){
        return node==nullptr?0:getheight(node->left) - getheight(node->right);
    }
    void DSA::AVL::deletion(int val){
        root = deleteNode(root,val);
    }
    Tree::node *AVL::rightrotate(node *z){
         node *y = z->left;
         node *t2 = y->right;

         y->right = z;
         z->left = t2;
         z->height=updateHeight(z);
         y->height = updateHeight(y);
         return y;
         
    }
    Tree::node* AVL::leftrotate(node *z){
        node *y = z->right;
        node *t2 = y->left;

        y->left = z;
        z->right = t2;
        z->height=updateHeight(z);
        y->height = updateHeight(y);
        return y;
    }
    int DSA::AVL::updateHeight(node* node) {
        return max(getheight(node->left), getheight(node->right)) + 1;
    }
    void DSA::AVL::insert(vector<int>x){
        for(int i : x){
            root = insert(getroot(),i);
        } 
    }
    void DSA::Traversal::inorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            inorder(root->left);
            cout << root->data<<" ";
            inorder(root->right);
        }
    }
    void DSA::BST::deletion(int key){
        deletion(getroot(),key);
    }
    void DSA::Traversal::postorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            preorder(root->left);
            preorder(root->right);
            cout << root->data<<" ";
        }
    }
    void DSA::Traversal::preorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            cout << root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void DSA::Traversal::inorder(){
        cout<<"\nInorder:";
        inorder(root);
        cout<<endl;
    }
    void DSA::Traversal::postorder(){
        cout<<"\nPostorder:";
        postorder(root);
        cout<<endl;
    }
    void DSA::Traversal::preorder(){
        cout << "\nPreorder:";
        preorder(root);
        cout<<endl;
    }
    

    RBT::node* RBT::rotateLeft(node* x) {
        node* y = x->right; // y is the right child of x
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y; // y becomes the root
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
        return y;
    }

    RBT::node* RBT::rotateRight(node* x) {
        node* y = x->left; // y is the left child of x
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y; // y becomes the root
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
        return y;
    }

    void RBT::fixInsertion(node* z) {
        while (z->parent != nullptr && z->parent->color == true) {
            if (z->parent == z->parent->parent->left) {
                node* y = z->parent->parent->right;
                if (y != nullptr && y->color == true) {
                    z->parent->color = false;
                    y->color = false;
                    z->parent->parent->color = true;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = false;
                    z->parent->parent->color = true;
                    rotateRight(z->parent->parent);
                }
            } else {
                node* y = z->parent->parent->left;
                if (y != nullptr && y->color == true) {
                    z->parent->color = false;
                    y->color = false;
                    z->parent->parent->color = true;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = false;
                    z->parent->parent->color = true;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color = false;
    }

    RBT::node* RBT::bstInsert(node* root, node* newNode) {
        if (root == nullptr)
            return newNode;

        if (newNode->data < root->data) {
            root->left = bstInsert(root->left, newNode);
            root->left->parent = root;
        } else {
            root->right = bstInsert(root->right, newNode);
            root->right->parent = root;
        }
        return root;
    }

    void RBT::inorderTraversal(node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << (root->color ? "R " : "B ");
            inorderTraversal(root->right);
        }
    }

    void RBT::insert(int val) {
        node* newNode = new node(val);
        root = bstInsert(root, newNode);
        fixInsertion(newNode);
    }

    void RBT::insert(vector<int> x) {
        for (int i : x) {
            insert(i);
        }
    }

    RBT::node* RBT::minValueNode(node* n) {
        while (n->left != nullptr) {
            n = n->left;
        }
        return n;
    }

    void RBT::deleteValue(int val) {
        root = deleteNode(root, val);
    }

    RBT::node* RBT::deleteNode(node* root, int val) {
        if (root == nullptr) return root;

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    void RBT::replaceNode(node* u, node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        if (v != nullptr)
            v->parent = u->parent;
    }

    void RBT::fixDeletion(node* x) {
        while (x != root && (x == nullptr || x->color == false)) {
            if (x == x->parent->left) {
                node* sibling = x->parent->right;
                if (sibling->color == true) {
                    sibling->color = false;
                    x->parent->color = true;
                    rotateLeft(x->parent);
                    sibling = x->parent->right;
                }
                if ((sibling->left == nullptr || sibling->left->color == false) &&
                    (sibling->right == nullptr || sibling->right->color == false)) {
                    sibling->color = true;
                    x = x->parent;
                } else {
                    if (sibling->right == nullptr || sibling->right->color == false) {
                        if (sibling->left != nullptr) sibling->left->color = false;
                        sibling->color = true;
                        rotateRight(sibling);
                        sibling = x->parent->right;
                    }
                    sibling->color = x->parent->color;
                    x->parent->color = false;
                    if (sibling->right != nullptr) sibling->right->color = false;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                node* sibling = x->parent->left;
                if (sibling->color == true) {
                    sibling->color = false;
                    x->parent->color = true;
                    rotateRight(x->parent);
                    sibling = x->parent->left;
                }
                if ((sibling->left == nullptr || sibling->left->color == false) &&
                    (sibling->right == nullptr || sibling->right->color == false)) {
                    sibling->color = true;
                    x = x->parent;
                } else {
                    if (sibling->left == nullptr || sibling->left->color == false) {
                        if (sibling->right != nullptr) sibling->right->color = false;
                        sibling->color = true;
                        rotateLeft(sibling);
                        sibling = x->parent->left;
                    }
                    sibling->color = x->parent->color;
                    x->parent->color = false;
                    if (sibling->left != nullptr) sibling->left->color = false;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        if (x != nullptr) x->color = false;
    }

    void RBT::displayTree() {
        inorderTraversal(root);
        cout << endl;
    }

    Graph::Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void Graph::addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void Graph::displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    
    void Graph::BFS(int start) {
        queue<int> q;
        unordered_set<int> visited;

        
        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            
            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }


    void Graph::DFS(int start) {
        stack<int> s;
        unordered_set<int> visited;

        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                cout << node << " ";

                for (int neighbor : adjList[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout <<endl;
    }

}