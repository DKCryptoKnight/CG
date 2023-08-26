#include <stdio.h>
#include <graphics.h>

void drawcircle(int x1, int y1, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;
    while (x >= y) {
        putpixel(x1 + x, y1 + y, 7);
        putpixel(x1 + y, y1 + x, 7);
        putpixel(x1 - y, y1 + x, 7);
        putpixel(x1 - x, y1 + y, 7);
        putpixel(x1 - x, y1 - y, 7);
        putpixel(x1 - y, y1 - x, 7);
        putpixel(x1 + y, y1 - x, 7);
        putpixel(x1 + x, y1 - y, 7);
        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        } else {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

int main() {
    int gd = DETECT, gm, error, x1, y1, radius;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    printf("Enter the center coordinates: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the radius: ");
    scanf("%d", &radius);
    drawcircle(x1, y1, radius);
    getch();
    closegraph();
    return 0;
}
