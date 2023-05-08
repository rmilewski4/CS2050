#include "lab1.h"

int main() {
	FILE *file = fopen("numbers.txt", "r");

	if(!file) {
		// Unable to open the specified file
		return EXIT_FAILURE;
	}

	int size;

	if(fscanf(file, "%d", &size) != 1) {
		fclose(file);
		// Unable to read the array size from the file
		return EXIT_FAILURE;
	}

	int array[size];

	for(int i = 0; i < size; ++i) {
		fscanf(file, "%d", array + i);
	}

    fclose(file);
	// END STARTER CODE
	float result = 0;
	//After running the function, if an error wasn't found, then print the result
	if(avgEven(array,size,&result) != 0) {
		printf("The average of all evens was %f\n",result);
	}
	//otherwise tell the user that no evens could be found resulting in an error
	else {
		printf("Error: No evens could be found!\n");
	}
    


}
