//
//  wzyFont.h
//  font
//
//  Created by wenziyang on 16/2/7.
//
//


/*
 
    同时兼容英文字，中文字显示。可作为标题，按钮字体元素等
 
    字体基本属性：
            size            字体大小比例，以屏幕宽作为标准（便于适配）
            fontSize        等价于 size 的值，表示字体大小。属于对象中的属性
            fontPos         字体位置坐标
            letterSpacing   字体间距
            fontType        字体类型  0:苹方中字 1:ArialBlack英字

 
    常用函数说明：
            draw (x,y)                      显示字体：x,y 表位置
            draw (str,x,y)                  显示字体：str 字符，x,y 表位置
            drawFontBackground(rise)        显示字体大小的矩形背景,rise 设置边界的扩展程度
 
            drawVectorOutLine
 
    设计说明：
            (1)需要存在 spacingShift 来修正因为字体间距过大而带来的偏移。假设字符有 4 个，字符大小为 100 像素，间距为 2.
            则获取的整个 StringBoundingBox 的长度为 750 像素左右.后面会带有 50 像素的空隙（不同字体有所区别），而显得不是完全居中，需要往右移动_间距 - 1)／2 的单位,即 (letterSpacing - 1)/2
            (2) 但若是中文字符，中英混输，以英文字符结尾，后面是不会出现间距的，此类情况比较麻烦。应该避免，建议中字都显中文，英字都显英文
 
            用 fontRect.getHeight() 作为单个字符的宽度来计算间距比使用 ofGetWidth() * fontSize 更准确，但仍然存在一定误差
 
            spacingShift 的值会同时修正 BoundingBox 绘制的矩形
 
            (3) 中文字体高度是有偏差的，不同的字体，偏差数值不同。一般中文偏差更大，用折衷的办法估算为 fontRect.getHeight() * 0.36 ，英文自己仍采用 fontRect.getHeight() * 0.5
            (4) 一个有助于理解字体间距的经验，字体之间的间距并不是固定的，似乎是根据字符本身的宽度得出的，像 L 的间距，就比 i 的间距大得多
 
    模块存在的不足：
            （1）中文字体有偏移问题,需要靠局部变量 shift 来修正
                经测试，同款字体，偏移是相对值。
                假设字体大小为 100 像素，偏移量可能为百分之五，即偏移 5 像素。不随字体的数量增多而增多
 
            （2）中文字体若是中英混输，即使寻找到在中文字体下正确的偏移比例，在英文字体都会发生不可避免的误差
                若后期不嫌麻烦，可以再测试一个英文偏移值出来，此值貌似也是固定比例
 
            （3）后面发现，即使是中文字，这个 shift 值也不是完全固定的。例如 “中文” 和 “混沌”，两个的偏移值多不同
            （4） 结论，除非偏差特别严重，默认不设置 shift 的大小。若像精确微调，则可设置
 
    使用建议：
            在字体较小，可以使用 space 做动画或是设置。但一旦间距大，就独立将每个字符当成粒子会更准确
            避免内存占用过大，同一个字体的不同文本显示，尽量通过改变String来显示。
*/


#include "ofxTrueTypeFontUC.h"

#ifndef WenzyFont_h
#define WenzyFont_h

class WenzyFont{
public:
    ofxTrueTypeFontUC font;
    string words;
    int fontType;
    float fontSize;
    ofPoint fontPos;
    float letterSpacing;
    bool chineseOrNot;
    bool hasSpaceOrNot; // 只针对英文字体，某些末尾会有间距，有些则无。需先测试某英文字体属于哪种模式
    
    
    void setup(float size,int fontType_){
        fontType = fontType_;
        fontSize = size;
        letterSpacing = 1;
        
        if(fontType == 0){
            font.loadFont("PingFang Medium.ttf", size * ofGetWidth());
            chineseOrNot = true;
        }
        
        if(fontType == 1){
            font.loadFont("fonts/ArialBlack.ttf", size * ofGetWidth());
            chineseOrNot = false;
            hasSpaceOrNot = true;
        }
        
        if(fontType == 2){
            // 另一种写法，作用未知。内存占用会非常大，达 130 多M
            //font.loadFont("fonts/Building.ttf", size * ofGetWidth(),true,true);
            font.loadFont("fonts/Building.ttf", size * ofGetWidth());
            chineseOrNot = false;
            hasSpaceOrNot = false;
        }
        
        if(fontType == 3){
            font.loadFont("fonts/方正清刻本悦宋简体.TTF", size * ofGetWidth());
            chineseOrNot = true;
        }
    }
    
