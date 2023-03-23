#ifndef GEOMETRY
#define GEOMETRY

#include <stdbool.h>

// class objects-structures forward-declarations
typedef struct geometry_point geometry_point;
typedef struct geometry_segment geometry_segment;
// In task there are specified two types of triangle classes,
// however a good idea not to copy-paste a lot of code is
// to use abstraction - we can't have theese in C 
// so it will be probably best to simulate abstraction 
// by field is_right. Using void* is overall ugly
// and passing another argument in functions is bug-prone.
typedef struct geometry_triangle geometry_triangle;

/*##############################################
 GEOMETRY_POINT functions (methods) declarations
###############################################*/

/**
*   Function to create new gemetry_point object with given coordinates
*   In params:
*       double x        x coordinate
*       double y        y coordinate
*   
*   Out params:
*       none
*   
*   Return:
*       geometry_point* pointer to created object
*/
geometry_point* geometry_point_new(double x, double y);

/**
*   Function to destroy given geometry_point object
*   In params:
*       geometry_point* point       point object that should be freed
*
*   Out params/return:
*       none
*/
void geometry_point_destroy(geometry_point* point);

/**
*   Function to get x coordinate of given point
*   In params:
*       goemetry_point* point       point
*
*   Out params:
*       none
*
*   Return:
*       double                      x coordinate of given point
*/
double geometry_point_getX(geometry_point* point);

/**
*   Function to get y coordinate of given point
*   In params:
*       goemetry_point* point       point
*
*   Out params:
*       none
*
*   Return:
*       double                      y coordinate of given point
*/
double geometry_point_getY(geometry_point* point);

/**
*   Function to move point by vector
*   User is expected to provide vector in normalized form;
*   i.e. unbouned or origin-bounded
*   In parms:
*       geometry_point* point       point to be moved
*       double vector_x             x coordinate of vector
*       double vector_y             y coordinate of vector
*       
*   Out params/return:
*       none (point object is changed)
*/
void geometry_point_moveByVector(geometry_point* point, double vector_x, double vector_y);

/**
*   Function to rotate point through an angle around another point
*   User is expected to provide angle measured in radians
*   calculated counterclockwise
*   In params:
*       geometry_point* rotated_point       point to be rotated
*       double angle                        angle to rotate through in radians calculated counterclockwise
*       geometry_point* reference_point     point around which rotations will be calculated
*
*   Out params/return:
*       none (roated_point object is changed)       
*/
void geometry_point_rotateByAngle(geometry_point* rotated_point, double angle, geometry_point* reference_point);

/**
*   Function to calculate distance between two given points
*   In params:
*       geometry_point* first_point         first point
*       geometry_point* second_point        second point
*
*   Out params:
*       none
*
*   Return:
*       double                              euclidean distance between two given points
*/
double geometry_point_calculateDistance(geometry_point* first_point, geometry_point* second_point);

/*##############################################
 GEOMETRY_SEGMENT functions (methods) declarations
###############################################*/

/**
*   Function to create new gemetry_segment object with given points.
*   In params:
*       geometry_point* start           starting point of segment
*       geometry_point* end             ending point of segment
*   
*   Out params:
*       none
*   
*   Return:
*       geometry_segment*               pointer to created object
*/
geometry_segment* geometry_segment_new(geometry_point* start, geometry_point* end);

/**
*   Function to destroy given geometry_segment object
*   In params:
*       geometry_segment* segment       segment object that should be freed
*
*   Out params/return:
*       none
*/
void geometry_segment_destroy(geometry_segment* segment);

/**
*   Function to get end points of given geometry_segment object
*   In params:
*       geometry_segment* segment       segment object to get ending points
*       
*   Out params:
*       geometry_point** start          pointer to starting point of given segment
*       geometry_point** end            pointer to ending point of given segment
*
*   Return:
*       none
*/
void geometry_segment_getPoints(geometry_segment* segment, geometry_point** start, geometry_point** end);

/**
*   Function to move segment by vector
*   User is expected to provide vector in normalized form;
*   i.e. unbouned/origin-bounded
*   In parms:
*       geometry_segment* segment       segment to be moved
*       double vector_x                 x coordinate of vector
*       double vector_y                 y coordinate of vector
*       
*   Out params/return:
*       none (segment object is changed)
*/
void geometry_segment_moveByVector(geometry_segment* segment, double vector_x, double vector_y);

/**
*   Function to rotate segment through an angle around another point
*   User is expected to provide angle measured in radians
*   calculated counterclockwise
*   In params:
*       geometry_segment* rotated_segment       segment to be rotated
*       double angle                            angle to rotate through in radians calculated counterclockwise
*       geometry_point* reference_point         point around which rotations will be calculated
*
*   Out params/return:
*       none (roated_segment object is changed)       
*/
void geometry_segment_rotateByAngle(geometry_segment* rotated_segment, double angle, geometry_point* reference_point);

/**
*   Function to calculate length of given segment
*   In params:
*       geometry_segment* segment       segment to calculate its length
*
*   Out params:
*       none
*
*   Return:
*       double                          length of given segment
*/
double geometry_segment_calculateLength(geometry_segment* segment);

