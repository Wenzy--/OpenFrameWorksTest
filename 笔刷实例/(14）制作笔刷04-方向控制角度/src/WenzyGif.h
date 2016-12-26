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
    ofxGifEncoder gifEncoder;
    ofImage screenImg;
    bool recordOnOff;
    
    void setup(){
        frameW  = 600; // 设置导出 gif 的宽
        frameH  = frameW * ofGetHeight()/(float)ofGetWidth(); // 高度自动原比例进行调整
        
        gifEncoder.setup(frameW, frameH, .25, 256);
        screenImg.allocate(frameW,frameH, OF_IMAGE_COLOR_ALPHA);
    }
    
    void update(){
        int ins = 3; // 影响导出的 gif 速度（间隔多少帧，截屏一次）
        if(ofGetFrameNum() % ins == 0 && recordOnOff){
            screenImg.grabScreen(0,0,ofGetWidth(),ofGetHeight());
            screenImg.resize(frameW,frameH);
            gifEncoder.addFrame(screenImg,1 /(60.0 / ins));
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
