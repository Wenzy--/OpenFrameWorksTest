#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    num = 10000;
    for(int i = 0;i < num;i++){
        pos.push_back(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
        vel.push_back(ofPoint(ofRandom(0,10),ofRandom(0,10)));
        ofColor c;
        c.setHsb(ofRandom(0,255),255,255);
        col.push_back(c);
       // col.push_back(ofColor c = setHsb(ofRandom(0,255),255,255,50));
    }
    
    radius = 1;
    
    ofSetColor(255,0,0);
    rectW = 200;
    rectH = 50;
    
    gravity.set(0,0.1);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetBackgroundAuto(true);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0;i < num;i++){
        vel[i] += gravity;
        pos[i] += vel[i];
    }
    
    for(int i = 0;i < num;i++){
    
    
        if (pos[i].x + radius > ofGetWidth() || pos[i].x - radius < 0) {
            if(pos[i].x - radius < 0){
                pos[i].x = radius;
            }
            if(pos[i].x + radius > ofGetWidth()){
                pos[i].x = ofGetWidth() - radius;
            }
            vel[i].x *= -1;
        }
        
        if (pos[i].y + radius> ofGetHeight() || pos[i].y - radius < 0) {
            if(pos[i].y - radius < 0){
                pos[i].y = radius;
            }
            if(pos[i].y + radius > ofGetHeight()){
                pos[i].y = ofGetHeight() - radius;
            }

            vel[i].y *= -0.85;
        }
        
        if(pos[i].y  > mouseY - rectH/2 && pos[i].y < mouseY + rectH/2 &&(pos[i].x + radius > mouseX - rectW/2 && pos[i].x - radius < mouseX + rectW/2)){
            if(pos[i].x < mouseX){
                pos[i].x = mouseX - rectW/2 - radius;
            }else{
                pos[i].x = mouseX + rectW/2 + radius;
            }
            
             vel[i].x *= -1;
        }
        
        if(pos[i].x  > mouseX - rectW/2 && pos[i].x < mouseX + rectW/2 &&(pos[i].y + radius > mouseY - rectH/2 && pos[i].y - radius < mouseY + rectH/2)){
            
            if(pos[i].y < mouseY){
                pos[i].y = mouseY - rectH/2 - radius;
            }else{
                pos[i].y = mouseY + rectH/2 + radius;
            }
            
            vel[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    for(int i = 0;i < num;i++){
        ofSetColor(col[i]);
        ofCircle(pos[i], radius);
    }
    ofRect(mouseX,mouseY,rectW,rectH);
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
