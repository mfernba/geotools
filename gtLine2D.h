//
//  gtLine2D.h
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//
//  Based on Geometric Tools for Computer Graphics by Dav H. Eberly
//

#ifndef gtLine2D_h
#define gtLine2D_h

#include "gtbuild.hxx"
#include "gtPoint2D.h"
#include "gtVec2D.h"
#include "gttypes.h"

struct gtLine2D_t
{
    struct gtPoint2D_t p;
    struct gtVec2D_t d;
};

DLL_GEOTOOLS struct gtLine2D_t gtLine2D_make_line_parametric(const struct gtPoint2D_t *point, const struct gtVec2D_t *direction);

DLL_GEOTOOLS struct gtLine2D_t gtLine2D_make_line_from_implicit_coeffs(double a, double b, double c);

DLL_GEOTOOLS struct gtLine2D_t gtLine2D_make_between_2_points(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2);

DLL_GEOTOOLS struct gtLine2D_t gtLine2D_copy(const struct gtLine2D_t *line);

DLL_GEOTOOLS void gtLine2D_get_implicit_coeffs(const struct gtLine2D_t *line, double *a, double *b, double *c);

#endif /* gtLine2D_h */
