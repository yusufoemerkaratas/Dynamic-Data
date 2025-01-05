#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;               // Data of the node
    struct Node** children; // Dynamic array to store child nodes
    int childCount;         // Number of children
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->children = NULL; // No children yet
    newNode->childCount = 0;  // Child count is 0
    return newNode;
}

void addChild(Node *parent, int data) {
    // Create a new child node
    Node* child = createNode(data);

    // Increase the size of the children array
    parent->childCount++;
    parent->children = realloc(parent->children, parent->childCount * sizeof(Node*));

    // Add the new child to the array
    parent->children[parent->childCount - 1] = child;
}

void addElement(Node* root, int parentData, int childData) {
    if (root == NULL) return;

    // If the current node matches the parentData, add the child
    if (root->data == parentData) {
        addChild(root, childData);
        return;
    }

    // Recur for all the children of this node
    for (int i = 0; i < root->childCount; i++) {
        addElement(root->children[i], parentData, childData);
    }
}
void printTree(Node* root, int level) {
    if (root == NULL) return;

    // Print the current node with indentation for levels
    for (int i = 0; i < level; i++) {
        printf("\t"); // Indentation
    }
    printf("%d\n", root->data);

    // Recur for each child
    for (int i = 0; i < root->childCount; i++) {
        printTree(root->children[i], level + 1);
    }
}
int main() {
    // Create the root node
    Node* root = createNode(1);

    // Add children to root
    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 9);

    addElement(root, 9, 8); // Add 6 to the node with data 3

    // Add children to one of the root's children
    addElement(root, 2, 4); // Add 4 to the node with data 2
    addElement(root, 2, 5); // Add 5 to the node with data 2
    addElement(root, 3, 6); // Add 6 to the node with data 3

    // Print the tree (pre-order traversal)
    printTree(root, 0);

    return 0;
}