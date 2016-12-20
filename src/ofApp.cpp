#include "ofApp.h"

//--------------------------------------------------------------


void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);
    
	leap.open();
    
	cam.setOrientation(ofPoint(-20, 0, 0));
    
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    music.load("a.mp3");
    music.play();
    music.setLoop(true);
    
    left3 = ofVec3f(-500,0,0);
    left4 = ofVec3f(500,0,0);
    right3 = ofVec3f(200,0,0);
}


//--------------------------------------------------------------
void ofApp::update(){
	fingersFound.clear();
	
	//here is a simple example of getting the hands and drawing each finger and joint
	//the leap data is delivered in a threaded callback - so it can be easier to work with this copied hand data
	
	//if instead you want to get the data as it comes in then you can inherit ofxLeapMotion and implement the onFrame method.
	//there you can work with the frame data directly.
    
    
    
    //Option 1: Use the simple ofxLeapMotionSimpleHand - this gives you quick access to fingers and palms.
    
    
    simpleHands = leap.getSimpleHands();
    
    if( leap.isFrameNew() && simpleHands.size() ){
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
		leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < simpleHands.size(); i++){
            for (int f=0; f<5; f++) {
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
                fingersFound.push_back(id);
            }
        }
    }
    
    
    if(simpleHands.size()){
        if(simpleHands[0].isLeft){
            left3 = simpleHands[0].fingers[THUMB].tip;
            left4 = simpleHands[0].fingers[PINKY].tip;
        }else{
            right3 = simpleHands[0].fingers[INDEX].tip;
        }
        if(simpleHands.size()>1){
            if(simpleHands[1].isLeft){
                left3 = simpleHands[1].fingers[THUMB].tip;
                left4 = simpleHands[1].fingers[PINKY].tip;
                right3 = simpleHands[0].fingers[INDEX].tip;
            }else{
                left3 = simpleHands[0].fingers[THUMB].tip;
                left4 = simpleHands[0].fingers[PINKY].tip;
                right3 = simpleHands[1].fingers[INDEX].tip;
            }
        }
    }
    hats.update(left3, left4, right3);
    
    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
	cam.begin();
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal;
        
        //        ofSetColor(0, 0, 255);
        //        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
        //        ofSetColor(255, 255, 0);
        //        ofDrawArrow(handPos, handPos + 100*handNormal);
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            ofSetColor(0, 150, 255);
            ofDrawBox(tip.x, tip.y, tip.z, 3);
        }
    }
    
    hats.draw();
	cam.end();
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}
