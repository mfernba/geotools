//
//  gtLine2D.c
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//
//  Based on Geometric Tools for Computer Graphics by Dav H. Eberly
//

#include "gtLine2D.h"

#include "gtassert.h"

// ------------------------------------------------------------------------------------------

struct gtLine2D_t gtLine2D_make_line(const struct gtPoint2D_t *point, const struct gtVec2D_t *direction)
{
    struct gtLine2D_t line;
    
    line.p = gtPoint2D_copy(point);
    line.v = gtVec2D_copy(direction);
    
    return line;
}

// ------------------------------------------------------------------------------------------

struct gtLine2D_t gtLine2D_make_between_2_points(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2)
{
    struct gtVec2D_t direction;
    
    direction = gtVec2D_make_director_vector(p1, p2);
    return gtLine2D_make_line(p1, &direction);
}

// ------------------------------------------------------------------------------------------

struct gtLine2D_t gtLine2D_copy(const struct gtLine2D_t *line)
{
    assert(line != NULL);
    return *line;
}
