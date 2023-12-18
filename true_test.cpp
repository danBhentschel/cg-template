#include <catch2/catch.hpp>
#include "project.cpp"

TEST_CASE("Should pass") {
  REQUIRE(myFunction() == 23);
}
