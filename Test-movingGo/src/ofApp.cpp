// Created By Wenzy in 2016 .图片素材来源网络

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    board.load("board.jpg");
    float ratio = 0.5;
    board.resize(board.getWidth() * ratio,board.getHeight() * ratio);
    board.setAnchorPercent(0.5, 0.5);
    black.load("black.png");
    black.resize(black.getWidth() * ratio,black.getHeight() * ratio);
    black.setAnchorPercent(0.5, 0.5);
    white.load("white.png");
    white.resize(white.getWidth() * ratio,white.getHeight() * ratio);
    
    pic0.load("pic0.png");
    pic1.load("pic1.png");
    pic2.load("pic2.png");
    pic3.load("pic3.png");
    
    girdW = board.getWidth()/20.0;
    
    for(int i = 0;i < pic0.getWidth();i++){
        for(int j = 0;j < pic0.getHeight();j++){
            if((pic0.getColor(i, j).r) < 25 ){
                pos0.push_back(ofPoint(i,j));
            }
        }
    }

    for(int i = 0;i < pic1.getWidth();i++){
        for(int j = 0;j < pic1.getHeight();j++){
            if((pic1.getColor(i, j).r) < 25 ){
                pos1.push_back(ofPoint(i,j));
            }
        }
    }
    
    for(int i = 0;i < pic2.getWidth();i++){
        for(int j = 0;j < pic2.getHeight();j++){
            if((pic2.getColor(i, j).r) < 25 ){
                pos2.push_back(ofPoint(i,j));
            }
        }
    }
    
    for(int i = 0;i < pic3.getWidth();i++){
        for(int j = 0;j < pic3.getHeight();j++){
            if((pic3.getColor(i, j).r) < 25 ){
                pos3.push_back(ofPoint(i,j));
            }
        }
    }
    
    pos = pos0;
    showPic = true;
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
   
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    if(showPic){
        ofSetColor(255);
        board.draw(0,0);
    }
    
    for(int i = 0;i < pos.size();i++){
        black.draw(pos[i].x * girdW - board.getWidth()/2 + girdW,pos[i].y * girdW - board.getHeight()/2 + girdW);
    }
    moving();
}

void ofApp::moving(){
    if(run){
        
        //moving mode 1
        
        for(int i = 0;i < pos1.size();i++){
            if(mode == 0){
                pos[i] += (pos1[i] - pos[i]) * 0.06;
            }
            if(mode == 1){
                pos[i] += (pos2[i] - pos[i]) * 0.06;
            }
            if(mode == 2){
                pos[i] += (pos3[i] - pos[i]) * 0.06;
            }
            if(mode == 3){
                pos[i] += (pos0[i] - pos[i]) * 0.06;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        mode = 0;
        run = true;
    }
    if(key == 't'){
        mode = 1;
    }
    if(key == 'y'){
        mode = 2;
    }
    if(key == 'u'){
        mode = 3;
    }
    if(key == 's'){
        showPic = !showPic;
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
