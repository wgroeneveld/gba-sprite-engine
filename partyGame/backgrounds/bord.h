
//{{BLOCK(bord)

//======================================================================
//
//	bord, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 160 tiles (t reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 10240 + 2048 = 12800
//
//	Time-stamp: 2020-08-12, 14:13:54
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BORD_H
#define GRIT_BORD_H

#define bordTilesLen 10240
extern const unsigned short bordTiles[5120];

#define bordMapLen 2048
extern const unsigned short bordMap[1024];

#define bordPalLen 512
extern const unsigned short bordPal[256];

#endif // GRIT_BORD_H

//}}BLOCK(bord)
