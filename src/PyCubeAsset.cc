#include <boost/python.hpp>
#include "Camera.h"
#include "CubeAsset.h"
#include "AABoundingBox.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(libpyhydra) {
	class_<Camera>("Camera", init<>())
	.def("greeting", &Camera::greet)
	.def("moveX", &Camera::move_x)
	.def("moveZ", &Camera::move_z)
	.def("rotateX", &Camera::rotate_x)	
	.def("rotateY", &Camera::rotate_y)
	.def("view", &Camera::getViewMatrix)
	.def("reset", &Camera::reset)
	;
	class_<CubeAsset>("CubeAsset", init<float, float, float>())
	.def("getColour", &CubeAsset::getColour)
	.def("setCubeColour", &CubeAsset::setColour)
	;
	
}
