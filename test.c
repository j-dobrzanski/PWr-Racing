#include "geometry.h"
#include <assert.h>
#include <stdlib.h>

static void geometry_test_point_creationAndDestruction(){
    {   
        double x = 1.345;
        double y = -123.0;
        geometry_point* point = geometry_point_new(x, y);
        assert(point != NULL);
        geometry_point_destroy(point);
    }

    {
        geometry_point* point = geometry_point_new(1.123, 0.576);
        assert(point != NULL);
        geometry_point_destroy(point);
    }

    {
        double y = -123.0;
        geometry_point* point = geometry_point_new(1.123, y);
        assert(point != NULL);
        geometry_point_destroy(point);
    }

    {
        double x = -123.0;
        geometry_point* point = geometry_point_new(x, 123.14);
        assert(point != NULL);
        geometry_point_destroy(point);
    }
}

static void geometry_test_point_getters(){
    {   
        double x = 1.345;
        double y = -123.0;
        geometry_point* point = geometry_point_new(x, y);
        // assert(point != NULL);
        assert(geometry_point_getX(point) == x);
        assert(geometry_point_getY(point) == y);
        geometry_point_destroy(point);
    }

    {
        geometry_point* point = geometry_point_new(1.123, 0.576);
        // assert(point != NULL);
        assert(geometry_point_getX(point) == 1.123);
        assert(geometry_point_getY(point) == 0.576);
        geometry_point_destroy(point);
    }

    {
        double y = -123.0;
        geometry_point* point = geometry_point_new(1.123, y);
        // assert(point != NULL);
        assert(geometry_point_getX(point) == 1.123);
        assert(geometry_point_getY(point) == y);
        geometry_point_destroy(point);
    }

    {
        double x = -123.0;
        geometry_point* point = geometry_point_new(x, 123.14);
        // assert(point != NULL);
        assert(geometry_point_getX(point) == x);
        assert(geometry_point_getY(point) == 123.14);
        geometry_point_destroy(point);
    }
}

static void geometry_test_point_move(){
    {
        double vector_x = 123123.1231;
        double vector_y = -324.345;
        double start_x = 234.6453;
        double start_y = 3453.345;
        geometry_point* point = geometry_point_new(start_x, start_y);
        geometry_point_moveByVector(point, vector_x, vector_y);
        assert(geometry_point_getX(point) == start_x + vector_x);
        assert(geometry_point_getY(point) == start_y + vector_y);
        geometry_point_destroy(point);
    }

    {
        double start_x = 0.0;
        double start_y = 123.097;
        geometry_point* point = geometry_point_new(start_x, start_y);
        geometry_point_moveByVector(point, 345.654, -0.001);
        assert(geometry_point_getX(point) == start_x + 345.654);
        assert(geometry_point_getY(point) == start_y - 0.001);
        geometry_point_destroy(point);
    }
}

static void geometry_test_segment_creationAndDestruciotn(){
    {
        geometry_point* start = geometry_point_new(1.123, 3.543);
        geometry_point* end = geometry_point_new(5.432, 6.0);
        geometry_segment* segment = geometry_segment_new(start, end);
        assert(segment != NULL);
        geometry_segment_destroy(segment);
        geometry_point_destroy(start);
        geometry_point_destroy(end);
    }

    {
        geometry_point* start = NULL;
        geometry_point* end = geometry_point_new(5.432, 6.0);
        geometry_segment* segment = geometry_segment_new(start, end);
        assert(segment == NULL);
        geometry_point_destroy(end);
    }

    {
        geometry_point* start = geometry_point_new(1.123, 3.543);
        geometry_point* end = NULL;
        geometry_segment* segment = geometry_segment_new(start, end);
        assert(segment == NULL);
        geometry_point_destroy(start);
    }

    {
        geometry_point* start = NULL;
        geometry_point* end = NULL;
        geometry_segment* segment = geometry_segment_new(start, end);
        assert(segment == NULL);
    }
}

static void geometry_test_segment_getters(){
    {
        geometry_point* start = geometry_point_new(1.123, 3.543);
        geometry_point* end = geometry_point_new(5.432, 6.0);
        geometry_segment* segment = geometry_segment_new(start, end);
        // assert(segment != NULL);
        geometry_point* got_start = NULL;
        geometry_point* got_end = NULL;
        geometry_segment_getPoints(segment, &got_start, &got_end);
        assert(got_start != NULL);
        assert(got_end != NULL);
        assert(geometry_point_getX(got_start) == geometry_point_getX(start));
        assert(geometry_point_getY(got_start) == geometry_point_getY(start));
        assert(geometry_point_getX(got_end) == geometry_point_getX(end));
        assert(geometry_point_getY(got_end) == geometry_point_getY(end));
        geometry_segment_destroy(segment);
        geometry_point_destroy(start);
        geometry_point_destroy(end);
    }

    {
        geometry_segment* segment = NULL;
        geometry_point* got_start = NULL;
        geometry_point* got_end = NULL;
        geometry_segment_getPoints(segment, &got_start, &got_end);
        assert(got_start == NULL);
        assert(got_end == NULL);
    }
}

