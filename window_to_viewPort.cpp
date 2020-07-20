#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define f 0.3
#define projection_angle 45
void show_screen();
void apply_rotation_along_x_axis(const int[5][3], const int);
void multiply_matrices(const float[4], const float[4][4], float[4]);
void draw_tetrahedron(int[5][3]);
void get_projected_point(int &, int &, int &);
void Line(const int, const int, const int, const int);
int main()
{
   int driver = VGA;
   int mode = VGAHI;
   initgraph(&driver, &mode, "..\\\\Bgi");

   show_screen();

   int tetrahedron[5][3] = {
       {280, 130, 50},  //  base front left
       {360, 130, 50},  //  base front right
       {360, 130, -50}, //  base back right
       {280, 130, -50}, //  base back left
       {320, 20, 0}     //  top
   };

   setcolor(15);
   draw_tetrahedron(tetrahedron);
   int angle = 0;
   int key_code = 0;

   char Key = NULL;

   do
   {
      Key = NULL;
      key_code = 0;
      Key = getch();
      key_code = int(Key);
      if (key_code == 0)
      {
         Key = getch();
         key_code = int(Key);
      }
      if (key_code == 27)
         break;
      else if (key_code == 43)
         angle -= 5;
      else if (key_code == 45)
         angle += 5;
      setfillstyle(1, 0);
      bar(40, 70, 600, 410);
      apply_rotation_along_x_axis(tetrahedron, angle);
   } while (1);

   return 0;
}
//------------------------  Funcion Definitions  ------------------------//
//-------------------  apply_rotation_along_x_axis( )  ------------------//
void apply_rotation_along_x_axis(const int control_points[5][3], const int theta)
{
   int edge_points[5][3] = {0};
   float angle = (theta * (M_PI / 180));
   for (int count = 0; count < 5; count++)
   {
      edge_points[count][0] = control_points[count][0];
      edge_points[count][1] = control_points[count][1];
      edge_points[count][2] = control_points[count][2];
      float matrix_a[4] = {edge_points[count][0], edge_points[count][1], edge_points[count][2], 1};
      float matrix_b[4][4] = {
          {1, 0, 0, 0},
          {0, cos(angle), sin(angle), 0},
          {0, -sin(angle), cos(angle), 0},
          {0, 0, 0, 1}};
      float matrix_c[4] = {0};
      multiply_matrices(matrix_a, matrix_b, matrix_c);
      edge_points[count][0] = (int)(matrix_c[0] + 0.5);
      edge_points[count][1] = (int)(matrix_c[1] + 0.5);
      edge_points[count][2] = (int)(matrix_c[2] + 0.5);
   }
   setcolor(10);
   draw_tetrahedron(edge_points);
}

/************************************************************************/
//----------------------  multiply_matrices( )  ------------------------//
/************************************************************************/

void multiply_matrices(const float matrix_1[4], const float matrix_2[4][4], float matrix_3[4])
{
   for (int count_1 = 0; count_1 < 4; count_1++)
   {
      for (int count_2 = 0; count_2 < 4; count_2++)
         matrix_3[count_1] +=
             (matrix_1[count_2] * matrix_2[count_2][count_1]);
   }
}

/************************************************************************/
//--------------------------  draw_tetrahedron( )  -------------------------//
/************************************************************************/

void draw_tetrahedron(int points[5][3])
{
   int edge_points[5][3];

   for (int i = 0; i < 5; i++)
   {
      edge_points[i][0] = points[i][0];
      edge_points[i][1] = points[i][1];
      edge_points[i][2] = points[i][2];

      get_projected_point(edge_points[i][0],
                          edge_points[i][1], edge_points[i][2]);

      edge_points[i][1] += 240;
   }

   Line(edge_points[0][0], edge_points[0][1],
        edge_points[1][0], edge_points[1][1]);
   Line(edge_points[1][0], edge_points[1][1],
        edge_points[2][0], edge_points[2][1]);
   Line(edge_points[2][0], edge_points[2][1],
        edge_points[3][0], edge_points[3][1]);
   Line(edge_points[3][0], edge_points[3][1],
        edge_points[0][0], edge_points[0][1]);

   Line(edge_points[0][0], edge_points[0][1],
        edge_points[4][0], edge_points[4][1]);
   Line(edge_points[1][0], edge_points[1][1],
        edge_points[4][0], edge_points[4][1]);
   Line(edge_points[2][0], edge_points[2][1],
        edge_points[4][0], edge_points[4][1]);
   Line(edge_points[3][0], edge_points[3][1],
        edge_points[4][0], edge_points[4][1]);
}

