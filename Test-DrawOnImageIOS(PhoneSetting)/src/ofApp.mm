//  Created by Wenzy in 2016.

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetOrientation(OF_ORIENTATION_90_LEFT);
    r = 10;
    pic.load("phone.jpg");
    
    pic.resize(ofGetWidth(),ofGetHeight());
    //pic.resize(ofGetWidth(),ofGetWidth() * pic.getHeight()/(float)pic.getWidth());
    ofSetWindowShape(pic.getWidth(),pic.getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    time += 0.02;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //--- 设置1
    //    r = 10;
    //    time += 0.02;
    //    for(int i = 0;i < pos.size();i++){
    //        ofDrawCircle(pos[i],r * sin(time + i/10.0));
    //    }
    
    
    //--- 设置2
    ofSetColor(120);
    pic.draw(0,0);
    
    for(int i = 0;i < pos.size();i++){
        ofSetColor( pic.getColor(pos[i].x, pos[i].y));
        r = 2;
        ofDrawCircle(pos[i],r + r * sin(ofGetElapsedTimef() * 20 + i));
    }
}
//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
     pos.push_back(ofPoint(touch.x,touch.y));
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
