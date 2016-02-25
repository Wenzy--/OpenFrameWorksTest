//
//  Circles.h
//  circleTest
//
//  Created by wenziyang on 16/1/26.
//
//

#ifndef Circles_h
#define Circles_h

class Circles{
public:
    float time,circleR,movingDist,speed,lineWidth;
    int num,resolution;
    bool colorMode,rotateMode;
    int shapeMode;
    
    void setup(){
        num = 35;
        circleR = 400;
        movingDist = 200;
        speed = 0.05;
        lineWidth = 1;
    }
    
    void update(){
        time+= speed;
    }
    
    void draw(){
        for(int i = 0;i < num;i++){
            ofNoFill();
           
            ofSetCircleResolution(resolution);
            ofSetLineWidth(lineWidth);
            float input = ofMap(i,0,num - 1,0,PI/2);
            float x = sin(time + i/10.0) * movingDist * (1 - i/(float)num);
            
            float y;
            if(rotateMode){
                y = 0;
            }else{
                y = cos(time + i/10.0) * movingDist * (1 - i/(float)num);
            }
            
            if(colorMode){
                ofSetColor(255,180);
            }else{
                ofSetColor(ofColor::fromHsb(i/(float)num * 255,255,255,200));
            }
            
            float r = sin(input) * circleR;
            
            if(shapeMode == 1){
                ofDrawCircle(ofGetWidth()/2 + x,ofGetHeight()/2 + y,r);
            }
            
            if(shapeMode == 2){
                ofDrawEllipse(ofGetWidth()/2 + x,ofGetHeight()/2 + y,r * sin(ofGetElapsedTimef() + i/50.0),r);
            }
            
            if(shapeMode == 3){
                ofPushMatrix();
                ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
                ofRotateY(ofGetFrameNum() * (num - i)/(float)num * speed * 30);
                ofDrawCircle(0,0,r);
                ofPopMatrix();
            }
        }
    }
};


#endif /* Circles_h */
