//
//  gtVec2D.c
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//
//  Based on Geometric Tools for Computer Graphics by Dav H. Eberly
//

#include "gtVec2D.h"

#include "gtassert.h"
#include "gtmath.h"
#include "gtPoint2D.h"

// ------------------------------------------------------------------------------------------

struct gtVec2D_t gtVec2D_make(double Ux, double Uy)
{
    struct gtVec2D_t vector;
    
    vector.Ux = Ux;
    vector.Uy = Uy;
    
    return vector;
}

// ------------------------------------------------------------------------------------------

struct gtVec2D_t gtVec2D_make_betweem_two_points(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2)
{
    double Ux, Uy;
    
    assert(p1 != NULL);
    assert(p2 != NULL);

    Ux = p2->x - p1->x;
    Uy = p2->y - p1->y;
    
    return gtVec2D_make(Ux, Uy);
}

// ------------------------------------------------------------------------------------------

struct gtVec2D_t gtVec2D_make_director_vector(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2)
{
    struct gtVec2D_t vec;
    
    vec = gtVec2D_make_betweem_two_points(p1, p2);
    gtVec2D_make_unit(&vec);
    
    return vec;
}

// ------------------------------------------------------------------------------------------

struct gtVec2D_t gtVec2D_copy(const struct gtVec2D_t *vector)
{
    assert(vector != NULL);
    return *vector;
}

// ------------------------------------------------------------------------------------------

double gtVec2D_length(const struct gtVec2D_t *vector)
{
    assert(vector != NULL);
    return gtmath_sqrt(vector->Ux * vector->Ux + vector->Uy * vector->Uy);
}

// ------------------------------------------------------------------------------------------

void gtVec2D_make_unit(struct gtVec2D_t *vector)
{
    double length;
    
    length = gtVec2D_length(vector);
    assert(length > 0.);
    
    vector->Ux /= length;
    vector->Uy /= length;
}

// ------------------------------------------------------------------------------------------

void gtVec2D_add_vector1_to_vector2(const struct gtVec2D_t *vector1, struct gtVec2D_t *vector2)
{
    assert(vector1 != NULL);
    assert(vector2 != NULL);
    
    vector2->Ux += vector1->Ux;
    vector2->Uy += vector1->Uy;
}

// ------------------------------------------------------------------------------------------

void gtVec2D_substract_vector1_to_vector2(const struct gtVec2D_t *vector1, struct gtVec2D_t *vector2)
{
    assert(vector1 != NULL);
    assert(vector2 != NULL);
    
    vector2->Ux -= vector1->Ux;
    vector2->Uy -= vector1->Uy;
}

// ------------------------------------------------------------------------------------------

void gtVec2D_scale(struct gtVec2D_t *vector, double scale_factor)
{
    assert(vector != NULL);
    
    vector->Ux *= scale_factor;
    vector->Uy *= scale_factor;
}

// ------------------------------------------------------------------------------------------

double gtVec2D_dot_product(const struct gtVec2D_t *vector1, const struct gtVec2D_t *vector2)
{
    assert(vector1 != NULL);
    assert(vector2 != NULL);
    
    return vector1->Ux * vector2->Ux + vector1->Uy * vector2->Uy;
}

// ------------------------------------------------------------------------------------------

double gtVec2D_angle_between_vectors(const struct gtVec2D_t *vector1, struct gtVec2D_t *vector2)
{
    double dot;
    
    dot = gtVec2D_dot_product(vector1, vector2);
    return gtmath_acos(dot);
}

// ------------------------------------------------------------------------------------------

void gtVec2D_move_point(const struct gtVec2D_t *vector, struct gtPoint2D_t *point, double distance_along_vector)
{
    assert(vector != NULL);
    gtPoint2D_move(point, vector->Ux * distance_along_vector, vector->Uy * distance_along_vector);
}
