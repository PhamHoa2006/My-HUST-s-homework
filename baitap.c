/*

*/
#include <stdio.h>
#include <math.h>

void simulate_ball_motion(double M, double N, double x, double y, double r, double v, double alpha, double v_min, double t) {
    
    double alpha_rad = - alpha * 3.141592653589793 / 180.0;
    double v_x = v * cos(alpha_rad);
    double v_y = v * sin(alpha_rad);
 
    while (t > 0 && v >= v_min) { 

        double t_right = (v_x > 0) ? (N - r - x) / v_x : INFINITY;
        double t_left  = (v_x < 0) ? (0 + r - x) / v_x : INFINITY;
        double t_bottom = (v_y > 0) ? (M - r - y) / v_y : INFINITY;
        double t_top   = (v_y < 0) ? (0 + r - y) / v_y : INFINITY;

        double t_min = fmin(fmin(t_right, t_left), fmin(t_top, t_bottom));

        if (t_min > t) {
            x += v_x * t;
            y += v_y * t;
            break;
        }

       
        x += v_x * t_min;
        y += v_y * t_min;
        t -= t_min;

        if (t_min == t_right || t_min == t_left) { 
            v_x = -v_x;
        }
        if (t_min == t_top || t_min == t_bottom) {  
            v_y = -v_y;
        }
        v *= 0.9;
        v_x *= 0.9;
        v_y *= 0.9;  
    }

    printf("%.0lf, %.0lf",x,y);
}

int main() {
    double M, N, x, y, r, v, alpha, v_min, t;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&M,&N,&x,&y,&r,&v,&alpha,&v_min,&t);
    
    simulate_ball_motion(M, N, x, y, r, v, alpha, v_min, t);


    return 0;
}
