#include <catch.hxx>

#include <stdexcept>
#include <vector>

using VI = std::vector<int>;


TEST_CASE("vector creation and access")
{
    std::vector<double> v1(10, 3.5);
    CHECK( v1.size() == 10 );
    CHECK( v1[9] == 3.5 );
    v1[9] = 17;
    CHECK( v1[9] == 17 );

    std::vector<int> v2{ 2, 4, 6, 8 };
    CHECK( v2.size() == 4 );
    CHECK( v2[1] == 4 );
}

TEST_CASE("growing and shrinking")
{
    VI v;

    CHECK( v == VI{} );
    v.push_back(2);
    CHECK( v == VI{2} );
    v.push_back(5);
    v.push_back(9);
    CHECK( v == VI{2, 5, 9} );

    v.pop_back();
    CHECK( v == VI{2, 5} );
}

TEST_CASE("optional bounds checking")
{
    std::vector<int> v{2, 3, 4};

    CHECK(v.at(2) == 4);
    v.at(2) = 8;
    CHECK(v.at(2) == 8);

    CHECK_THROWS_AS(v.at(3), std::out_of_range);

    /* These two lines both have UB: */
    // v[10] = 12;
    // CHECK( v[10] == 12 );
}

static void inc_vec_wrong(std::vector<int> v)
{
    for (size_t i = 0; i < v.size(); ++i)
        ++v[i];
}

TEST_CASE("vector passed by value")
{
    VI v{2, 3, 4};
    inc_vec_wrong(v);
    CHECK( v == VI{2, 3, 4} );
}

static void inc_vec(std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
        ++v[i];
}

TEST_CASE("vector passed by reference")
{
    VI v{2, 3, 4};
    inc_vec(v);
    CHECK( v == VI{3, 4, 5} );
}

static double sum_vec(std::vector<double> const& v)
{
    double result = 0;
    for (double d : v) result += d;
    return result;
}

TEST_CASE("sum vector passed by const&")
{
    std::vector<double> v{1.1, 20.2, 400};
    CHECK( sum_vec(v) == Approx(421.3) );
}

static void dec_vec_wrong(std::vector<int> &v)
{
    for (int z : v) --z;
}

TEST_CASE("for-each by value")
{
    VI v{3, 4, 5};
    dec_vec_wrong(v);
    CHECK( v == VI{3, 4, 5} );
}

static void dec_vec(std::vector<int> &v)
{
    for (int& z : v) --z;
}

TEST_CASE("for-each by reference")
{
    VI v{3, 4, 5};
    dec_vec(v);
    CHECK( v == VI{2, 3, 4} );
}

