#pragma once
#include "Entity.h"

inline bool MovingEntity::RotateHeadingToFacePosition(Vector3 target)
{
	Vector3 toTarget = norm(Vector3(target - m_Position));
  double angle = acos(dot(m_Heading,toTarget));

  if (angle < 0.00001) 
	  return true;

  if (angle > m_MaxTurnRate) 
	  angle = m_MaxTurnRate;
  
  Matrix2x2 RotationMatrix;
  

  //RotationMatrix=rotation2d(angle * m_Heading.Sign(toTarget));	
  //RotationMatrix.TransformVector2Ds(m_Heading);
  //RotationMatrix.TransformVector2Ds(m_Velocity);

  m_Side = norm(m_Heading);

  return false;
}
inline void MovingEntity::SetHeading(Vector3 new_heading)
{
  //assert( (new_heading.lsq() - 1.0) < 0.00001);
  
  m_Heading = new_heading;
  m_Side = norm(m_Heading);
}