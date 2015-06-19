/*
 * MainScene.h
 *
 *  Created on: Jun 10, 2015
 *      Author: yoondae-hyun
 */

#ifndef MAINSCENE_H_
#define MAINSCENE_H_

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "MainScene.h"

using namespace cocos2d;

class MainScene: public cocos2d::CCLayer {
private:
	CCSize _screenSize;
	CCSprite* rankingButton;

public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(MainScene)
	;

	void createGameScene(void);

//    virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	~MainScene(void);
};

#endif /* MAINSCENE_H_ */
