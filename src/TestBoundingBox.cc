using namespace std;
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "AABoundingBox.cc"

BOOST_AUTO_TEST_SUITE( TestBoundingBox );

BOOST_AUTO_TEST_CASE(CollidesTrue)
{
	auto b1 = make_shared<AABoundingBox>(AABoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = make_shared<AABoundingBox>(AABoundingBox(Vector3(0.1f, 0.1f, 0.1f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(b1->CollidesWith(b2));
	BOOST_CHECK(b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_CASE(CollidesFalse)
{
	auto b1 = make_shared<AABoundingBox>(AABoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = make_shared<AABoundingBox>(AABoundingBox(Vector3(10.0f, 10.0f, 10.0f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(!b1->CollidesWith(b2));
	BOOST_CHECK(!b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_SUITE_END()
