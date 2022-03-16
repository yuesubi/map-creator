#include "map.h"

#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#include "macro.h"


struct Map *Map_new()
{
	struct Map *newMap = (struct Map *) malloc(sizeof(struct Map));

	if (newMap) {
		newMap->tiles = NULL;
		newMap->tileCount = 0;
	}

	return newMap;
}

void Map_del(struct Map *p_Map)
{
	free(p_Map);
}

char Map_addTile(struct Map *p_Map, struct Tile p_Tile)
{
	p_Map->tileCount++;

	size_t newSize = sizeof(struct Tile) * p_Map->tileCount;
	struct Tile *tmp = (struct Tile *) realloc(p_Map->tiles, newSize);

	if (!tmp) {
		WARN("failed to reallocate memory");
		p_Map->tileCount--;
		return -2;
	}

	p_Map->tiles = tmp;
	p_Map->tiles[p_Map->tileCount - 1] = p_Tile;

	return 0;
}

char Map_remTile(struct Map *p_Map, int p_TileId)
{
	p_Map->tileCount--;
	struct Tile lastTile = p_Map->tiles[p_Map->tileCount];

	size_t newSize = sizeof(struct Tile) * (p_Map->tileCount);
	struct Tile *tmp = (struct Tile *) realloc(p_Map->tiles, newSize);

	if (!tmp) {
		WARN("failed to reallocate memory");
		p_Map->tileCount++;
		return -2;
	}

	if (lastTile.id != p_TileId) {
		for (int i = 0; i < p_Map->tileCount; i++)
		{
			if (tmp[i].id == p_TileId) {
				tmp[i] = lastTile;
				goto exit;
			}
		}

		WARN("cannot find the specified tile");
	}
	
exit:
	p_Map->tiles = tmp;

	return 0;
}

void Map_render(struct Map *p_Map, struct Tilemap *p_Tilemap, Vector2 p_Offset,
	float p_Scale)
{
	for (int i = 0; i < p_Map->tileCount; i++) {
		Vector2 pos = { p_Map->tiles[i].x + p_Offset.x,
		p_Map->tiles[i].y + p_Offset.y };
		Tilemap_renderTile(p_Tilemap, p_Map->tiles[i].img, pos, p_Scale);
	}
}

void Map_print(struct Map *p_Map)
{
	printf("Map <%p> {\n", p_Map);
	for (int i = 0; i < p_Map->tileCount; i++) {
		printf("\tTile <%p> { x: %u; y: %u; img: %d; id: %d; },\n",
			&(p_Map->tiles[i]), p_Map->tiles[i].x,
			p_Map->tiles[i].y, p_Map->tiles[i].img,
			p_Map->tiles[i].id);
	}
	printf("}\n");
}
