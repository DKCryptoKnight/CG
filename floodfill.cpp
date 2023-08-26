#include <stdio.h>
#include <graphics.h>

void floodfill(int x, int y, int newColor, int oldColor) {
  
  // If the pixel at (x, y) has the old color, then flood fill it with the new color.
  if (getpixel(x, y) == oldColor) {
    putpixel(x, y, newColor);
    floodfill(x + 1, y, newColor, oldColor);
    floodfill(x - 1, y, newColor, oldColor);
    floodfill(x, y + 1, newColor, oldColor);
    floodfill(x, y - 1, newColor, oldColor);
  }
}

int main() {
  // Initialize the graphics system.
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "c:\\turboc3\\bgi");

  // Set the drawing color to white.
  setcolor(WHITE);

  // Draw a rectangle.
  rectangle(100, 100, 200, 200);

  // Flood fill the rectangle with red.
  floodfill(150, 150, RED, BLACK);

  // Wait for the user to press a key.
  getch();

  // Close the graphics window.
  closegraph();

  return 0;
}

