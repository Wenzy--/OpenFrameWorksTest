#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // 读取原始文件
    ofBuffer buffer = ofBufferFromFile("原始版.md");
    myStr = buffer.getText();
    
    // 文本替换测试
    reStr = replaceStr(myStr,"基本知识","今天");
    ofBuffer msg(reStr.c_str(), reStr.length());
    // 导出为 markdown 格式
    ofBufferToFile("字符替换测试.md", msg);

    // 导出 P5 版
    P5_Str = replaceStr(myStr,"-(OFbegin)","-(OFend)","");
    P5_Str = replaceStr(P5_Str,"-(P5begin)","");
    P5_Str = replaceStr(P5_Str,"-(P5end)","");
    
    P5_Str = replaceStr(P5_Str,"(OF:","*)","");
    P5_Str = replaceStr(P5_Str,"(P5:","");
    P5_Str = replaceStr(P5_Str,"*)","");
    
    ofBuffer msg1(P5_Str.c_str(), P5_Str.length());
    ofBufferToFile("Processing版.md", msg1);

    
    // 导出 OF 版
    OF_Str = replaceStr(myStr,"-(P5begin)","-(P5end)","");
    OF_Str = replaceStr(OF_Str,"-(OFbegin)","");
    OF_Str = replaceStr(OF_Str,"-(OFend)","");
   
    OF_Str = replaceStr(OF_Str,"(P5:","*)","");
    OF_Str = replaceStr(OF_Str,"(OF:","");
    OF_Str = replaceStr(OF_Str,"*)","");

    ofBuffer msg2(OF_Str.c_str(), OF_Str.length());
    ofBufferToFile("Openframeworks版.md", msg2);
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
