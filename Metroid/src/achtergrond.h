//
// Created by kyles on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND_H
#define GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND_H


//{{BLOCK(tussenscherm)

//======================================================================
//
//	tussenscherm, 256x256@8,
//	Transparent palette entry: 1.
//	+ palette 256 entries, not compressed
//	+ 86 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32
//	Total size: 512 + 5504 + 2048 = 8064
//
//	Time-stamp: 2020-01-09, 19:44:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int tussenschermTiles[1376] __attribute__((aligned(4)))=
        {
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0D0101,0x01010A0B,
                0x0B0D0101,0x0111080B,0x0B0D0101,0x0103140E,0x0B0D0101,0x07130F17,0x0B0D0101,0x0412000C,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0B0001,
                0x01010101,0x0B0B0F06,0x01010101,0x0B15120D,0x01010101,0x0B181309,0x02010101,0x0B0D0314,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0D01010C,0x01010C0B,
                0x0D01010C,0x01010C0B,0x0D01010C,0x10010C0B,0x0D01010C,0x10010C0B,0x0D01010C,0x06010C0B,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0B0D01,0x0107130B,
                0x010C0B00,0x010A0001,0x01071305,0x01010101,0x01010A05,0x01010101,0x010C0B0F,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0D0101,0x07130B0B,
                0x0C0B0001,0x0A000101,0x07130510,0x01010101,0x010A0510,0x01010101,0x0C0B0F06,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0D0101,0x0101010C,
                0x0B0D0101,0x0101010C,0x0B0D0101,0x0201010C,0x0B0D0101,0x0001010C,0x0B0D0101,0x0F06010C,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B051001,0x04120B0B,
                0x010A0B0D,0x0B000101,0x01010A14,0x00010101,0x01010412,0x10010101,0x01010713,0x06010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0C0B0B0D,
                0x0101010A,0x130B0B0D,0x01010C0B,0x0B190B0D,0x01010A05,0x0F170B0D,0x0111080F,0x0D0C0B0D,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x010C0B0D,
                0x01010107,0x010C0B0D,0x01010103,0x010C0B0D,0x01011108,0x010C0B0D,0x0101030B,0x010C0B0D,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x06010101,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x080B0001,0x01010111,
                0x141A0F06,0x0101010C,0x0F171402,0x0101010A,0x09110800,0x01011108,0x0D010A0F,0x01010C0B,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0B0901,
                0x02010101,0x01071314,0x05100101,0x01010713,0x12000101,0x01010104,0x080F0601,0x01010111,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x010C0B0B,0x01010101,
                0x0C051001,0x14020101,0x01010101,0x13051001,0x01010101,0x04120001,0x01010101,0x11080F06,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0B0B09,0x01010C0B,
                0x01010713,0x010C0510,0x01010107,0x01010101,0x01010101,0x01010101,0x01010101,0x06010101,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x05100101,0x120B0B0B,
                0x0A0B0D01,0x00010101,0x010A1402,0x01010101,0x01041200,0x01010101,0x0107130F,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010104,0x0B0B0D01,
                0x01010A0B,0x0B0B0D01,0x010C0B00,0x0E0B0D01,0x010A0510,0x170B0D01,0x11080F06,0x0C0B0D01,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0101010A,0x01010101,
                0x01011108,0x06010101,0x01010314,0x0D010101,0x0107130F,0x09010101,0x01041200,0x14020101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0C0B0B00,0x0B0D0101,
                0x0C0B0B0F,0x0B0D0101,0x0C0B1512,0x0B0D0101,0x0C0B1813,0x0B0D0101,0x0C0B0D03,0x0B0D0101,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B0B0B0B,0x0101010C,
                0x0001010C,0x0101030B,0x0601010C,0x0111080F,0x0101010C,0x01041200,0x0101010C,0x01041200,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01041200,0x01010101,
                0x01041200,0x01010101,0x01041200,0x01010101,0x01041200,0x01010101,0x01041200,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x010C0B0D,0x0B0D0101,
                0x010C0B0D,0x0C0B0001,0x010C0B0D,0x07130510,0x010C0B0D,0x010A0510,0x010C0B0D,0x0C0B0F06,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x07130B0B,0x0B0D0101,
                0x0A000101,0x0B0D0101,0x01010101,0x0B0D0101,0x01010101,0x0B0D0101,0x01010101,0x0B0D0101,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0101010C,0x03140201,
                0x0101010C,0x03140201,0x0101010C,0x03140201,0x0101010C,0x03140201,0x0101010C,0x03140201,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x14020101,0x0B0B0B0B,
                0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010A0B,0x0B0B0B0D,
                0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x11080B0B,0x01010101,
                0x0B0F0601,0x01010103,0x09010101,0x01010412,0x10010101,0x01010A05,0x01010101,0x01110809,

                0x0B0D0101,0x0A14020C,0x0B0D0101,0x0809010C,0x0B0D0101,0x0B0D010C,0x0B0D0101,0x0510010C,
                0x0B0D0101,0x0901010C,0x0B0D0101,0x0201010C,0x0B0D0101,0x0601010C,0x0B0D0101,0x0101010C,
                0x00010101,0x0B0D1108,0x0F060111,0x0B0D010A,0x0B0D010C,0x0B0D010C,0x13090713,0x0B0D0107,
                0x03051612,0x0B0D0101,0x04120B14,0x0B0D0101,0x010A0B0F,0x0B0D0101,0x010C0B00,0x0B0D0101,
                0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,
                0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,0x0D01010C,0x0D010C0B,0x0D01010C,0x01010C0B,
                0x080B1402,0x01010111,0x0B0F0601,0x0107130B,0x06010101,0x07130B0F,0x01010101,0x0C0B0901,
                0x01010101,0x0C0B0D01,0x01010101,0x04120001,0x01011108,0x010A0B0D,0x0B0B0B0D,0x0101030B,

                0x0B140201,0x01011108,0x0F060101,0x07130B0B,0x01010101,0x130B0F06,0x01010101,0x0B090101,
                0x01010101,0x0B0D0101,0x01010101,0x12000101,0x0111080D,0x0A0B0D01,0x0B0B0D01,0x01030B0B,
                0x0B0D0101,0x0510010C,0x0B0D0101,0x0510010C,0x0B0D0107,0x0510010C,0x0B0D010C,0x0F06010C,
                0x0B0D010C,0x0901010C,0x0B0D0104,0x0D01010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,
                0x0101010A,0x01010101,0x0101010A,0x01010101,0x0101010A,0x01010101,0x01010713,0x06010101,
                0x01011108,0x10010101,0x0101030B,0x00010101,0x01030B00,0x0B090101,0x0B140201,0x11080B0B,
                0x01110809,0x060C0B0D,0x01041209,0x010C0B0D,0x01110809,0x010C0B0D,0x0107130F,0x010C0B0D,
                0x01010A05,0x010C0B0D,0x01010412,0x010C0B0D,0x0101010C,0x010C0B0D,0x01010101,0x010C0B0D,

                0x0111080F,0x010C0B0D,0x010A0B0D,0x010C0B0D,0x04120F06,0x010C0B0D,0x0A140201,0x010C0B0D,
                0x12090101,0x010C0B15,0x14020101,0x010C0B0B,0x09010101,0x010C0B0B,0x10010101,0x010C0B05,
                0x01010101,0x02010101,0x01010101,0x00010101,0x01010101,0x0F060101,0x01010101,0x14020101,
                0x01010101,0x0B000101,0x01010101,0x130F0601,0x01010101,0x030B0D01,0x01010101,0x04120901,
                0x10010314,0x01010A05,0x06010412,0x0104120F,0x01011108,0x01030B00,0x0101010A,0x07131402,
                0x0B0B0B0B,0x04120B0B,0x01010107,0x030B0001,0x01010101,0x13051001,0x01010101,0x12090101,
                0x13051001,0x01010107,0x0A051001,0x01010101,0x13051001,0x01010107,0x130F0601,0x01010107,
                0x12000101,0x01010104,0x14020101,0x0101010A,0x0D010107,0x0107130B,0x01010104,0x0B0B0510,

                0x01010101,0x07130510,0x01010101,0x010A0510,0x01010101,0x07130510,0x01010101,0x07130F06,
                0x01010101,0x04120001,0x01010101,0x0A140201,0x030F0601,0x0B0D0101,0x010C0B0B,0x10010101,
                0x01010101,0x10010101,0x01010101,0x10010101,0x01010101,0x10010101,0x01010101,0x06010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010713,0x01030F06,0x0B0B0B05,0x01010C0B,
                0x01010A05,0x01010101,0x01010A05,0x01010101,0x01010A05,0x01010101,0x0107130F,0x01010101,
                0x01110809,0x01010101,0x01030B0D,0x01010101,0x030B0001,0x09010101,0x14020101,0x080B0B0B,
                0x11080901,0x0C0B0D01,0x04120901,0x0C0B0D01,0x11080901,0x0C0B0D01,0x07130F06,0x0C0B0D01,
                0x010A0510,0x0C0B0D01,0x01041200,0x0C0B0D01,0x01010C0B,0x0C0B0D01,0x01010111,0x0C0B0D01,

                0x010A1402,0x08000101,0x11080901,0x0A0F0601,0x0C0B0D01,0x0C0B0D01,0x13051001,0x07130907,
                0x12090101,0x01030516,0x14020101,0x0104120B,0x0F060101,0x01010A0B,0x00010101,0x01010C0B,
                0x0C0B0D11,0x0B0D0101,0x0C0B0D01,0x0B0D0101,0x0C0B0D01,0x0B0D0101,0x0C0B0D01,0x0B0D0101,
                0x0C0B0D01,0x0B0D0101,0x0C0B0D01,0x0B0D0101,0x0C0B0D01,0x0B0D0101,0x0C0B0D01,0x0B0D0101,
                0x0601010C,0x0107130F,0x0901010C,0x01010C0B,0x120B0B0B,0x01010104,0x0101010C,0x01010101,
                0x0101010C,0x01010101,0x0101010C,0x01010101,0x0101010C,0x01010101,0x0101010C,0x01010101,
                0x01041200,0x01010101,0x01041200,0x01010101,0x01041200,0x01010101,0x01041200,0x01010101,
                0x01041200,0x01010101,0x01041200,0x01010101,0x01041200,0x01010101,0x0B0B0B00,0x04120B0B,

                0x010C0B0D,0x0B140201,0x010C0B0D,0x0F060101,0x010C0B0D,0x01010101,0x010C0B0D,0x01010101,
                0x010C0B0D,0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,0x0111080D,0x010C0B0D,0x0B0B0D01,
                0x01011108,0x0B0D0101,0x07130B0B,0x0B0D0101,0x130B0F06,0x0B0D0107,0x0B090101,0x0B0D010C,
                0x0B0D0101,0x0B0D010C,0x12000101,0x0B0D0104,0x0A0B0D01,0x0B0D0101,0x01030B0B,0x0B0D0101,
                0x0101010C,0x03140201,0x0B0B0B0B,0x030B0B0B,0x0101010C,0x03140201,0x0101010C,0x03140201,
                0x0101010C,0x03140201,0x0101010C,0x03140201,0x0101010C,0x03140201,0x0101010C,0x03140201,
                0x0B0D0101,0x0101010C,0x0B0D0101,0x0B0B0B0B,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,
                0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x14020101,0x0B0B0B0B,

                0x01010101,0x010C0B0D,0x01011108,0x010C0B0D,0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,
                0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,0x01010101,0x010C0B0D,0x0107130B,0x0B0B0B0D,
                0x01010101,0x01041209,0x01010101,0x01041200,0x01010101,0x01041209,0x01010101,0x01110809,
                0x10010101,0x01010A05,0x00010101,0x01010412,0x0B090101,0x0101010C,0x07130B0B,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x04120001,0x01010101,0x04120001,0x01010101,0x04120001,0x01010101,0x04120001,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x10010101,0x0B0B0B05,0x0B0D0101,0x0101010A,0x0A140201,0x01010101,0x04120001,0x01010101,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010412,0x01010101,0x010A0B00,0x01010101,0x0C0B0001,0x01010101,0x0A051001,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x080B0001,0x01010111,0x141A0F06,0x0101010C,0x0F171402,0x0101010A,0x09110800,0x01011108,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x0B0D0101,0x0B0B0B0B,0x0B0D0101,0x0601010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01011108,0x0B0D0101,0x01030B0F,0x0B0D0101,0x04120901,0x0B0D0101,0x0A051001,0x0B0D0101,

                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x0D01010C,0x010C0B0B,0x0D01010C,0x07130B0B,0x0D01010C,0x030B190B,0x0D01010C,0x080F170B,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x0D010101,0x01010C0B,0x0D010101,0x01010C0B,0x0D010101,0x01010C0B,0x0D010111,0x01010C0B,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x0D010101,0x0B0B0B0B,0x12051001,0x01010104,0x11080F06,0x01010101,0x010C0B00,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x0101030B,0x01010101,0x01030510,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,

                0x04120001,0x01010101,0x04120001,0x01010101,0x04120001,0x01010101,0x04120001,0x01010101,
                0x04120001,0x01010101,0x04120001,0x01010101,0x04120001,0x01010101,0x04120001,0x01010101,
                0x07130F06,0x01010101,0x010A0510,0x01010101,0x010A0510,0x01010101,0x010A0510,0x01010101,
                0x07130F06,0x01010101,0x11080901,0x01010101,0x030B0D01,0x01010101,0x0B000101,0x01010103,
                0x080F0601,0x06010111,0x08090101,0x02010111,0x12090101,0x00010104,0x08090101,0x0F060111,
                0x130F0601,0x14020107,0x0A051001,0x0B000101,0x04120001,0x130F0601,0x010C0B09,0x030B0D01,
                0x0D010A0F,0x01010C0B,0x10010314,0x01010A05,0x06010412,0x0104120F,0x01011108,0x01030B00,
                0x0101010A,0x07131402,0x0B0B0B0B,0x04120B0B,0x01010107,0x030B0001,0x01010101,0x13051001,

                0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,
                0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0101,0x0101010C,0x0B0D0107,0x0101010C,
                0x08090101,0x0B0D0111,0x12090101,0x0B0D0104,0x12000101,0x0B0D0104,0x12090101,0x0B0D0104,
                0x08090101,0x0B0D0111,0x0A051001,0x0B0D0101,0x04120001,0x0B0D0101,0x010C0B09,0x0B0D0101,
                0x0D01010C,0x0B0D0C0B,0x0D01010C,0x0F060C0B,0x0D01010C,0x0D010C0B,0x0D01010C,0x06010C0B,
                0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,0x0D01010C,0x01010C0B,
                0x0D010103,0x06010C0B,0x0D011108,0x10010C0B,0x0D010A0B,0x10010C0B,0x0D04120F,0x10010C0B,
                0x0D0A1402,0x06010C0B,0x15120901,0x01010C0B,0x0B140201,0x01010C0B,0x0B090101,0x01010C0B,

                0x0107130F,0x01010101,0x01010A05,0x01010101,0x01010A05,0x0B0B0901,0x01010A05,0x01010101,
                0x0107130F,0x01010101,0x010C0B00,0x01010101,0x07130510,0x01010101,0x12140201,0x01010104,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01030B0B,0x01010101,0x01031402,0x01010101,
                0x01031402,0x01010101,0x01031402,0x01010101,0x01031402,0x01010101,0x01030B00,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0B000101,0x00010103,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0101030B,0x01030B00,

                0x0B0B0001,0x120B0B0B,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x02010104,0x0B0B0B14,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01011108,0x04120901,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x12090101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,

                0x0B0D0104,0x0B0B0B0B,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010713,0x0B0D0101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x0D01010C,0x01010C0B,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x05100101,0x01010C0B,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,

                0x00010101,0x0B0B0B0B,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010412,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
                0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,
        };

