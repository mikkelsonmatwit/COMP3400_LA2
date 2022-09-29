#include <math.h>
#include "parta.h"

/**
 * Returns the predicted price of an item after inflation
 * 
 * @param current_price current price of an item
 * @param num_years the number of years in the future to predict the price for
 * @param rate the predicted inflation rate
 * 
 * @return the price prediction
 * 
 */

int inflation(int current_price, int num_years, float rate) {
    if (current_price < 0) {
        return -1;
    }
    if (num_years < 0) {
        return -1;
    }
    if (rate < 0) {
        return -1;
    }
    rate = rate / 100;
    float new_price = current_price;
    while(num_years > 0) {
        new_price = new_price + (new_price * rate);
        num_years--;
    }
    current_price = (int) round(new_price);
    return current_price;
}
