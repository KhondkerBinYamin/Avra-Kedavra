
#ifndef __CROSS_SCENE_H__
#define __CROSS_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class CrossScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(CrossScene);

	void menuCloseCallback(cocos2d::Ref* pSender);
	void Next(Ref *pSender);
	void addMonster(float dt);



	struct CharacterInfo {
		Sprite* character;
		FILE *health;
		float healthlength;

	};

	CharacterInfo harry, enemy;

	float a;


private:
	Sprite * box1;
	Sprite * box2;
private:
	Label* labelTouchInfo;



};

#endif // __HELLOWORLD_SCENE_H__

