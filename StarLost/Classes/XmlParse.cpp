//
//  XmlParse.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-13.
//
//

#include <stdio.h>
#include "XmlParse.h"
using namespace std;

void XmlParse:: xmlParseScene()
{
    
    string bundlePath=CCFileUtils::sharedFileUtils()->fullPathForFilename("scene.xml");
    
    CCString *contrnStr=CCString::createWithContentsOfFile(bundlePath.c_str());
    
    //获取沙盒目录的文件
    
    string docPath=CCFileUtils::sharedFileUtils()->getWritablePath()+"scene.xml";
    if(!CCFileUtils::sharedFileUtils()->isFileExist(docPath))
    {
        
        CCLog("%s",docPath.c_str());
        
        fstream file;
        
        file.open(docPath.c_str(),ios::out);
        file<<contrnStr->getCString();
        file.close();
    }
    CCLog("%s",docPath.c_str());
    
    
    
    
    
    TiXmlDocument *doc=new TiXmlDocument(docPath.c_str());
    
    doc->LoadFile();
    SceneArray=CCArray::create();
    SceneArray->retain();
    TiXmlElement *rootElement=doc->RootElement();
    
    CCLog("%s",rootElement->GetText());
    CCLog("%s",rootElement->Value());
    TiXmlElement * sceneElement=rootElement->FirstChildElement()->FirstChildElement();
    
    CCLog("%s",sceneElement->GetText());
    CCLog("%s",sceneElement->Value());
    
    SceneArray=CCArray::create();
    SceneArray->retain();
    while (sceneElement)
    {
        
        TiXmlElement * ElementName=sceneElement->FirstChildElement();
        const char * sceneName=ElementName->GetText();
        CCLog("%s",sceneName);
        
        TiXmlElement * ElementNumber=ElementName->NextSiblingElement();
        const char * s=ElementNumber->GetText();
        CCString *str=CCString::create(s);
        int sceneNumber=str->intValue();
        CCLog("%d",sceneNumber);
        
        TiXmlElement * ElementChapter=ElementNumber->NextSiblingElement();
        const char * C=ElementChapter->GetText();
        CCString *str1=CCString::create(C);
        int sceneChapter=str1->intValue();
        CCLog("%d",sceneChapter);
        
        TiXmlElement * ElementUnlocke=ElementChapter->NextSiblingElement();
        const char * L=ElementUnlocke->GetText();
        CCString *str2=CCString::create(L);
        int sceneUnlock=str2->intValue();
        CCLog("%d",sceneUnlock);
    
        
   
        CCDictionary *  dic=CCDictionary::create();
        dic->retain();
        dic->setObject(CCString::createWithFormat("%s",sceneName), "SceneName");
        
        dic->setObject(str, "SceneNumber");
        dic->setObject(str1, "SceneChapter");
        dic->setObject(str2, "SceneUnlock");

        SceneArray->addObject(dic);
        
     
     
        
        sceneElement=sceneElement->NextSiblingElement();
        
    }
    
    
}


void XmlParse::xmlParseChapter(int sceneNumber)
{
    ChapterArray=CCArray::create();
    ChapterArray->retain();
    char str[50];
    sprintf(str, "Chapter%d.xml",sceneNumber);
    
    string bundlePath=CCFileUtils::sharedFileUtils()->fullPathForFilename(str);
    CCString *contrnStr=CCString::createWithContentsOfFile(bundlePath.c_str());
    
    string docPath=CCFileUtils::sharedFileUtils()->getWritablePath()+str
    ;
    
    if(!CCFileUtils::sharedFileUtils()->isFileExist(docPath))
    {
        fstream file;
        file.open(docPath.c_str(),ios::out);
        file<<contrnStr->getCString();
        file.close();
    }
    
    CCLog("%s",docPath.c_str());
    
    
    TiXmlDocument *doc=new TiXmlDocument(docPath.c_str());
    doc->LoadFile();
  
    
    TiXmlElement *rootElement=doc->RootElement();
    
    TiXmlElement * LevelElement=rootElement->FirstChildElement()->FirstChildElement();
    CCLog("%s",LevelElement->GetText());
    
    while (LevelElement)
    {
        TiXmlElement * ElementName=LevelElement->FirstChildElement();
        
        CCString * LevelName=CCString::createWithFormat("%s",ElementName->GetText());
        CCLog("%s",LevelName->getCString());
        
        TiXmlElement * ElementNumber=ElementName->NextSiblingElement();
        
        CCString * LevelNumber=CCString::createWithFormat("%s",ElementNumber->GetText());
        
        TiXmlElement * ElementUnLock=ElementNumber->NextSiblingElement();
        CCString *LevelUnlock=CCString::createWithFormat("%s",ElementUnLock->GetText());
        CCLog("%d",LevelUnlock->intValue());
        TiXmlElement * ElementstarNumber=ElementUnLock->NextSiblingElement();
        
        CCString * LevelstarNumber=CCString::createWithFormat("%s",ElementstarNumber->GetText());
        
        TiXmlElement * ElementScore=ElementstarNumber->NextSiblingElement();
        CCString * LevelScore=CCString::createWithFormat("%s",ElementScore->GetText());
        
        
        CCDictionary * dic=CCDictionary::create();
        dic->retain();
        
        dic->setObject(LevelName, "ChapterName");
        dic->setObject(LevelNumber, "ChapterNumber");
        dic->setObject(LevelUnlock, "ChapterUnlock");
        dic->setObject(LevelstarNumber, "ChapterSatrNum");
        dic->setObject(LevelScore, "ChapterScore");
        
        
        ChapterArray->addObject(dic);
        
        LevelElement=LevelElement->NextSiblingElement();
        
        
        
    }
}
