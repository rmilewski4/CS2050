#include "prelab1.h"


int main(void) {
    float temp;
    int arrsize = 0;
    FILE * fp;
    fp = fopen("floats.txt","r");
    if(NULL != fp) {
        while(fp && !feof(fp)) {
            fscanf(fp,"%f", &temp);
            arrsize++;
        }
        rewind(fp);
    }
    float * arr = (float *) malloc(sizeof(float) * arrsize); 
    if(arr == NULL) {
        printf("Array not sucessfully malloc'd!\n");
    }
    arrsize = 0;
    char tempchar[255];
    if(NULL != fp) {
        while(fp && !feof(fp)) {
            //fscanf(fp,"%f", &temp);
            fgets(tempchar,255,fp);
            temp = strtof(tempchar, NULL);
            arr[arrsize] = temp;
            printf("arr[%d] = %f\n",arrsize,arr[arrsize]);
            arrsize++;
        }
        fclose(fp);
    }
    float LEQ;
    if((findLEQ(arr,arrsize,150,&LEQ)) == 1) {
        printf("The result of the LEQ is %.1f\n",LEQ);
    }
    else {
        printf("All members of the array are greater than the selected value\n");
    }
    free(arr);
}