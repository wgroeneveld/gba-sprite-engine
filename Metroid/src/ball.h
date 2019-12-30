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
//	Time-stamp: 2019-12-30, 23:14:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int ballTiles[64] __attribute__((aligned(4)))=
        {
                0x00000000,0x101D111A,0x26290000,0x08202B23,0x07031B00,0x15070707,0x07191E00,0x15070707,
                0x19030C00,0x25070707,0x0F050421,0x08201721,0x0707251D,0x10100806,0x07070709,0x10101007,
                0x03111D10,0x00000000,0x21162008,0x0000290F,0x07070715,0x00092807,0x07070715,0x00201907,
                0x07070725,0x00200319,0x17212008,0x0A040525,0x06081010,0x1D250707,0x07101010,0x09070707,
                0x07070724,0x10101307,0x07072103,0x10041907,0x07192400,0x0E022207,0x1C100200,0x07070127,
                0x13130100,0x07070708,0x081E0000,0x07071208,0x00000000,0x07071815,0x00000000,0x2A140D00,
                0x07131010,0x24070707,0x070B041F,0x00170707,0x070D020E,0x00241907,0x27240707,0x001E1027,
                0x08070707,0x0001131D,0x08290707,0x00001E08,0x15180707,0x00000000,0x000D1405,0x00000000,
        };

//}}BLOCK(ball)


//{{BLOCK(shared)

//======================================================================
//
//	shared, 16x16@8,
//	+ palette 63 entries, not compressed
//	Total size: 126 = 126
//
//	Time-stamp: 2019-12-30, 23:14:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short sharedPal[64] __attribute__((aligned(4)))=
        {
                0x0000,0x4211,0x1CE7,0x6B5A,0x0843,0x2D6B,0x56B5,0x7FFF,
                0x1085,0x39CE,0x4A53,0x739C,0x0001,0x6318,0x2109,0x318C,
                0x14A6,0x5AD6,0x39CF,0x0C63,0x294A,0x35AD,0x4632,0x4E74,
                0x18C7,0x77BD,0x6F7C,0x4210,0x5ED7,0x0C64,0x1CE8,0x14A5,
                0x0422,0x4E73,0x6319,0x5294,0x4631,0x318D,0x35AE,0x5EF7,
                0x6F7B,0x3DEF,0x2D6C,0x4A52,0x01A0,0x029A,0x0108,0x57DF,
                0x3DEF,0x3BE0,0x00BC,0x0074,0x01B2,0x1EA4,0x0CEC,0x259F,
                0x3BFF,0x1C20,0x05B9,0x327E,0x10FE,0x7FFF,0x0842,
        };

//}}BLOCK(shared)


#endif //GBA_SPRITE_ENGINE_PROJECT_BALL_H