    void draw(float posX,float posY){
        font.setLetterSpacing(letterSpacing);
        ofRectangle fontRect;
        fontPos = ofPoint(posX,posY);
        fontRect = font.getStringBoundingBox(words,0,0);
        
        float spacingShift = fontRect.getHeight() * (letterSpacing - 1)/2;
        float x,y;
        
        if(chineseOrNot){
            y = fontPos.y + fontRect.getHeight() * 0.36;
            x = posX - fontRect.getWidth()/2 + spacingShift;
        }else{
            y = fontPos.y + fontRect.getHeight() * 0.5;
            if(hasSpaceOrNot){
                x = posX - fontRect.getWidth()/2 + spacingShift;
            }else{
                x = posX - fontRect.getWidth()/2 + spacingShift/2;
            }
            
        }
      
        // shift 是字体本身就有的偏移量，是自带bug，每种字体的偏移量都不同，可自行设置
        float shift;
        
        if(fontType == 0){
            shift = 0.14 * ofGetWidth() * fontSize;
        }
        if(fontType == 1){
            shift = 0.06 * ofGetWidth() * fontSize;
        }
        if(fontType == 2){
            shift = 0.06 * ofGetWidth() * fontSize;
        }
        
        font.drawString(words,x - shift,y);
    }
    
    void draw(string str,float posX,float posY){
        words = str;
        draw(posX,posY);
    }
    
    void drawFontBackground(float rise){
        ofRectangle fontRect;
        fontRect = font.getStringBoundingBox(words,fontPos.x,fontPos.y);
        
        float spacingShift = fontRect.getHeight() * (letterSpacing - 1)/2;
        
        float newH,newX,newW;
        if(chineseOrNot){
            newH = fontRect.y + fontRect.getHeight() * 0.36 - rise;
            newX = fontPos.x - fontRect.getWidth()/2 - rise + spacingShift;
            newW = fontRect.getWidth() + rise * 2 - spacingShift * 2;
        }else{
            newH = fontRect.y + fontRect.getHeight() * 0.5 - rise;
          
            if(hasSpaceOrNot){
                newW = fontRect.getWidth() + rise * 2 - spacingShift * 2;
                newX = fontPos.x - fontRect.getWidth()/2 - rise + spacingShift;
            }else{
                newW = fontRect.getWidth() + rise * 2 - spacingShift;
                newX = fontPos.x - fontRect.getWidth()/2 - rise + spacingShift/2;
            }
        }
        
        ofDrawRectangle(newX,
                        newH,
                        newW,
                        fontRect.getHeight() + rise * 2);
    }

    void drawVectorOutLine(){
        
        ofRectangle fontRect;
        fontRect = font.getStringBoundingBox(words,0,0);
        
        float spacingShift = fontRect.getHeight() * (letterSpacing - 1)/2;
        float x,y;
        
        if(chineseOrNot){
            y = fontPos.y + fontRect.getHeight() * 0.36;
            x = fontPos.x - fontRect.getWidth()/2 + spacingShift;
        }else{
            y = fontPos.y + fontRect.getHeight() * 0.5;
            if(hasSpaceOrNot){
                x = fontPos.x - fontRect.getWidth()/2 + spacingShift;
            }else{
                x = fontPos.x - fontRect.getWidth()/2 + spacingShift/2;
            }
        }

        ofTranslate(x,y);
        
        vector<ofPath> path;
        path = font.getStringAsPoints(words);
        
        for(int i = 0;i < path.size();i++){
            ofSetColor(255);
            path[i].setStrokeWidth(1);
            vector<ofPolyline> lines;
            
            lines = path[i].getOutline();
            for(int j =0;j < lines.size();j++){
                ofSetColor(ofColor::fromHsb((j * 60) % 255,255,255));
                lines[j].draw();
            }
        }
    }
};


#endif /* wzyFont_h */
