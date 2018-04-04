#ifndef GAME_CFG_H
#define GAME_CFG_H

/* Tile image width in pixels */
#define TILE_WIDTH       20
/* Tile image height in pixels */
#define TILE_HEIGHT      20
/* Game board width in pixels */
#define SCREEN_WIDTH     540
/* Game board height in pixels */
#define SCREEN_HEIGHT    540

/* Game board width in tiles */
#define MAP_TILES_WIDTH     (SCREEN_WIDTH / TILE_WIDTH)
/* Game board height in tiles */
#define MAP_TILES_HEIGHT    (SCREEN_HEIGHT / TILE_HEIGHT)

#endif // GAME_CFG_H
