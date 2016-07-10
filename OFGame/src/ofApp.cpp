#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(700,400);
    font.loadFont("font.otf",15);
    
    bottle.load("bottle.png");
    background.load("background.png");
    boss.load("boss.png");
    bone.load("bone.png");
    gold.load("gold.png");
    count = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // 绘制背景
    ofSetColor(255);
    background.draw(0,0,ofGetWidth(),ofGetHeight());
    
    // 绘制文字后的半透明背景
    ofSetColor(0,150);
    ofDrawRectangle(0, 250, 700, 80);
    ofDrawRectangle(0, 350, 700, 40);
    
    if(count == 0){
        ofSetColor(255);
        font.drawString("你為了尋找傳說中的寶藏，进入了黑暗森林。", 30,280);
        font.drawString("突然，你和你的小伙伴在路上看见一个神秘药瓶，你打算怎么做。", 30,310);
        ofSetColor(150,150,255);
        font.drawString("1.踢飞它", 30, 380);
        font.drawString("2.自己喝了", 180, 380);
        font.drawString("3.怂恿小伙伴喝了", 330, 380);
        
        ofSetColor(255);
        bottle.setAnchorPercent(0.5,0.5);
        bottle.draw(ofGetWidth()/2,ofGetHeight()/3,100,100);
    }
    
    
    if(count == 1){
        ofSetColor(255);
        font.drawString("水壶翻倒了，突然一股浓烟冒出。", 30,280);
        font.drawString("终极 Boss 直接出现到面前 …(⊙_⊙;)，你准备", 30,310);
        ofSetColor(150,150,255);
        font.drawString("1.情况不妙，闪", 30, 380);
        font.drawString("2.我是勇者我进攻！", 240, 380);
        font.drawString("3.陪它聊聊天", 500, 380);
        
        ofSetColor(255);
        boss.setAnchorPercent(0.5,0.5);
        boss.draw(ofGetWidth()/2,ofGetHeight()/3,100,100);
    }
    
    if(count == 2){
        ofSetColor(255);
        font.drawString("你感到力量无穷，同时受到宝藏的呼唤", 30,280);
        font.drawString("直接来到了终极 Boss 的面前，你准备", 30,310);
        ofSetColor(150,150,255);
        font.drawString("1.不啰嗦，直接进攻", 30, 380);
        font.drawString("2.陪它聊聊天", 250, 380);
        
        ofSetColor(255);
        boss.setAnchorPercent(0.5,0.5);
        boss.draw(ofGetWidth()/2,ofGetHeight()/3,100,100);
    }


    if(count == 3){
        ofSetColor(255);
        font.drawString("小伙伴痛苦地跪倒在地上。", 30,280);
        font.drawString("化身成终极 Boss 站到你的面前 …(⊙_⊙;)，你准备", 30,310);
        ofSetColor(150,150,255);
        font.drawString("1.情况不妙，闪", 30, 380);
        font.drawString("2.我是勇者我进攻！", 240, 380);
        font.drawString("3.陪它聊聊天", 500, 380);
        
        ofSetColor(255);
        boss.setAnchorPercent(0.5,0.5);
        boss.draw(ofGetWidth()/2,ofGetHeight()/3,100,100);
    }
    
    if(count == 4){
        ofSetColor(255,0,0);
        background.draw(0,0,ofGetWidth(),ofGetHeight());
        ofSetColor(255);
        font.drawString("你的速度太慢了，Boss 向你扔了一个火球", 30,280);
        font.drawString("由于巨大的实力差距，你挂了.....", 30,310);
        ofSetColor(150,150,255);
        ofSetColor(150,150,255);
        font.drawString("游戏结束", 30, 380);

        ofSetColor(255);
        bone.setAnchorPercent(0.5,0.5);
        bone.draw(ofGetWidth()/2,ofGetHeight()/3,100,100);
    }
    
    if(count == 5){
        ofSetColor(255);
        font.drawString("Boss 被你的气势打倒了", 30,280);
        font.drawString("宝藏出现", 30,310);
        ofSetColor(150,150,255);
        font.drawString("你和小伙伴带着宝藏逃离黑暗森林，通关成功！", 30, 380);
        
        ofSetColor(255);
        gold.setAnchorPercent(0.5,0.5);
        gold.draw(ofGetWidth()/2,ofGetHeight()/3,170,150);
    }
    
    if(count == 6){
        ofSetColor(255,0,0);
        background.draw(0,0,ofGetWidth(),ofGetHeight());
        ofSetColor(255);
        font.drawString("Boss 拒绝你的请求,并向你扔了个火球", 30,280);
        font.drawString("由于巨大的实力差距，你挂了.....", 30,310);
        ofSetColor(150,150,255);
        font.drawString("游戏结束", 30, 380);
       
        ofSetColor(255);
        bone.setAnchorPercent(0.5,0.5);
        bone.draw(ofGetWidth()/2,ofGetHeight()/3,100,100);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(count == 0){
        if(key == '1'){
            count = 1;
        }
        if(key == '2'){
            count = 2;
        }
        if(key == '3'){
            count = 3;
        }
    }else if(count == 1 || count == 3){
        if(key == '1'){
            count = 4;
        }
        if(key == '2'){
            count = 5;
        }
        if(key == '3'){
            count = 6;
        }
    }else if(count == 2){
        if(key == '1'){
            count = 5;
        }
        if(key == '2'){
            count = 6;
        }
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
