//
//  XmlParse.h
//  StarLost
//
//  Created by Gmeng on 14-12-13.
//
//

#ifndef StarLost_XmlParse_H
#define StarLost_XmlParse_H
#include <fstream>

#include "tinyxml/tinyxml.h"
#include "cocos2d.h"

using namespace std;
USING_NS_CC;
class XmlParse
{
public:
    void xmlParseScene();
    
    void xmlParseChapter(int sceneNumber);
  
   CCArray * SceneArray;
    
    CCArray * ChapterArray;

    
    
    
};

#endif