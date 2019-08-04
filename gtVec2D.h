//
//  gtVec2D.h
//  geotools
//
//  Created by Manuel Fernández Baños on 15/7/19.
//  Copyright © 2019 Manuel Fernández Baños. All rights reserved.
//
//  Based on Geometric Tools for Computer Graphics by Dav H. Eberly
//

#ifndef gtVec2D_h
#define gtVec2D_h

#include "gtbuild.hxx"
#include "gttypes.h"

struct gtVec2D_t
{
    double Ux, Uy;
};

DLL_GEOTOOLS struct gtVec2D_t gtVec2D_make(double Ux, double Uy);

DLL_GEOTOOLS struct gtVec2D_t gtVec2D_make_betweem_two_points(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2);

DLL_GEOTOOLS struct gtVec2D_t gtVec2D_make_director_vector(const struct gtPoint2D_t *p1, const struct gtPoint2D_t *p2);

DLL_GEOTOOLS struct gtVec2D_t gtVec2D_copy(const struct gtVec2D_t *vector);

DLL_GEOTOOLS double gtVec2D_length(const struct gtVec2D_t *vector);

DLL_GEOTOOLS void gtVec2D_make_unit(struct gtVec2D_t *vector);


DLL_GEOTOOLS void gtVec2D_add_vector1_to_vector2(const struct gtVec2D_t *vector1, struct gtVec2D_t *vector2);

DLL_GEOTOOLS void gtVec2D_substract_vector1_to_vector2(const struct gtVec2D_t *vector1, struct gtVec2D_t *vector2);

DLL_GEOTOOLS void gtVec2D_scale(struct gtVec2D_t *vector, double scale_factor);

DLL_GEOTOOLS double gtVec2D_dot_product(const struct gtVec2D_t *vector1, const struct gtVec2D_t *vector2);

DLL_GEOTOOLS void gtVec2D_move_point(const struct gtVec2D_t *vector, struct gtPoint2D_t *point, double distance_along_vector);


#endif /* gtVec2D_h */
