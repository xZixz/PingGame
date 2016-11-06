#include "cocos2d.h"
#include "../model/PTile.h"

class SceneDelegate;

USING_NS_CC;

class GameScene : public LayerColor, public SceneDelegate {
public:
  static Scene* createScene();
  virtual bool init();

  // handle touches
  void enableTouches();
  virtual bool onTouchBegan(const Touch* touch, Event* event);
  virtual void onTouchEnded(const Touch* touch, Event* event);

  void addScore(int scores);
  virtual void tileEndAct();

  CREATE_FUNC(GameScene);
  GameScene();
  ~GameScene();

private:
  Node* _baseNode;
  std::vector<PTile*> _currentTiles;
  Label* _scoreLabel;
  Size _screenSize;
  int _score;
};
