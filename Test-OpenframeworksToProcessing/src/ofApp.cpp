#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // 读取文件
    ofBuffer buffer = ofBufferFromFile("ofApp.cpp");
    myStr = buffer.getText();
    
    newStr = replaceStr(myStr,"#include \"ofApp.h\""," ");
    newStr = replaceStr(newStr,"ofDrawRectangle","rect");
    newStr = replaceStr(newStr,"ofBackground","background");
    newStr = replaceStr(newStr,"ofSetWindowShape","size");
    newStr = replaceStr(newStr,"void ofApp::keyPressed(int key)","void keyPressed()");
    newStr = replaceStr(newStr,"void ofApp::keyReleased(int key)","void keyReleased()");
    newStr = replaceStr(newStr,"void ofApp::mouseMoved(int x, int y )","void mouseMoved()");
    newStr = replaceStr(newStr,"void ofApp::mouseDragged(int x, int y, int button)",
                         "void mouseDragged()");
    newStr = replaceStr(newStr,"void ofApp::mousePressed(int x, int y, int button)",
                        "void mousePressed()");
    newStr = replaceStr(newStr,"void ofApp::mouseReleased(int x, int y, int button)",
                        "void mouseReleased()");
    newStr = replaceStr(newStr,"void ofApp::mouseEntered(int x, int y)","void mouseEntered()");
    newStr = replaceStr(newStr,"void ofApp::mouseExited(int x, int y)","void mouseExited()");

    newStr = replaceStr(newStr,"void ofApp::windowResized(int w, int h){"," }"," ");
    newStr = replaceStr(newStr,"void ofApp::gotMessage(ofMessage msg){"," }"," ");
    newStr = replaceStr(newStr,"void ofApp::dragEvent(ofDragInfo dragInfo){"," }"," ");
    newStr = replaceStr(newStr,"void ofApp::","void ");
    
    ofBuffer msg(newStr.c_str(), newStr.length());
   
    // 导出为 pde 格式
    ofBufferToFile("p5export.pde", msg);
   
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
}


string ofApp::replaceStr(string loadStr,string keyWords,string replaceWords){
    string newStr;
    int num = 0; // 可统计词数
    for(int i = 0;i < loadStr.size();i++){
        // 激活标志
        bool match = true;
        if(loadStr[i] == keyWords[0]){
            for(int j = 1;j < keyWords.size();j++){
                if(loadStr[i + j] == keyWords[j]){
                    match = true;
                }else{
                    match = false;
                    j = keyWords.size();
                }
            }
        }else{
            match = false;
        }
        
        if(match){
            newStr.append(replaceWords);
            i += keyWords.size() - 1; // 作用是跳过
            num++;
        }else{
            string temp = ofToString(loadStr[i]);
            newStr.append(temp);
        }
    }
    cout << num << endl;
    return newStr;
}

string ofApp::replaceStr(string loadStr,string start,string end,string replaceWords){
    string newStr;
    int num = 0; // 可统计词数
    for(int i = 0;i < loadStr.size();i++){
        // 激活标志
        bool matchA = true;
        if(loadStr[i] == start[0]){
            for(int j = 1;j < start.size();j++){
                if(loadStr[i + j] == start[j]){
                    matchA = true;
                }else{
                    matchA = false;
                    j = start.size();
                }
            }
        }else{
            matchA = false;
        }
        
        if(matchA){
            i += start.size() - 1; // 作用是跳过
            
            // 寻找下一个标记,计算距离
            
            int index = 0;
            bool matchB = false;
            while(!matchB){
                index++;
                if(loadStr[i + index] == end[0]){
                    for(int j = 1;j < end.size();j++){
                        if(loadStr[i + index + j] == end[j]){
                            matchB = true;
                        }else{
                            matchB = false;
                            j = end.size();
                        }
                    }
                }else{
                    matchB = false;
                }
            }
            
            i += index + end.size() - 1;
            newStr.append(replaceWords);
            num++;
            
        }else{
            string temp = ofToString(loadStr[i]);
            newStr.append(temp);
        }
        
        
    }
    cout << num << endl;
    return newStr;
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
