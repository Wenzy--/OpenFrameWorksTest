//
//  bezierLine.cpp
//  bezierLine
//
//  Created by wenziyang on 15/10/29.
//
//

#include "bezierLine.h"

bezierLine::bezierLine(){
    pos[0] = ofPoint(100,200);
    pos[1] = ofPoint(600,300);
    pos[2] = ofPoint(200,500);
    pos[3] = ofPoint(600,600);
}

void bezierLine::dragged(float mX,float mY){
    for(int i = 0;i < 4;i++){
        if(check[i]){
            pos[i].x = mX;
            pos[i].y = mY;
        }
    }
}

void bezierLine::pressed(float mX,float mY){
    for(int i = 0;i < 4;i++){
        if(ofDist(mX,mY,pos[i].x,pos[i].y) < 50){
            check[i] = true;
        }
    }
}

void bezierLine::released(){
    for(int i = 0;i < 4;i++){
        check[i] = false;
    }
}


void bezierLine::draw(){
    ofBezier(pos[0].x,pos[0].y,pos[1].x,pos[1].y,pos[2].x,pos[2].y,pos[3].x,pos[3].y);
    float circleW = 5;
    for(int i = 0;i < 4;i++){
       ofFill();
       ofSetColor(50 + 50 * i);
       ofCircle(pos[i],circleW);
    }
}
