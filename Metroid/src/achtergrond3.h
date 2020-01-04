//
// Created by kyles on 29/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND3_H
#define GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND3_H



//{{BLOCK(bricksForeground)

//======================================================================
//
//	bricksForeground, 256x256@8,
//	Transparent palette entry: 0.
//	+ 16 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32
//	Total size: 1024 + 2048 = 3072
//
//	Time-stamp: 2020-01-04, 21:19:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int bricksForegroundTiles[256] __attribute__((aligned(4)))=
        {
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x0F0F0F0F,0x0F0F0F0F,0x0F0E1010,0x10100E0F,0x0F0E0E0E,0x0E0E100F,0x0F0E0E0E,0x0E0E0E0F,
                0x0F0E0E0E,0x0E0E0E0F,0x0F110E0E,0x0E0E0E0F,0x0F0F1111,0x11110E0F,0x0F0F0F0F,0x0F0F0F0F,
                0x0F0F0F0F,0x0F0F0F0F,0x10100E0F,0x0F0E1010,0x0E0E100F,0x0F0E0E0E,0x0E0E0E0F,0x0F0E0E0E,
                0x0E0E0E0F,0x0F0E0E0E,0x0E0E0E0F,0x0F110E0E,0x11110E0F,0x0F0F1111,0x0F0F0F0F,0x0F0F0F0F,
                0x0E0E0E11,0x0E0E0E0E,0x1010110E,0x10101010,0x0E11110E,0x0E100E0E,0x1011110E,0x0E0E0E0E,
                0x0E11110E,0x0E0E0E0E,0x1111110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,0x0E0E110E,0x0E0E0E0E,

                0x0E0E0E0E,0x110E0E0E,0x10101010,0x0E0E1010,0x0E100E0E,0x0E100E10,0x0E0E0E0E,0x0E10100E,
                0x0E0E0E0E,0x0E10100E,0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E100E0E,
                0x1111110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,
                0x110E110E,0x0E110E0E,0x0E11110E,0x11110E11,0x1111110E,0x11111111,0x0E0E0E11,0x0E0E0E0E,
                0x0E0E0E0E,0x0E10100E,0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E100E11,
                0x0E110E11,0x0E100E0E,0x11111111,0x0E101111,0x11111111,0x0E0E1111,0x0E0E0E0E,0x110E0E0E,
                0x1111110E,0x0E0E0E0E,0x0E0E0E11,0x0E0E0E0E,0x1010110E,0x10101010,0x0E11110E,0x0E100E0E,
                0x1011110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,0x1111110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,

                0x0E0E0E0E,0x0E10100E,0x0E0E0E0E,0x110E0E0E,0x10101010,0x0E0E1010,0x0E100E0E,0x0E100E10,
                0x0E0E0E0E,0x0E10100E,0x0E0E0E0E,0x0E10100E,0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E100E0E,
                0x0E0E110E,0x0E0E0E0E,0x1111110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,0x0E11110E,0x0E0E0E0E,
                0x0E11110E,0x0E0E0E0E,0x110E110E,0x0E110E0E,0x0E11110E,0x11110E11,0x1111110E,0x11111111,
                0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E10100E,0x0E0E0E0E,0x0E100E0E,0x0E0E0E0E,0x0E100E0E,
                0x0E0E0E0E,0x0E100E11,0x0E110E11,0x0E100E0E,0x11111111,0x0E101111,0x11111111,0x0E0E1111,
                0x0F0F0F0F,0x0F0F0F0F,0x100E110F,0x0F101010,0x0E0E110F,0x0F100E0E,0x1111110F,0x0F0E0E11,
                0x0F0F0F0F,0x0F0F0F0F,0x0F101010,0x100E110F,0x0F100E0E,0x0E0E110F,0x0F0E0E11,0x1111110F,

                0x0F111111,0x1111110F,0x1010100F,0x0F101010,0x0E0E0E10,0x110E0E0E,0x0E0E0E10,0x11110E0E,
                0x1111110F,0x11111111,0x0F101010,0x1010100F,0x110E0E0E,0x0E0E0E10,0x11110E0E,0x0E0E0E10,
                0x11111111,0x1111110F,0x0E0E110F,0x0E10100E,0x0E11110F,0x0E0E0E0E,0x1111110F,0x11111111,
                0x0E10100E,0x0E0E110F,0x0E0E0E0E,0x0E11110F,0x11111111,0x1111110F,0x0E0E110F,0x0E10100E,
                0x11111111,0x1111110F,0x1010100F,0x0F101010,0x0E0E0E10,0x110E0E0E,0x0E0E0E10,0x11110E0E,
                0x1111110F,0x11111111,0x0F101010,0x1010100F,0x110E0E0E,0x0E0E0E10,0x11110E0E,0x0E0E0E10,
                0x0E11110F,0x0E0E0E0E,0x1111110F,0x11111111,0x0E10100E,0x0E0E110F,0x0E0E0E0E,0x0E11110F,
                0x11111111,0x1111110F,0x0E0E110F,0x0E10100E,0x0E11110F,0x0E0E0E0E,0x1111110F,0x11111111,
        };

