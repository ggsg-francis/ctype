#define SOKOL_IMPL
#ifdef _WIN32
#define SOKOL_GLCORE33
#else
#define SOKOL_METAL
#endif
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"

sg_pass_action pass_action;

void init(void) {
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext()
    });
    pass_action = (sg_pass_action) {
        .colors[0] = { .action=SG_ACTION_CLEAR, .val={1.0f, 0.0f, 0.0f, 1.0f} }
    };


	char c = 'a';

	unsigned long long test = 0b111010101010000010101110101011001111101010;
	unsigned long long testbak;

	char encoded[128];

	// encode
	for (int i = 0; i < sizeof(test); ++i) { // for every byte
		void* testp = &test;
		unsigned char bits_l = (((unsigned char*)testp)[i] & 0b11110000) >> 4;
		unsigned char bits_r = ((unsigned char*)testp)[i] & 0b00001111;

		char cl = (char)(bits_l + 'a');
		char cr = (char)(bits_r + 'a');

		encoded[i * 2] = cl;
		encoded[i * 2 + 1] = cr;

		if (i == sizeof(test) - 1)
			encoded[i * 2 + 2] = 0; // null terminate
	}

	testbak = test;
	test = 0;

	// decode
	int j = 0;
	for (int i = 0; i < strlen(encoded); i += 2) {
		char cl = encoded[i];
		char cr = encoded[i + 1];

		unsigned char bits_l = ((unsigned char)cl - 'a');
		unsigned char bits_r = ((unsigned char)cr - 'a');

		void* testp = &test;

		((unsigned char*)testp)[j] = (bits_l << 4) | bits_r;
		++j;
	}

	int jskhdfk = 0;
}

void frame(void) {
    float g = pass_action.colors[0].val[1] + 0.01f;
    pass_action.colors[0].val[1] = (g > 1.0f) ? 0.0f : g;
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());
    sg_end_pass();
    sg_commit();
}

void cleanup(void) {
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[]) {
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .width = 400,
        .height = 300,
        .window_title = "Clear (sokol app)",
    };
}
