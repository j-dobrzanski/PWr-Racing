#ifndef GEOMETRY
#define GEOMETRY

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

// geometry_point functions (methods) declarations

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

// geometry_segment functions (methods) declarations

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

// geometry_triangle functions (methods)

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