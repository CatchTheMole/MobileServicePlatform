#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Score.h"
#include "Ranking.h"

#define TAG_SPRITE_IMAGE        1000
#define TAG_LABEL_SCORE    500
using namespace cocos2d;

class HelloWorld: public cocos2d::Layer {
private:
	Size _screenSize;
	CCProgressTimer* _progressTimeBar;CCLabelBMFont* _scoreFont;
	int _gameTime;
	int _score;
	static int gameScore;
	int _type;
	int rabbitTime;
	bool _flag;

public:

	virtual bool init() override;

	static cocos2d::Scene* scene();

	void timeCount(float time);

	CREATE_FUNC(HelloWorld)
	;

	void createGameScene(void);
	void compareImage(Vec2 onTouchBeganLocation);
	void AddMole(float time);
	void VariableMole(Vec2 position);
	void TimeBar();
	void InitScore();
	void AddScore(int add);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void changeFlag();

};

#endif // __HELLOWORLD_SCENE_H__
