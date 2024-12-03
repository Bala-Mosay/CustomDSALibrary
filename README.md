
# Custom DSA Library

## Overview
The **Custom DSA Library** is a lightweight C++ library implementing core data structures:**Sorting Algorithms**, **Trees**, **Linked Lists**, and **Graphs**. This library is designed to simplify the learning and application of fundamental data structures in real-world and academic projects.

## Features
- **Sorting**
   -Quick Sorting
   -Merge Sorting
   -Heap Sorting
   -Bubble Sorting
   -Insertion Sorting
- **Trees:**
  - Binary Tree
  - Binary Search Tree
  - AVL Tree
  - RED BLACK Trees
- **Linked Lists:**
  - Singly Linked List
  - Doubly Linked List
  - Circular Linked List
- **Graphs:**
  - Representation: Adjacency List and Adjacency Matrix
  - Traversals: Depth First Search (DFS), Breadth First Search (BFS)
  - Algorithms: Shortest Path (Dijkstra's Algorithm)


## Folder Structure
```plaintext
CustomDSALibrary/
├── include         # Header files (declarations)
│    └── dsa_library.h  
|
├── src             # Source files (implementations)
│    └──dsa_library.cpp
├── main.cpp        # Example usage and test cases
└── README.md       # Project documentation

```

## Usage Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/Bala-Mosay/CustomDSALibrary.git
   ```
2. Navigate to the project directory:
   ```bash
   cd CustomDSALibrary
   ```
3. Compile the library along with the `main.cpp` file:
   ```bash
   g++ src/*.cpp main.cpp -o dsa_library
   ```
4. Run the executable:
   ```bash
   ./dsa_library
   ```

## Example Usage
Below is an example of how to use the library in `main.cpp`:

```cpp
#include "dsa_library.h"


int main() {
    // Example: Using Linked List
    LinkedList<int> list;
    list.insert(10);
    list.insert(20);
    list.display();

    // Example: Using Trees
    BinarySearchTree<int> bst;
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.inOrderTraversal();

    // Example: Using Graph
    Graph<int> graph(5); // Create a graph with 5 vertices
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.BFS(0);

    return 0;
}
```

## Contributing
Contributions are welcome! If you have suggestions or improvements, feel free to create a pull request or open an issue.


## Author
**Bala Mosay J**  
- GitHub:https://github.com/Bala-Mosay
- LinkedIn:www.linkedin.com/in/bala-mosay-j

---

*Happy Coding!* 🎉
