#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    circles.setup();
    gui.setup();
    gui.add(num.set("num",99,1,500));
    gui.add(speed.set("speed",0.1,0.001,0.8));
    gui.add(circleR.set("circleR",400,1,800));
    gui.add(movingDist.set("movingDist",50,1,1500));
    gui.add(resolution.set("resolution",100,3,100));
    gui.add(lineWidth.set("lineWidth",1,1,15));
    gui.add(shapeMode.set("shapeMode",1,1,5));
    gui.add(colorMode.setup("colorMode",true));
    gui.add(rotateMode.setup("rotateMode",true));
    showGui = true;
    
    gif.setup();
    cout << ofGetWidth() << ofGetHeight() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    circles.update();
    circles.num = num;
    circles.speed = speed;
    circles.circleR = circleR;
    circles.movingDist = movingDist;
    circles.resolution = resolution;
    circles.lineWidth = lineWidth;
    circles.shapeMode = shapeMode;
    circles.colorMode = colorMode;
    circles.rotateMode = rotateMode;
    
    gif.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    circles.draw();
    if(showGui){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'q'){
        showGui = !showGui;
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