static void geometry_test_segment_move(){
    {
        double start_x = 0.98734;
        double start_y = 123.32;
        double end_x = -123;
        double end_y = 90534.2;
        double vector_x = 123.412;
        double vector_y = 5.234;
        geometry_point* start = geometry_point_new(start_x, start_y);
        geometry_point* end = geometry_point_new(end_x, end_y);
        geometry_segment* segment = geometry_segment_new(start, end);
        geometry_segment_moveByVector(segment, vector_x, vector_y);
        geometry_point* got_start = NULL;
        geometry_point* got_end = NULL;
        geometry_segment_getPoints(segment, &got_start, &got_end);
        assert(geometry_point_getX(got_start) == start_x + vector_x);
        assert(geometry_point_getY(got_start) == start_y + vector_y);
        assert(geometry_point_getX(got_end) == end_x + vector_x);
        assert(geometry_point_getY(got_end) == end_y + vector_y);
        geometry_point_destroy(start);
        geometry_point_destroy(end);
        geometry_segment_destroy(segment);
    }

    {
        double start_x = 0.98734;
        double start_y = 123.32;
        double end_x = -123;
        double end_y = 90534.2;
        geometry_point* start = geometry_point_new(start_x, start_y);
        geometry_point* end = geometry_point_new(end_x, end_y);
        geometry_segment* segment = geometry_segment_new(start, end);
        geometry_segment_moveByVector(segment, 123.412, 5.234);
        geometry_point* got_start = NULL;
        geometry_point* got_end = NULL;
        geometry_segment_getPoints(segment, &got_start, &got_end);
        assert(geometry_point_getX(got_start) == start_x + 123.412);
        assert(geometry_point_getY(got_start) == start_y + 5.234);
        assert(geometry_point_getX(got_end) == end_x + 123.412);
        assert(geometry_point_getY(got_end) == end_y + 5.234);
        geometry_point_destroy(start);
        geometry_point_destroy(end);
        geometry_segment_destroy(segment);
    }
}

static void geometry_test_triangle_creationAndDestruction(){
    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, false);
        assert(triangle != NULL);
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = NULL;
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, false);
        assert(triangle == NULL);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = NULL;
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, false);
        assert(triangle == NULL);
        geometry_point_destroy(first);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = NULL;
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, false);
        assert(triangle == NULL);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
    }

    {
        geometry_triangle* triangle = geometry_triangle_new(NULL, NULL, NULL, false);
        assert(triangle == NULL);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, true);
        assert(triangle != NULL);
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = NULL;
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, true);
        assert(triangle == NULL);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = NULL;
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, true);
        assert(triangle == NULL);
        geometry_point_destroy(first);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = NULL;
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, true);
        assert(triangle == NULL);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
    }

    {
        geometry_triangle* triangle = geometry_triangle_new(NULL, NULL, NULL, true);
        assert(triangle == NULL);
    }
}


static void geometry_test_triangle_gettersPoints(){
    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, false);
        // assert(triangle != NULL);
        geometry_point* got_first = NULL;
        geometry_point* got_second = NULL;
        geometry_point* got_third = NULL;
        geometry_triangle_getPoints(triangle, &got_first, &got_second, &got_third);
        assert(got_first != NULL);
        assert(got_second != NULL);
        assert(got_third != NULL);
        assert(geometry_point_getX(got_first) == geometry_point_getX(first));
        assert(geometry_point_getY(got_first) == geometry_point_getY(first));
        assert(geometry_point_getY(got_second) == geometry_point_getY(second));
        assert(geometry_point_getY(got_second) == geometry_point_getY(second));
        assert(geometry_point_getY(got_third) == geometry_point_getY(third));
        assert(geometry_point_getY(got_third) == geometry_point_getY(third));
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, true);
        // assert(triangle != NULL);
        geometry_point* got_first = NULL;
        geometry_point* got_second = NULL;
        geometry_point* got_third = NULL;
        geometry_triangle_getPoints(triangle, &got_first, &got_second, &got_third);
        assert(got_first != NULL);
        assert(got_second != NULL);
        assert(got_third != NULL);
        assert(geometry_point_getX(got_first) == geometry_point_getX(first));
        assert(geometry_point_getY(got_first) == geometry_point_getY(first));
        assert(geometry_point_getY(got_second) == geometry_point_getY(second));
        assert(geometry_point_getY(got_second) == geometry_point_getY(second));
        assert(geometry_point_getY(got_third) == geometry_point_getY(third));
        assert(geometry_point_getY(got_third) == geometry_point_getY(third));
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* got_first = NULL;
        geometry_point* got_second = NULL;
        geometry_point* got_third = NULL;
        geometry_triangle_getPoints(NULL, &got_first, &got_second, &got_third);
        assert(got_first == NULL);
        assert(got_second == NULL);
        assert(got_third == NULL);
    }
}

