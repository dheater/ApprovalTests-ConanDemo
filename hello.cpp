#include "ApprovalTests.hpp"
#include <catch2/catch.hpp>

TEST_CASE("HelloApproval")
{
    ApprovalTests::Approvals::verify("Hello Approvals");
}
