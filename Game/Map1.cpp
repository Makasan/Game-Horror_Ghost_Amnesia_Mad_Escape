#include "Map1.h"

Map1::Map1(Texture* texture, Vector2f position, Vector2f size)
{
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
	body.setSize(size);
	/*genmap*/
	
}

void Map1::draw(RenderWindow& window)
{
	window.draw(body);
}
