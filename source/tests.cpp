#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

Vec2 v1{1.0f, 2.0f};
Vec2 v2{3.0f, 2.0f};

TEST_CASE ("describe_operator+ ", "[operator+]")
{
	Vec2 v1{1.0f, 2.0f};
	Vec2 v2{3.0f, 2.0f};
	Vec2 v3{0.0f, 4.0f};
	Vec2 v4{0.4f, 0.0f};

	v1+=v2;
	v2+=v3;
	v3+=v4;
	v4+=v1;

	REQUIRE(v1.x == 4.0f);
	REQUIRE(v1.y == 4.0f);
	REQUIRE(v2.x == 3.0f);
	REQUIRE(v2.y == 6.0f);
	REQUIRE(v3.x == 0.4f);
	REQUIRE(v3.y == 4.0f);
	REQUIRE(v4.x == 4.4f);
	REQUIRE(v4.y == 4.0f);
}

TEST_CASE ("describe_operator- ", "[operator-]")
{
	Vec2 v1{1.0f, 2.0f};
	Vec2 v2{3.0f, 2.0f};
	Vec2 v3{0.0f, 4.0f};
	Vec2 v4{0.4f, 0.0f};

	v1-=v2;
	v2-=v3;
	v3-=v4;
	v4-=v1;

	REQUIRE(v1.x == -2.0f);
	REQUIRE(v1.y == 0.0f);
	REQUIRE(v2.x == 3.0f);
	REQUIRE(v2.y == -2.0f);
	REQUIRE(v3.x == -0.4f);
	REQUIRE(v3.y == 4.0f);
	REQUIRE(v4.x == 2.4f);
	REQUIRE(v4.y == 0.0f);
}

TEST_CASE ("describe_operator/ ", "[operator/]")
{
	Vec2 v1{1.0f, 2.0f};
	Vec2 v2{3.0f, -2.7f};
	Vec2 v3{0.0f, 3.1f};

	float a1{3.4f};
	float a2{-1.0f};
	float a3{1.6f};
	
	v1/=a1;
	v2/=a3;
	v3/=a2;

	REQUIRE(v1.x == Approx(0.29412f));
	REQUIRE(v1.y == Approx(0.29412f*2));
	REQUIRE(v2.x == Approx(1.875f));
	REQUIRE(v2.y == Approx(-1.6875f));
	REQUIRE(v3.x == Approx(0.0f));
	REQUIRE(v3.y == Approx(-3.1f));
}


TEST_CASE ("describe_operator* ", "[operator*]")
{
	Vec2 v1{1.0f, 2.0f};
	Vec2 v2{3.0f, -2.7f};
	Vec2 v3{0.0f, 3.1f};

	float a1{3.4f};
	float a2{-1.0f};
	float a3{1.6f};
	
	v1*=a1;
	v2*=a3;
	v3*=a2;

	REQUIRE(v1.x == Approx(3.4f));
	REQUIRE(v1.y == Approx(6.8f));
	REQUIRE(v2.x == Approx(4.8f));
	REQUIRE(v2.y == Approx(-4.32));
	REQUIRE(v3.x == Approx(0.0f));
	REQUIRE(v3.y == Approx(-3.1f));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
