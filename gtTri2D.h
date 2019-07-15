//
//  gtTri2D.h
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//

#ifndef gtTri2D_h
#define gtTri2D_h

#include "gtbuild.hxx"
#include "gttypes.h"
#include "gtPoint2D.h"

struct gtTri2D_t
{
    struct gtPoint2D_t p0;
    struct gtPoint2D_t p1;
    struct gtPoint2D_t p2;
};

enum gtTri2D_orientation_t
{
    GTTRI2D_ORIENTATION_CLOCKWISE,
    GTTRI2D_ORIENTATION_COUNTERCLOCKWISE,
    GTTRI2D_ORIENTATION_DEGENERATE
};

DLL_GEOTOOLS struct gtTri2D_t gtTri2D_make(const struct gtPoint2D_t *p0, const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2);

DLL_GEOTOOLS double gtTri2D_area(const struct gtTri2D_t *tri);

DLL_GEOTOOLS enum gtTri2D_orientation_t gtTri2D_orientation(const struct gtTri2D_t *tri);

#endif /* gtTri2D_h */
