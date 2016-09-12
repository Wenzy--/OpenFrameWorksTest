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
        ofDrawCircle(mouseX,mouseY,8);
    }
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
    if(x > 100 && x < 105){
        play1 = true;
    }
    if(x > 200 && x < 205){
        play2 = true;
    }
    if(x > 300 && x < 305){
        play3 = true;
    }
    if(x > 400 && x < 405){
        play4 = true;
    }
    if(x > 500 && x < 505){
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
