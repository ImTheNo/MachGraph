#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtGui>
#include <vector>
#include <cmath>

 #include "imageviewer.h"

#define BILIN(func, x0, y0, x, y, sqr) (func(sqr[0][0]) * (x[1] - x0)* (y[1] - y0) + \
                        func(sqr[1][0]) * (x0 - x[0])* (y[1] - y0) + \
                        func(sqr[0][1]) * (x[1] - x0)* (y0 - y[0]) + \
                        func(sqr[1][1]) * (x0 - x[0])* (y0 - y[0]))
#define EPS 1E-5

#define ROTATE_X(x, y, x0, y0, factor) (((x) - x0) * cos(factor) + ((y) - y0) * sin(factor) + x0)
#define ROTATE_Y(x, y, x0, y0, factor) ((-1) * ((x) - x0) * sin(factor) + ((y) - y0) * cos(factor) + y0)
#endif
