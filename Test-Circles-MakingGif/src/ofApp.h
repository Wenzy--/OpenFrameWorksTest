#pragma once

#include "ofMain.h"
#include "Circles.h"
#include "ofxGui.h"
#include "WenzyGif.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    Circles circles;
    ofxPanel gui;
    ofParameter<float> num;
    ofParameter<float> speed;
    ofParameter<float> movingDist;
    ofParameter<float> circleR;
    ofParameter<float> resolution;
    ofParameter<float> lineWidth;
    ofParameter<int> shapeMode;
    ofxToggle colorMode,rotateMode;
    bool showGui;
    
    WenzyGif gif;
    
};