/************************************************************************/
//---------------------  get_projected_point( )  -----------------------//
/************************************************************************/

void get_projected_point(int &x, int &y, int &z)
{
   float fcos0 = (f * cos(projection_angle * (M_PI / 180)));
   float fsin0 = (f * sin(projection_angle * (M_PI / 180)));

   float Par_v[4][4] = {
       {1, 0, 0, 0},
       {0, 1, 0, 0},
       {fcos0, fsin0, 0, 0},
       {0, 0, 0, 1}};

   float xy[4] = {x, y, z, 1};
   float new_xy[4] = {0};

   multiply_matrices(xy, Par_v, new_xy);

   x = (int)(new_xy[0] + 0.5);
   y = (int)(new_xy[1] + 0.5);
   z = (int)(new_xy[2] + 0.5);
}

//-------------------------------  Line( )  -----------------------------//

void Line(const int x_1, const int y_1, const int x_2, const int y_2)
{
   int color = getcolor();

   int x1 = x_1;
   int y1 = y_1;

   int x2 = x_2;
   int y2 = y_2;

   if (x_1 > x_2)
   {
      x1 = x_2;
      y1 = y_2;

      x2 = x_1;
      y2 = y_1;
   }

   int dx = abs(x2 - x1);
   int dy = abs(y2 - y1);
   int inc_dec = ((y2 >= y1) ? 1 : -1);

   if (dx > dy)
   {
      int two_dy = (2 * dy);
      int two_dy_dx = (2 * (dy - dx));
      int p = ((2 * dy) - dx);

      int x = x1;
      int y = y1;

      putpixel(x, y, color);

      while (x < x2)
      {
         x++;

         if (p < 0)
            p += two_dy;

         else
         {
            y += inc_dec;
            p += two_dy_dx;
         }

         putpixel(x, y, color);
      }
   }

   else
   {
      int two_dx = (2 * dx);
      int two_dx_dy = (2 * (dx - dy));
      int p = ((2 * dx) - dy);

      int x = x1;
      int y = y1;

      putpixel(x, y, color);

      while (y != y2)
      {
         y += inc_dec;

         if (p < 0)
            p += two_dx;

         else
         {
            x++;
            p += two_dx_dy;
         }

         putpixel(x, y, color);
      }
   }
}

//--------------------------  show_screen( )  ---------------------------//

void show_screen()
{
   setfillstyle(1, 1);
   bar(210, 26, 420, 38);

   settextstyle(0, 0, 1);
   setcolor(15);
   outtextxy(5, 5, "******************************************************************************");
   outtextxy(5, 17, "*-**************************************************************************-*");
   outtextxy(5, 29, "*-----------------------                             ------------------------*");
   outtextxy(5, 41, "*-**************************************************************************-*");
   outtextxy(5, 53, "*-**************************************************************************-*");

   setcolor(11);
   outtextxy(218, 29, "3D Rotation along X-axis");
   setcolor(15);

   for (int count = 0; count <= 30; count++)
      outtextxy(5, (65 + (count * 12)), "*-*                                                                      *-*");
   outtextxy(5, 438, "*-**************************************************************************-*");
   outtextxy(5, 450, "*-------------------------                          -------------------------*");
   outtextxy(5, 462, "******************************************************************************");
   setcolor(12);
   outtextxy(229, 450, "Press any Key to exit.");
}