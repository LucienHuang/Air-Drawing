//
//  HatCreator.hpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "ofMain.h"
#include "Hat.hpp"

class HatCreator{
public:
    HatCreator();
    void update(ofVec3f finger);
    void fall();
    void draw();
    
    ofVec3f position;
    ofVec3f vel;
    ofVec3f acc;
    float friction;
    vector<Hat> hats;
    int red, green, blue;
    int LR;
};
