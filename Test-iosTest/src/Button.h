//
//  Button.h
//  DrawingTrainingTest
//
//  Created by wenziyang on 15/12/22.
//
//

//#include "ofxTrueTypeFontUC.h"

#ifndef Button_h
#define Button_h

class Button{
public:
    float x,y,w,h;
    ofRectangle buttonRect;
    bool over,active,pressedOnOff,display;
    ofColor buttonCol;
    ofColor normalCol = ofColor(60);
    ofColor pressCol = ofColor(90);
    ofColor strokeCol = ofColor(0,0);
    float fontSize;
    string words;
    bool run;
    int type;
    
    void setup(float centerX,float centerY,float w_,float h_){
        
        x = centerX - w_/2;
        y = centerY - h_/2;
        w = w_;
        h = h_;
        buttonRect.set(x,y,w,h);
       
        buttonCol = normalCol;
        active = false;
        display = true;
    }
    
    void update(float x,float y){
        if(display){
            if(buttonRect.inside(x,y)){
                over = true;
            }else{
                over = false;
            }
            if(active){
                buttonCol = pressCol;
            }else{
                buttonCol = normalCol;
            }
        }
    }
    
    void draw(){
        if(display){
            
            if(type != 4){
                ofFill();
                ofSetColor(buttonCol);
                ofDrawRectangle(buttonRect);
                
                ofNoFill();
                ofSetColor(strokeCol);
                ofDrawRectangle(buttonRect);
                
                
                ofRectangle fontRect;
                ofPoint fontPos = ofPoint(x + w/2,y + h/2);
              
                float fontX = fontPos.x - fontRect.getWidth()/2;
                float fontY = fontPos.y + fontRect.getHeight()/4;
                ofSetColor(255);
               // chineseFont.drawString(words,fontX,fontY);
            }else{
                
                ofFill();
                ofSetColor(buttonCol);
                //ofDrawRectangle(buttonRect);
                ofDrawCircle(buttonRect.getCenter().x,buttonRect.getCenter().y,buttonRect.getWidth()/2 * 1.3);
                
                ofNoFill();
                ofSetLineWidth(2);
                ofSetColor(strokeCol);
                ofSetCircleResolution(50);
                ofDrawCircle(buttonRect.getCenter().x,buttonRect.getCenter().y,buttonRect.getWidth()/2 * 1.3);
                
                float line = w * 0.65;

                ofDrawLine(x - line/2 + w/2,y - line/2 + w/2,x + line/2 + w/2,y + line/2 + w/2);
                ofDrawLine(x + line/2 + w/2,y - line/2 + w/2,x - line/2 + w/2,y + line/2 + w/2);
            }
        }
    }
    
    void mousePressed(int x,int y){
        if(display){
            if(buttonRect.inside(x,y)){
                active = true;
            }else{
                active = false;
            }
        }
    }
    
    void mouseDragged(int x,int y){
        if(display){
            if(buttonRect.inside(x,y)){
                active = true;
            }else{
                active = false;
            }
            over = false;
            
           
        }
    }
    
    void mouseReleased(int x,int y){
        if(display){
            active = false;
            if(buttonRect.inside(x,y)){
                pressedOnOff = true;
            }
        }
    }
};

//
//class Button{
//public:
//    BasicButton btn1,btn2,btn11,btnBack;
//    int screenPage;
//    
//    void setup(){
//        screenPage = 1;
//        btn1.display = true;
//        btn1.setup(ofGetWidth()/2,ofGetHeight() * 0.8,ofGetWidth() * 0.27,ofGetWidth() * 0.06,1);
//        btn11.display = false;
//        btn11.setup(ofGetWidth()/2,ofGetHeight() * 0.93,ofGetWidth() * 0.27,ofGetWidth() * 0.06,3);
//        btn2.display = true;
//        btn2.setup(ofGetWidth()/2,ofGetHeight() * 0.87,ofGetWidth() * 0.27,ofGetWidth() * 0.06,2);
//        btnBack.display = true;
//        btnBack.setup(ofGetWidth() * 0.06/2,ofGetHeight() - ofGetWidth() * 0.06/2,ofGetWidth() * 0.06,ofGetWidth() * 0.06,0);
//    }
//    
//    void update(float mX,float mY){
//        btn1.update(mX,mY);
//        btn2.update(mX,mY);
//        btn11.update(mX,mY);
//        btnBack.update(mX,mY);
//        
//        if(btn1.status != btn1.lastStatus){
//            screenPage = 2;
//            btn1.display = false;
//            btn2.display = false;
//            btn11.display = true;
//        }
//        if(btn2.status != btn2.lastStatus){
//            screenPage = 3;
//            btn1.display = false;
//            btn2.display = false;
//            btn11.display = false;
//        }
//        if(btnBack.status != btnBack.lastStatus){
//            screenPage = 1;
//            btn1.display = true;
//            btn2.display = true;
//            btn11.display = false;
//        }
//        
////        if(btn1.active == true){
////            screenPage = 2;
////            btn1.display = false;
////            btn2.display = false;
////            btn11.display = true;
////        }
////        if(btn2.active == true){
////            screenPage = 3;
////            btn1.display = false;
////            btn2.display = false;
////            btn11.display = false;
////        }
////        if(btnBack.active == true){
////            screenPage = 1;
////            btn1.display = true;
////            btn2.display = true;
////            btn11.display = false;
////        }
//    }
//    
//    void draw(){
//        btn1.draw();
//        btn11.draw();
//        btn2.draw();
//        btnBack.draw();
//    }
//    
//    void mousePressed(int x,int y){
//        btn1.mousePressed(x,y);
//        btn11.mousePressed(x,y);
//        btn2.mousePressed(x,y);
//        btnBack.mousePressed(x,y);
//    }
//    
//    void mouseDragged(int x,int y){
//        btn1.mouseDragged(x,y);
//        btn11.mouseDragged(x,y);
//        btn2.mouseDragged(x,y);
//        btnBack.mouseDragged(x,y);
//    }
//    
//    void mouseReleased(int x,int y){
//        btn1.mouseReleased(x,y);
//        btn11.mouseReleased(x,y);
//        btn2.mouseReleased(x,y);
//        btnBack.mouseReleased(x,y);
//    }
//};


#endif /* Button_h */
