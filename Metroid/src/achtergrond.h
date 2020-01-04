//
// Created by kyles on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND_H
#define GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND_H


//{{BLOCK(dungeon_background)

//======================================================================
//
//	dungeon_background, 256x256@8,
//	Transparent palette entry: 1.
//	+ 106 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32
//	Total size: 6784 + 2048 = 8832
//
//	Time-stamp: 2020-01-03, 03:59:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int dungeon_backgroundTiles[1696] __attribute__((aligned(4)))=
        {
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x13131313,0x13130113,0x11111111,0x11171317,0x17171717,0x17111311,0x17171717,0x17111311,
                0x17171717,0x17111311,0x17171717,0x17111311,0x17171717,0x17111311,0x19191919,0x19171317,
                0x13131313,0x13131313,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171717,0x17171717,0x17171717,0x17171717,0x19191717,0x17171919,0x14151919,0x19191514,
                0x13131313,0x01131313,0x11111111,0x13171111,0x17171717,0x13111717,0x17171717,0x13111717,
                0x17171717,0x13111717,0x17171717,0x13111717,0x17171717,0x13111717,0x19191919,0x13171919,

                0x13131313,0x13131313,0x11111117,0x11111111,0x17171711,0x17171717,0x17171711,0x17171717,
                0x17171711,0x17171717,0x17171711,0x17171717,0x17171711,0x17171717,0x19191917,0x19191919,
                0x13011313,0x13131313,0x17131711,0x11111111,0x11131117,0x17171717,0x17131717,0x17171717,
                0x19011917,0x19191919,0x12121219,0x12121212,0x15151619,0x15151515,0x15151713,0x15151515,
                0x13131313,0x13130113,0x11111111,0x11171317,0x17171717,0x17111311,0x17171717,0x17111311,
                0x19191919,0x17190119,0x12121212,0x19121212,0x15151515,0x19161515,0x15151515,0x13171515,
                0x13131313,0x13011313,0x11111111,0x17131711,0x17171717,0x11131117,0x17171717,0x11131117,
                0x17171717,0x11131117,0x17171717,0x11131117,0x17171717,0x11131117,0x19191919,0x17131719,

                0x13131313,0x13131313,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171717,0x17171717,0x17171717,0x17171717,0x19171717,0x17191919,0x15191919,0x19151414,
                0x01131313,0x13131313,0x13171111,0x11111117,0x13111717,0x17171711,0x13111717,0x17171711,
                0x13111717,0x17171711,0x13111717,0x17171711,0x13111717,0x17171711,0x13171919,0x19191917,
                0x01131313,0x13131313,0x13171111,0x11111117,0x13111717,0x17171711,0x13171717,0x17171717,
                0x01191717,0x19191919,0x12121917,0x12121212,0x15161917,0x15151515,0x15171319,0x15151515,
                0x13131313,0x13011313,0x11111111,0x17131711,0x17171717,0x11131117,0x17171717,0x11131117,
                0x19191919,0x19011919,0x12121212,0x12121212,0x15151515,0x16151515,0x15151515,0x17151515,

                0x13131313,0x13131313,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171717,0x17171717,0x17171719,0x17171717,0x17171719,0x17171717,0x19191913,0x19191919,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x13131313,0x13130113,0x11111111,0x15191111,0x17171717,0x14151717,0x17171717,0x12151917,
                0x17171717,0x11121917,0x17171717,0x17121917,0x17171717,0x11151917,0x19191919,0x15151919,
                0x18141415,0x15151418,0x15141515,0x15141814,0x15151514,0x14151515,0x15181415,0x15141815,
                0x15151617,0x17161515,0x16171313,0x13131716,0x15111313,0x13131115,0x14151111,0x11111514,

                0x01131313,0x01131313,0x13171111,0x11111117,0x13111717,0x17171711,0x13111717,0x17171711,
                0x13111717,0x17171711,0x13111717,0x17171711,0x13111717,0x17171711,0x13171919,0x19191917,
                0x13131313,0x01131313,0x11111111,0x19191111,0x17171717,0x12121917,0x17171717,0x15151219,
                0x19171717,0x15151512,0x12191717,0x15151515,0x15121917,0x15151515,0x15151219,0x15151515,
                0x15121113,0x11111215,0x15161116,0x15151215,0x12171612,0x15151215,0x16111612,0x15121515,
                0x17161212,0x15121515,0x11161215,0x18141516,0x11161215,0x15151517,0x17171212,0x15151217,
                0x13131301,0x13131313,0x11111919,0x11111111,0x17191212,0x17171717,0x19121414,0x17171717,
                0x12141515,0x17171719,0x14151515,0x17171912,0x15151515,0x17191214,0x15151515,0x19121212,

                0x13131313,0x13011313,0x11111111,0x19111111,0x17171717,0x15171717,0x17171717,0x15191717,
                0x17171717,0x12191717,0x17171717,0x12191717,0x17171717,0x15191717,0x19191919,0x15191919,
                0x14141513,0x15141818,0x14151515,0x14181415,0x15151414,0x15151515,0x18141512,0x14181515,
                0x15161711,0x16151515,0x17131317,0x13171616,0x11131311,0x13111515,0x15111115,0x11151414,
                0x01131315,0x13131313,0x11191515,0x11111111,0x17151414,0x17171717,0x19151215,0x17171717,
                0x19121117,0x17171717,0x19121713,0x17171717,0x19151113,0x17171717,0x19151511,0x19191919,
                0x13131301,0x13131313,0x11111111,0x19111111,0x17171717,0x12191717,0x17171717,0x15121917,
                0x17171717,0x15151219,0x19171717,0x15151512,0x12191717,0x15151515,0x15121919,0x15151515,

                0x12111301,0x11121515,0x16111619,0x15121515,0x17161212,0x15121512,0x11161215,0x12151516,
                0x16121215,0x12151517,0x16121515,0x14151611,0x16121515,0x15151711,0x17121215,0x15121717,
                0x12111111,0x11121515,0x12151515,0x11161515,0x12151515,0x16171215,0x15121515,0x16111615,
                0x15121515,0x12161715,0x15141818,0x12161116,0x15151515,0x12161117,0x12151515,0x12171717,
                0x13130113,0x13131313,0x11191916,0x11111111,0x19121212,0x17171717,0x12141412,0x17171719,
                0x14151512,0x17171912,0x15151515,0x17191214,0x15151515,0x19121415,0x15151512,0x12121215,
                0x13130113,0x13130113,0x11111111,0x11171317,0x17171717,0x17111311,0x17171717,0x17111311,
                0x17171717,0x17111311,0x17171717,0x17111311,0x17171717,0x17111311,0x19191919,0x19171317,

                0x01131313,0x14011313,0x13171111,0x15191717,0x13111717,0x14121911,0x13111717,0x12161911,
                0x13111717,0x16191911,0x13111717,0x19171711,0x13111717,0x17171711,0x13171919,0x19191917,
                0x11181515,0x15151811,0x13151814,0x14181513,0x12171414,0x14141712,0x15151415,0x15141515,
                0x15121212,0x12121215,0x14151613,0x13161514,0x15151319,0x19131515,0x16151619,0x19151615,
                0x01131313,0x19011313,0x11111111,0x12191711,0x17171717,0x15121717,0x17171717,0x15151917,
                0x17171717,0x15151219,0x19171717,0x15151512,0x19171717,0x15151515,0x12191719,0x15151515,
                0x15151512,0x12151515,0x15151515,0x17121515,0x15151515,0x11171215,0x15151515,0x19111712,
                0x12151515,0x00191117,0x17151515,0x00001911,0x11121515,0x00000019,0x19171215,0x00000000,

                0x19111117,0x12121119,0x00001911,0x11111900,0x00000019,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00111212,0x17111100,0x00171111,0x11000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x12151512,0x12141416,0x16121217,0x14151514,0x14121711,0x15151515,0x12171119,0x15151515,
                0x17111900,0x15151512,0x11190000,0x15151517,0x19000000,0x15151211,0x00000000,0x12121719,
                0x13130119,0x13131301,0x11171912,0x11111111,0x17171214,0x17171717,0x17191415,0x17171717,
                0x19121515,0x17171717,0x12121515,0x17171719,0x14161215,0x17171719,0x15141416,0x19171912,

                0x13131313,0x01131301,0x17111111,0x19171713,0x11171717,0x12191113,0x11171717,0x16191113,
                0x11171717,0x19191113,0x11171717,0x17171113,0x11171717,0x17171113,0x17191919,0x19191713,
                0x18151514,0x15181111,0x15181415,0x18151313,0x17141414,0x14171212,0x15141512,0x14151515,
                0x12121216,0x12121515,0x15161319,0x16151414,0x15131917,0x13151515,0x15161919,0x15161516,
                0x13011415,0x13130113,0x17191514,0x11171317,0x19121414,0x17111311,0x19161215,0x17111311,
                0x19191612,0x17111311,0x17171913,0x17111311,0x17171719,0x17111311,0x19191919,0x19171317,
                0x13131313,0x01131301,0x11111111,0x19171111,0x17171717,0x12171717,0x17171717,0x15191717,
                0x17171717,0x15121917,0x17171717,0x15151219,0x17171717,0x15151519,0x19171919,0x15151512,

                0x15151219,0x15151515,0x15151512,0x12151515,0x15151515,0x17121515,0x15151515,0x11171215,
                0x15151515,0x19111712,0x15151515,0x00191117,0x12151515,0x00001911,0x17121515,0x00000019,
                0x11111712,0x12111919,0x00191117,0x11190000,0x00001911,0x00000000,0x00000019,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x11121212,0x11110000,0x17111111,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x15151217,0x14141612,0x12121711,0x15151416,0x12171100,0x15151514,0x17111900,0x15151512,
                0x11190000,0x15151217,0x19000000,0x15151711,0x00000000,0x15121119,0x00000000,0x12171900,

                0x13011912,0x13130113,0x17191214,0x11111111,0x17121415,0x17171717,0x19141515,0x17171717,
                0x12151515,0x17171719,0x12151515,0x17171912,0x16121515,0x17171914,0x14141612,0x17191215,
                0x01131313,0x13131313,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171719,0x17171717,0x17171713,0x17171717,0x17171912,0x17171717,0x19191315,0x19191919,
                0x01131313,0x13131313,0x13191919,0x11191919,0x13111717,0x17171717,0x13111717,0x17171711,
                0x13111717,0x17171711,0x13111717,0x17171711,0x13111717,0x17171711,0x13171919,0x19191917,
                0x15120113,0x15151515,0x15151911,0x15151515,0x15151219,0x15151515,0x15151513,0x12151515,
                0x15151512,0x17121515,0x15151515,0x11171515,0x15151515,0x19111215,0x15151515,0x00191715,

                0x00111715,0x00000000,0x00191112,0x00000000,0x00001917,0x00000000,0x00000011,0x00000000,
                0x00000019,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x12171100,0x00000000,0x12111900,0x00000000,0x17190000,0x00000000,0x11000000,
                0x00000000,0x19000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x15151514,0x13011215,0x15151515,0x11191515,0x15151515,0x19121515,0x15151512,0x13151515,
                0x15151217,0x12151515,0x15151711,0x12161215,0x12121119,0x14141216,0x12171900,0x15151414,
                0x13131313,0x13131301,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171919,0x17171717,0x17171313,0x17171717,0x17191212,0x17171717,0x19131515,0x19191919,

                0x13131313,0x13131301,0x19191911,0x19191913,0x11171717,0x17171713,0x11171717,0x17171113,
                0x11171717,0x17171113,0x11171717,0x17171113,0x11171717,0x17171113,0x17191919,0x19191713,
                0x13131313,0x13130113,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171717,0x17171717,0x17171717,0x17171717,0x17171717,0x19171717,0x19191919,0x13191919,
                0x12011313,0x15151515,0x15191111,0x15151515,0x15121917,0x15151515,0x15151317,0x15151515,
                0x15151219,0x12151515,0x15151513,0x17151515,0x15151512,0x11121515,0x15151515,0x19171515,
                0x11171515,0x00000000,0x19111215,0x00000000,0x00191715,0x00000000,0x00001112,0x00000000,
                0x00001917,0x00000000,0x00000011,0x00000000,0x00000019,0x00000000,0x00000000,0x00000000,

                0x00000000,0x17110000,0x00000000,0x11190000,0x00000000,0x19000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x15151412,0x01121515,0x15151512,0x19151515,0x15151517,0x12151515,0x15151211,0x15151515,
                0x15121719,0x15151515,0x15171100,0x16121515,0x12111900,0x14121612,0x17190000,0x15141412,
                0x13131215,0x13131301,0x17191515,0x11111713,0x17121515,0x17171113,0x19151515,0x17171113,
                0x13151515,0x17171101,0x12151515,0x17171101,0x15151515,0x17171101,0x15151515,0x19191713,
                0x01131313,0x13131313,0x11111111,0x11111111,0x17171717,0x17171717,0x17171717,0x17171717,
                0x17171717,0x17171717,0x17171717,0x17171717,0x17171717,0x17171717,0x19191919,0x19191919,

                0x15151515,0x00001112,0x15151515,0x00001917,0x12151515,0x00000011,0x17151515,0x00000019,
                0x11121515,0x00000000,0x11171515,0x00000000,0x19111515,0x00000000,0x00111215,0x00000000,
                0x12110000,0x15151515,0x17190000,0x15151515,0x11000000,0x15151512,0x19000000,0x15151517,
                0x00000000,0x15151211,0x00000000,0x15151711,0x00000000,0x15151119,0x00000000,0x16121100,
                0x13121515,0x13130113,0x19151515,0x11171317,0x12151515,0x17111317,0x15151515,0x17111319,
                0x15151515,0x17110113,0x15151515,0x17110112,0x15151512,0x17110115,0x15151516,0x19171315,
                0x13131313,0x12131301,0x17111111,0x15191713,0x11171717,0x15121713,0x11171717,0x15151913,
                0x11171717,0x15151301,0x11171717,0x15151201,0x11171717,0x15151501,0x17191919,0x15151513,

                0x15151515,0x00111215,0x15151515,0x00191715,0x15151515,0x00001112,0x15151515,0x00001917,
                0x12151515,0x00000011,0x17151515,0x00000011,0x11151515,0x00000019,0x11121515,0x00000000,
                0x11000000,0x15151512,0x19000000,0x15151517,0x00000000,0x15151211,0x00000000,0x15151719,
                0x00000000,0x15121100,0x00000000,0x15171100,0x00000000,0x15111900,0x00000000,0x12110000,
                0x13131215,0x13131301,0x17191515,0x11111713,0x17121515,0x17171113,0x19151515,0x17171113,
                0x13151515,0x17171101,0x12121515,0x17171101,0x12161612,0x17171101,0x14141216,0x19191713,
                0x15151515,0x13130112,0x15151515,0x11171915,0x15151515,0x17191215,0x15151515,0x17191515,
                0x15151515,0x19131515,0x15151512,0x19121515,0x15151517,0x19151515,0x12121211,0x13121212,

                0x01131313,0x13131313,0x13171111,0x11111117,0x13111717,0x17171711,0x13111717,0x17171711,
                0x13111717,0x17171711,0x13111717,0x17171711,0x13111717,0x17171711,0x13111717,0x17171711,
                0x00191715,0x00000000,0x00001115,0x00000000,0x00001112,0x00000000,0x00001917,0x00000000,
                0x00000011,0x00000000,0x00000011,0x00000000,0x00000019,0x00000000,0x00000000,0x00000000,
                0x00000000,0x14171900,0x00000000,0x15110000,0x00000000,0x12110000,0x00000000,0x17190000,
                0x00000000,0x11000000,0x00000000,0x11000000,0x00000000,0x19000000,0x00000000,0x00000000,
                0x15151514,0x13011215,0x15151515,0x17191515,0x15151515,0x19121515,0x15151515,0x19151515,
                0x15151515,0x13151515,0x15151212,0x12151515,0x15151717,0x15151515,0x12121111,0x12121212,

                0x13131313,0x13131301,0x17111111,0x11111713,0x11171717,0x17171113,0x11171717,0x17171113,
                0x11171719,0x17171113,0x11171719,0x17171113,0x11171719,0x17171113,0x11171713,0x17171113,
                0x01131313,0x15151512,0x19171111,0x15151515,0x12191717,0x15151515,0x15191717,0x15151515,
                0x15131917,0x15151515,0x15121917,0x15151515,0x15151917,0x15151515,0x12121317,0x12121212,
                0x19171515,0x00000000,0x00111515,0x00000000,0x00111215,0x00000000,0x00191715,0x00000000,
                0x00001115,0x00000000,0x00001112,0x00000000,0x00001917,0x00000000,0x00000011,0x00000000,
                0x00000000,0x17190000,0x00000000,0x11000000,0x00000000,0x11000000,0x00000000,0x19000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x15151514,0x13130112,0x15151515,0x11171915,0x15151515,0x17191215,0x15151515,0x17191515,
                0x15151515,0x19131515,0x15151512,0x19121515,0x15151517,0x19151515,0x12121211,0x13121212,
                0x11111719,0x13191711,0x18181818,0x14141414,0x15151515,0x15151515,0x15151512,0x15151515,
                0x15151511,0x15151515,0x15151200,0x15151515,0x15121100,0x15151515,0x12110000,0x12121212,
                0x01171717,0x19191917,0x14141414,0x14141414,0x15151515,0x15151515,0x15151515,0x15151515,
                0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x12121212,0x12121212,
                0x11171919,0x19171111,0x18181818,0x14141418,0x15151515,0x15151515,0x15151212,0x15151515,
                0x15151111,0x15151515,0x15120000,0x15151515,0x12110000,0x15151515,0x11000000,0x12121212,

                0x17171713,0x19191701,0x14141414,0x14141414,0x15151515,0x15151515,0x15151515,0x15151515,
                0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x12121212,0x12121212,
                0x17191319,0x17111111,0x14141414,0x18181814,0x15151515,0x15151515,0x15151515,0x15151515,
                0x15151515,0x15151515,0x15151515,0x12151515,0x15151515,0x11121515,0x12121212,0x00111212,
                0x00000019,0x00000000,0x00000018,0x00000000,0x00000015,0x00000000,0x00000012,0x00000000,
                0x00000011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x11170117,0x00000000,0x11110117,0x00000000,0x11110117,0x00000000,0x16111711,
                0x00000000,0x16111711,0x00000000,0x16161711,0x00000000,0x16161711,0x00000000,0x16161711,

                0x11111711,0x11171111,0x16161711,0x11171616,0x16161116,0x16171616,0x16161116,0x16171616,
                0x16161116,0x16171616,0x12161116,0x16171612,0x12121116,0x16171212,0x15151116,0x16171215,
                0x00000000,0x17011700,0x00000000,0x11011700,0x00000000,0x11011700,0x00000000,0x11171100,
                0x00000000,0x11171100,0x00000000,0x16171100,0x00000000,0x16171100,0x00000000,0x16171100,
                0x11171111,0x17111111,0x16171111,0x17161616,0x16111611,0x17161616,0x16111616,0x17161616,
                0x16111616,0x17161616,0x16111616,0x17161212,0x12111616,0x17121212,0x15111616,0x17121515,
                0x01171111,0x00000017,0x01111111,0x00000017,0x01111116,0x00000017,0x17111616,0x00000011,
                0x17111616,0x00000011,0x17161616,0x00000011,0x17161616,0x00000011,0x17161616,0x00000011,

                0x00000000,0x16161716,0x00000000,0x12161716,0x00000000,0x12161716,0x00000000,0x15121716,
                0x00000000,0x15121716,0x00000000,0x15151716,0x00000000,0x15151716,0x00000000,0x15151716,
                0x15141612,0x12111515,0x15141615,0x14111515,0x15141615,0x14111515,0x15141615,0x14111515,
                0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,
                0x00000000,0x16171600,0x00000000,0x16171600,0x00000000,0x16171600,0x00000000,0x12171600,
                0x00000000,0x12171600,0x00000000,0x15171600,0x00000000,0x15171600,0x00000000,0x15171600,
                0x14161216,0x11151515,0x14161512,0x11151515,0x14161512,0x11151515,0x14161515,0x11151515,
                0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,

                0x17161612,0x00000016,0x17161214,0x00000016,0x17161214,0x00000016,0x17121514,0x00000016,
                0x17121518,0x00000016,0x17151518,0x00000016,0x17151518,0x00000016,0x17151518,0x00000016,
                0x00000000,0x15151716,0x00000000,0x15151716,0x00000000,0x15151716,0x00000000,0x15151716,
                0x00000000,0x15151716,0x00000000,0x15151716,0x00000000,0x15151716,0x00000000,0x15151716,
                0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,
                0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,
                0x00000000,0x15171600,0x00000000,0x15171600,0x00000000,0x15171600,0x00000000,0x15171600,
                0x00000000,0x15171600,0x00000000,0x15171600,0x00000000,0x15171600,0x00000000,0x15171600,

                0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,
                0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,
                0x17151518,0x00000016,0x17151518,0x00000016,0x17151518,0x00000016,0x17151518,0x00000016,
                0x17151518,0x00000016,0x17151518,0x00000016,0x17151518,0x00000016,0x17151518,0x00000016,
                0x12151414,0x15151716,0x17161212,0x15151716,0x17161212,0x15151716,0x17161212,0x15151716,
                0x17161212,0x15121711,0x17161212,0x15121711,0x17111612,0x12161711,0x17171116,0x16161711,
                0x15181615,0x18111515,0x15181615,0x18111515,0x15181615,0x18111515,0x15141615,0x18111515,
                0x15141615,0x14111515,0x15141615,0x14111515,0x15141612,0x15111515,0x12151116,0x15171212,

                0x18181818,0x18181818,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,
                0x15151515,0x15151515,0x15151512,0x15151515,0x12121212,0x12121212,0x16161616,0x16161616,
                0x18181818,0x18181818,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,
                0x15151515,0x15151515,0x15151515,0x15151515,0x12121212,0x12121212,0x16161616,0x16161616,
                0x15141414,0x15171612,0x16121212,0x15171617,0x16121212,0x15171617,0x16121212,0x15171617,
                0x16121212,0x12171117,0x16121212,0x12171117,0x11161212,0x16171117,0x17111616,0x16171117,
                0x18161515,0x11151515,0x18161515,0x11151515,0x18161515,0x11151515,0x14161515,0x11151515,
                0x14161515,0x11151515,0x14161515,0x11151515,0x14161212,0x11151515,0x15111616,0x17121212,

                0x17151518,0x14151216,0x17151518,0x12161716,0x17151518,0x12161716,0x17151518,0x12161716,
                0x17121514,0x12161711,0x17121514,0x12161711,0x17161215,0x16111711,0x17161615,0x11171711,
                0x18181814,0x18181818,0x15151512,0x15151515,0x15151512,0x15151515,0x15151512,0x15151515,
                0x15151512,0x15151515,0x15151212,0x15151515,0x12121212,0x12121212,0x16161616,0x16161616,
        };

