#include <stddef.h>
#include "partb.h"

/**
 * Computes the average of all the elements in the array
 * 
 * @param array the array of elements
 * @param array_len the length of the array
 * 
 * @return the average of the array elements
 */
float array_avg(int* array, int array_len) {
    if (array_len == 0) {
        return 0.0;
    } else if(array == NULL) {
        return 0.0;
    } else {
        double sum = 0;
        for(int i = 0; i < array_len; i++) {
            sum = sum + array[i];
        }

        return sum / array_len;
    }
}

/**
 * Fills an array with consecutive numbers from begin to end
 * 
 * @param array the array to fill
 * @param array_len the length of the array
 * @param begin the first number to fill the array
 * @param end the last number to fill the array
 */
void array_fill(int* array, int array_len, int begin, int end) {
    if((end-begin) + 1 > array_len) {
        for(int i = 0; i < array_len; i++) {
            array[i] = begin + i;
        }
    } else {
        for(int i = begin; i <= end; i++) {
            array[i - begin] = i;
        }
    }
}
