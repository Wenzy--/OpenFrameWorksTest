#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(700,400);
    ofBackground(255);
    ofSetBackgroundAuto(false);
    r = 50;
    brush.load("brush.png");
    brush.setAnchorPercent(0.5,0.5);
    
    gif.setup();
//    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);
//    fbo.begin();
//    ofBackground(255);
//    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    gif.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
   // fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    gif.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
   // fbo.begin();
    ofSetColor(0,150);
    brush.draw(mouseX,mouseY,r * 2,r * 2);
   // fbo.end();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
