/*
 * Ranking.h
 *
 *  Created on: Jun 11, 2015
 *      Author: yoondae-hyun
 */

#ifndef RANKING_H_
#define RANKING_H_

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "MainScene.h"
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using namespace cocos2d;

class Ranking: public cocos2d::CCLayer {
private:
	CCSize _screenSize;
	Label* label_score[6][2]; // [등수][0:순위, 1:점수]

public:
	vector<int> scoreList;

	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(Ranking)
	;

	void createGameScene(void);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void rankScore();
};
#endif /* RANKING_H_ */
