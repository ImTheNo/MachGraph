#include <QtGui>
#include <vector>
#include <cmath>

 #include "imageviewer.h"
 #include "filters.h"

 void ImageViewer::contrast()
 {
     long i, j;
     uint gist[NUM_INTENS] = { 0 };
     uchar intens_max_n = 0 , intens_min_n = NUM_INTENS - 1;
     std::vector<std::vector<uchar> > brightness(image.width(), std::vector<uchar>(image.height(), 0));
     if (SanityCheck()) 
     {
         return;
     }
//         QMessageBox::information(this, tr("Image Viewer"),
//                                  tr("Test"));

     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             QRgb tmp = image.pixel(i, j);
             brightness[i][j] = uchar(RED_W * qRed(tmp) + GREEN_W * qGreen(tmp) + BLUE_W * qBlue(tmp));
             gist[brightness[i][j]]++;
         }

     }
     for (i = 0; i < NUM_INTENS; i++) 
     {
         if (gist[i] > 0) 
         {
             intens_min_n = i;
             break;
         }
     }
     for (i = NUM_INTENS - 1; i >= 0; i--) 
     {
         if (gist[i] > 0) 
         {
             intens_max_n = i;
             break;
         }
     }
     if (intens_max_n <= intens_min_n) 
     {
         return;
     }
     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             if (brightness[i][j] == 0 || brightness[i][j] == NUM_INTENS - 1) 
             {
                 continue;
             }
             QRgb tmp = image.pixel(i, j);
             double conv = (brightness[i][j] - intens_min_n) * (NUM_INTENS - 1) / 
                           (brightness[i][j] * (intens_max_n - intens_min_n));
             int r, g, b;
             r = conv * qRed(tmp);
             r = NORM(r);
             g = conv * qGreen(tmp);
             g = NORM(g);
             b = conv * qBlue(tmp);
             b = NORM(b);
             image.setPixel(i, j, qRgb(r, g, b));
         }
     }
     updateLabel();
 }

 void ImageViewer::per_channel()
 {
     long i, j, k;
     uint gist[NUM_CH][NUM_INTENS] = { { 0 } };
     uchar intens_max_n[NUM_CH] = { 0 } , intens_min_n[NUM_CH] = { NUM_INTENS - 1, NUM_INTENS - 1, NUM_INTENS - 1};
     std::vector<std::vector<std::vector<uchar> > > brightness(NUM_CH, std::vector<std::vector<uchar> >(image.width(), std::vector<uchar>(image.height(), 0)));
     if (SanityCheck()) 
     {
         return;
     }

     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             QRgb tmp = image.pixel(i, j);
             brightness[0][i][j] = qRed(tmp);
             brightness[1][i][j] = qGreen(tmp);
             brightness[2][i][j] = qBlue(tmp);
             for (k = 0; k < NUM_CH; k++) 
             {
                 gist[k][brightness[k][i][j]]++;
             }
         }
     }
     for (k = 0; k < NUM_CH; k++) 
     {
        for (i = 0; i < NUM_INTENS; i++) 
         {
             if (gist[k][i] > 0) 
             {
                 intens_min_n[k] = i;
                 break;
             }
         }
         for (i = NUM_INTENS - 1; i >= 0; i--) 
         {
             if (gist[k][i] > 0) 
             {
                 intens_max_n[k] = i;
//         QMessageBox::information(this, tr("Image Viewer"),
//                                  tr("Max on %1 iteration is %2").arg(QString().setNum(k)).arg(QString().setNum(intens_max_n[k])));
                 break;
             }
         }
     }
     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             int chan[3];
             chan[0] = brightness[0][i][j];
             chan[1] = brightness[1][i][j];
             chan[2] = brightness[2][i][j];
             for (k = 0; k < NUM_CH; k++) 
             {
                 if (intens_max_n[k] <= intens_min_n[k] || brightness[k][i][j] == 0 || brightness[k][i][j] == NUM_INTENS - 1) 
                 {
                     continue;
                 }
                 chan[k] = ((chan[k] - intens_min_n[k]) * (NUM_INTENS - 1) / 
                           (chan[k] * (intens_max_n[k] - intens_min_n[k]))) * chan[k];
                 chan[k] = NORM(chan[k]);
             }
             image.setPixel(i, j, qRgb(chan[0], chan[1], chan[2]));
         }
     }
     updateLabel();
 }

 void ImageViewer::from_user_gaus_filter()
 {
     bool result;
     sigma = QInputDialog::getDouble(this, tr("Sigma definition"), tr("Sigma: "), sigma, 0.33, 7.0, 5, &result);
     if (!result) 
     {
         return;
     }
     gaus_filter(sigma);
 }
 void ImageViewer::gaus_filter(double sigma)
 {
     int size = 3 * sigma;
     int i, j, n;
     if (SanityCheck()) 
     {
         return;
     }
     size = size % 2 ? size : size + 1;
     n = size / 2;
     std::vector<std::vector<double> > filter(size, std::vector<double>(size, 0.0)); 

     for (i = 0; i <= n; i++) 
     {
         for (j = 0; j <= i; j++) 
         {
             filter[j + n][i + n] = filter[i + n][j + n] = gaus_dist(i, j, sigma);
         }
     }
     for (i = 0; i <= n; i++) 
     {
         for (j = 0; j <= n; j++) 
         {
             filter[-i + n][-j + n] = filter[-i + n][j + n] = 
             filter[i + n][-j + n] = filter[i + n][j + n]; 
         }
     }

     convolution(filter);
     updateLabel();
 }

 void ImageViewer::unsharp_filter()
 {
     int size = 3;
     int i, j, n, x, y;
     if (SanityCheck()) 
     {
         return;
     }
     n = size / 2;
     std::vector<std::vector<double> > filter(size, std::vector<double>(size, 0.0)); 

     for (i = 0, x = -n; i < size; i++, x++) 
     {
         for (j = 0, y = -n; j < size; j++, y++) 
         {
             filter[i][j] = (-alpha) * gaus_dist(x, y, 1);
         }
     }
     filter[n][n] += 1 + alpha;
     convolution(filter);
     updateLabel();
 }
 
 void ImageViewer::convolution(std::vector<std::vector<double> > & filter)
 {
     /* 
      * I supposed that my filter has (2n+1)*(2n+1) size
      * so i need to find out its center and numbers that
      * will be used to iterate throug it (-n, n)
      */
     int center = filter.size() / 2;
     int n = filter.size() / 2;
     int proc_i, proc_j; // index of currently processing point 
     double factor_sum = 0.0; //for normalizing
     uint i, j;
     for (i = 0; i < filter.size(); i++) 
     {
         for (j = 0; j < filter.size(); j++) 
         {
             factor_sum += filter[i][j];
         }
     }
     for (i = 0; i < filter.size(); i++) 
     {
         for (j = 0; j < filter.size(); j++) 
         {
             filter[i][j] /= factor_sum;
         }
     }
     for (proc_i = 0; proc_i < image.width(); proc_i++) 
     {
         for (proc_j = 0; proc_j < image.height(); proc_j++) 
         {
             /* in this place filter's weighs multiplied with
              * matching dots near (proc_i, proc_j)
              */
             double sum[NUM_CH] = {0.0};
             int filter_i = center - n; //index of weigh in filter, at this moment index is inverted
             int local_i = proc_i - n;
             while (filter_i <= center + n) 
             {
                 int filter_j = center - n;
                 int local_j = proc_j - n;

                 while (filter_j <= center + n) 
                 {
                     int x = local_i, y = local_j; // determining pixel position
                     /*  if pixel is "out" of image it's value is the same as 
                      *  the closest pixel that is "in" image
                      */
                     x = NORM_WITH(local_i, image.width()); 
                     y = NORM_WITH(local_j, image.height());
                     QRgb tmp = image.pixel(x, y);
                     //Now we have pixel, its weighs are filter[filter_i][filter_j]
                     sum[0] += filter[filter_i][filter_j] * qRed(tmp); 
                     sum[1] += filter[filter_i][filter_j] * qGreen(tmp); 
                     sum[2] += filter[filter_i][filter_j] * qBlue(tmp); 
                     filter_j++;
                     local_j++;
                 }
                 filter_i++;
                 local_i++;
             }
             image.setPixel(proc_i, proc_j, qRgb(NORM(sum[0]), NORM(sum[1]), NORM(sum[2])));
         }
     }
 }

 double static inline gaus_dist(double x, double y, double sigma) 
 {
     return std::exp((-(x * x + y * y)) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
 }
