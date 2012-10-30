#pragma once

#include "ofMain.h"
#include "KinectController.h"
#include "ofxGui.h"
#include "WallSimulator.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void drawBlobs(float x, float y);

		KinectController kinect;
		ofxPanel gui;
		ofParameter<bool> fill;
		ofParameter<int> debugView;
		ofParameter<ofVec2f> outputOffset;
		ofParameter<ofVec2f> outputSize;
		WallSimulator wall;
};
