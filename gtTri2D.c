//
//  gtTri2D.c
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//

#include "gtTri2D.h"

#include "gtassert.h"
#include "gtmath.h"
#include "gtPoint2D.h"
#include "gtTolerances.h"

// ------------------------------------------------------------------------------------------

struct gtTri2D_t gtTri2D_make(const struct gtPoint2D_t *p0, const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2)
{
    struct gtTri2D_t triangle;
    
    triangle.p0 = gtPoint2D_copy(p0);
    triangle.p1 = gtPoint2D_copy(p1);
    triangle.p2 = gtPoint2D_copy(p2);
    
    return triangle;
}

// ------------------------------------------------------------------------------------------

double gtTri2D_area(const struct gtTri2D_t *tri)
{
    double x0, y0, x1, y1, x2, y2;
    double area1, area2;
    
    assert(tri != NULL);
    
    x0 = tri->p0.x;
    y0 = tri->p0.y;

    x1 = tri->p1.x;
    y1 = tri->p1.y;

    x2 = tri->p2.x;
    y2 = tri->p2.y;

    area1 = 0.5 * ((x1 * y2 + y0 * x2 + x0 * y1) - (x1 * y0 - y1 * x2 - x0 * y2));
    area2 = 0.5 * (((x1 - x0) * (y2 - y0)) - ((x2 - x0) * (y1 - y0)));
    assert(fabs(area1 - area2) < 1.e-10);
    
    return area1;
}

// ------------------------------------------------------------------------------------------

enum gtTri2D_orientation_t gtTri2D_orientation(const struct gtTri2D_t *tri)
{
    double area;
    
    area = gtTri2D_area(tri);
    
    if (fabs(area) < GTTOLERANCES_DEGENERATE_TRIANGLE_AREA)
    {
        return GTTRI2D_ORIENTATION_DEGENERATE;
    }
    else if (area > 0.)
    {
        return GTTRI2D_ORIENTATION_COUNTERCLOCKWISE;
    }
    else
    {
        assert(area < 0.);
        return GTTRI2D_ORIENTATION_CLOCKWISE;
    }
}
