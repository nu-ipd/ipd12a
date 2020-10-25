#include <memory>

#include <catch.hxx>

// How big to make the arrays we allocate
static size_t const N { 15 };

struct posn
{
    double x, y;
};

TEST_CASE("manual, single object")
{
    posn* p = new posn{3, 4};

    CHECK( p->x == 3 );
    CHECK( p->y == 4 );

    ++p->x;
    --p->y;

    CHECK( p->x == 4 );
    CHECK( p->y == 3 );

    delete p;
}

TEST_CASE("automatic, single object")
{
    std::unique_ptr<posn>p{ new posn{3, 4} };

    CHECK( p->x == 3 );
    CHECK( p->y == 4 );

    ++p->x;
    --p->y;

    CHECK( p->x == 4 );
    CHECK( p->y == 3 );
}

TEST_CASE("manual, array")
{
    double* a = new double[N]{};

    for (size_t i = 0; i < N; ++i)
        CHECK( a[i] == 0.0 );

    for (size_t i = 0; i < N; ++i)
        a[i] = i;

    for (size_t i = 0; i < N; ++i)
        CHECK( a[i] == i );

    delete [] a;
}

