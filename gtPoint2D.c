//
//  gtPoint2D.c
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//
//  Based on Geometric Tools for Computer Graphics by Dav H. Eberly
//

#include "gtPoint2D.h"

#include "gtassert.h"
#include "gtmath.h"

// ------------------------------------------------------------------------------------------

struct gtPoint2D_t gtPoint2D_make(double x, double y)
{
    struct gtPoint2D_t p;
    
    p.x = x;
    p.y = y;
    
    return p;
}

// ------------------------------------------------------------------------------------------

struct gtPoint2D_t gtPoint2D_copy(const struct gtPoint2D_t *p)
{
    assert(p != NULL);
    return *p;
}

// ------------------------------------------------------------------------------------------

double gtPoint2D_distance_from_p1_to_p2(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2)
{
    double diff_x, diff_y;
    
    assert(p1 != NULL);
    assert(p2 != NULL);
    
    diff_x = p1->x - p2->x;
    diff_y = p1->y - p2->y;
    
    return gtmath_sqrt(diff_x * diff_x + diff_y * diff_y);
}

// ------------------------------------------------------------------------------------------

void gtPoint2D_move(struct gtPoint2D_t *p, double dx, double dy)
{
    assert(p != NULL);
    
    p->x += dx;
    p->y += dy;
}