/**
*   Function to determine if given segments are parrarel
*   In params:
*       geometry_segment* first_segment         first segment
*       geometry_segment* second_segment        second_segment
*
*   Out params:
*       none
*
*   Return:
*       bool                                    true if given segments are parallel, false otherwise
*/
bool geometry_segment_areParallel(geometry_segment* first_segment, geometry_segment* second_segment);

/**
*   Function to determine if given segments are perpendicular
*   In params:
*       geometry_segment* first_segment         first segment
*       geometry_segment* second_segment        second_segment
*
*   Out params:
*       none
*
*   Return:
*       bool                                    true if given segments are perpendicular, false otherwise
*/
bool geometry_segment_arePerpendicular(geometry_segment* first_segment, geometry_segment* second_segment);

/**
*   Function to calculate intersection point of given segments
*   In params:
*       geometry_segment* first_segment         first segment
*       geometry_segment* second_segment        second_segment
*
*   Out params:
*       none
*
*   Return:
*       geometry_point*                         object of geometry_point structure(class) which is interesection
*                                               of given segments, if segments are parallel, then NULL
*/
geometry_point* geometry_segment_calculateIntersection(geometry_segment* first_segment, geometry_segment* second_segment);

/*##############################################
 GEOMETRY_TRIANGLE functions (methods) declarations
###############################################*/

/**
*   Function to create new gemetry_triangle object with given points.
*   Those points don't need to be proper dynamic-allocated objects
*   In params:
*       geometry_point* first           first point of triangle
*       geometry_point* second          second point of triangle
*       geometry_point* third           third point of triangle
*       bool is_right                   user should specify if triangle should be considered right-angled
*   
*   Out params:
*       none
*   
*   Return:
*       geometry_triangle*               pointer to created object
*/
geometry_triangle* geometry_triangle_new(geometry_point* first, geometry_point* second, geometry_point* third, bool is_right);

/**
*   Function to destroy given geometry_triangle object
*   In params:
*       geometry_triangle* triangle       triangle object that should be freed
*
*   Out params/return:
*       none
*/
void geometry_triangle_destroy(geometry_triangle* triangle);

/**
*   Function to get points of given geometry_triangle object
*   In params:
*       geometry_triangle* triangle         triangle object to get ending points
*       
*   Out params:
*       geometry_point** first              pointer to first point of given segment
*       geometry_point** second             pointer to second point of given segment
*       geometry_point** third              pointer to third point of given segment
*
*   Return:
*       none
*/
void geometry_triangle_getPoints(geometry_triangle* triangle, geometry_point** first, geometry_point** second, geometry_point** third);

/**
*   Function to get is_right field of given triangle
*   In params:
*       geometry_triangle* triangle     triangle to get its field
*   
*   Out params:
*       none
*
*   Return:
*       bool                            logical value of field is_right of the given triangle
*/
bool geometry_triangle_getIsRight(geometry_triangle* triangle);

/**
*   Function to move triangle by vector
*   User is expected to provide vector in normalized form;
*   i.e. unbouned or origin-bounded
*   In parms:
*       geometry_triangle* triangle     triangle to be moved
*       double vector_x                 x coordinate of vector
*       double vector_y                 y coordinate of vector
*       
*   Out params/return:
*       none (triangle object is changed)
*/
void geometry_triangle_moveByVector(geometry_triangle* triangle, double vector_x, double vector_y);

/**
*   Function to rotate triangle through an angle around another point
*   User is expected to provide angle measured in radians
*   calculated counterclockwise
*   In params:
*       geometry_triangle* rotated_triangle         triangle to be rotated
*       double angle                                angle to rotate through in radians calculated counterclockwise
*       geometry_point* reference_point             point around which rotations will be calculated
*
*   Out params/return:
*       none (roated_triangle object is changed)       
*/
void geometry_triangle_rotateByAngle(geometry_triangle* rotated_triangle, double angle, geometry_point* reference_point);

/**
*   Function to calculate perimeter of a given triangle
*   In params:
*       geometry_triangle* triangle     triangle to calculate its perimeter
*
*   Out params:
*       none
*
*   Return:
*       double                          calculated perimeter of given triangle,
*                                       -1 if error(s) occured
*/
double geometry_triangle_calculatePerimeter(geometry_triangle* triangle);

/**
*   Function to calculate area of a given triangle
*   In params:
*       geometry_triangle* triangle     triangle to calculate its area
*
*   Out params:
*       none
*
*   Return:
*       double                          calculated area of given triangle,
*                                       -1 if error(s) occured
*/
double geometry_triangle_calculateArea(geometry_triangle* triangle);

/**
*   Function to determine if two given triangles intersect
*   In params:
*       geometry_triangle* first_triangle       first triangle
*       geometry_triangle* second_triangle      second triangle
*
*   Out params:
*       none
*
*   Return:
*       bool                                    true if triangles are disjoint,
*                                               false if they intersect
*/
bool geometry_triangle_areDisjoint(geometry_triangle* first_triangle, geometry_triangle* second_triangle);

/**
*   Function to calculate hypotenuse of a given triangle.
*   User should provide a right-angled triangle
*   In params:
*       geometry_triangle* triangle     triangle to calculate its hypotenuse
*
*   Out params:
*       none
*
*   Return:
*       double                          calculated hypotenuse of given triangle,
*                                       -1 if given triangle is not right-angled
*/
double geometry_triangle_calculateHypotenuse(geometry_triangle* triangle);
#endif