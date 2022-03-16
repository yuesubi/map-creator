#include "tilepicker.h"

#include "raylib.h"

#include "../macro.h"
#include "../assets/tilemap.h"


struct TilePicker *TilePicker_new(struct Tilemap *p_Tilemap)
{
	struct TilePicker *tilePicker = (struct TilePicker *) malloc(sizeof(struct TilePicker));

	tilePicker->tilemap = p_Tilemap;
	tilePicker->picked = 0;

	tilePicker->scrollY = 0.f;
	tilePicker->animTargetScrollY = 0.f;

	return tilePicker;
}

void TilePicker_del(struct TilePicker *p_TilePicker)
{
	if (p_TilePicker)
		free(p_TilePicker);
}

char ButtonColision(struct TilePicker *p_TilePicker)
{
	const float posX = TILEPICKER_MARGIN_X;
	const float posY = TILEPICKER_MARGIN_Y;

	const float sizeX = (TILEPICKER_WIDTH > 0)? TILEPICKER_WIDTH :
		GetScreenWidth() - TILEPICKER_MARGIN_X - TILEPICKER_WIDTH;
	const float sizeY = (TILEPICKER_HEIGHT > 0)? TILEPICKER_HEIGHT :
		GetScreenHeight() - TILEPICKER_MARGIN_Y - TILEPICKER_HEIGHT;

	float mouseX = GetMouseX();
	float mouseY = GetMouseY();

	float x = posX + sizeX / 2.f - TILEPICKER_BUTTON_W / 2.f;
	float y = posY + TILEPICKER_BUTTON_Y;
	float width  = TILEPICKER_BUTTON_W;
	float height = TILEPICKER_BUTTON_H;

	if (x < mouseX && mouseX < x + width) {
		if (y < mouseY && mouseY < y + height) {
			p_TilePicker->animTargetScrollY -= sizeY / 4.f;
			return 1;
		}
	}

	y = posY + sizeY - TILEPICKER_BUTTON_Y - TILEPICKER_BUTTON_H;

	if (x < mouseX && mouseX < x + width) {
		if (y < mouseY && mouseY < y + height) {
			p_TilePicker->animTargetScrollY += sizeY / 2.f;
			return 1;
		}
	}
	
	return 0;
}

void TilePicker_update(struct TilePicker *p_TilePicker, float p_Dt)
{
	if (IsMouseButtonPressed(0)) {
		if (ButtonColision(p_TilePicker))
			goto done_left_click;
	}
done_left_click:

	// Scroll animation
	float diff = p_TilePicker->animTargetScrollY - p_TilePicker->scrollY;

	if (diff != 0.f) {
		float step = TILEPICKER_ANIM_VEL * p_Dt;
		
		if (diff > 0.f) {
			if (diff > step)
				p_TilePicker->scrollY += step;
			else
				p_TilePicker->scrollY =
					p_TilePicker->animTargetScrollY;
		} else {
			if (diff < -step)
				p_TilePicker->scrollY -= step;
			else
				p_TilePicker->scrollY =
					p_TilePicker->animTargetScrollY;
		}
	}
}

void TilePicker_render(struct TilePicker *p_TilePicker)
{
	if (!p_TilePicker)
		return;

	const float posX = TILEPICKER_MARGIN_X;
	const float posY = TILEPICKER_MARGIN_Y;

	const float sizeX = (TILEPICKER_WIDTH > 0)? TILEPICKER_WIDTH :
		GetScreenWidth() - TILEPICKER_MARGIN_X - TILEPICKER_WIDTH;
	const float sizeY = (TILEPICKER_HEIGHT > 0)? TILEPICKER_HEIGHT :
		GetScreenHeight() - TILEPICKER_MARGIN_Y - TILEPICKER_HEIGHT;

	// Draw background
	DrawRectangle(posX, posY, sizeX, sizeY, SHM_ORANGE);

	// Draw palette tiles
	float offsetY = (p_TilePicker->scrollY / (TILEPICKER_TILE_SIZE +
		TILEPICKER_TILE_MARGIN));
	int startTile = (int) offsetY;
	offsetY = (startTile - offsetY) * (TILEPICKER_TILE_SIZE +
		TILEPICKER_TILE_MARGIN);

	int tileAmount = (int) (sizeY / (TILEPICKER_TILE_SIZE +
		TILEPICKER_TILE_MARGIN));

	//printf("%d : %f : %f\n", startTile, p_TilePicker->scrollY, offsetY);
	if (!(startTile < p_TilePicker->tilemap->tileAmount)) {
		p_TilePicker->scrollY -= (TILEPICKER_TILE_SIZE +
			TILEPICKER_TILE_MARGIN) *
			p_TilePicker->tilemap->tileAmount;
	}
	
	for (int y = 0; y < tileAmount; y++) {
		Vector2 tilePos = {
			posX + (sizeX / 2.f),
			posY + offsetY + TILEPICKER_TILE_SIZE * 1.5f +
				(TILEPICKER_TILE_SIZE + TILEPICKER_TILE_MARGIN)
				* y
		};
		int tile = (y + startTile) % p_TilePicker->tilemap->tileAmount;

		Tilemap_renderTileScreen(p_TilePicker->tilemap, tile, tilePos,
			(float) TILEPICKER_TILE_SIZE);
	}

	// Draw Buttons
	DrawRectangle(posX + sizeX / 2.f - TILEPICKER_BUTTON_W / 2.f,
		posY + TILEPICKER_BUTTON_Y, TILEPICKER_BUTTON_W,
		TILEPICKER_BUTTON_H, SHM_RED);

	DrawRectangle(posX + sizeX / 2.f - TILEPICKER_BUTTON_W / 2.f,
		posY + sizeY - TILEPICKER_BUTTON_Y - TILEPICKER_BUTTON_H,
		TILEPICKER_BUTTON_W, TILEPICKER_BUTTON_H, SHM_RED);
}
