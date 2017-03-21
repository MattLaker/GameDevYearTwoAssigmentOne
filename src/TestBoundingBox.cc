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
#include "CubeAsset.cc"
#include "GameAsset.cc"
#include "Camera.cc"

BOOST_AUTO_TEST_SUITE( TestBoundingBox );
/*
BOOST_AUTO_TEST_CASE(CollidesTrue)
{
	auto cam = make_shared<Camera>(Camera());
	auto c2 = make_shared<CubeAsset>(CubeAsset(-2.0f, 0.1f, 0.1f));

	auto b1 = cam->getBBox();//make_shared<AABoundingBox>(AABoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = c2->getBBox(); //make_shared<AABoundingBox>(AABoundingBox(Vector3(0.1f, 0.1f, 0.1f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(b1->CollidesWith(b2));
	BOOST_CHECK(b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_CASE(CollidesFalse)
{
	auto cam = make_shared<Camera>(Camera());
	auto c2 = make_shared<CubeAsset>(CubeAsset(-12.0f, 10.1f, 10.1f));

	auto b1 = cam->getBBox();//make_shared<AABoundingBox>(AABoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = c2->getBBox(); //make_shared<AABoundingBox>(AABoundingBox(Vector3(0.1f, 0.1f, 0.1f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(!b1->CollidesWith(b2));
	BOOST_CHECK(!b2->CollidesWith(b1));
}
*/
BOOST_AUTO_TEST_CASE(CollidesMove)
{
	//create a camera with a bounding box, surrounded by bounding boxes
	auto cam = make_shared<Camera>(Camera());
	auto cambox = cam->getBBox();

	auto forward = make_shared<AABoundingBox>(AABoundingBox(Vector3(-2.0f, 0.0f, -1.0f), 1.0f, 1.0f, 1.0f));
	auto backward = make_shared<AABoundingBox>(AABoundingBox(Vector3(-2.0f, 0.0f, 1.0f), 1.0f, 1.0f, 1.0f));
	auto left = make_shared<AABoundingBox>(AABoundingBox(Vector3(-3.0f, 0.0f, 0.0f), 1.0f, 1.0f, 1.0f));
	auto right = make_shared<AABoundingBox>(AABoundingBox(Vector3(-1.0f, 0.0f, 0.0f), 1.0f, 1.0f, 1.0f));
	
	//check that the camera is not colliding with the bounding boxes
	BOOST_CHECK(cambox->CollidesWith(forward));
	BOOST_CHECK(cambox->CollidesWith(backward));
	BOOST_CHECK(cambox->CollidesWith(left));
	BOOST_CHECK(cambox->CollidesWith(right));

	//move the camera backwards one unit and checks collisions
	cam->move_z(-1.0);
	cambox = cam->getBBox();
	BOOST_CHECK(cambox->CollidesWith(forward));
	BOOST_CHECK(!cambox->CollidesWith(backward));
	BOOST_CHECK(cambox->CollidesWith(left));
	BOOST_CHECK(cambox->CollidesWith(right));

	//move the camera forward  two units and check collisions
	cam->move_z(2.0);
	cambox = cam->getBBox();
	BOOST_CHECK(!cambox->CollidesWith(forward));
	BOOST_CHECK(cambox->CollidesWith(backward));
	BOOST_CHECK(cambox->CollidesWith(left));
	BOOST_CHECK(cambox->CollidesWith(right));

	//move the camera back to the centre then to the left one unit and check collisions
	cam->move_z(-1.0);
	cam->move_x(1.0);
	cambox = cam->getBBox();
	BOOST_CHECK(cambox->CollidesWith(forward));
	BOOST_CHECK(cambox->CollidesWith(backward));
	BOOST_CHECK(!cambox->CollidesWith(left));
	BOOST_CHECK(cambox->CollidesWith(right));

	//move the camera to the right two units and check collisions
	cam->move_x(-2.0);
	cambox = cam->getBBox();
	BOOST_CHECK(cambox->CollidesWith(forward));
	BOOST_CHECK(cambox->CollidesWith(backward));
	BOOST_CHECK(cambox->CollidesWith(left));
	BOOST_CHECK(!cambox->CollidesWith(right));

	//move the camera back to the centre and check collisions
	cam->move_x(1.0);
	cambox = cam->getBBox();
	BOOST_CHECK(cambox->CollidesWith(forward));
	BOOST_CHECK(cambox->CollidesWith(backward));
	BOOST_CHECK(cambox->CollidesWith(left));
	BOOST_CHECK(cambox->CollidesWith(right));
}

BOOST_AUTO_TEST_SUITE_END()
