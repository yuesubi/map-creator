#include <stdio.h>

#include "raylib.h"
#include "raymath.h"

#include "macro.h"
#include "map.h"
#include "panel/tilepicker.h"


int main()
{
	InitWindow(640, 460, "Create map tool");
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	struct Map *map = Map_new();
	struct Tilemap *tilemap = Tilemap_new("res/dungeon_sheet.png", 16, 16);

	struct TilePicker *tilePicker = TilePicker_new(tilemap);

	for (int i = 0; i < tilemap->tileAmount; i++) {
		struct Tile tile = { i % tilemap->tilesInRow, (int) (i / tilemap->tilesInRow), i, i };
		Map_addTile(map, tile);
	}

	Vector2 offset = { .5f, .5f };
	float zoom = 32.f;

	// Map_print(map);

	SetTargetFPS(60);
	
	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BLACK);

			Map_render(map, tilemap, offset, zoom);

			Vector2 mPos = { GetMouseX(), GetMouseY() };
			DrawRectangleLines(mPos.x, mPos.y, zoom, zoom, RED);

			TilePicker_render(tilePicker);
		EndDrawing();
	}

	TilePicker_del(tilePicker);
	Map_del(map);
	Tilemap_del(tilemap);

	CloseWindow();

	return 0;
}
