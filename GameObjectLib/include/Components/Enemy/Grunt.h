#include "Components/EnemyAbstract.h"
#include "Scenes/SceneGame1.h"
#include "Components/SpriteRenderer.h"

class Grunt : public EnemyAbstract
{
public:
    enum Direction { Left, Right };
    Grunt();
    void setDirection(Direction direction);
    void MouvementGrunt();
private:
    Sprite sprite;
    Direction direction;
};