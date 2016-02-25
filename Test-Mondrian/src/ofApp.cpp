#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    float h = ofGetHeight();
    float w = ofGetWidth();
    
    ofPoint A = ofPoint(0,0);
    ofPoint B = ofPoint(0,h);
    ofPoint C = ofPoint(w,h);
    ofPoint D = ofPoint(w,0);
    
    fractal(A,B,C,D,0);
}

void ofApp::fractal(ofPoint A,ofPoint B,ofPoint C,ofPoint D,int num){
    num += 10;
    
    ofColor red = ofColor(255,25,19);
    ofColor yellow = ofColor(255,224,19);
    ofColor blue = ofColor(42,17,240);
    
    if(min((B-A).y,(C-B).x) > 20){

        float chose = ofNoise(ofGetFrameNum()/200.0 + num * 4);
      
        if(chose > 0 && chose < 0.3){
            ofSetColor(red);
        }else if(chose > 0.4 && chose < 0.55){
            ofSetColor(255);
        }else if(chose > 0.55 && chose < 0.65){
            ofSetColor(yellow);
        }else{
            ofSetColor(blue);
        }
        
        
        ofFill();
        ofBeginShape();
        ofVertex(A);
        ofVertex(B);
        ofVertex(C);
        ofVertex(D);
        ofEndShape();
        
        ofNoFill();
        ofSetLineWidth(50);
        ofSetColor(0);

        ofBeginShape();
        ofVertex(A);
        ofVertex(B);
        ofVertex(C);
        ofVertex(D);
        ofVertex(A);
        ofEndShape();
        
       
        
        float ratio = ofMap(ofNoise(ofGetFrameNum()/100.0 + num * 4),0,1,0,1);
        
        //float ratio = ofMap(mouseX + 100 * ofNoise(ofGetFrameNum()/100.0) ,0,ofGetWidth(),0.1,0.9);
        int model = int(ofNoise(ofGetFrameNum()/100.0 + num) * 2);
        
        float sideP = 0.8; //draw other side
        
        if(model == 0){
            ofPoint E = A + (D - A) * ratio;
            ofPoint F = B + (C - B) * ratio;
            if(ratio > 0.5){
                fractal(A,B,F,E,num);
                if(ofNoise(ofGetFrameNum()/100.0 + num)> sideP){
                   fractal(E,F,C,D,num);
                }
                
                
            }else{
                fractal(E,F,C,D,num);
                if(ofNoise(ofGetFrameNum()/100.0 + num)> sideP){
                   fractal(A,B,F,E,num);
                }
            }
        }
        
        if(model == 1){
            ofPoint E = A + (B - A) * ratio;
            ofPoint F = D + (C - D) * ratio;
            if(ratio > 0.5){
                fractal(A,E,F,D,num);
                if(ofNoise(ofGetFrameNum()/100.0 + num)> sideP){
                    fractal(E,B,C,F,num);
                }
            }else{
                fractal(E,B,C,F,num);
                if(ofNoise(ofGetFrameNum()/100.0 + num)> sideP){
                    fractal(A,E,F,D,num);
                }
            }
        }
    }
}

void ofApp::emptyFunction(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
