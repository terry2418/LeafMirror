#include "testApp.h"

ofColor niceRandomColor(){
	ofColor c;
	unsigned char hue = ofRandom(255);
	unsigned char sat = ofRandom(190,256);
	unsigned char bri = ofRandom(190,256);
	c.setHsb(hue,sat,bri);
	return c;
}


//--------------------------------------------------------------
void testApp::setup(){
	wall.setup();
	ofBackground(0);
	ofEnableAlphaBlending();
	wall.beginGlow();
	wall.drawBackground(0,0);
	wall.endGlow();
	currentColor = niceRandomColor();

	gui.add(wall.parameters);
	gui.add(particles.parameters);
	ofSetCircleResolution(50);

}

//--------------------------------------------------------------
void testApp::update(){
	particles.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	//unsigned long now = ofGetElapsedTimeMillis();
	//drawBackground(0,0);
	wall.beginGlow();
	particles.draw(0,0);
	wall.endGlow();

	wall.begin();
	//particles.draw(0,0);
	wall.end();
	wall.drawSimulation(0,0);

	wall.drawOutput(0,600,wall.wallWidth,wall.wallHeight);

	gui.draw();
	//particles.draw(0,0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles.addParticle(ofVec2f(x,y)/ofVec2f((wall.ledSeparationX)*wall.wallWidth,(wall.ledSeparationY)*wall.wallHeight)*ofVec2f(640,480)
			,currentColor);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if(button==2){
		currentColor = niceRandomColor();
	}else
	particles.addParticle(ofVec2f(x,y)/ofVec2f((wall.ledSeparationX)*wall.wallWidth,(wall.ledSeparationY)*wall.wallHeight)*ofVec2f(640,480)
			,currentColor);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}