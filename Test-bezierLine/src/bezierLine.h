//
//  bezierLine.h
//  bezierLine
//
//  Created by wenziyang on 15/10/29.
//
//
#include "ofMain.h"

class bezierLine{
public:
    bezierLine();
    
    void draw();
    void dragged(float a,float b);
    void pressed(float a,float b);
    void released();
   
    ofPoint pos[4];
    bool check[4];
};