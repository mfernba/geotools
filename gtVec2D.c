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

struct gtVec2D_t gtVec2D_copy(const struct gtVec2D_t *vector)
{
    struct gtVec2D_t other_vector;
    
    assert(vector != NULL);
    
    other_vector = *vector;
    
    return other_vector;
}

// ------------------------------------------------------------------------------------------

double gtVec2D_length(const struct gtVec2D_t *vector)
{
    assert(vector != NULL);
    return gtsqrt(vector->Ux * vector->Ux + vector->Uy * vector->Uy);
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

double gtVec2D_dot_product(const struct gtVec2D_t *vector1, const struct gtVec2D_t *vector2)
{
    assert(vector1 != NULL);
    assert(vector2 != NULL);
    
    return vector1->Ux * vector2->Ux + vector1->Uy * vector2->Uy;
}
