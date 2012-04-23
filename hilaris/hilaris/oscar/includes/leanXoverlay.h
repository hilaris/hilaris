/*	
	Copyright (C) 2008 Reto Bättig
	
	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation; either version 2.1 of the License, or (at
	your option) any later version.
	
	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
	General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with this library; if not, write to the Free Software Foundation,
	Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*!@file leanXoverlay.h
 * @Overlay graphics to image
 */
#ifndef H_LEANXOVERLAY
#define H_LEANXOVERLAY

#include <oscar.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	struct OSC_PICTURE *p;
	char *filename;
	uint8 width;
	uint8 height;
	uint8 from;
	uint8 to;
} ov_font_t;

	
int ov_init();
void ov_text(struct OSC_PICTURE *pPic, int x, int y, int size, const char *text, uint32 col_fg, uint32 col_bg);
void ov_line(struct OSC_PICTURE *pPic, int x1, int y1, int x2, int y2, uint32 col);
void ov_box(struct OSC_PICTURE *pPic, int x1, int y1, int x2, int y2, uint32 col, bool fill);
void ov_bar_vert(struct OSC_PICTURE *pic, int x1, int y1, int x2, int y2, int percentage, uint32 color); 
void ov_ellipse(struct OSC_PICTURE *pPic, int x1, int y1, int x2, int y2, uint32 col, bool fill);
void ov_pixel(struct OSC_PICTURE *pPic, int x, int y, uint32 col);
void ov_plot_vector(struct OSC_PICTURE *pic, int x0, int y0, int8 *v, int len, uint32 col);
void ov_plot_vector_scale8(struct OSC_PICTURE *pic, int x1, int y1, int height, int8 *vect, int16 len, uint32 color); 
void ov_plot_vector_scale16(struct OSC_PICTURE *pic, int x1, int y1, int height, int16 *vect, int16 len, uint32 color); 
void ov_plot_vector_scale32(struct OSC_PICTURE *pic, int x1, int y1, int height, int32 *vect, int16 len, uint32 color); 

#ifdef __cplusplus
}
#endif

#endif
