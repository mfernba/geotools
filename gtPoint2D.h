//
//  gtPoint2D.h
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//
//  Based on Geometric Tools for Computer Graphics by Dav H. Eberly
//

#ifndef gtPoint2D_h
#define gtPoint2D_h

#include "gtbuild.hxx"

struct gtPoint2D_t
{
    double x, y;
};

DLL_GEOTOOLS struct gtPoint2D_t gtPoint2D_make(double x, double y);

DLL_GEOTOOLS struct gtPoint2D_t gtPoint2D_copy(const struct gtPoint2D_t *p);


DLL_GEOTOOLS double gtPoint2D_distance_from_p1_to_p2(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2);

DLL_GEOTOOLS void gtPoint2D_move(struct gtPoint2D_t *p, double dx, double dy);


#endif /* gtPoint2D_h */
