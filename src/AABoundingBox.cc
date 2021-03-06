#include "AABoundingBox.h"

/*
* Constructor for a Bounding box which every game asset has to handle collision detection.
*/
AABoundingBox::AABoundingBox(const Vector3 centre, const float width, const float height, const float depth) :
  centre(make_shared<Vector3>(centre)),
  extent_x(make_shared<Vector3>(Vector3((float) width/2.0, 0.0f, 0.0f))),
  extent_y(make_shared<Vector3>(Vector3(0.0f, (float) height/2.0, 0.0f))),
  extent_z(make_shared<Vector3>(Vector3(0.0f, 0.0f, (float) depth/2.0))) {
}

AABoundingBox::~AABoundingBox() {
  centre.reset();
  extent_x.reset();
  extent_y.reset();
}

/*! sets the centre of the bounding box
* Sets the centre of the bounding box to the given vector.
*/
void AABoundingBox::SetCentre(Vector3 & v) {
  centre = make_shared<Vector3>(v);
}

/*! returns the centre of the bounding box
* returns the centre of the bounding box as a smart pointer to a vector.
*/
std::shared_ptr<Vector3> AABoundingBox::GetCentre() {
  return centre;
}

/*! part of handing collision
* takes in two pairs of floats and calcultes whether or not the two points are overlapping
*/
bool straddles(const pair<float, float> & a, const pair<float, float> & b) {
  return (a.first >= b.first && a.first <= b.second)  // a1 intersects b
    || (a.second >= b.first && a.second <= b.second)  // a2 intersects b
    || (b.first >= a.first && b.first <= a.second)    // b1 intersects a
    || (b.second >= a.first && b.second <= a.second); // b2 intersects a
}

/*!projects onto an exis bases on position and size
* Takes in a bounding box, an ENUM and and projects the side of the bounding box onto the given 
* axis using the centre and extent value of the bounding box. 
*/
pair<float,float> AABoundingBox::projectOntoAxis(const AABoundingBox & b, enum AXIS axis) {
  float lo, hi;

  switch (axis) {
  case X:
    {
      Vector3 bx = *b.extent_x;
      lo  = projection( Point3(Vector3(*(b.centre)) + (bx * -1)), xAxis());
      hi  = projection( Point3(Vector3(*(b.centre)) + bx), xAxis());
    }
    break;
  case Y:
    {
      Vector3 by = *b.extent_y;
      lo  = projection( Point3(Vector3(*(b.centre)) + (by * -1)), yAxis());
      hi  = projection( Point3(Vector3(*(b.centre)) + by), yAxis());
    }
    break;
    case Z:
    {
      Vector3 bz = *b.extent_z;
      lo  = projection( Point3(Vector3(*(b.centre)) + (bz * -1)), zAxis());
      hi  = projection( Point3(Vector3(*(b.centre)) + bz), zAxis());
    }
    break;  

    }

  return make_pair(lo, hi);
}

/*! checks collision between bounding boxes
* Called on one bounding box and works out if that bounding box is colliding with the parameter
* bounding box, if they are colliding then the method returns true, if the are not colliding it
* returns false
*/
bool AABoundingBox::CollidesWith(const shared_ptr<AABoundingBox> b) {
  pair<float, float> a_x_proj = projectOntoAxis(*this, X),
    a_y_proj = projectOntoAxis(*this, Y),
    a_z_proj = projectOntoAxis(*this, Z),
    b_x_proj = projectOntoAxis(*b, X),
    b_y_proj = projectOntoAxis(*b, Y),
    b_z_proj = projectOntoAxis(*b, Z);

  return (straddles(a_x_proj, b_x_proj)) && (straddles(a_y_proj, b_y_proj)) && (straddles(a_z_proj, b_z_proj));
}

/*ostream& operator<<(ostream& os, const AABoundingBox& obj) {
  os << "c:(" << obj.centre->getX() << ", " << obj.centre->getY() << ") w:" << (obj.extent_x->getX()*2) << " h:" << (obj.extent_y->getY()*2);
  return os;
}*/
