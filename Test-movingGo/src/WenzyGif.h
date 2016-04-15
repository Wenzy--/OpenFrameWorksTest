//
//  WenzyGif.h
//  mySketch
//
//  Created by wenziyang on 16/1/28.
//
//

#ifndef WenzyGif_h
#define WenzyGif_h

#include "ofxGifEncoder.h"

class WenzyGif{
public:
    int frameW, frameH;
    int nFrames;
    ofxGifEncoder gifEncoder;
    ofImage screenImg;
    bool recordOnOff,pressedB,showCutRect;
    
    void setup(){
        nFrames = 0;
        frameW  = 400;
        //frameH  = frameW * ofGetHeight()/(float)ofGetWidth();
        frameH  = 400;
        
        gifEncoder.setup(frameW, frameH, .25, 256);
        screenImg.allocate(frameW,frameH, OF_IMAGE_COLOR_ALPHA);
    }
    
    void update(){
        int ins = 3;
        if(ofGetFrameNum() % ins == 0 && recordOnOff){
            //当grabScreen不是从（0，0）点截，容易出问题
            // screenImg.grabScreen(cutStartPoint.x,cutStartPoint.y,cutEndPoint.x - cutStartPoint.x,cutEndPoint.y - cutStartPoint.y);
            screenImg.grabScreen(0,0,ofGetWidth(),ofGetHeight());
            
            screenImg.resize(frameW,frameH);
            gifEncoder.addFrame(screenImg,1 /(60.0 / ins));
            //gifEncoder.addFrame(screenImg,0.05);
        }
    }
    
    void draw(){
        if(showCutRect){
            ofNoFill();
            ofSetColor(255,100);
        }
    }
    
    void keyPressed(int key){
        if(key == 'b'){
            gifEncoder.reset();
            recordOnOff = true;
            cout << "press" << endl;
        }
        if(key == 's'){
            gifEncoder.save(ofToString(ofGetFrameNum()) + ".gif");
            recordOnOff = false;
        }
    }
    
    void exit(){
        gifEncoder.exit();
    }
    
};

#endif /* WenzyGif_h */
