#include "cocos2d.h"
#include "../model/PTile.h"

USING_NS_CC;

class GameScene : public Layer {
public:
  static Scene* createScene();
  virtual bool init();

  // handle touches
  void enableTouches();
  virtual void onTouchesBegan(const std::vector<Touch*> touches, Event* event);
  virtual void onTouchesEnded(const std::vector<Touch*> touches, Event* event);

  CREATE_FUNC(GameScene);
  GameScene();
  ~GameScene();

private:
  Node* _baseNode;
  std::vector<PTile> _currentTiles;
};
