//
//  hatSystem.hpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "ofMain.h"
#include "HatCreator.hpp"

class HatSystem{
public:
    HatSystem();
    void update(ofVec3f l1, ofVec3f l2, ofVec3f r);
    void draw();
    
    ofVec3f mirror1, mirror2, mirror3, mirror4, mirror5, mirror6, mirror7;
    
    HatCreator right;
    HatCreator left;
    
    HatCreator up;
    HatCreator down;
    HatCreator back;
    HatCreator forth;
    HatCreator in;
    HatCreator out;
    float angle;
    bool fist;
};
