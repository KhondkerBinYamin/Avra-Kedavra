#pragma once
#ifndef __HELLO_WORLD_SCENE_H__
#define __HELLO_WORLD_SCENE_H__
#include "cocos2d.h"

class GraphicsScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
	void MenuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(GraphicsScene);
	void Play(Ref *pSender);
	void Instruction(Ref *pSender);
	void Settings(Ref *pSender);
	void  ImageButton(Ref*pSender);
	int point_save;
	FILE* sp;
	int var;
	FILE *fp;
	FILE *hp;
	FILE *hp1;
	
	
};
#endif 