unsigned short bricksForegroundMap[1024] __attribute__((aligned(4)))=
        {
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,

                0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,

                0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,

                0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1003,
                0x0004,0x1003,0x0004,0x1003,0x0004,0x1003,0x0004,0x1003,
                0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,

                0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0005,
                0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,
                0x0006,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0001,
                0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1003,
                0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0007,
                0x0008,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0009,
                0x000A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1003,
                0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0005,
                0x0006,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,
                0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x000B,
                0x000B,0x100C,0x100C,0x100D,0x100D,0x0002,0x0002,0x1003,
                0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x000B,
                0x000B,0x100E,0x100E,0x000F,0x000F,0x0001,0x0001,0x0005,
                0x0006,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
        };

//}}BLOCK(bricksForeground)


//{{BLOCK(rocks)

//======================================================================
//
//	rocks, 256x256@8,
//	Transparent palette entry: 0.
//	+ 29 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32
//	Total size: 1856 + 2048 = 3904
//
//	Time-stamp: 2020-01-04, 21:19:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int rocksTiles[464] __attribute__((aligned(4)))=
        {
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x0D0D0807,0x0D0D0D0D,0x08050808,0x0D060508,0x0D080409,0x0D0D0D08,0x0D0D020C,0x09080608,
                0x04050402,0x06080605,0x0D0D0D04,0x0D090D08,0x0B0A0D0D,0x0A0A0B0A,0x010C0405,0x0802010C,
                0x09090909,0x09090909,0x0C0B0B09,0x0C0C0C0C,0x01010C0A,0x01010101,0x0101010B,0x01010101,
                0x0603010B,0x08080504,0x0803010A,0x04080706,0x0804010B,0x04080D07,0x0703010B,0x0503060D,
                0x09090909,0x0D0D0D0D,0x0B0B0C0C,0x0B0B0B0B,0x01010101,0x01010101,0x03030301,0x03030303,
                0x07070608,0x07070708,0x04050605,0x03030202,0x05070708,0x07020406,0x03020302,0x05080203,

                0x09090909,0x09090909,0x0C0C0C0C,0x0C0C0B0B,0x01010101,0x01010101,0x02020202,0x02020402,
                0x06060506,0x05060507,0x0D040304,0x0302060D,0x050D0406,0x06020204,0x03060D06,0x05030C0C,
                0x09090909,0x09090909,0x0C0C0C0C,0x0C0C0C0C,0x01010101,0x0C020C0C,0x02030402,0x05030406,
                0x07050504,0x0D070507,0x02020203,0x08060203,0x02020505,0x08080608,0x06040204,0x07040205,
                0x09090909,0x09090909,0x0B0B0B0A,0x0B0B0B0B,0x01010106,0x01010101,0x01010307,0x02030303,
                0x05030104,0x06060607,0x0606030C,0x06070706,0x0702020B,0x07070706,0x08040302,0x02020608,
                0x09090909,0x0D0D0D0D,0x0B0B0C0B,0x0B0B0B0A,0x01010101,0x01010101,0x03030303,0x01030303,
                0x08060602,0x06040506,0x07070706,0x07060706,0x04020205,0x02030204,0x05040405,0x06030302,

                0x0A0A0909,0x0A0A0A0A,0x0C0C0B0B,0x0C0C0C0C,0x01010101,0x01010101,0x02050301,0x02020404,
                0x0205080D,0x06050707,0x04030204,0x06040302,0x03030304,0x02030204,0x07070602,0x06060708,
                0x0A0A0909,0x060A0A0A,0x0C0C0C0B,0x0C0C0C0C,0x01010101,0x01010101,0x05050402,0x07060504,
                0x02050706,0x04040405,0x02030507,0x02020402,0x07050407,0x08050607,0x03020303,0x03030303,
                0x0B0A050A,0x0B0B0A0A,0x0C030C0C,0x04030C0C,0x03010101,0x040C010C,0x07060204,0x08060205,
                0x04080502,0x0D070402,0x04020204,0x0D0D0202,0x07060207,0x04060604,0x05070502,0x0D070606,
                0x09090909,0x07060909,0x0C0C0C0C,0x060C0C0C,0x01010101,0x0D020101,0x04050203,0x02070402,
                0x06040708,0x02020807,0x02020302,0x03030303,0x02080706,0x06030202,0x04040202,0x08040406,

                0x02040502,0x0D080402,0x08080704,0x0D0D0D08,0x08080808,0x080D0D0D,0x02030206,0x08060504,
                0x06060505,0x0D0D0D08,0x08080804,0x06080808,0x0D0D0D0D,0x0D0D0808,0x0D0D0D0D,0x0D0D0D0D,
                0x08060408,0x07050204,0x08080206,0x02040504,0x03050809,0x07060604,0x04020B0A,0x05040405,
                0x08050508,0x08080708,0x04020304,0x04020202,0x0D08080D,0x0D0D0808,0x0D0D080D,0x0D0D0D0D,
                0x02050504,0x04050402,0x08040202,0x05050507,0x04060406,0x06060404,0x05060506,0x04050605,
                0x07080708,0x08080806,0x02020202,0x02020202,0x0808080D,0x080D0D08,0x0D0D0D0D,0x0D0D0D0D,
                0x03030405,0x07080502,0x02030304,0x04070D08,0x0D070706,0x0706050D,0x060D0705,0x07040402,
                0x02060808,0x05050806,0x04040202,0x04020202,0x0D0D0808,0x0D080808,0x0D0D0D0D,0x0D0D0D0D,

                0x0D0D0502,0x0D0D0605,0x04070D06,0x04060D06,0x06040206,0x08040408,0x02040407,0x0D070402,
                0x08060405,0x0D0D0D08,0x080D0804,0x06080606,0x0D0D0D0D,0x0D0D0D0D,0x0D0D0D0D,0x0D0D0D0D,
                0x07060407,0x07060202,0x06070707,0x03020406,0x05020407,0x05040504,0x02040308,0x04060802,
                0x04040205,0x05040608,0x0D040303,0x04020207,0x060D0D0D,0x07070602,0x06080D0D,0x080D0D08,
                0x04030303,0x04020302,0x06050403,0x06040202,0x04040406,0x07040506,0x07050505,0x05070607,
                0x04050406,0x07080704,0x05050405,0x02040202,0x07080807,0x08080706,0x080D0D0D,0x0D080D0D,
                0x02020202,0x02050203,0x02030303,0x02030203,0x06050505,0x06040407,0x05070705,0x0D0D0605,
                0x07060705,0x05060707,0x03030303,0x02020303,0x080D0D08,0x07050608,0x08080D0D,0x0D0D0D08,

                0x06070405,0x04040505,0x03020302,0x03030303,0x07080607,0x04050605,0x05060505,0x08070807,
                0x06050707,0x05060605,0x02030302,0x03030302,0x08080808,0x080D0808,0x0D0D0D0D,0x0D0D0D0D,
                0x07070402,0x08050507,0x07080804,0x080D0807,0x02030508,0x0A040402,0x06040208,0x05060502,
                0x05080602,0x08080808,0x06080602,0x0D070404,0x08080808,0x0D0D0D0D,0x0D0D0D0D,0x0D0D0D0D,
                0x02020407,0x02070602,0x06030304,0x04040207,0x05070505,0x06070505,0x06060604,0x06050505,
                0x07050507,0x06070606,0x02040202,0x02020202,0x08080808,0x0808080D,0x0D0D0D0D,0x0D0D0D0D,
                0x0A0A0A0A,0x0404050A,0x0C0C0C0C,0x04040C0C,0x01010101,0x04040303,0x07040202,0x0D0D0806,
                0x05050405,0x06060607,0x07050405,0x08050302,0x05060602,0x07060402,0x04020406,0x0D070607,

                0x0D0D0502,0x0D0D0407,0x02060D05,0x04070806,0x02030608,0x07040202,0x08020208,0x05080706,
                0x04080502,0x07050504,0x06070806,0x0D0D0505,0x07070808,0x0D0D0D0D,0x0D0D0D0D,0x0D0D0D0D,
                0x09090909,0x09090909,0x0B0B0B0A,0x0B0B0B0B,0x01010C0B,0x01010101,0x01010106,0x03010301,
                0x0503010C,0x07060506,0x04050203,0x060D0604,0x06020307,0x0302080D,0x0D020302,0x04020408,
                0x09090909,0x0D0D0D0D,0x0B0B0C0C,0x0B0B0A0A,0x01010101,0x01010101,0x01030201,0x01010101,
                0x04040806,0x06060806,0x05020506,0x05050404,0x05020202,0x02040404,0x06040304,0x05030302,
                0x0D080202,0x04050504,0x02070708,0x04050402,0x02040504,0x05060502,0x0504020D,0x02020405,
                0x06030C05,0x05040407,0x06040302,0x06040404,0x0D080808,0x080D080D,0x0D0D0D0D,0x0D0D0D0D,

                0x03040602,0x06020303,0x08040607,0x04050608,0x06050204,0x02020302,0x02040406,0x06050402,
                0x08040507,0x07040607,0x07040406,0x05040507,0x070D0806,0x08080807,0x080D0D08,0x0D07080D,
        };

