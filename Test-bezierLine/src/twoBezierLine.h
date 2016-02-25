//
//  twoBezierLine.h
//  bezierLine
//
//  Created by wenziyang on 15/10/29.
//
//
#include "ofMain.h"

class twobezierLine{
public:
    twobezierLine();
    
    void draw();
    void dragged(float a,float b);
    void pressed(float a,float b);
    void released();
    
    ofPoint pos[8];
    bool check[4];
    float line1,line2;
};