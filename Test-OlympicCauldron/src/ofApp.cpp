#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 中央黄光
    light1.setPointLight();
    light1.enable();
    light1.setAmbientColor(ofFloatColor(0.05,0,0));
    light1.setAttenuation(1.0,0.00001,0.0000001);
    light1.setDiffuseColor(ofFloatColor(1,215.0/255.0,0));
    light1.setSpecularColor(ofFloatColor(0.2,0.2,0.2));
    light1.setPosition(0, 0, 0);
    
    // 红光
    light2.setPointLight();
    light2.enable();
    light2.setAmbientColor(ofFloatColor(0.07,0,0));
    light2.setAttenuation(1.0,0.0001,0.000001);
    light2.setDiffuseColor(ofFloatColor(1,0,0));
    light2.setSpecularColor(ofFloatColor(0.2,0.2,0.2));
    light2.setPosition(-700, 0, 0);
    
    // 红光
    light3.setPointLight();
    light3.enable();
    light3.setAmbientColor(ofFloatColor(0.07,0,0));
    light3.setAttenuation(1.0,0.0001,0.000001);
    light3.setDiffuseColor(ofFloatColor(1,0,0));
    light3.setSpecularColor(ofFloatColor(0.2,0.2,0.2));
    light3.setPosition(700, 0, 0);
    
    num = 30;
    lineVertexNum = 8;
    cam.setDistance(1600);  // 控制摄像头距离
}

//--------------------------------------------------------------
void ofApp::update(){
    num = ofGetMouseY()/(float)ofGetHeight() * 50;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetDepthTest(true);

    cam.begin();
    
    // 显示光源位置
    // light1.draw();
    // light2.draw();
    // light3.draw();

    // 显示坐标系统
    // ofDrawAxis(50);
    
    ofEnableLighting();
    ofPushMatrix();
    ofSetLineWidth(5);
    
    // 循环次数决定单个元件的旋转对称个数，写成 i < 1 则只呈现一个
    for(int i = 0;i < 4;i++){
        fireLine(90 * i);
    }
  
    ofPopMatrix();
    cam.end();
  
    // 显示当前帧速率
    ofDisableLighting();
    ofSetDepthTest(false);
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(), 20 ,ofGetHeight() - 20);
}

void ofApp::fireLine(float interval){
    ofPushMatrix();
    ofRotateY(90);
    ofSeedRandom(1);
    for(int j = 0;j < num;j++){
        ofPushMatrix();
        float angle = j/(float)num;
        ofRotateX(j/(float)num * 360);
        ofSetLineWidth(5);
        ofTranslate(0,400);
        
        float sinInterval,rotateInterval;
        // rotateInterval 决定每个旋转部件间的偏移量
        rotateInterval = 4 * ofGetMouseX()/(float)ofGetWidth();
        
        float speed = 60;  // 控制旋转速度
        
        ofRotate(-ofGetElapsedTimef() * speed + j/(float)num * 360 * rotateInterval + interval);
        
        for(int i = 0;i < lineVertexNum;i++){
            float l = 16 + 10 * i;
            float circleR = 15  - i * 1.5;
            if(i == lineVertexNum - 1){
                circleR = 40;
            }
            ofDrawLine(0,0,l,0);
            ofTranslate(l,0);
            ofPushMatrix();
            ofRotateY(90);
            if(i == lineVertexNum - 1){
                ofDrawCircle(0,0,circleR);
            }else{
                ofDrawSphere(0,0,circleR);
            }
            ofPopMatrix();
            ofRotate(sin(i/(float)lineVertexNum * 2 * PI) * 40);
        }
        ofPopMatrix();
    }
    ofPopMatrix();
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
