#ifndef AABOUNDINGBOX_H
#define AABOUNDINGBOX_H

#include <memory>
#include <utility>
#include <ostream>

using namespace std;

#include "GameMaths.h"

enum AXIS {X, Y, Z};

class AABoundingBox {
public:
  AABoundingBox(const Vector3, const float, const float, const float);
  virtual ~AABoundingBox();
  void SetCentre(Vector3 &);

  bool CollidesWith(const shared_ptr<AABoundingBox>);

private:
  shared_ptr<Vector3> centre, extent_x, extent_y, extent_z;

  pair<float,float> projectOntoAxis(const AABoundingBox &, enum AXIS);

};

#endif
