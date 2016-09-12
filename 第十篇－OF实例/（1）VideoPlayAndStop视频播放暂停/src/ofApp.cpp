// Created By Wenzy in 2016

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load("1.mov");
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    cout << video.isPlaying() << endl; // 获取视频的播放状态： 0：非播放（暂定） 1:播放
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0,0,1000,500);   // 位置x坐标,位置y坐标,视频宽度,视频长度
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'p'){
        video.play();  // 播放
    }
    if(key == 's'){
        video.setPaused(true);  // 暂停
    }
    if(key == 'd'){
        video.setPaused(false);  // 继续（播放）
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
