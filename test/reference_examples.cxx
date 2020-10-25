#include <catch.hxx>

void inc_ptr(int* p)
{
    *p += 1;
}

TEST_CASE("C-style increment")
{
    int x = 0;
    inc_ptr(&x);
    CHECK( x == 1 );
}

void inc_ref(int& r)
{
    r += 1;
}

TEST_CASE("C++-style increment")
{
    int x{0};
    inc_ref(x);
    CHECK( x == 1 );
}

void swap_ptr(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

TEST_CASE("C-style swap")
{
    int x = 3, y = 4;
    swap_ptr(&x, &y);
    CHECK( x == 4 );
    CHECK( y == 3 );
}

void swap_ref(int& r, int& s)
{
    int temp = r;
    r = s;
    s = temp;
}

TEST_CASE("C++-style swap")
{
    int x = 3, y = 4;
    swap_ref(x, y);
    CHECK( x == 4 );
    CHECK( y == 3 );
}

void broken_swap_ref(int& r, int& s)
{
    int& temp = r;
    r = s;
    s = temp;
}

TEST_CASE("broken swap")
{
    int x = 3, y = 4;
    broken_swap_ref(x, y);
    CHECK( x == 4 );
    CHECK( y == 4 );
}

