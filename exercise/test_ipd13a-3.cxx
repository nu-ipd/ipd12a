#include "ipd13a-3.hxx"
#include <catch.hxx>

using ipd::sort_refs;


TEST_CASE("sort_refs(int& a, int& b, int& c)")
{
    // TODO: add more tests
}


TEST_CASE("sort_refs(float& a, float& b, float& c)")
{
    // TODO: add more tests
}


TEST_CASE ("sort_refs(int& a, int& b)")
{
    int a, b;

    SECTION ("a > b") {
        a = 5;
        b = 3;

        CHECK (sort_refs(a, b));
        CHECK (a == 3);
        CHECK (b == 5);

        CHECK (sort_refs(b, a));
        CHECK (b == 3);
        CHECK (a == 5);
    }

    SECTION ("a < b") {
        a = 3;
        b = 5;

        CHECK_FALSE (sort_refs(a, b));
        CHECK (a == 3);
        CHECK (b == 5);

        std::swap(a, b);

        CHECK_FALSE (sort_refs(b, a));
        CHECK (b == 3);
        CHECK (a == 5);
    }

    SECTION ("a == b") {
        a = 4;
        b = 4;

        CHECK_FALSE (sort_refs(a, b));
        CHECK (a == 4);
        CHECK (b == 4);

        CHECK_FALSE (sort_refs(b, a));
        CHECK (a == 4);
        CHECK (b == 4);
    }
}
