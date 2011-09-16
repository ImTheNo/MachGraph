#ifndef FILTERS_H
 #define FILTERS_H


 #define BMP "BMP" 
 #define BMP_FILE_FORMAT "BMP images (*.bmp)" 

 #define NUM_INTENS 256
 #define NUM_CH 3

 #define RED_W ((double)0.2125)
 #define GREEN_W ((double)0.7154)
 #define BLUE_W ((double)0.0721)

 #define NORM_WITH(a, border) ((a < 0) ? 0 : ((a > border - 1) ? border - 1 : (a))) 
 #define NORM(a) NORM_WITH(a, NUM_INTENS) 

 double static inline gaus_dist(double x, double y, double sigma);
#endif
