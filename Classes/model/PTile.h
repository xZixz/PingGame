#include "cocos2d.h"
#include "TileTheme.h"
#include "../interface/SceneDelegate.h"

USING_NS_CC;

class PTile : public Sprite {
public:

  static PTile* create(std::string themeName);
  static PTile* create();
  virtual bool init(std::string themeName);
  virtual void onClick();
  virtual void act();
  virtual void endAct();

  virtual void setSceneDelegate(SceneDelegate* sceneDelegate);

  PTile();
  ~PTile();
private:
  TileTheme _theme;
  SceneDelegate* _sceneDelegate;

};
