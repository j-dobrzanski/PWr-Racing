#include "geometry.h"
#include <stdlib.h>

// LOCAL FUNCTIONS DECLARATIONS

// LOCAL FUNCTIONS DEFINITIONS

// GLOBAL FUNCTIONS DEFINITIONS

struct geometry_point {
    double x;
    double y;
};

struct geometry_segment {
    geometry_point* start;
    geometry_point* end;
};

struct geometry_triangle {
    geometry_point* first;
    geometry_point* second;
    geometry_point* third;
    bool is_right;
};

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
geometry_point* geometry_point_new(double x, double y){
    geometry_point* new_point = malloc(sizeof(*new_point));
    if(new_point == NULL){
        return NULL;
    }
    new_point->x = x;
    new_point->y = y;
    return new_point;
}

/**
*   Function to destroy given geometry_point object
*   In params:
*       geometry_point* point       point object that should be freed
*
*   Out params/return:
*       none
*/
void geometry_point_destroy(geometry_point* point){
    if(point != NULL){
        free(point);
    }
}

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
double geometry_point_getX(geometry_point* point){
    if(point != NULL){
        return point->x;
    }
    return 0;
}

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
double geometry_point_getY(geometry_point* point){
    if(point != NULL){
        return point->y;
    }
    return 0;
}

/**
*   Function to create new gemetry_segment object with given points.
*   Those points don't need to be proper dynamic-allocated objects
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
geometry_segment* geometry_segment_new(geometry_point* start, geometry_point* end){
    if(start == NULL || end == NULL){
        return NULL;
    }
    geometry_point* new_start = geometry_point_new(start->x, start->y);
    geometry_point* new_end = geometry_point_new(end->x, end->y);
    geometry_segment* new_segment = malloc(sizeof(*new_segment));
    if(new_start == NULL || new_end == NULL || new_segment == NULL){
        free(new_segment);
        free(new_start);
        free(new_end);
        return NULL;
    }
    new_segment->start = new_start;
    new_segment->end = new_end;
    return new_segment;
}

/**
*   Function to destroy given geometry_segment object
*   In params:
*       geometry_segment* segment       segment object that should be freed
*
*   Out params/return:
*       none
*/
void geometry_segment_destroy(geometry_segment* segment){
    if(segment == NULL){
        return;
    }
    free(segment->end);
    free(segment->start);
    free(segment);
}

/**
*   Function to get end points of given geometry_segment object
*   In params:
*       geometry_segment* segment       segment object to get ending points
*       
*   Out params:
*       geometry_point* start           starting point of given segment
*       geometry_point* end             ending point of given segment
*
*   Return:
*       none
*/
void geometry_segment_getPoints(geometry_segment* segment, geometry_point** start, geometry_point** end){
    if(segment == NULL){
        return;
    }
    *start = segment->start;
    *end = segment->end;
}

/**
*   Function to create new gemetry_triangle object with given points.
*   Those points don't need to be proper dynamic-allocated objects
*   In params:
*       geometry_point* first           first point of triangle
*       geometry_point* second          second point of triangle
*       geometry_point* third           third point of triangle
*   
*   Out params:
*       none
*   
*   Return:
*       geometry_triangle*               pointer to created object
*/
geometry_triangle* geometry_triangle_new(geometry_point* first, geometry_point* second, geometry_point* third, bool is_right){
    if(first == NULL || second == NULL || third == NULL){
        return NULL;
    }
    geometry_point* new_first = geometry_point_new(first->x, first->y);
    geometry_point* new_second = geometry_point_new(second->x, second->y);
    geometry_point* new_third = geometry_point_new(third->x, third->y);
    geometry_triangle* new_triangle = malloc(sizeof(*new_triangle));
    if(new_first == NULL || new_second == NULL || new_third == NULL || new_triangle == NULL){
        free(new_first);
        free(new_second);
        free(new_third);
        free(new_triangle);
        return NULL;
    }
    new_triangle->first = new_first;
    new_triangle->second = new_second;
    new_triangle->third = new_third;
    new_triangle->is_right = is_right;
    return new_triangle;
}

/**
*   Function to destroy given geometry_triangle object
*   In params:
*       geometry_triangle* triangle       triangle object that should be freed
*
*   Out params/return:
*       none
*/
void geometry_triangle_destroy(geometry_triangle* triangle){
    if(triangle == NULL){
        return;
    }
    free(triangle->first);
    free(triangle->second);
    free(triangle->third);
    free(triangle);
}

/**
*   Function to get points of given geometry_triangle object
*   In params:
*       geometry_triangle* triangle       triangle object to get ending points
*       
*   Out params:
*       geometry_point* first           first point of given segment
*       geometry_point* second          second point of given segment
*       geometry_point* third           third point of given segment
*
*   Return:
*       none
*/
void geometry_triangle_getPoints(geometry_triangle* triangle, geometry_point** first, geometry_point** second, geometry_point** third){
    if(triangle == NULL){
        return;
    }
    *first = triangle->first;
    *second = triangle->second;
    *third = triangle->third;
}

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
bool geometry_triangle_getIsRight(geometry_triangle* triangle){
    if(triangle != NULL){
        return triangle->is_right;
    }
    return false;
}
