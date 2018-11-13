
#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"
using namespace cocos2d;

class OverScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(OverScene);

	void menuCloseCallback(cocos2d::Ref* pSender);
	void Next(Ref *pSender);
	void addMonster(float dt);
	float a;





};

#endif 