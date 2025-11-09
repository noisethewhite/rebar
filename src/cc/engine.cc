#include "../hh/engine.hh"
#include "SDL3/SDL_messagebox.h"
#include "SDL3/SDL_render.h"
#include <iostream>


// Error reporting, used only in main.cc
void RebarEngine::report_error(::std::exception const& e) noexcept {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Rebar: Error", e.what(), sdl::get_window());
}


//
// 1 of 3: Init Engine
//
void RebarEngine::init(::std::vector<::std::string> const& args) {

    sdl::create_window("Rebar Test SDL3", 640, 480);
    SDL_Renderer *renderer = SDL_CreateRenderer(sdl::get_window(), nullptr);
    ::std::cout << SDL_GetRendererName(renderer) << ::std::endl;
    if (!renderer) {
        std::fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
    } else {
        // draw one frame so Wayland gets a buffer to map
        SDL_SetRenderDrawColor(renderer, 50, 100, 150, 255); // any color
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    // TODO:
    // - Settings storer and loader
    // - VSync and framerate setting
}


//
// 2 of 3: Handle Event
//
void RebarEngine::handle_event(SDL_Event const& event) noexcept {
    
}


//
// 3 of 3: What to do each frame
//
void RebarEngine::frame(uint64_t delta_ms) {
    SDL_DelayNS(sixtieth_of_second_ns);
}
