
#ifndef __GAME_SCENE_H__
#define  __GAME_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	void MenuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(GameScene);
	void Next(Ref *pSender);
	void Back(Ref *pSender);
	std::vector<Sprite*>boxes;
	int index[15];
	int point;
	int c;
	Label* PointInfo;
	FILE* fp;
	int fight = 0;
	int click = 1;
	int clickflag = 0;
	FILE* sp;
	int store;//rand value store kora  hobe
	int scene_num;


};
 #endif 
