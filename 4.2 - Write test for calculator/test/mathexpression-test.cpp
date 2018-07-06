//
// Created by sebas on 10/11/2017.
//
#include "MathExpression.h"
#include "catch.hpp"
#include <iostream>
#include <algorithm>
#include <vector>



// -------------- Ska inte godkännas ----------
// HelloWorld!
// 35+
// (1*2)(3+56)
// (2+3
// 2 1 3
// 2++8

// User inputs invalid expression so isValid must be False and errormessage should not be empty
TEST_CASE( "User inputs invalid expression, isValid = false, errormessage != """) {

	SECTION("input HelloWorld!") {
		MathExpression me("HelloWorld!");

		REQUIRE_FALSE(me.isValid());
		REQUIRE(me.errorMessage() != "");
	}

	SECTION("input 35+") {
		MathExpression me("35+");

		REQUIRE_FALSE(me.isValid());
		REQUIRE(me.errorMessage() != "");
	}

	SECTION("input (1*2)(3+56)") {
		MathExpression me("(1*2)(3+56)");

		REQUIRE_FALSE(me.isValid());
		REQUIRE(me.errorMessage() != "");
	}

	SECTION("input (2+3") {
		MathExpression me("(2+3");

		REQUIRE_FALSE(me.isValid());
		REQUIRE(me.errorMessage() != "");
	}

	SECTION("input 2 1 3") {
		MathExpression me("2 1 3");

		REQUIRE_FALSE(me.isValid());
		REQUIRE(me.errorMessage() != "");
	}

	SECTION("input 2++8") {
		MathExpression me("2++8");

		REQUIRE_FALSE(me.isValid());
		REQUIRE(me.errorMessage() != "");
	}
}

//  -------------- Ska godkännas ---------
// (32+5)­(2+1)
// 5*(21+1)­1
// (2)+(3)
// 2
// (35)
// 4/8
TEST_CASE( "Valid inputs should be valid, infix same as input, correct postfix and correct result") {

	SECTION("input (32+5)-(2+1)") {

		MathExpression me("(32+5)-(2+1)");
		REQUIRE(me.isValid());

		SECTION("infix should be same as input") {

				REQUIRE(me.infixNotation() == "(32+5)-(2+1)");
		}

		SECTION("postfix should be correct") {

			REQUIRE(me.postfixNotation() == "32 5 + 2 1 + -");

		}

		SECTION("calculation should be correct") {

			REQUIRE(me.calculate() == 34);
		}
	}

	SECTION("input 5*(21+1)-1") {

		MathExpression me("5*(21+1)-1");
		REQUIRE(me.isValid());

		SECTION("infix should be same as input") {

			REQUIRE(me.infixNotation() == "5*(21+1)-1");
		}

		SECTION("postfix should be correct") {

			REQUIRE(me.postfixNotation() == "5 21 1 + * 1 -");

		}

		SECTION("calculation should be correct") {

			REQUIRE(me.calculate() == 109);
		}
	}

	SECTION("input (2)+(3)") {

		MathExpression me("(2)+(3)");
		REQUIRE(me.isValid());

		SECTION("infix should be same as input") {

			REQUIRE(me.infixNotation() == "(2)+(3)");
		}

		SECTION("postfix should be correct") {

			REQUIRE(me.postfixNotation() == "2 3 +");

		}

		SECTION("calculation should be correct") {

			REQUIRE(me.calculate() == 5);
		}
	}

	SECTION("input 2") {

		MathExpression me("2");
		REQUIRE(me.isValid());

		SECTION("infix should be same as input") {

			REQUIRE(me.infixNotation() == "2");
		}

		SECTION("postfix should be correct") {

			REQUIRE(me.postfixNotation() == "2");

		}

		SECTION("calculation should be correct") {

			REQUIRE(me.calculate() == 2);
		}
	}

	SECTION("input (35)") {

		MathExpression me("(35)");
		REQUIRE(me.isValid());

		SECTION("infix should be same as input") {

			REQUIRE(me.infixNotation() == "(35)");
		}

		SECTION("postfix should be correct") {

			REQUIRE(me.postfixNotation() == "35");

		}

		SECTION("calculation should be correct") {

			REQUIRE(me.calculate() == 35);
		}
	}

	SECTION("input 4/8") {

		MathExpression me("4/8");
		REQUIRE(me.isValid());

		SECTION("infix should be same as input") {

			REQUIRE(me.infixNotation() == "4/8");
		}

		SECTION("postfix should be correct") {

			REQUIRE(me.postfixNotation() == "4 8 / ");

		}

		SECTION("calculation should be correct") {

			REQUIRE(me.calculate() == 0.5);
		}
	}
}

TEST_CASE( "Floating points should be handeled correctly to match Approx() result" ) {

	MathExpression me("12/14");
	REQUIRE(me.calculate() == Approx(0.86).epsilon(0.01));

}

TEST_CASE( "When = is used, data should be reset and expression validated" ) {
	MathExpression me("20");
	me = ("5*5");
	REQUIRE(me.infixNotation() == "5*5");
	REQUIRE(me.calculate() == 25);
}