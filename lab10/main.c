#include "lab10.h"


int main(void) {
    //Initalize our tree
    BST * tree = initBST();
    //Insert arbitrary numbers into the BST for testing
    insertBST(tree, 20);
    insertBST(tree, 10);
    //Testing search functionality
    if(BSTContains(tree, 10) == 1) {
        printf("found 10!\n");
    }
    if(BSTContains(tree, 25)==0){
        printf("Data doesn't exist\n");
    }
    insertBST(tree, 30);
    //Create variable to track the time it takes to do search and print
    time_t binarytime = clock();
    //run print in order
    printInOrder(tree);
    //Get the ending time by calling clock and subtracting from the beginning time and print the amount of seconds by dividing by the clock speed.
    binarytime = clock() - binarytime;
    printf("It took %f seconds to run print in order \n",(float)binarytime/CLOCKS_PER_SEC);
    //reset the clock by calling it again to be ran for the bst search
    binarytime = clock();
    //Run the BST Search with a number we added
    BSTContains(tree,30);
    //Find the time it took and print the result
    binarytime = clock() - binarytime;
    printf("It took %f seconds to run BST Search \n",(float)binarytime/CLOCKS_PER_SEC);
    //Testing minimum
    int min = getMin(tree);
    printf("The min is %d\n",min);
    //Free tree when done
    freeTree(tree);
}