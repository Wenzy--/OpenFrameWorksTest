// Created By Wenzy in 2016

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600, 400);
    ofBackground(255,214,79);
    ofSetBackgroundAuto(false);
    //载入音频
    sound1.load("do.wav");
    sound2.load("re.wav");
    sound3.load("mi.wav");
    sound4.load("fa.wav");
    sound5.load("so.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
    if(play1){
        sound1.play();
        play1 = false;
    }
    if(play2){
        sound2.play();
        play2 = false;
    }
    if(play3){
        sound3.play();
        play3 = false;
    }
    if(play4){
        play4 = false;
        sound4.play();
    }
    if(play5){
        play5 = false;
        sound5.play();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(isDragging){
        ofSetColor(107,27,157,100);
        ofSetLineWidth(10);
        ofDrawLine(mouseX,mouseY,lastMouseX,lastMouseY);
    }
    
    lastMouseX = mouseX;
    lastMouseY = mouseY;
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
    isDragging = true;
    if((mouseX - 100) * (lastMouseX - 100) < 0){
        play1 = true;
    }
    if((mouseX - 200) * (lastMouseX - 200) < 0){
        play2 = true;
    }
    if((mouseX - 300) * (lastMouseX - 300) < 0){
        play3 = true;
    }
    if((mouseX - 400) * (lastMouseX - 400) < 0){
        play4 = true;
    }
    if((mouseX - 500) * (lastMouseX - 500) < 0){
        play5 = true;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    isDragging = false;
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
