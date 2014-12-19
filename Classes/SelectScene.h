//add by sa14225023
#ifndef __SelectScene__
#define __SelectScene__
#include "cocos2d.h"

USING_NS_CC;

class SelectScene : public Layer
{
public:
	bool init();
	static Scene* createScene();
	void onStartGoldKing();
	void onStartSaber();
	CREATE_FUNC(SelectScene);
};

#endif


