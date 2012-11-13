#pragma once
#include "cinder/CinderResources.h"

#define RES_PASSTHRU_VERT	CINDER_RESOURCE( ../shaders/, passThru_vert.glsl, 126, GLSL )
#define RES_BLUR_FRAG		CINDER_RESOURCE( ../shaders/, gaussianBlur_frag.glsl, 127, GLSL )

#define BUBBLEMAN_WAVE CINDER_RESOURCE( ../resources/, bubbleman_wave.png, 129, IMAGE )
#define BUBBLEMAN_RUN CINDER_RESOURCE( ../resources/, bubbleman_run.png, 130, IMAGE )

#define RES_CUSTOM_FONT CINDER_RESOURCE( ../resources/, ee_nobblee_boldwebfont.ttf, 128, TTF );

