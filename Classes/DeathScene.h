
#ifndef __DEATH_SCENE_H__
#define __DEATH_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class DeathScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void Next(Ref *pSender);
	void addMonster(float dt);


	// implement the "static create()" method manually
	CREATE_FUNC(DeathScene);




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

