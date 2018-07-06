#include "catch.hpp"
#include "../include/Support/SupportStructures.h"
#include <iostream>


using namespace std;

TEST_CASE("Check point < operator") {

    Point a{0,7};
    SECTION("Lesser point a should be smaller than greater point b")
    {
        Point b{1,2};
        REQUIRE(a<b);
    }
    SECTION("Lesser point a should not be greater than greater point b")
    {
        Point b{1,2};
        REQUIRE_FALSE(b<a);
    }
    SECTION("Equal points, should not be greater than one eanother")
    {
        Point b{0,7};
        REQUIRE_FALSE(b<a);
        REQUIRE_FALSE(a<b);
    }


}