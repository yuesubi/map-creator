#include <stdlib.h>


#define TILEPICKER_MARGIN_X 0
#define TILEPICKER_MARGIN_Y 34
#define TILEPICKER_WIDTH 46
#define TILEPICKER_HEIGHT 0

#define TILEPICKER_TILE_SIZE 32
#define TILEPICKER_TILE_MARGIN 10

#define TILEPICKER_BUTTON_Y 6
#define TILEPICKER_BUTTON_W 24
#define TILEPICKER_BUTTON_H 16

#define TILEPICKER_ANIM_VEL 400


struct TilePicker {
	struct Tilemap *tilemap;
	short picked;

	float scrollY;
	float animTargetScrollY;
};


struct TilePicker *TilePicker_new(struct Tilemap *tilemap);
void TilePicker_del(struct TilePicker *tilePicker);

void TilePicker_update(struct TilePicker *tilePicker, float deltaTime);
void TilePicker_render(struct TilePicker *tilePicker);
