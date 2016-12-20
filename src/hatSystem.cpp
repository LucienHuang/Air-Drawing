//
//  hatSystem.cpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "hatSystem.hpp"

HatSystem::HatSystem(){
    right.LR = 0;
    left.LR = 0;
    up.LR = 1;
    down.LR = 1;
    angle = 0;
    fist = false;
}

void HatSystem::update(ofVec3f l1, ofVec3f l2, ofVec3f r){
    mirror1.x = -r.x;
    mirror1.y = r.y;
    mirror1.z = r.z;
    
    mirror2.x = r.x;
    mirror2.y = -r.y;
    mirror2.z = r.z;
    
    mirror3.x = -r.x;
    mirror3.y = -r.y;
    mirror3.z = r.z;
    
    if((l1-l2).length()<150){
        fist = true;
    }else if(fist==true){
        right.position = ofVec3f(0,0,0);
        left.position = ofVec3f(0,0,0);
        up.position = ofVec3f(0,0,0);
        down.position = ofVec3f(0,0,0);
        fist = false;
    }
    
    
//    mirror4.x =r.x;
//    mirror4.y = r.y;
//    mirror4.z = -r.z;
//    
//    mirror5.x = -r.x;
//    mirror5.y = -r.y;
//    mirror5.z = -r.z;
//    
//    mirror6.x = r.x;
//    mirror6.y = -r.y;
//    mirror6.z = -r.z;
//    
//    mirror7.x = -r.x;
//    mirror7.y = r.y;
//    mirror7.z = -r.z;
    if(fist==false){
        
        right.update(r);
        left.update(mirror1);
        up.update(mirror2);
        down.update(mirror3);
    }else{
        right.fall();
        left.fall();
        up.fall();
        down.fall();
    }
    
//    back.update(mirror4);
//    forth.update(mirror5);
//    in.update(mirror6);
//    out.update(mirror7);
    
    angle+=0.05;
}

void HatSystem::draw(){
    ofRotateZ(angle);
    ofRotateY(angle);
    right.draw();
    left.draw();
    up.draw();
    down.draw();
//    back.draw();
//    forth.draw();
//    in.draw();
//    out.draw();
}
