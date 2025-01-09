/*Description<br>
Trong một trò chơi đánh bóng 2D. Một quả bóng hình tròn tâm ở tọa độ x,y và bán kính r đang di chuyển trong hình chữ nhật tọa độ trên cùng bên trái và dưới cùng bên phải là 0,0 và M,N.<br>
Quả bóng di chuyển với tốc độ v (theo thời gian đơn vị) và góc di chuyển là alpha (góc theo độ tính theo trục ngang từ trái sang phải, góc phần tư thứ nhất sẽ là 0-90). Khi chạm vào biên (biên quả bóng chạm vào cạnh của khung hình chữ nhật), quả bóng sẽ bị bật lại theo đúng luật phản xạ, và tốc độ bị giảm đi 10%.<br>
Nếu tốc độ sau khi va chạm giảm xuống dưới 1 ngưỡng v_min thì quả bóng sẽ dừng lại.
<br>Giả sử trong quá trình di chuyển, tốc độ của quả bóng sẽ không thay đổi nếu không bị va chạm vào biên.
<br>Hãy tìm vị trí của quả bóng sau thời gian t đơn vị.

<br>Đầu vào sẽ là 
<br>+ M,N
<br>+ x, y
<br>+ r, v, alpha, v_min
<br>+ t
<br>Đầu ra sẽ là tọa độ của tâm quả bóng sau t đơn vị thời gian (lấy 0 chữ số thập phân)
<br>code
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
