#include "tilepicker.h"

#include "raylib.h"

#include "../macro.h"
#include "../assets/tilemap.h"


struct TilePicker *TilePicker_new(struct Tilemap *p_Tilemap)
{
	struct TilePicker *tilePicker = (struct TilePicker *) malloc(sizeof(struct TilePicker));

	tilePicker->tilemap = p_Tilemap;
	tilePicker->picked = 0;

	return tilePicker;
}

void TilePicker_del(struct TilePicker *p_TilePicker)
{
	if (p_TilePicker)
		free(p_TilePicker);
}

void TilePicker_render(struct TilePicker *p_TilePicker)
{
	if (!p_TilePicker)
		return;

	Vector2 position = { TILEPICKER_MARGIN_X, TILEPICKER_MARGIN_Y };

	Vector2 size = {
		(TILEPICKER_WIDTH > 0)? TILEPICKER_WIDTH : GetScreenWidth() -
			TILEPICKER_MARGIN_X - TILEPICKER_WIDTH,
		(TILEPICKER_HEIGHT > 0)? TILEPICKER_HEIGHT : GetScreenHeight() -
			TILEPICKER_MARGIN_Y - TILEPICKER_HEIGHT
	};

	DrawRectangleV(position, size, SHM_ORANGE);

	int j = 0;
	//float posY = TILEPICKER_TILE_MARGIN + TILEPICKER_TILE_SIZE;
	for (int i = TILEPICKER_TILE_MARGIN + TILEPICKER_TILE_SIZE; i < size.y; i +=
		TILEPICKER_TILE_SIZE + TILEPICKER_TILE_MARGIN) {
		Vector2 pos = { position.x + size.x / 2.f,
			position.y + i };

		Tilemap_renderTileScreen(p_TilePicker->tilemap, j, pos, (float)
			TILEPICKER_TILE_SIZE);
		//printf(" : %d : ( %f : %f ) : %d\n", j, pos.x, pos.y, TILEPICKER_TILE_SIZE);
		j++;
	}
}
