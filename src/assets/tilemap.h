#include "raylib.h"


struct Tilemap {
	Texture2D text;
	Vector2 tileDim;

	int tilesInRow;
	int tileAmount;
};


struct Tilemap *Tilemap_new(const char *texturePath, int tileWidth,
	int tileHeight);
void Tilemap_del(struct Tilemap *tilemap);

void Tilemap_renderTile(struct Tilemap *tilemap, short img, Vector2 position,
	float scale);
void Tilemap_renderTileScreen(struct Tilemap *tilemap, short img,
	Vector2 position, float scale);  // Doesn't scale the position
