#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Struct For Circles //
typedef struct _circle_ {
  int x;
  int y;
  int radius;
} circle;

// Functions //
void do_circles_overlap(circle *tha_circleA, circle *tha_circleB);
circle makeCircle(int x, int y, int r);

// The Main //
int main() {
  int contLoop = 1;
  int ax, ay, ar, bx, by, br;

  while (contLoop) {
    printf("Circle A X is: ");
    scanf("%d", &ax);
    printf("Circle A Y is: ");
    scanf("%d", &ay);
    printf("Circle A Radius is: ");
    scanf("%d", &ar);
    
    printf("\n\n\n");

    printf("Circle B X is: ");
    scanf("%d", &bx);
    printf("Circle B Y is: ");
    scanf("%d", &by);
    printf("Circle B Radius is: ");
    scanf("%d", &br);

    printf("\n\n\n");

    circle circleA = makeCircle(ax, ay, ar);
    circle circleB = makeCircle(bx, by, br);

    do_circles_overlap(&circleA, &circleB);

    printf("Do U Want To Continue? (0 or 1)");
    scanf("%d", &contLoop);
    printf("\n\n\n");
  }
    
  return 0;
}

void do_circles_overlap(circle *tha_circleA, circle *tha_circleB) {
  printf("Circle A with center @(%d, %d) and radius %d and\n", 	tha_circleA->x, tha_circleA->y, tha_circleA->radius);
  printf("Circle B with center @(%d, %d) and radius %d ", 	tha_circleB->x, tha_circleB->y, tha_circleB->radius);
  
  double distX = pow((tha_circleA->x - tha_circleB->x), 2);
  double distY = pow((tha_circleA->y - tha_circleB->y), 2);
  double pyth	= sqrt(distX + distY);

  double radiusCom = tha_circleA->radius + tha_circleB->radius;

  if (radiusCom > pyth) {
    printf("DO overlap!\n");
  } else {
    printf("DO NOT overlap!\n");
  }
}

circle makeCircle(int x, int y, int r) {
  circle newCircle = {x, y, r};

  return newCircle;
}
