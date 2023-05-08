#pragma once
#include "Arduino.h"
//#include <stdlib.h>
#include <math.h>

class node{
    public:
        float posX, posY;
        node(float posX, float posY){
            this -> posX = posX;
            this -> posY = posY;
        }
};


class RRT
{
private:
    /* data */
    float posInitiateX, posInitiateY, posDesireX, posDesireY, distanceD, limitInfX,  limitInfY, limitSupX, limitSupY;
    int iter;
    bool status;

public:
    std::vector<node*> nodes;
    std::vector<node*> path;

    //Sin Posiciones iniciales en los input  ---- Without Positions initiates
   RRT(float posInitiateX, float posInitiateY, float posDesireX, float posDesireY, float distanceD, float limitInfX, float limitInfY, float limitSupX, float limitSupY, float iter){
        this -> posInitiateX = posInitiateX;
        this -> posInitiateY = posInitiateY;
        this -> posDesireX = posDesireX;
        this -> posDesireY = posDesireY;
        this -> distanceD = distanceD;
        this -> limitInfX = limitInfX;
        this -> limitInfY = limitInfY;
        this -> limitSupX = limitSupX;
        this -> limitSupY = limitSupY;
        this -> iter = iter;

    }

    RRT( float posDesireX, float posDesireY, float distanceD, float limitInfX, float limitInfY, float limitSupX, float limitSupY){
        posInitiateX = 0;
        posInitiateY = 0;
        this -> posDesireX = posDesireX;
        this -> posDesireY = posDesireY;
        this -> distanceD = distanceD;
        this -> limitInfX = limitInfX;
        this -> limitInfY = limitInfY;
        this -> limitSupX = limitSupX;
        this -> limitSupY = limitSupY;

    }

    RRT(float limitInfX, float limitInfY, float limitSupX, float limitSupY,float distanceD){
        posInitiateX = 0;
        posInitiateY = 0;
        posDesireX = 0;
        posDesireY = 0;
        this -> limitInfX = limitInfX;
        this -> limitInfY = limitInfY;
        this -> limitSupX = limitSupX;
        this -> limitSupY = limitSupY;
        this -> distanceD = distanceD;
    }

     void RRTSetPosDesire(float posDesireX, float posDesireY){
        this -> posDesireX = posDesireX;
        this -> posDesireY = posDesireY;
    }

    void RRTSetPosInitiates(float posInitiateX, float posInitiateY){
        this -> posInitiateX = posInitiateX;
        this -> posInitiateY = posInitiateY;
    }


    void RRTSetLimitsInf(float limitInfX, float limitInfY){
        this -> limitInfX = limitInfX;
        this -> limitInfY = limitInfY;
    }

    void RRTSetLimits(float limitInfX, float limitInfY, float limitSupX, float limitSupY){
        this -> limitSupX = limitSupX;
        this -> limitSupY = limitSupY;
    }

    float randomValues();

    node* randomPoints();


    node* setDesireNodes(float posDesireX, float posDesireY);

    void getNearestNode();

    float nodeNearDesire(node* desireNode, node* nearestNode);

    void findPath();

    void setStatus(bool status);

    void reverseStatus(bool status);
    
    bool getStatus();

    node *desireNode();
    
    node *initiateNode();

    float getDistanceNodes(node* node1, node* node2 );   
};

