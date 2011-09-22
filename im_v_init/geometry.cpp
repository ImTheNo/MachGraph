
 #include "geometry.h"
 #include "filters.h"
 #include <QDebug>

 void ImageViewer::rotate()
 {
     bool result;
     qreal x_real, y_real;
     int i, j, k, l;
     r_factor = QInputDialog::getDouble(this, tr("Scale factor"), tr("factor in radians: "), r_factor, -M_PI, M_PI, 10, &result);
     QPointF cen((image.width() - 1) / 2, (image.height() - 1) / 2);
     if (!result) 
     {
         return;
     }
     std::vector<std::vector<QRgb> > new_image(image.width(), std::vector<QRgb>(image.height(), qRgb(0, 0, 0))); 

     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             QRgb tmp[2][2];
             int r, g, b;
             bool flag = true; //if all coordinates valid get them
                 int y[2], x[2];
                 x[0] = x_real = ROTATE_X(i, j, cen.rx(), cen.ry(), (0 - r_factor));
                 x[1] = x[0] + 1;
                 y[0] = y_real = ROTATE_Y(i, j, cen.rx(), cen.ry(), (0 - r_factor));
                 y[1] = y[0] + 1;
                 for (k = 0; k < 2 && flag == true; k++) 
                 {
                     for (l = 0; l < 2 && flag == true; l++) 
                     {
                         if (x[k] < 0 || y[l] < 0 || x[k] > image.width() - 1 || y[l] > image.height() - 1) 
                         {
                             flag = false;
                         }
                         else
                         {
                             tmp[k][l] = image.pixel(x[k], y[l]);
                         }
                     }
                 }
             if (!flag) 
             {
                 continue;
             }
             r = BILIN(qRed, x_real, y_real, x, y, tmp);
             g = BILIN(qGreen, x_real, y_real, x, y, tmp);
             b = BILIN(qBlue, x_real, y_real, x, y, tmp);
             new_image[i][j] = qRgb(NORM(r), NORM(g), NORM(b));
         }
     }
     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             image.setPixel(i, j, new_image[i][j]);
         }
     }
     updateLabel();
 }
 void ImageViewer::scale()
 {
     bool result;
     int new_height, new_width;
     qreal step_x, step_y;
     qreal x_real, y_real;
     int i, j, k, l;
     factor = QInputDialog::getDouble(this, tr("Scale factor"), tr("factor: "), factor, 0.0, 2048.0, 10, &result);
     if (!result) 
     {
         return;
     }
     new_width = image.width() * factor;
     new_height = image.height() * factor;
     std::vector<std::vector<QRgb> > new_image(new_width, std::vector<QRgb>(new_height, qRgb(0, 0, 0))); 
      
     step_x = ((image.width() * factor) - 1) / (image.width() - 1);
     step_y = ((image.height() * factor) - 1) / (image.height() - 1);
     if (factor - 1.0 < EPS) 
     {
         gaus_filter(1.0);
     }
     for (i = 0; i < new_width; i++) 
     {
         int x[2] = {int(i / step_x), int(i / step_x + 1)}; 
         if (x[0] >= image.width() - 1) 
         {
             x[0]--;
             x[1]--;
         }
         x_real = i / step_x;
         for (j = 0; j < new_height; j++) 
         {
             // sqr array contains weighs for bilenear interpolation
             QRgb tmp[2][2];  
             int r, g, b;
             int y[2] = {int(j / step_y), int(j / step_y + 1) };
             if (y[0] >= image.height() - 1) 
             {
                 y[0]--;
                 y[1]--;
             }
             y_real = j / step_y;
             for (k = 0; k < 2; k++) 
             {
                 for (l = 0; l < 2; l++) 
                 {
                     tmp[k][l] = image.pixel(x[k], y[l]);
                 }
             }
             r = BILIN(qRed, x_real, y_real, x, y, tmp);
             g = BILIN(qGreen, x_real, y_real, x, y, tmp);
             b = BILIN(qBlue, x_real, y_real, x, y, tmp);
             new_image[i][j] = qRgb(r, g, b);
         }
     }
     x_real = (new_width - image.width()) / 2;
     y_real = (new_height - image.height()) / 2;
     for (i = 0; i < image.width(); i++) 
     {
         for (j = 0; j < image.height(); j++) 
         {
             int x_pos = x_real + i, y_pos = y_real + j;
             if (x_pos < 0 || y_pos < 0 || y_pos > new_height - 1 || x_pos > new_width - 1) 
             {
                 image.setPixel(i, j, qRgb(0, 0, 0));
             }
             else
             {
                 image.setPixel(i, j, new_image[x_real + i][y_real + j]);
             }
         }
     }
     updateLabel();
 }
