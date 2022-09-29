#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "partb.h"

TEST_CASE("Array {1} Average") {
    int array[] = {1};
    float actual = array_avg(array, 1);
    REQUIRE(actual == Approx(1.0));
}

TEST_CASE("Array {1, 3} Average") {
    int array[] = {1, 3};
    float actual = array_avg(array, 2);
    REQUIRE(actual == Approx(2.0));
}
TEST_CASE("Array {1, 3, 5, 7, 9} Average") {
    int array[] = {1, 3, 5, 7, 9};
    float actual = array_avg(array, 5);
    REQUIRE(actual == Approx(5.0));
}
TEST_CASE("Array {1, 2} Average") {
    int array[] = {1, 2};
    float actual = array_avg(array, 2);
    REQUIRE(actual == Approx(1.5));
}
TEST_CASE("Empty array average") {
    int array[] = {};
    float actual = array_avg(array, 0);
    REQUIRE(actual == 0.0);
}
TEST_CASE("Null array average") {
    float actual = array_avg(NULL, 1); // NOTE: You should always reject a NULL
                                       //   even if other arguments are incorrect
    REQUIRE(actual == 0.0);
}

TEST_CASE("Array fill 11 through 12") {
#define ARRAY1_LEN (2)
    int array[ARRAY1_LEN];
    array_fill(array, ARRAY1_LEN, 11, 12);

    REQUIRE(array[0] == 11);
    REQUIRE(array[1] == 12);
}
TEST_CASE("Array fill 11 through 14") {
#define ARRAY2_LEN (4)
    int array[ARRAY2_LEN];
    array_fill(array, ARRAY2_LEN, 11, 14);

    REQUIRE(array[0] == 11);
    REQUIRE(array[1] == 12);
    REQUIRE(array[2] == 13);
    REQUIRE(array[3] == 14);
}
TEST_CASE("Array fill too short") {
#define ARRAY3_LEN (2)
    int array[ARRAY3_LEN];
    array_fill(array, ARRAY3_LEN, 11, 14);

    REQUIRE(array[0] == 11);
    REQUIRE(array[1] == 12);
}
TEST_CASE("Array fill null") {
    array_fill(NULL, 0, 11, 14);
    // Above should not crash
}
