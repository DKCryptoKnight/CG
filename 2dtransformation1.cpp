#include <stdio.h>
#include <graphics.h>
#include <math.h>

void translate(int x[], int y[], int n, int tx, int ty) {
    int i;
    for(i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

void rotate(int x[], int y[], int n, float angle) {
    int i;
    float rad = angle * 3.14159 / 180;
    for(i = 0; i < n; i++) {
        int temp_x = x[i];
        int temp_y = y[i];
        x[i] = temp_x * cos(rad) - temp_y * sin(rad);
        y[i] = temp_x * sin(rad) + temp_y * cos(rad);
    }
}

void scale(int x[], int y[], int n, float sx, float sy) {
    int i;
    for(i = 0; i < n; i++) {
        x[i] = x[i] * sx;
        y[i] = y[i] * sy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    
    int x[] = {200, 300, 250};
    int y[] = {100, 100, 200};
    int n = 3;
    
    // Original triangle
    setcolor(WHITE);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    
    // Translation
    translate(x, y, n, 50, 50);
    setcolor(YELLOW);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    
    // Rotation
    rotate(x, y, n, 45);
    setcolor(RED);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    
    // Scaling
    scale(x, y, n, 1.5, 1.5);
    setcolor(BLUE);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    
    getch();
    closegraph();
    return 0;
}
