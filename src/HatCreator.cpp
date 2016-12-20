//
//  HatCreator.cpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "HatCreator.hpp"

HatCreator::HatCreator(){
    position = ofVec3f(0,0,0);
    vel = ofVec3f(0,0,0);
    acc = ofVec3f(0,0,0);
    friction = 0.99;
    if(LR==0){
    red = 255;
    green = 150;
    blue = 150;
    }else{
        red = 150;
        green = 150;
        blue = 255;
    }
}

void HatCreator::fall(){
    for(int i = 0; i<hats.size(); i++){
        hats[i].fall();
        if(hats[i].lifeSpan<0){
            hats.erase(hats.begin()+i);
        }
    }
}

void HatCreator::update(ofVec3f finger){
    
    if(red==255&&green<255&&blue==150){
        green++;
    }else if(red>150&&green==255&&blue==150){
        red--;
    }else if(red==150&&green==255&&blue<255){
        blue++;
    }else if(red==150&&green>150&&blue==255){
        green--;
    }else if(red<255&&green==150&&blue==255){
        red++;
    }else if(red==255&&green==150&&blue>150){
        blue--;
    }
    
    acc = 0.0005*(finger-position);
    vel+=acc;
    vel*=friction;
    position+=vel;
    
        Hat tempHat(position, red, green, blue);
        hats.push_back(tempHat);
    
    for(int i = 0; i<hats.size(); i++){
        hats[i].update(finger);
        if(hats[i].lifeSpan<0){
            hats.erase(hats.begin()+i);
        }
    }
}

void HatCreator::draw(){
    for(int i = 0; i<hats.size(); i++){
        hats[i].draw();
    }
}
