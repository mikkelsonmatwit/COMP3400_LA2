#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "partc.h"

TEST_CASE("count_upper(A)") {
    int actual = string_count_upper("A");

    REQUIRE(actual == 1);
}

TEST_CASE("count_upper(aA)") {
    int actual = string_count_upper("aA");

    REQUIRE(actual == 1);
}
TEST_CASE("count_upper(AAaB)") {
    int actual = string_count_upper("AAaB");

    REQUIRE(actual == 3);
}
TEST_CASE("count_upper(NULL)") {
    int actual = string_count_upper(NULL);

    REQUIRE(actual == 0);
}

TEST_CASE("concat (, ABC)") {
    const char* src = "ABC";
    char dest[16];
    dest[0] = '\0';
    char *ret = string_concat(dest, src);

    REQUIRE(strcmp(ret, "ABC") == 0);
    REQUIRE(strcmp(src, "ABC") == 0);
    REQUIRE(ret == dest);
}

TEST_CASE("concat (DEF, ABC)") {
    const char* src = "ABC";
    char dest[16];
    dest[0] = 'D';
    dest[1] = 'E';
    dest[2] = 'F';
    dest[3] = '\0';
    char* ret = string_concat(dest, src);

    REQUIRE(strcmp(ret, "DEFABC") == 0);
    REQUIRE(strcmp(src, "ABC") == 0);
    REQUIRE(ret == dest);
}

TEST_CASE("concat (NULL, src)") {
    const char* src = "ABC";
    
    char* ret = string_concat(NULL, src);
    REQUIRE(ret == NULL);
}

TEST_CASE("concat (dest, NULL)") {
    char dest[16];
    dest[0] = 'D';
    dest[1] = 'E';
    dest[2] = 'F';
    dest[3] = '\0';
    
    char* ret = string_concat(dest, NULL);

    REQUIRE(strcmp(ret, "DEF") == 0);
    REQUIRE(ret == dest);
}
