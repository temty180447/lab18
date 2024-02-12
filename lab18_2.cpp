#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2){

    if(R1->x + R1->w < R2->x || R2->x + R2->w < R1->x || R1->y + R1->h < R2->y || R2->y + R2->h < R1->y){ return 0; }
    double x_overlap = min(R1->x + R1->w, R2->x + R2->w) - max(R1->x, R2->x);
    double y_overlap = min(R1->y + R1->h, R2->y + R2->h) - max(R1->y, R2->y);
    
    if((R1->y-R1->h) < (R2->y-R2->h) && R1->y > R2->y){
        y_overlap = -(R2->y-R2->h);
    }
    
    return x_overlap * y_overlap;
}