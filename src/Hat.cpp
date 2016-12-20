//
//  Hat.cpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "Hat.hpp"

Hat::Hat(ofVec3f pos, int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
    mPos = pos;
    mVel = ofVec3f(0,0,0);
    mAcc = ofVec3f(0,0,0);
    friction = 0.99;
    lifeSpan = 1800;
    size = 10;
    alpha = 255;
}

void Hat::fall(){
    mAcc = 0.5*(mPos-ofVec3f(0,0,0)).getNormalized();
    mVel+=mAcc+ofRandom(-0.1,0.1);
    mVel*=friction;
    mPos += mVel;
    if((mPos-ofVec3f(0,0,0)).length()>700){
        mVel = -mVel;
    }
    if((mPos-ofVec3f(0,0,0)).length()>750){
        mPos = ofVec3f(0,0,0);
    }
    lifeSpan-=3;
    size = ofMap(lifeSpan, 0, 1800, 0.5, 10);
    if(lifeSpan<1000){
        alpha = ofRandom(0,255);
    }
}

void Hat::update(ofVec3f hand){
    lifeSpan--;
    size = ofMap(lifeSpan, 0, 1800, 0.5, 10);
    if(lifeSpan<400){
        alpha = ofRandom(0,255);
    }
}

void Hat::draw(){
    ofSetColor(r, g, b, alpha);
    ofDrawSphere(mPos, size);
}
