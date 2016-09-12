// Created By Wenzy in 2016

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load("1.mov");
    video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    time += 1.01;
    video.update();
  
// 速度 1：
//    video.setSpeed(3); // 播放速度 X 3
    
// 速度 2：
    video.setSpeed(0.5); // 播放速度 X 0.5
    
// 速度 3：
//    float speed = ofNoise(time) * 3; // noise控制
//    float speed = ofRandom(0.2,3); // random控制
//    cout << speed << endl;
//    video.setSpeed(speed);   //控制播放速度
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0,0,1000,500);   // 位置x坐标,位置y坐标,视频宽度,视频长度
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
