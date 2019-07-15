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

struct gtLine2D_t gtLine2D_make_line_parametric(const struct gtPoint2D_t *point, const struct gtVec2D_t *direction)
{
    struct gtLine2D_t line;
    
    line.p = gtPoint2D_copy(point);
    line.d = gtVec2D_copy(direction);
    
    return line;
}

// ------------------------------------------------------------------------------------------

struct gtLine2D_t gtLine2D_make_line_from_implicit_coeffs(double a, double b, double c)
{
    double length;
    struct gtPoint2D_t p;
    struct gtVec2D_t d;
    
    length = a * a + b * b;
    assert(length > 0.);
    
    p.x = -a * c / length;
    p.y = -b * c / length;
    
    d = gtVec2D_make(-b, a);
    gtVec2D_make_unit(&d);
    
    return gtLine2D_make_line_parametric(&p, &d);
}

// ------------------------------------------------------------------------------------------

struct gtLine2D_t gtLine2D_make_between_2_points(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2)
{
    struct gtVec2D_t direction;
    
    direction = gtVec2D_make_director_vector(p1, p2);
    return gtLine2D_make_line_parametric(p1, &direction);
}

// ------------------------------------------------------------------------------------------

struct gtLine2D_t gtLine2D_copy(const struct gtLine2D_t *line)
{
    assert(line != NULL);
    return *line;
}

// ------------------------------------------------------------------------------------------

void gtLine2D_get_implicit_coeffs(const struct gtLine2D_t *line, double *a, double *b, double *c)
{
    assert(line != NULL);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    
    *a = -line->d.Uy;
    *b = line->d.Ux;
    *c = line->p.x * line->d.Uy - line->p.y * line->d.Ux;
}
