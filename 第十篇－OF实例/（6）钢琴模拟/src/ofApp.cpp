// Created By Wenzy in 2016

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(700, 400);
    //载入音频
    sound1.load("do.wav");
    sound2.load("re.wav");
    sound3.load("mi.wav");
    sound4.load("fa.wav");
    sound5.load("so.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,214,79);
    ofSetRectMode(OF_RECTMODE_CENTER);
    float w = ofGetWidth() * 0.1;
    float h = ofGetHeight() * 0.8;
    
    if(key1){
        ofSetColor(255);
    }else{
        ofSetColor(238,145,117);
    }
    ofDrawRectangle(ofGetWidth()/6 , ofGetHeight()/2, w, h);
    
    if(key2){
        ofSetColor(255);
    }else{
        ofSetColor(246,96,100);
    }
    ofDrawRectangle(ofGetWidth()/6 * 2, ofGetHeight()/2, w, h);

    if(key3){
        ofSetColor(255);
    }else{
        ofSetColor(214,86,113);
    }
    ofDrawRectangle(ofGetWidth()/6 * 3, ofGetHeight()/2, w, h);

    if(key4){
        ofSetColor(255);
    }else{
        ofSetColor(124,60,131);
    }
    ofDrawRectangle(ofGetWidth()/6 * 4, ofGetHeight()/2, w, h);

    if(key5){
        ofSetColor(255);
    }else{
        ofSetColor(107,27,157);
    }
    ofDrawRectangle(ofGetWidth()/6 * 5, ofGetHeight()/2, w, h);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //播放音频
    if(key == 'a'){
        sound1.play();
        key1 = true;
    }
    if(key == 's'){
        sound2.play();
        key2 = true;
    }
    if(key == 'd'){
        sound3.play();
        key3 = true;
    }
    if(key == 'f'){
        sound4.play();
        key4 = true;
    }
    if(key == 'g'){
        sound5.play();
        key5 = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'a'){
        key1 = false;
    }
    if(key == 's'){
        key2 = false;
    }
    if(key == 'd'){
        key3 = false;
    }
    if(key == 'f'){
        key4 = false;
    }
    if(key == 'g'){
        key5 = false;
    }
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
