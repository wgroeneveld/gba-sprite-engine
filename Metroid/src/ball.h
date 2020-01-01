//
// Created by kyles on 30/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BALL_H
#define GBA_SPRITE_ENGINE_PROJECT_BALL_H

//{{BLOCK(ball)

//======================================================================
//
//	ball, 16x16@8,
//	+ 4 tiles not compressed
//	Total size: 256 = 256
//
//	Time-stamp: 2020-01-01, 22:38:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int ballTiles[64] __attribute__((aligned(4)))=
        {
                0x00000000,0x080B0305,0x010A0000,0x060D0A03,0x02030A00,0x03020202,0x02020100,0x03020202,
                0x02030700,0x03020202,0x03030403,0x010D0303,0x0202030B,0x01010603,0x02020203,0x01010102,
                0x05030B08,0x00000000,0x030A0D06,0x00000A01,0x02020203,0x000A0302,0x02020203,0x000D0202,
                0x02020203,0x000D0302,0x03030D01,0x03040303,0x03060101,0x0B030202,0x02010101,0x03020202,
                0x0202020A,0x01010902,0x02020A05,0x01040202,0x02020A00,0x04030302,0x03080100,0x02020103,
                0x09090A00,0x02020206,0x06010000,0x02020A06,0x00000000,0x02020C0A,0x00000000,0x08010500,
                0x02090101,0x0A020202,0x02020401,0x000A0202,0x02030304,0x000A0202,0x03010202,0x00010803,
                0x06020202,0x000A090B,0x060A0202,0x00000106,0x0A0C0202,0x00000000,0x00050108,0x00000000,
        };

//}}BLOCK(ball)



//{{BLOCK(shared)

//======================================================================
//
//	shared, 16x16@8,
//	+ palette 38 entries, not compressed
//	Total size: 76 = 76
//
//	Time-stamp: 2020-01-01, 22:38:16
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short sharedPal[38] __attribute__((aligned(4)))=
        {
                0x0000,0x19D0,0x2F5D,0x1235,0x0843,0x2A97,0x1085,0x0001,
                0x14A6,0x0C63,0x2698,0x0C64,0x18C7,0x0422,0x01A0,0x029A,
                0x0108,0x57DF,0x3DEF,0x3BE0,0x00BC,0x0074,0x01B2,0x1EA4,
                0x0CEC,0x259F,0x3BFF,0x1C20,0x294A,0x4D20,0x05B9,0x327E,
                0x2494,0x7FFF,0x0842,0x0CDE,0x739C,0x42FE,
        };

//}}BLOCK(shared)



#endif //GBA_SPRITE_ENGINE_PROJECT_BALL_H
