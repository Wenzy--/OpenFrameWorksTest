#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(700,400);
    ofBackground(255);
    ofSetBackgroundAuto(false);
    r = 50;
    //brushDist = 10;
    brushDist = 10;
    brush.load("brush.png");
    brush.setAnchorPercent(0.5,0.5);
    
    
    gif.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    gif.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        ofBackground(255);
    }
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
    int brushNum;
    float dist = ofDist(mouseX, mouseY, lastX, lastY);
    float angle = atan2(mouseY - lastY,mouseX - lastX);
    
    if (dist > brushDist) {
        brushNum = int(dist/brushDist);
        float newX,newY;
        for (int i = 1; i <= brushNum; i++) {
            float length = i * brushDist;
            newX = lastX + cos(angle) * length;
            newY = lastY + sin(angle) * length;
            ofSetColor(0,150);
            ofPushMatrix();
            ofTranslate(newX,newY);
            ofRotate(ofRadToDeg(angle) + 90);
            brush.draw(0,0,r * 2,r * 2 * brush.getHeight()/(float)brush.getWidth());
            ofPopMatrix();
            
        }
        lastX = newX;
        lastY = newY;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (lastX == 0 && lastY == 0) {
        lastX = mouseX;
        lastY = mouseY;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    lastX = 0;
    lastY = 0;
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