static void geometry_test_triangle_gettersIsRight(){
    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        bool is_right = false;
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, is_right);
        // assert(triangle != NULL);
        bool got_is_right = geometry_triangle_getIsRight(triangle);
        assert(got_is_right == is_right);
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        geometry_point* first = geometry_point_new(1.123, 3.543);
        geometry_point* second = geometry_point_new(5.432, 6.0);
        geometry_point* third = geometry_point_new(3.5435, 109.511);
        bool is_right = true;
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, is_right);
        // assert(triangle != NULL);
        bool got_is_right = geometry_triangle_getIsRight(triangle);
        assert(got_is_right == is_right);
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }
}

static void geometry_test_triangle_move(){
    {
        double first_x = 1.123;
        double first_y = 24;
        double second_x = 0.123;
        double second_y = -0.423;
        double third_x = 90.32;
        double third_y = 12.543;
        double vector_x = 3.141592;
        double vector_y = 2.73;
        geometry_point* first = geometry_point_new(first_x, first_y);
        geometry_point* second = geometry_point_new(second_x, second_y);
        geometry_point* third = geometry_point_new(third_x, third_y);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, false);
        geometry_triangle_moveByVector(triangle, vector_x, vector_y);
        // assert(triangle != NULL);
        geometry_point* got_first = NULL;
        geometry_point* got_second = NULL;
        geometry_point* got_third = NULL;
        geometry_triangle_getPoints(triangle, &got_first, &got_second, &got_third);
        assert(geometry_point_getX(got_first) == first_x + vector_x);
        assert(geometry_point_getY(got_first) == first_y + vector_y);
        assert(geometry_point_getX(got_second) == second_x + vector_x);
        assert(geometry_point_getY(got_second) == second_y + vector_y);
        assert(geometry_point_getX(got_third) == third_x + vector_x);
        assert(geometry_point_getY(got_third) == third_y + vector_y);
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }

    {
        double first_x = 1.123;
        double first_y = 24;
        double second_x = 0.123;
        double second_y = -0.423;
        double third_x = 90.32;
        double third_y = 12.543;
        geometry_point* first = geometry_point_new(first_x, first_y);
        geometry_point* second = geometry_point_new(second_x, second_y);
        geometry_point* third = geometry_point_new(third_x, third_y);
        geometry_triangle* triangle = geometry_triangle_new(first, second, third, true);
        geometry_triangle_moveByVector(triangle, 3.141592, 2.73);
        // assert(triangle != NULL);
        geometry_point* got_first = NULL;
        geometry_point* got_second = NULL;
        geometry_point* got_third = NULL;
        geometry_triangle_getPoints(triangle, &got_first, &got_second, &got_third);
        assert(geometry_point_getX(got_first) == first_x + 3.141592);
        assert(geometry_point_getY(got_first) == first_y + 2.73);
        assert(geometry_point_getX(got_second) == second_x + 3.141592);
        assert(geometry_point_getY(got_second) == second_y + 2.73);
        assert(geometry_point_getX(got_third) == third_x + 3.141592);
        assert(geometry_point_getY(got_third) == third_y + 2.73);
        geometry_triangle_destroy(triangle);
        geometry_point_destroy(first);
        geometry_point_destroy(second);
        geometry_point_destroy(third);
    }
}


int main(){
    geometry_test_point_creationAndDestruction();
    geometry_test_point_getters();
    geometry_test_segment_creationAndDestruciotn();
    geometry_test_segment_getters();
    geometry_test_triangle_creationAndDestruction();
    geometry_test_triangle_gettersPoints();
    geometry_test_triangle_gettersIsRight();
    geometry_test_point_move();
    geometry_test_segment_move();
    geometry_test_triangle_move();
    return 0;
}
