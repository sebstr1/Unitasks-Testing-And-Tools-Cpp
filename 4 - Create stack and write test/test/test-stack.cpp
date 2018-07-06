#include "catch.hpp"
#include "stack.h"
#include <vector>
#include <algorithm>

SCENARIO("Using an empty stack") {
  GIVEN("an empty stack") {
    Stack<int> stack{};

    THEN("it should be empty.") {
      REQUIRE(stack.empty());
    }

    THEN("it should have 0 size.") {
      REQUIRE(stack.size() == 0);
    }

    THEN("pop() should throw an exception") {
      REQUIRE_THROWS(stack.pop());
    }

    WHEN("a value has been pushed") {
      stack.push(3);

      THEN("it should no longer be empty.") {
        REQUIRE_FALSE(stack.empty());
      }

      THEN("its size should be 1.") {
        REQUIRE(stack.size() == 1);
      }

      AND_WHEN("the value has been popped again") {
        int popped = stack.pop();

        THEN("that value should match what was pushed") {
          REQUIRE(popped == 3);

          AND_THEN("the stack should be empty again.") {
            CHECK(stack.empty());
            CHECK(stack.size() == 0);
          }
        }
      }
    }
  }
}

SCENARIO("Using a stack with n values") {
  GIVEN("a stack with n values") {
    Stack<int> stack{};
    std::vector<int> values{};
    int n = rand() % 100;   // An arbitrary limit to avoid excessive work.
    for (int i = 0; i < n; i++) {
      int v = rand();
      stack.push(v);
      values.push_back(v);  // Save for later comparison.
    }

    THEN("all the values should be popped in LIFO order.") {
      std::reverse(values.begin(), values.end());
      for (int v : values) {
        REQUIRE(stack.pop() == v);
      }
    }

    WHEN("a value is pushed") {
      int value = rand();
      stack.push(value);

      THEN("the stack should not be empty.") {
        REQUIRE_FALSE(stack.empty());
      }

      THEN("the size should be n + 1.") {
        REQUIRE(stack.size() == n + 1);
      }

      // The extra push also represents the case where n ≥ 1.
      AND_WHEN("the value is popped again") {
        stack.pop();

        THEN("the size should be n again.") {
          REQUIRE(stack.size() == n);
        }
      }
    }
  }
}
