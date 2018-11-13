
#ifndef __FIGHT_SCENE_H__
#define __FIGHT_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class FightScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(FightScene);

	void menuCloseCallback(cocos2d::Ref* pSender);
	void addMonster(float dt);
	void Next(Ref *pSender);



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

