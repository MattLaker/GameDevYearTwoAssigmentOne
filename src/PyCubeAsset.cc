#include <boost/python.hpp>
#include "Camera.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(libpyhydra) {
	class_<Camera>("Camera", init<>())
	//.def("greeting", &Camera::greet)
	;
}
