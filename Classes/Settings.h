#ifndef __SETTINGS_H__
#define  __SETTINGS_H__
#include "cocos2d.h"
using namespace cocos2d;
class SettingsScene: public cocos2d::Layer
{
public :

    static cocos2d::Scene* createScene();
    virtual bool init();  
	void MenuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(SettingsScene);
	FILE* fp;
	void Reset(Ref *pSender);
	void GoBack(Ref *pSender);
	void Resume(Ref *pSender);
	void  ImageButton(Ref*pSender);
	void Off(Ref *pSender);
	void On(Ref *pSender);
	int point_save;
	FILE* sp;
	FILE *hp;
	FILE *hp1;
};
#endif

