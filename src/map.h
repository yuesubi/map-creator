#include "tile.h"
#include "assets/tilemap.h"


struct Map {
	struct Tile *tiles;
	int tileCount; 
};


struct Map *Map_new();
void Map_del(struct Map *map);

char Map_addTile(struct Map *map, struct Tile tile);
char Map_remTile(struct Map *map, int tileId);

void Map_render(struct Map *map, struct Tilemap *tilemap, Vector2 offset,
	float p_Scale);

void Map_print(struct Map *map);
