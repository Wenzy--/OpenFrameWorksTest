//
//  twoBezierLine.cpp
//  bezierLine
//
//  Created by wenziyang on 15/10/29.
//
//

#include "ofMain.h"
#include "twobezierLine.h"

twobezierLine::twobezierLine(){
    pos[0] = ofPoint(100,200);
    pos[1] = ofPoint(600,300);
    pos[2] = ofPoint(200,500);
    pos[3] = ofPoint(500,600);
    line1 = ofDist(pos[2].x,pos[2].y,pos[3].x,pos[3].y);
    cout << line1 << endl;
    line2 = 50;
    
    float angle = atan2(pos[3].y - pos[2].y,pos[3].x - pos[2].x);
    
    cout << angle << endl;
    
    pos[4] = pos[3];
    
    pos[5] = ofPoint(pos[4].x + line2 * cos(angle),pos[4].y + line2 * sin(angle));
  
    
    cout <<"Run"<<endl;

    //pos[5] = ofPoint(500,300);
    pos[6] = ofPoint(300,700);
    pos[7] = ofPoint(700,700);
    
     for(int i = 0;i < 8;i++){
         check[i] = false;
     }
}

void twobezierLine::dragged(float mX,float mY){
    
    
    for(int i = 0;i < 8;i++){
        if(check[i]){
            pos[i].x = mX;
            pos[i].y = mY;
            if(i == 2){
                float angle1 = atan2(pos[3].y - pos[2].y,pos[3].x - pos[2].x);
                pos[5].x = pos[3].x + line2 * cos(angle1);
                pos[5].y = pos[3].y + line2 * sin(angle1);
            }
            if(i == 5){
                float angle2 = atan2(pos[5].y - pos[4].y,pos[5].x - pos[4].x);
                pos[2].x = pos[3].x - line1 * cos(angle2);
                pos[2].y = pos[3].y - line1 * sin(angle2);
            }
        }
    }
}

void twobezierLine::pressed(float mX,float mY){
    for(int i = 0;i < 8;i++){
        if(ofDist(mX,mY,pos[i].x,pos[i].y) < 7){
            check[i] = true;
        }else{
            check[i] = false;
        }
    }
    cout << "press" <<endl;
}

void twobezierLine::released(){
    for(int i = 0;i < 8;i++){
        check[i] = false;
    }
    line1 = ofDist(pos[2].x,pos[2].y,pos[3].x,pos[3].y);
    line2 = ofDist(pos[4].x,pos[4].y,pos[5].x,pos[5].y);
}

void twobezierLine::draw(){
    ofBezier(pos[0].x,pos[0].y,pos[1].x,pos[1].y,pos[2].x,pos[2].y,pos[3].x,pos[3].y);
    ofBezier(pos[4].x,pos[4].y,pos[5].x,pos[5].y,pos[6].x,pos[6].y,pos[7].x,pos[7].y);
    float circleW = 4;
    for(int i = 0;i < 8;i++){
        ofFill();
        ofSetColor(255);
        ofCircle(pos[i],circleW);
    }
    ofSetColor(100);
    ofLine(pos[0].x,pos[0].y,pos[1].x,pos[1].y);
    ofLine(pos[3].x,pos[3].y,pos[2].x,pos[2].y);
    ofLine(pos[4].x,pos[4].y,pos[5].x,pos[5].y);
    ofLine(pos[7].x,pos[7].y,pos[6].x,pos[6].y);
}