const unsigned short tussenschermMap[1024] __attribute__((aligned(4)))=
        {
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,
                0x0008,0x0009,0x000A,0x000B,0x000C,0x000D,0x000E,0x000F,
                0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,
                0x0018,0x0019,0x001A,0x001B,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x001C,0x001D,0x001E,0x001F,0x0020,0x0021,
                0x0022,0x0023,0x0024,0x0025,0x1026,0x0027,0x0028,0x0029,
                0x002A,0x002B,0x002C,0x102D,0x002E,0x102F,0x0030,0x0031,
                0x0032,0x0033,0x0034,0x0035,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0036,0x0037,0x0038,0x0039,0x003A,0x003B,0x003C,0x003D,
                0x003E,0x003F,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0047,
                0x0048,0x0049,0x004A,0x004B,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x004C,0x004D,0x004E,0x004F,0x0050,0x1051,0x0052,0x0053,
                0x0054,0x1055,0x084A,0x084B,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,

                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
                0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
        };

const unsigned short tussenschermPal[256] __attribute__((aligned(4)))=
        {
                0x6E47,0x0000,0x48E0,0x1E5B,0x00F2,0x7FF6,0x1C00,0x0007,
                0x5BFF,0x7ECC,0x32DF,0x7FFF,0x0196,0x5980,0x4A56,0x7F72,
                0x3000,0x000C,0x6FFF,0x4B7F,0x7FFB,0x5A52,0x30F2,0x1D96,
                0x5987,0x5AD6,0x5ADB,0x0000,0x0000,0x0000,0x0000,0x0000,
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
        };

//}}BLOCK(tussenscherm)


#endif //GBA_SPRITE_ENGINE_PROJECT_ACHTERGROND_H