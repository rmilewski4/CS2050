#include "lab10.h"

// suggested implementation
typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

struct BST {
	Node *root;
	int size;
};

//This function will initalize a BST by creating space for the tree itself. It will return the created (empty) tree on success or NULL on failure. This function has O(1) time complexity because the BST is empty and
//Is independent of the size of the BST
BST * initBST() {
    //Malloc space for our tree and check for malloc errors, if found, then return NULL
    BST * tree = malloc(sizeof(BST));
    if(tree == NULL) {
        return NULL;
    }
    //Set our inital variables to the default. Since the list is empty, the root is set to NULL and size is set to 0 to indicate an empty BST
    tree->root = NULL;
    tree->size = 0;
    //Finally, we return our created tree.
    return tree;
}
//This is a helper function created to assist insertBST. It will accept two Node pointer parameters, the first being the root node, and the second being the node to be added to the BST.
//It will return the updated BST with the root pointer passed back. This helper function will have expected O(log(N)) time complexity as long as data is passed in randomly and the attributes of a BST
//can be actually used. If the data passed into the BST is already in sorted order, time complexity will degrade to O(N).
Node * insert(Node * root, Node * insertedNode) {
    //Check if the root is NULL and if so, set the node to be inserted on the root
    if(root == NULL) {
        root = insertedNode;
    }
    //If the root isn't NULL, then we must go left or right down the tree. We choose what path to go by comparing both node's data variable
    //If the node to be inserted is smaller, then it will always go to the left of the root, and as such we will enter this if
    if(insertedNode->data < root->data) {
        //We then set our left pointer equal to the result of calling the insert function again on the left of the tree. This recursion simplifies the code
        root->left = insert(root->left, insertedNode);
    }
    //Otherwise, if the root is smaller than the data to be inserted, then the inserted Node will always go to the right
    else if(insertedNode->data > root->data) {
        //We do the same as above, except executed on the right node instead of the left
        root->right = insert(root->right, insertedNode);
    }
    //Finally, after we are done updating the tree, we return the updated root node.
    return root;
}

//The insertBST function takes in a initalized BST pointer and data to be added to the tree. It will return 0 if insertion succeeded or 1 if it failed.
//As stated in the helper function description, this will have expected O(log(N)) time complexity if data is randomly added. If data is already in sorted order,
//Then insertBST will degrade to O(N) time complexity.
int insertBST(BST *tree, int data) {
    //Malloc space for our new node and check for any errors.
    Node * newnode = malloc(sizeof(Node));
    if(newnode == NULL) {
        return 1;
    }
    //Setup the newnode by adding the data to it, and setting its left and right pointers to NULL since it will be a leaf node when added
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    //Update our root node by calling our insert function with the root and the node to be added
    tree->root = insert(tree->root,newnode);
    //Update the size by 1 and return 0 to indicate success.
    tree->size += 1;
    return 0;
}

//This is a helper function for BSTContains that allows for recursion. It accepts a node pointer that is the root, and the data to be searched for. As long as the BST remains balanced
//This function will remain expected O(log(N)) time complexity.
int contains(Node * root, int data) {
    //If the root we hit is NULL, it means that the value isn't in the BST and we can return 1
    if(root == NULL) {
        return 0;
    }
    //If the root contains the data we are searching for, then return 1
    if(root->data == data) {
        return 1;
    }
    //Otherwise if the data is less than the data found in the root, then execute the function on the left root to try and identify the value
    else if(data < root->data) {
        return contains(root->left,data);
    }
    //If neither of the above Ifs are true, then the data must be on the right side of the tree, so we execute the funciton on the right side of the tree.
    return contains(root->right,data);
}
//This function takes in a BST pointer and an int to search for inside the tree. It will return 0 if the element isn't in the tree, or 1 if it does.
//It will have expected O(log(N)) time complexity as long as the tree remains balanced as it is assumed.
//If the tree degrades into a linked list, time complexity becomes O(N).
int BSTContains(BST *tree, int data) {
    //We are just returning our helper function on the root of the tree with our data passed along.
    return(contains(tree->root,data));
}

//This is a helper function to free the nodes inside the BST. It gets passed the root node to be freed. Because we have to free
//Each individual node, this function will always have O(N) time complexity
void freeNode(Node * root) {
    //If the root is NULL, then we are done and we can exit the function
    if(root == NULL) {
        return;
    }
    //Otherwise we need to free the right and left child nodes first before we can free our root node, so we call the function on each side
    freeNode(root->left);
    freeNode(root->right);
    //Finally, we free our root node and set it equal to NULL to indicate that it was freed
    free(root);
    root = NULL;
}
//This function will take in a BST pointer and free the memory stored in it. It will always have O(n) time complexity due to the fact that each element needs to be individually freed
void freeTree(BST *tree) {
    //We free our nodes by calling our helper function on the root
    freeNode(tree->root);
    //Then we can just free the space allocated for our BST pointer that was passed in and set it equal to NULL
    free(tree);
    tree = NULL;
}
//This is a helper function to print the indivdual nodes in the BST, it takes in the root node pointer and will print all of the nodes in order
//This function will have O(n) time complexity because each node will need to be printed and this is depending on the size of the BST
void printNodes(Node * root) {
    //If our root node isn't NULL, then we can execute these instructions.
    if(root != NULL) {
        //Because we are printing in order, We first need to print all the nodes to the left of the root, print the root itself, and then print the nodes to the right.
        printNodes(root->left);
        printf("%d\n",root->data);
        printNodes(root->right);
    }
}
//The printInOrder function will take in a BST pointer and print the indivdual nodes of the BST in order
//This function will have O(N) time complexity because it will need to print every node of the tree which is dependent on the size of the tree
void printInOrder(BST *tree) {
    //We call our helper function to print the Nodes by passing it the root node
    printNodes(tree->root);
}
//This is a helper function to assist with the getMin function. It takes in the root node pointer and will return the smallest data found in the BST. It has 
//expected O(log(N)) time complexity as long as the tree remains balanced. If the tree is sorted in desceding order like a linked list, time complexity may degrade to O(N).
int findMinWithRoot(Node * root) {
    //If the node to the left of the root node doesn't exist, then the root is the minimum node, so we return the data stored in root.
    if(root->left == NULL) {
        return root->data;
    }
    //Otherwise, the node will be further down the left side of the tree so we call our function on the left side of the tree.
    return findMinWithRoot(root->left);
}
//This function takes in a BST pointer and will return the minimum element found. Its time complexity will be expected O(log(N)) as long as the tree remains balanced.
int getMin(BST *tree) {
    //We get the minimum by calling our helper function on the root and returning what is found
    return findMinWithRoot(tree->root);
}