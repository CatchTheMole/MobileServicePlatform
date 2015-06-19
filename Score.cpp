/*
 * Score.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: Jusu
 */

#include <Score.h>

namespace cocos2d {

int Score::scoring(int _type) {
	score = 0;
	if (_type == 0) {
		score = score + 10;
	} else if (_type == 1) {
		score = score + 30;
	} else if (_type == 2) {
		score = score + 20;
	} else if (_type == 3) {
		score = score + 15;
	} else if (_type == 4) {
		score = score - 15;
	}

	return score;
}

} /* namespace cocos2d */
