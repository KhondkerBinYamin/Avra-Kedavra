#ifndef __INSTRUCTION_H__
#define  __INSTRUCTION_H__
#include "cocos2d.h"
using namespace cocos2d;
class instructionScene: public cocos2d::Layer
{
public :

    static cocos2d::Scene* createScene();
    virtual bool init();  
	void MenuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(instructionScene);
	FILE* fp;
	void BackToMenu(Ref *pSender);
	FILE* sp;
};
#endif

