//
//  Hat.hpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "ofMain.h"

class Hat{
public:
    Hat(ofVec3f pos, int red, int green, int blue);
    void update(ofVec3f hand);
    void fall();
    void draw();
    
    ofVec3f mPos;
    int lifeSpan;
    int r, g, b;
    float size;
    float alpha;
    
    ofVec3f mVel;
    ofVec3f mAcc;
    float friction;
};
