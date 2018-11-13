
#ifndef __GAME_WIN_H__
#define __GAME_WIN_H__

#include "cocos2d.h"
using namespace cocos2d;

class WinScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(WinScene);
	void addMonster(float dt);
	float a;





};

#endif 