#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "hatSystem.hpp"

class ofApp : public ofBaseApp{
    
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
    void exit();
    
	ofxLeapMotion leap;
	vector <ofxLeapMotionSimpleHand> simpleHands;
    
	vector <int> fingersFound;
    ofEasyCam cam;
    ofVec3f left3, left4, right3;
    HatSystem hats;
    ofSoundPlayer music;
};
