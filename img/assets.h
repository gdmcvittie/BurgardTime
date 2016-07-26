#ifndef ASSETS_H
#define ASSETS_H

// the_bottom_bun.png
// 24x8
PROGMEM const unsigned char the_bottom_bun[] = {
// width, height
24, 8,
0x1C, 0x34, 0x6E, 0x76, 0x6E, 0x56, 0x6E, 0x56, 0x6E, 0x56, 
0x6E, 0x56, 0x6E, 0x56, 0x6E, 0x56, 0x6E, 0x56, 0x6E, 0x56, 
0x6E, 0x76, 0x3C, 0x1C

};

PROGMEM const unsigned char the_bottom_bun_mask[] = {
// width, height
24, 8,
0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0x7E

};

// the_egg_f1.png
// 16x24
PROGMEM const unsigned char the_egg_f1[] = {
// width, height
16, 24,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 
0x18, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 
0x60, 0x30, 0x1E, 0xFF, 0xFF, 0x80, 0x2A, 0x55, 0x28, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x60, 
0x3D, 0x3F, 0x18, 0x30, 0x20, 0x00, 0x00, 0x00

};

PROGMEM const unsigned char the_egg_f1_mask[] = {
// width, height
16, 24,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF8, 0xFC, 
0xFE, 0xBE, 0x9E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xF0, 
0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF1, 0xFF, 
0xFF, 0x7F, 0x7F, 0x7D, 0x78, 0x70, 0x00, 0x00

};

// the_egg_f2.png
// 16x24
PROGMEM const unsigned char the_egg_f2[] = {
// width, height
16, 24,
0x00, 0x00, 0x00, 0x00, 0x0C, 0x18, 0xF0, 0xE0, 0xC0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 
0x55, 0x2A, 0x80, 0xFF, 0xFF, 0x1E, 0x30, 0x60, 0x20, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x18, 0x3F, 0x3D, 
0x60, 0x60, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00

};

PROGMEM const unsigned char the_egg_f2_mask[] = {
// width, height
16, 24,
0x00, 0x00, 0x00, 0x9E, 0xBE, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0x70, 
0x00, 0x00, 0x00, 0x00, 0x70, 0x78, 0x7D, 0x7F, 0x7F, 0xFF, 
0xFF, 0xF1, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00

};

// the_hotdog_f1.png
// 16x16
PROGMEM const unsigned char the_hotdog_f1[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0E, 0x9E, 0xFE, 0xFC, 
0xF8, 0xF0, 0xA0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
0x06, 0x03, 0x61, 0x61, 0x70, 0x7F, 0x7F, 0x39, 0x13, 0x07, 
0x03, 0x00

};

PROGMEM const unsigned char the_hotdog_f1_mask[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x8E, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFE, 0xFC, 0xF8, 0xF0, 0xC0, 0x80, 0x00, 0x03, 0x0F, 0x0F, 
0x0F, 0xFF, 0xF7, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 
0x0F, 0x0F

};

// the_hotdog_f2.png
// 16x16
PROGMEM const unsigned char the_hotdog_f2[] = {
// width, height
16, 16,
0x00, 0x00, 0x80, 0xA0, 0xF0, 0xF8, 0xFC, 0xFE, 0x9E, 0x0E, 
0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x13, 
0x39, 0x7F, 0x7F, 0x70, 0x61, 0x61, 0x03, 0x06, 0x02, 0x00, 
0x00, 0x00

};

PROGMEM const unsigned char the_hotdog_f2_mask[] = {
// width, height
16, 16,
0x80, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
0x9F, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x3F, 0x7F, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF7, 0xFF, 0x0F, 0x0F, 0x0F, 
0x03, 0x00

};

// the_ladder.png
// 16x16
PROGMEM const unsigned char the_ladder[] = {
// width, height
16, 16,
0x00, 0xFF, 0xFF, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
0x10, 0x10, 0x10, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x10, 
0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xFF, 
0xFF, 0x00

};

PROGMEM const unsigned char the_ladder_mask[] = {
// width, height
16, 16,
0xFF, 0xFF, 0xFF, 0xFF, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 
0x38, 0x38, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xFF, 0xFF, 
0xFF, 0xFF

};

// the_meat.png
// 24x8
PROGMEM const unsigned char the_meat[] = {
// width, height
24, 8,
0x00, 0x00, 0x28, 0x14, 0x2A, 0x54, 0x22, 0x14, 0x28, 0x54, 
0x22, 0x04, 0x22, 0x54, 0x28, 0x14, 0x2A, 0x54, 0x22, 0x54, 
0x28, 0x14, 0x00, 0x00

};

PROGMEM const unsigned char the_meat_mask[] = {
// width, height
24, 8,
0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0x7E

};

// the_pickles_f1.png
// 16x16
PROGMEM const unsigned char the_pickles_f1[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x40, 0xF0, 0x78, 0xFC, 0xFC, 0xFC, 0x7C, 
0xFC, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0F, 
0x97, 0xBF, 0x9F, 0xDD, 0x5D, 0xDF, 0xD7, 0x8F, 0x87, 0x00, 
0x00, 0x00

};

