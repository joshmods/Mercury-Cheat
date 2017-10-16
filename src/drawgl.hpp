/*
 * drawgl.hpp
 *
 *  Created on: May 21, 2017
 *      Author: nullifiedcat
 */

#ifndef DRAWGL_HPP_
#define DRAWGL_HPP_

#include "drawing.h"

extern "C" {
#include "freetype-gl/vec234.h"
#include "freetype-gl/vertex-buffer.h"
}

namespace drawgl {

struct vertex_v2c4_t {
	ftgl::vec2 xy;
	ftgl::vec4 rgba;
};

struct vertex_v2t2c4_t {
	ftgl::vec2 xy;
	ftgl::vec2 st;
	ftgl::vec4 rgba;
};


extern ftgl::vertex_buffer_t* buffer_lines;
extern ftgl::vertex_buffer_t* buffer_triangles_plain;
extern ftgl::vertex_buffer_t* buffer_triangles_textured;

extern const float white[4];

void Initialize();

void FilledRect(float x, float y, float w, float h, const float* rgba = white);
void Line(float x, float y, float dx, float dy, const float* rgba = white);
void Rect(float x, float y, float w, float h, const float* rgba = white);
void TexturedRect(float x, float y, float w, float h, float u, float v, float u2, float v2, const float* rgba = white);

void Refresh();
void Render();

void PreRender();
void PostRender();

extern bool ready_state;

}

#endif /* DRAWGL_HPP_ */
