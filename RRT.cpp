#include "RRT.h"


    float RRT ::randomValues(){
        return random(0,(float)iter+1)/(float)iter;
    }


    node* RRT ::randomPoints(){

            float coordXRand = limitInfX +(limitSupX - limitInfX) * randomValues();
            float coordYRand = limitInfX +(limitSupX - limitInfX)*randomValues();

            return new node(coordXRand, coordYRand);

    }


    node* RRT :: setDesireNodes(float posDesireX, float posDesireY){

           return new node(posDesireX,posDesireY);

    }

    void RRT :: getNearestNode(node* inputRandomNode){
            node *nearestNode = new node(0,0);
            node *nodes;
            node *inputRandomNode;
            node *newNode;
            float  minDist;
            float distanceNodes;
            ,i_min=0;
            bool act = true;
            //minDist = 1000;
            nodes=new node(0,0);

            
            //minDist = getDistanceNodes(inputRandomNode, nearestNode);
            while (act==true) {
              
              while(nodoRRT.size() < iter){
                    minDist = 1000; 

                    inputRandomNode = randomPoints();
                               
                    for(int i = 1; i < nodoRRT.size() ;i++){//int  i = 1

                        distanceNodes = getDistanceNodes(inputRandomNode, nearestNode);
                    
                        if(distanceNodes < minDist){
                          
                          nearestNode = nodes; 
                          minDist = distanceNodes;                          
                          vectorNumeros[nodoRRT.size()]=minDist;
                               
                        }
                        
                    }
                    
                    float x =nearestNode -> posX + distanceD*((inputRandomNode -> posX - nearestNode -> posX) / getDistanceNodes(inputRandomNode,nearestNode));//+((randomValues()*100)-10);
                    float y =nearestNode -> posY + distanceD*((inputRandomNode -> posY - nearestNode -> posY) / getDistanceNodes(inputRandomNode,nearestNode));//+((randomValues()*100)-10);
                    newNode = new node(x,y);
                    //newNode -> parents = nearestNode;
                    nodoRRT.push_back(newNode);
                    
                    nodes = newNode; 
                    
                    if(getDistanceNodes(desireNode(), newNode) < distanceD){
                      Serial.println("path near to desire found : "+String(newNode->posX) + " y "+ String(newNode->posY));
                      act =  false;
                      break;
                    }
                    
                                               
              }

              if(act == true && nodoRRT.size() >= iter){
              
              //nodoRRT.erase(nodoRRT.begin(),nodoRRT.end());
              Serial.println("path no found!!"); 
              nodoRRT.clear();
              nodes=new node(0,0);
              newNode= new node(0,0);
              nearestNode = new node(0,0);
              delete nodes;
              
              
              }
              
            } 
            findPath();
            reverseStatus(getStatus()); 
           
    }


    void findPath(){
        path.push_back(initiateNode());
        float minDistToDesire = getDistanceNodes(desireNode(),initiateNode());
       
        node* nodoResult;
        int newj = 0;      
             
        for(int j = 0; j < nodoRRT.size();j++){
                                
            for(int i = 1; i < nodoRRT.size(); i++){
            
            if(getDistanceNodes(nodoRRT[j],nodoRRT[i]) < distanceD){

                if(getDistanceNodes(desireNode(),nodoRRT[i]) < minDistToDesire){
                minDistToDesire = getDistanceNodes(desireNode(),nodoRRT[i]);
                nodoResult = nodoRRT[i];
                newj=i;
                
                } 
            }
            }
            
            j=newj;      
            path.push_back(nodoResult);       
        }
        path.push_back(desireNode());      
    }


    node *desireNode(){    
      return new node(posDesireX,posDesireY);
    }
    
    node *initiateNode(){    
      return new node(posInitiateX,posInitiateY);
    }

    void setStatus(bool status){
          this->status= status;          
    }

    void reverseStatus(bool status){
        this->status=!status;      
    }
    
    bool getStatus(){
          return this->status;
    }


    float RRT :: getDistanceNodes(node* node1, node* node2 ){

        return sqrt(pow(node1 -> posX - node2 -> posX,2)+pow(node1 -> posY - node2 -> posY,2));

    }