const unsigned short dungeon_backgroundMap[1024] __attribute__((aligned(4)))=
        {
                0x1001,0x1002,0x1401,0x1003,0x1004,0x1005,0x1006,0x1404,
                0x0403,0x1007,0x1008,0x1009,0x1404,0x0403,0x100A,0x100B,
                0x100C,0x1407,0x1001,0x1002,0x1401,0x1003,0x1004,0x1005,
                0x1006,0x1404,0x0403,0x1001,0x1002,0x1401,0x000D,0x000D,
                0x100E,0x100F,0x140E,0x1010,0x1011,0x1012,0x1412,0x0013,
                0x0410,0x1014,0x1015,0x1016,0x1409,0x0017,0x0018,0x1019,
                0x101A,0x101B,0x100E,0x100F,0x140E,0x1010,0x1011,0x1012,
                0x1412,0x0013,0x0410,0x100E,0x100F,0x140E,0x000D,0x000D,

                0x101C,0x101D,0x141C,0x101E,0x101F,0x1020,0x1021,0x1022,
                0x1023,0x1024,0x1025,0x1026,0x1027,0x1028,0x1029,0x102A,
                0x102B,0x102C,0x101C,0x101D,0x141C,0x101E,0x101F,0x1020,
                0x1021,0x1022,0x1023,0x101C,0x101D,0x141C,0x000D,0x000D,
                0x102D,0x102E,0x142D,0x102F,0x1030,0x0000,0x0000,0x1031,
                0x1032,0x1033,0x1034,0x1035,0x1036,0x1037,0x0000,0x0000,
                0x1038,0x1039,0x102D,0x102E,0x142D,0x102F,0x1030,0x0000,
                0x0000,0x1031,0x1032,0x102D,0x102E,0x142D,0x000D,0x000D,

                0x103A,0x103B,0x143A,0x103C,0x0000,0x0000,0x0000,0x0000,
                0x103D,0x103E,0x143B,0x103F,0x1040,0x0000,0x0000,0x0000,
                0x0000,0x1041,0x103A,0x103B,0x143A,0x103C,0x0000,0x0000,
                0x0000,0x0000,0x103D,0x1042,0x103B,0x143A,0x000D,0x000D,
                0x1043,0x1044,0x1443,0x1045,0x0000,0x0000,0x0000,0x0000,
                0x1046,0x1047,0x1048,0x1049,0x104A,0x0000,0x0000,0x0000,
                0x0000,0x104B,0x1043,0x1044,0x1443,0x1045,0x0000,0x0000,
                0x0000,0x0000,0x1046,0x104C,0x1044,0x1443,0x000D,0x000D,

                0x104D,0x104E,0x144D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x104F,0x1050,0x1051,0x1052,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x104D,0x104E,0x144D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x104D,0x104E,0x144D,0x000D,0x000D,
                0x1053,0x1054,0x1453,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x1055,0x1056,0x1057,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x1053,0x1054,0x1453,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x1053,0x1054,0x1453,0x000D,0x000D,

                0x1058,0x1059,0x1458,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105A,0x105B,0x105C,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x1058,0x1059,0x1458,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x1058,0x1059,0x1458,0x000D,0x000D,
                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,

                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,
                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,

                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,
                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,

                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,
                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,

                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,
                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,

                0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x105F,0x1060,0x1061,0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x105D,0x105E,0x145D,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x105D,0x105E,0x145D,0x000D,0x000D,
                0x1062,0x1063,0x1462,0x1064,0x1065,0x1065,0x1065,0x1065,
                0x1464,0x1066,0x1067,0x1068,0x1069,0x1065,0x1065,0x1065,
                0x1065,0x1065,0x1062,0x1063,0x1462,0x1064,0x1065,0x1065,
                0x1065,0x1065,0x1464,0x1062,0x1063,0x1462,0x000D,0x000D,

                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,

                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,

                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,

                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,

                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,

                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
                0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,
        };

//}}BLOCK(dungeon_background)


//{{BLOCK(sharedBackground)

//======================================================================
//
//	sharedBackground, 16x16@8,
//	Transparent palette entry: 1.
//	+ palette 26 entries, not compressed
//	Total size: 52 = 52
//
//	Time-stamp: 2020-01-03, 03:59:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short sharedBackgroundPal[26] __attribute__((aligned(4)))=
        {
                0x1340,0x0000,0x1884,0x1CA6,0x24E8,0x2D29,0x356A,0x35CE,
                0x3DAD,0x216B,0x3A52,0x42F6,0x4F5A,0x5F9C,0x57DD,0x6FFF,
                0x7FFF,0x3548,0x3273,0x1464,0x475C,0x3AF9,0x31EE,0x28E8,
                0x57BF,0x1CA5,
        };

//}}BLOCK(sharedBackground)


#endif // GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND_H