PROGMEM const unsigned char the_pickles_f1_mask[] = {
// width, height
16, 16,
0x00, 0x80, 0xE0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 
0xFE, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xCF, 
0x00, 0x00

};

// the_pickles_f2.png
// 16x16
PROGMEM const unsigned char the_pickles_f2[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0xF0, 0xF8, 0xFC, 0x7C, 0xFC, 0xFC, 0xFC, 
0x78, 0xF0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 
0x8F, 0xD7, 0xDF, 0x5D, 0xDD, 0x9F, 0xBF, 0x97, 0x0F, 0x07, 
0x00, 0x00

};

PROGMEM const unsigned char the_pickles_f2_mask[] = {
// width, height
16, 16,
0x00, 0x00, 0xF8, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 
0xFE, 0xFC, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0xCF, 0xDF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 
0x0F, 0x00

};

// the_platform.png
// 8x4
PROGMEM const unsigned char the_platform[] = {
// width, height
8, 4,
0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02

};

PROGMEM const unsigned char the_platform_mask[] = {
// width, height
8, 4,
0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F

};

// the_player_f1.png
// 16x16
PROGMEM const unsigned char the_player_f1[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x00, 0x8C, 0xBE, 0xFE, 0xFE, 0xBE, 
0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 
0x3F, 0x7F, 0x7F, 0x37, 0x3F, 0x7F, 0x7B, 0x3F, 0x07, 0x03, 
0x00, 0x00

};

PROGMEM const unsigned char the_player_f1_mask[] = {
// width, height
16, 16,
0x00, 0x80, 0x80, 0x80, 0xDE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xDE, 0x80, 0x80, 0x80, 0x00, 0x00, 0x07, 0x0F, 0x7F, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0F, 
0x07, 0x00

};

// the_player_f2.png
// 16x16
PROGMEM const unsigned char the_player_f2[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0xF8, 0xF8, 0x78, 
0x30, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x06, 
0x3E, 0x7F, 0x7F, 0x37, 0x3F, 0x7F, 0x7F, 0x3E, 0x06, 0x07, 
0x00, 0x00

};

PROGMEM const unsigned char the_player_f2_mask[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 
0xFC, 0xF8, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x1F, 0x1F, 0x7F, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0F, 
0x0F, 0x00

};

// the_player_f3.png
// 16x16
PROGMEM const unsigned char the_player_f3[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3C, 0x7C, 0xF8, 0xF8, 
0xF0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 
0x06, 0x3E, 0x77, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x07, 0x00, 
0x00, 0x00

};

PROGMEM const unsigned char the_player_f3_mask[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x7C, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 
0xFC, 0xF8, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1F, 
0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0F, 
0x00, 0x00

};

// the_player_f4.png
// 16x16
PROGMEM const unsigned char the_player_f4[] = {
// width, height
16, 16,
0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xF8, 0xF8, 0x7C, 0x3C, 
0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x77, 0x3E, 0x06, 0x0C, 0x00, 
0x00, 0x00

};

PROGMEM const unsigned char the_player_f4_mask[] = {
// width, height
16, 16,
0x00, 0x00, 0x80, 0xC0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 
0xFE, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x7F, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x1E, 
0x00, 0x00

};

// the_salt.png
// 8x8
PROGMEM const unsigned char the_salt[] = {
// width, height
8, 8,
0x00, 0x00, 0x79, 0xAF, 0xDF, 0xF9, 0x00, 0x00

};

PROGMEM const unsigned char the_salt_mask[] = {
// width, height
8, 8,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00

};

