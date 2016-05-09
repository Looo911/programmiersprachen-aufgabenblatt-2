#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <cmath>


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

//2.4
TEST_CASE("vektor_add / sub / mult / div", "[operator+-/*]")
{	
	//Addition 
	REQUIRE ((Vec2(1,1)+Vec2(1,1)) == Vec2(2,2));
	REQUIRE ((Vec2()+Vec2(1,1)) == Vec2(1,1));
	REQUIRE ((Vec2(1.5,1.5)+Vec2(-1.5,-1.5)) == Vec2(0,0));

	//Subtraktion
	REQUIRE ((Vec2(1,1)-Vec2(1,1)) == Vec2(0,0));
	REQUIRE ((Vec2()-Vec2(1,1)) == Vec2(-1,-1));
	REQUIRE ((Vec2(1.5,1.5)-Vec2(-1.5,-1.5)) == Vec2(3,3));

	//Multiplikation
	REQUIRE ((Vec2(1,1)*float(1.5)) == Vec2(1.5,1.5));
	REQUIRE ((Vec2()*float(1)) == Vec2(0,0));
	REQUIRE ((Vec2(1.5,1.5)*float(-1.5)) == Vec2(-2.25,-2.25));
	//Multiplikation.rev
	REQUIRE ((float(1.5)*Vec2(1,1)) == Vec2(1.5,1.5));
	REQUIRE ((float(1)*Vec2()) == Vec2(0,0));
	REQUIRE ((float(-1.5)*Vec2(1.5,1.5)) == Vec2(-2.25,-2.25));
	//Division 
	REQUIRE ((Vec2(1,1)/float(2)) == Vec2(0.5,0.5));
	REQUIRE ((Vec2()/float(1)) == Vec2(0,0));
	REQUIRE ((Vec2(1.5,1.5)/float(-1.5)) == Vec2(-1,-1));
}

//2.5
TEST_CASE("matritzen_mult", "[operator*]")
{
	
	REQUIRE ((Mat2()*=Mat2())==Mat2());
	REQUIRE ((Mat2(1,2,3,4)*=Mat2())==Mat2(1,2,3,4));
	REQUIRE ((Mat2(1,2,3,4)*=Mat2(1,2,3,4))==Mat2(7,10,15,22));
	
	REQUIRE ((Mat2()*Mat2())==Mat2());
	REQUIRE ((Mat2(1,2,3,4)*Mat2())==Mat2(1,2,3,4));
	REQUIRE ((Mat2(1,2,3,4)*Mat2(1,2,3,4))==Mat2(7,10,15,22));
}

//2.6
TEST_CASE("matritzen_transp,inv,det,rot,mat*vek", "[operator]")
{
	//Determinante
	REQUIRE ((Mat2().det())==1);
	REQUIRE ((Mat2(1,2,3,4).det())==-2);
	REQUIRE ((Mat2(1,1,1,1).det())==0);
	//Matrix*Vektor
	REQUIRE ((Mat2()*Vec2())==Vec2());
	REQUIRE ((Mat2(1,2,3,4)*Vec2(1,1))==Vec2(3,7));
	REQUIRE ((Mat2(1,2,3,4)*Vec2(-1,0))==Vec2(-1,-3));
	//Inverses
	REQUIRE ((inverse(Mat2()))==Mat2());
	REQUIRE ((inverse(Mat2(1,2,3,4)))==Mat2(-2.0f,1.0f,(3.0f/2.0f),-0.5f));
	REQUIRE ((inverse(Mat2(1,0,1,1)))==Mat2(1,0,-1,1));
	//Transpose
	REQUIRE ((transpose(Mat2()))==Mat2());
	REQUIRE ((transpose(Mat2(1,2,3,4)))==Mat2(1,3,2,4));
	REQUIRE ((transpose(Mat2(0,-4,4,0)))==Mat2(0,4,-4,0));
}

//2.8 & 2.9 & 2.13
TEST_CASE("Circle&Rectangle", "[operator]")
{	
	//Circle:

	//getter: center
	REQUIRE (((Circle().center()))==Vec2());
	REQUIRE (((Circle(Vec2(1,1),2,Color()).center()))==Vec2(1,1));
	REQUIRE (((Circle(Vec2(1,2),4,Color()).center()))==Vec2(1,2));

	//getter: radius
	REQUIRE (((Circle().radius()))==1);
	REQUIRE (((Circle(Vec2(1,1),2,Color()).radius()))==2);
	REQUIRE (((Circle(Vec2(1,2),4,Color()).radius()))==4);

	//circumference
	//REQUIRE ( ((Circle().circumference())) == 2*M_PI);
	//REQUIRE ( ((Circle(Vec2(1,1), 2,Color()).circumference())==4*M_PI));	
	//REQUIRE ( ((Circle(Vec2(1,1), 4,Color()).circumference())==2*4*M_PI));

	//is_inside	
	REQUIRE ((Circle(Vec2(0,0),0.5,Color()).is_inside(Vec2(0,0.5))==false));
	REQUIRE ((Circle(Vec2(0,0),0.5,Color()).is_inside(Vec2(-0.5,0))==false));

	//Rectangle:
	
	//getter: center
	REQUIRE (((Rectangle().point()))==Vec2());
	REQUIRE (((Rectangle(Vec2(1,1),2,-4,Color()).point()))==Vec2(1,1));
	REQUIRE (((Rectangle(Vec2(1,2),4,0,Color()).point()))==Vec2(1,2));

	//getter: width
	REQUIRE (((Rectangle().width()))==1);
	REQUIRE (((Rectangle(Vec2(1,1),0,3,Color()).width()))==0);
	REQUIRE (((Rectangle(Vec2(1,2),-4,0,Color()).width()))==-4);
	//getter: height
	REQUIRE (((Rectangle().height()))==1);
	REQUIRE (((Rectangle(Vec2(1,1),0,3,Color()).height()))==3);
	REQUIRE (((Rectangle(Vec2(1,2),-4,0,Color()).height()))==0);

	//circumference
	REQUIRE (((Rectangle().circumference()))==4.0); //Default circle
	REQUIRE (((Rectangle(Vec2(1,1), 2,0,Color()).circumference())==4.0));	
	REQUIRE (((Rectangle(Vec2(1,1), 4,-5,Color()).circumference())==18.0));

	//is inside
	REQUIRE ((Rectangle(Vec2(0,0),0.5, 0.5,Color()).is_inside(Vec2(0,0.5))==false));
	REQUIRE ((Rectangle(Vec2(0,0),0.5, -0.5,Color()).is_inside(Vec2(0,-0.5))==false));
	REQUIRE ((Rectangle(Vec2(0,0), 0.5, -0.5,Color()).is_inside(Vec2(-0.5,-0.5))==false));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
