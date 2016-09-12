// Created By Wenzy in 2016

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //载入音频
    sound.load("1.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
    //左右移动控制播放速度
    float speed = ofMap(mouseX,0,ofGetWidth(),0.1,3);
    sound.setSpeed(speed);
    
    //上下移动控制播放音量
    float vol = ofMap(mouseY, 0,ofGetHeight(), 0, 4);
    sound.setVolume(vol);
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //播放音频
    if(key == 'p'){
        sound.play();
    }
    //暂停音频
    if(key == 's'){
        sound.stop();
    }
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