// the_title.png
// 128x64
PROGMEM const unsigned char the_title[] = {
// width, height
128, 64,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x8F, 0x71, 
0x1D, 0x0D, 0x0D, 0x0D, 0x0B, 0x0B, 0x0B, 0x1B, 0x37, 0x6F, 
0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xBF, 0xDF, 0x6F, 0x6F, 0xB7, 
0x97, 0xD7, 0xD7, 0xD7, 0xD7, 0x97, 0xB7, 0x6F, 0xEF, 0x1F, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xDF, 0x2F, 0x2F, 0x37, 
0x37, 0xB7, 0x97, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 
0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0x97, 0x37, 0xF7, 0x07, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0x7F, 0x9F, 0xE3, 0x3C, 0x07, 0x00, 0x00, 0x00, 
0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC1, 0x1F, 
0xF0, 0x37, 0x97, 0xD7, 0xD7, 0x17, 0x77, 0x1B, 0x0B, 0x0B, 
0x18, 0x3F, 0x11, 0x00, 0x1C, 0x3E, 0x3F, 0xFF, 0xC3, 0xD9, 
0xD9, 0xC3, 0xFF, 0xFF, 0x7F, 0x00, 0x7F, 0x3F, 0x18, 0x1B, 
0x0D, 0x0D, 0x1B, 0x1B, 0x37, 0x17, 0x0B, 0xEB, 0x8B, 0xCB, 
0xEB, 0xEB, 0xEB, 0x08, 0x3F, 0x38, 0x20, 0x00, 0x00, 0x00, 
0x03, 0x3B, 0x13, 0xC3, 0xC3, 0xFF, 0x7F, 0x1F, 0xC3, 0x73, 
0x3B, 0x9B, 0xDB, 0x9B, 0xB8, 0x3C, 0x33, 0x94, 0x97, 0xB7, 
0xB7, 0x97, 0x97, 0x97, 0x37, 0x37, 0x2F, 0x2F, 0x2F, 0x2F, 
0x2F, 0xEF, 0xCF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xE3, 
0x7C, 0x1F, 0x01, 0x00, 0x6C, 0xEE, 0xEE, 0xEF, 0xCF, 0xDE, 
0xDE, 0xCE, 0x6C, 0x00, 0x01, 0xFF, 0xFF, 0xC0, 0x9F, 0xBE, 
0x80, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0x78, 
0x38, 0x88, 0xC0, 0xE0, 0xF8, 0x1C, 0x1F, 0x1F, 0x19, 0x19, 
0x18, 0x98, 0x98, 0xF0, 0x00, 0x00, 0x3C, 0x7E, 0xFF, 0x7F, 
0x0F, 0x02, 0x00, 0x00, 0x70, 0xFF, 0xFF, 0xFF, 0x01, 0x81, 
0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 
0x00, 0x87, 0x7F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x06, 0xFF, 
0x3F, 0x03, 0xF3, 0xFF, 0xFF, 0x1F, 0xC3, 0xE1, 0xFF, 0x3F, 
0x0F, 0x03, 0x00, 0x00, 0xC0, 0xC4, 0xC6, 0xC6, 0xFE, 0x07, 
0xF9, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFB, 0xF7, 0xEE, 0xDC, 
0xD8, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD8, 
0xDC, 0xEE, 0xEC, 0xE9, 0xEB, 0xDB, 0xD3, 0xD7, 0xD3, 0xD9, 
0xD8, 0xD8, 0xE8, 0xE8, 0xEC, 0xEF, 0xEF, 0xF2, 0xF6, 0xCC, 
0xB1, 0xB7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xB7, 0xB3, 0xDB, 
0xD9, 0xEC, 0xEE, 0xEC, 0xD8, 0xD8, 0xD8, 0xB0, 0xB0, 0xD8, 
0xDC, 0xDF, 0xD0, 0xD7, 0xD7, 0xD8, 0xE6, 0xFB, 0xF7, 0xEE, 
0xD8, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD8, 0xD0, 0xD6, 0xD1, 
0xDC, 0xDF, 0xD8, 0xD0, 0xD0, 0xD0, 0xD0, 0xD3, 0xD8, 0xD8, 
0xEB, 0xEB, 0xE9, 0xD8, 0xD3, 0xB7, 0xB1, 0xDC, 0xEC, 0xEC, 
0xD8, 0xD8, 0xD0, 0xD0, 0xD0, 0xD0, 0xD1, 0xDF, 0xE6, 0xF9, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 
0x0F, 0xE7, 0xF3, 0x79, 0x0C, 0xA6, 0x30, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 
0xBF, 0xBF, 0xBF, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0xBF, 
0xBF, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x97, 0xB3, 0x98, 0x0F, 0x7F, 
0xFF, 0xC0, 0x15, 0x2A, 0x94, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0xBF, 0x9C, 0xD9, 0x43, 0x67, 
0x3F, 0xFF, 0xFE, 0x7C, 0xE9, 0xE3, 0xCF, 0x1F, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFC, 0xFE, 
0xFF, 0xDF, 0x7F, 0x7F, 0xFF, 0xDE, 0xFC, 0xD1, 0xC7, 0x1F, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0x3F, 0x9F, 0xD0, 0xC7, 0xE7, 0xEF, 0xFF, 
0xFF, 0xFE, 0xF0, 0xE7, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0xA7, 0xB7, 0xB0, 0x9E, 0xDF, 
0xCC, 0xD9, 0xD3, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFC, 0xFC, 0xFD, 0xC0, 0xDA, 0xD9, 0xDC, 0xDF, 
0xDF, 0xCE, 0xE4, 0xF1, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCC, 0xE9, 0xE3, 0xF5, 0xF7, 
0xD7, 0xF7, 0xE7, 0xEF, 0xE5, 0xC3, 0xF9, 0xFC, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFC, 0xFD, 0xF0, 0xE7, 0xEE, 0xEF, 0xEF, 0xEF, 0xEF, 
0xE7, 0xF0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF

};

PROGMEM const unsigned char the_title_mask[] = {
// width, height
128, 64,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF

};

// the_top_bun.png
// 24x8
PROGMEM const unsigned char the_top_bun[] = {
// width, height
24, 8,
0x38, 0x2C, 0x76, 0x6E, 0x76, 0x6A, 0x76, 0x6A, 0x76, 0x6A, 
0x76, 0x6A, 0x76, 0x6A, 0x76, 0x6A, 0x76, 0x6A, 0x76, 0x6A, 
0x76, 0x6E, 0x3C, 0x38

};

PROGMEM const unsigned char the_top_bun_mask[] = {
// width, height
24, 8,
0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0x7E

};

#endif