const unsigned short rocksMap[1024] __attribute__((aligned(4)))=
        {
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,
                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,
                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,

                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,
                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0006,
                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,
                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0006,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x0011,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x0011,

                0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0002,0x0003,
                0x0004,0x0005,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,
                0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0002,0x0003,
                0x0004,0x0005,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,
                0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x000D,0x000E,
                0x000F,0x0010,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,
                0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x000D,0x000E,
                0x000F,0x0010,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,

                0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,0x0005,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,0x0005,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,0x0010,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,
                0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,0x0010,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,

                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,0x0009,
                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,0x0009,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,0x0014,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,0x0014,

                0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,
                0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,

                0x0003,0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0019,
                0x001A,0x0008,0x0017,0x0002,0x0003,0x0009,0x000A,0x0006,
                0x0003,0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0019,
                0x001A,0x0008,0x0017,0x0002,0x0003,0x0009,0x000A,0x0006,
                0x000E,0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x001B,
                0x001C,0x0013,0x0018,0x000D,0x000E,0x0014,0x0015,0x0011,
                0x000E,0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x001B,
                0x001C,0x0013,0x0018,0x000D,0x000E,0x0014,0x0015,0x0011,

                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,
                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0009,
                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,
                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0009,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x0014,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x0014,

                0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,
                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,
                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,

                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,
                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0006,
                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,
                0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,0x0006,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x0011,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,
                0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,0x0011,

                0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0002,0x0003,
                0x0004,0x0005,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,
                0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0002,0x0003,
                0x0004,0x0005,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,
                0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x000D,0x000E,
                0x000F,0x0010,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,
                0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x000D,0x000E,
                0x000F,0x0010,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,

                0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,0x0005,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,0x0005,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,0x0010,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,
                0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,0x0010,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,

                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,0x0009,
                0x0005,0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,
                0x0001,0x0002,0x0003,0x0004,0x0005,0x0002,0x0003,0x0009,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,0x0014,
                0x0010,0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,
                0x000C,0x000D,0x000E,0x000F,0x0010,0x000D,0x000E,0x0014,

                0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0017,
                0x0002,0x0003,0x0009,0x000A,0x0002,0x0003,0x000B,0x0001,
                0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,
                0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0018,
                0x000D,0x000E,0x0014,0x0015,0x000D,0x000E,0x0016,0x000C,

                0x0003,0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0019,
                0x001A,0x0008,0x0017,0x0002,0x0003,0x0009,0x000A,0x0006,
                0x0003,0x0008,0x0017,0x0002,0x0003,0x000B,0x0001,0x0019,
                0x001A,0x0008,0x0017,0x0002,0x0003,0x0009,0x000A,0x0006,
                0x000E,0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x001B,
                0x001C,0x0013,0x0018,0x000D,0x000E,0x0014,0x0015,0x0011,
                0x000E,0x0013,0x0018,0x000D,0x000E,0x0016,0x000C,0x001B,
                0x001C,0x0013,0x0018,0x000D,0x000E,0x0014,0x0015,0x0011,

                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,
                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0009,
                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0004,
                0x0005,0x0006,0x0007,0x0008,0x0017,0x0002,0x0003,0x0009,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x0014,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x000F,
                0x0010,0x0011,0x0012,0x0013,0x0018,0x000D,0x000E,0x0014,
        };

//}}BLOCK(rocks)


//{{BLOCK(sharedBackground2)

//======================================================================
//
//	sharedBackground2, 16x16@8,
//	Transparent palette entry: 0.
//	+ palette 18 entries, not compressed
//	Total size: 36 = 36
//
//	Time-stamp: 2020-01-04, 21:19:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short sharedBackground2Pal[18] __attribute__((aligned(4)))=
        {
                0x1340,0x6BDE,0x3A52,0x46D6,0x2DEF,0x29AD,0x216B,0x1D2A,
                0x14E7,0x2C47,0x3CEC,0x554F,0x6215,0x14A5,0x450E,0x1884,
                0x5DFA,0x1CA8,
        };

//}}BLOCK(sharedBackground2)

#endif //GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND3_H