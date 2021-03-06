//----------------------------------------------------------------------------------------------------------------------
/// @file Boid.h
/// @class Boid
/// @brief this class contains movement methods and behaviours for the boids
//----------------------------------------------------------------------------------------------------------------------
#ifndef BOID_H
#define BOID_H

#include <ctime>
#include <deque>
#include <iostream>
#include <ngl/VertexArrayObject.h>
#include <ngl/Transformation.h>
#include <ngl/Vec3.h>
#include <stdlib.h>
#include <vector>
//----------------------------------------------------------------------------------------------------------------------
class Boid
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor
  /// @param [in] _id boid ID
  //----------------------------------------------------------------------------------------------------------------------
  Boid(int _id);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor
  //----------------------------------------------------------------------------------------------------------------------
  ~Boid();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to st the boid position
  /// @param [in] _x the x value ot be set
  /// @param [in] _y the y value ot be set
  /// @param [in] _z the z value ot be set
  //----------------------------------------------------------------------------------------------------------------------
  void setPos(float _x, float _y, float _z);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set a neighbour to the boid
  /// @param [in] boid the neighbouring boid
  /// @return appends boid to m_neighbours
  //----------------------------------------------------------------------------------------------------------------------
  void setNeighbour(Boid *boid);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to cclear the boid's neighbours
  /// @return clears m_neighbours
  //----------------------------------------------------------------------------------------------------------------------
  void clearNeighbour();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the boid's velocity
  /// @param [in] _x the x value ot be set
  /// @param [in] _y the y value ot be set
  /// @param [in] _z the z value ot be set
  //----------------------------------------------------------------------------------------------------------------------
  void setVelocity(float _x, float _y, float _z);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the weight on the separation force
  /// @param [in] _separationWeight the weight value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setSWeight(int _separationWeight);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the weight on the cohesion force
  /// @param [in] _cohesionWeight the weight value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setCWeight(int _cohesionWeight);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the weight on the alignment force
  /// @param [in] _alignWeight the weight value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setAWeight(int _alignWeight);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the mass of the boid
  /// @param [in] _mass the value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setMass(int _mass);
  //----------------------------------------------------------------------------------------------------------------------
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the speed of the boid
  /// @param _speed the speed value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setSpeed(float _speed);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the separation distance
  /// @param [in] _sepDist the value to be set
  //----------------------------------------------------------------------------------------------------------------------
  inline void setSepDist(int _sepDist){m_separationDistance = _sepDist;}
  // accessors
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the number of neighbours the boid has
  /// @return returns the size of m_neighbours
  //----------------------------------------------------------------------------------------------------------------------
  int getNeighbours() const {return m_neighbours.size();}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the position of the boid
  /// @return returns m_position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getPosition() const {return m_position;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the velocity of the boid
  /// @return returns m_velocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getVelocity() const {return m_velocity;}
  float getRadius() const {return m_boundRadius;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the id of a boid
  /// @return returns m_id
  //----------------------------------------------------------------------------------------------------------------------
  int getId() const {return m_id;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the x and y rotations of a boid
  /// @return returns a Vec3 of (m_pitch, m_yaw, 0)
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getRotation() const {return ngl::Vec3(m_pitch, m_yaw, 0);}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the distance a boid will look for neighbours
  /// @return returns m_searchRad
  //----------------------------------------------------------------------------------------------------------------------
  int getSearchRad() const {return m_searchRad;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set steering force vector
  //----------------------------------------------------------------------------------------------------------------------
  void setSteering();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set cohesion force vector
  //----------------------------------------------------------------------------------------------------------------------
  void setCohesion();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set the alignment force vector
  //----------------------------------------------------------------------------------------------------------------------
  void setAlignment();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set the separation force vector
  //----------------------------------------------------------------------------------------------------------------------
  void setSeparation();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set the avoidance force vector
  //----------------------------------------------------------------------------------------------------------------------
  void setAvoid();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set the reposition force vector
  /// @param [in] _reposition the point to reposition from
  //----------------------------------------------------------------------------------------------------------------------
  void setReposition(ngl::Vec3 _reposition);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set the reposition force vector away from the walls
  /// of the Swarm
  //----------------------------------------------------------------------------------------------------------------------
  void repositionBounds();
  //----------------------------------------------------------------------------------------------------------------------
  void setDirection();
  /// @brief method to calculate and set the new position based on the current steering
  /// vector, current velocity and speed
  //----------------------------------------------------------------------------------------------------------------------
  void updatePosition();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to move the boid by combining all the steering methods and
  /// updatePosition
  //----------------------------------------------------------------------------------------------------------------------
  void move();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calculate and set the boid's rotation based on its velocity
  //----------------------------------------------------------------------------------------------------------------------
  void setRotate();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to check if boids are colliding
  //----------------------------------------------------------------------------------------------------------------------
  void Collision(ngl::Vec3 _pos, float _rad);
  //----------------------------------------------------------------------------------------------------------------------
private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the bounding radius of the boid
  //----------------------------------------------------------------------------------------------------------------------
  float m_boundRadius;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the boids position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_position;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief vector containing pointers to all the boid's neighbours
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Boid *> m_neighbours;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the boid's ID
  //----------------------------------------------------------------------------------------------------------------------
  int m_id;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the boid's current speed
  //----------------------------------------------------------------------------------------------------------------------
  float m_speed;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the initial speed set to the boid, this acts as a minimum
  //----------------------------------------------------------------------------------------------------------------------
  float m_setSpeed;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the weight of the cohesion force acting on the boid
  //----------------------------------------------------------------------------------------------------------------------
  int m_cohesionWeight;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the weight of the alignment force acting on the boid
  //----------------------------------------------------------------------------------------------------------------------
  int m_alignmentWeight;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the weight of the separation force acting on the boid
  //----------------------------------------------------------------------------------------------------------------------
  int m_separationWeight;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the distance at which boids begin to feel the separation force
  float m_separationDistance;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the mass of the boid, determines how quickly boid can change direction or move
  //----------------------------------------------------------------------------------------------------------------------
  int m_mass;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the distance the boid sees ahead of itself
  //----------------------------------------------------------------------------------------------------------------------
  float m_viewRange;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the weight of the avoidance force
  //----------------------------------------------------------------------------------------------------------------------
  int m_avoidWeight;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the position of the collision
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_collisionPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the boids veclocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_velocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the cohesion force vector
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_cohesion;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the alignment force vector
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_alignment;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the separation force vector
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_separation;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the avoidance force vector
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_avoid;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the direction vector that is the result of the weighted
  /// average of all the steering forces
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_direction;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief vector from the current velocity to the direction vector.
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_steering;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the reposition force vector
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_reposition;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the yaw (y-axis rotation) of the boid
  //----------------------------------------------------------------------------------------------------------------------
  float m_yaw;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the pitch (x-axis rotation) of the boid
  //----------------------------------------------------------------------------------------------------------------------
  float m_pitch;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the distance that the boid searches for neighbours
  //----------------------------------------------------------------------------------------------------------------------
  int m_searchRad;
};

#endif // BOID_H
