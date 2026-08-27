#include <notcurses/notcurses.h>
#include <string>
#include <filesystem>
#include "FileManager.h"
using namespace std;
namespace fs=std::filesystem;

void draw_list(ncplane* p,
               const FileManager& fm,
               const int selected,
               const uint64_t normal,
               const uint64_t sel,
               const int scroll,
               const uint32_t max) {
    const auto files = fm.get_files();

    for (int i = scroll; i < scroll + max && i < files.size(); i++) {
        ncplane_set_channels(p, (i == selected) ? sel : normal);

        ncplane_printf_yx(
            p,
            1 + (i - scroll),
            2,
            "%-20s",
            files[i].path().filename().c_str()
        );
    }

    ncplane_set_channels(p, normal);
}
void open(FileManager& fm, int selected) {
    auto files = fm.get_files();

    if (selected >= 0 && selected < files.size()) {
        fm.open_directory(
            files[selected].path().filename().string()
        );
    }
}
void clear(ncplane* p,
           int& selected,
           int& scroll) {
    scroll=0, selected=0;
    ncplane_erase(p);
}

void ncurses_start() {
    FileManager fm;
    // Notcurses initialization

    constexpr notcurses_options opts{};
    notcurses* nc = notcurses_init(&opts, stdout);

    // Base plane
    ncplane* std = notcurses_stdplane(nc);
    // Colors
    uint64_t normal = 0;
    ncchannels_set_fg_rgb(&normal, 0xffffff);
    ncchannels_set_bg_default(&normal);

    uint64_t sel = 0;
    ncchannels_set_fg_rgb(&sel, 0x000000);
    ncchannels_set_bg_rgb(&sel, 0x00ff00);
    // Terminal size

    unsigned y, x;
    ncplane_dim_yx(std, &y, &x);

    // TOP

    ncplane_options top_opt{};
    top_opt.y = 0;
    top_opt.x = 0;
    top_opt.rows = 3;
    top_opt.cols = x;

    ncplane* top = ncplane_create(std, &top_opt);

    ncplane_putstr_yx(
        top,
        1,
        (x - 24) / 2,
        "Goat File Manager"
    );

    // LEFT

    ncplane_options left_opt{};
    left_opt.y = 3;
    left_opt.x = 0;
    left_opt.rows = y - 6;
    left_opt.cols = x / 2;

    ncplane* left = ncplane_create(std, &left_opt);

    ncplane_putstr_yx(
        left,
        1,
        2,
        "[ FILES ]"
    );


    // RIGHT

    ncplane_options right_opt{};
    right_opt.y = 3;
    right_opt.x = x / 2;
    right_opt.rows = y - 6;
    right_opt.cols = x - (x / 2);

    ncplane* right = ncplane_create(std, &right_opt);

    ncplane_putstr_yx(
        right,
        1,
        2,
        "[ INFO ]"
    );

    // BOTTOM

    ncplane_options bottom_opt{};
    bottom_opt.y = y - 3;
    bottom_opt.x = 0;
    bottom_opt.rows = 3;
    bottom_opt.cols = x;

    ncplane* bottom = ncplane_create(std, &bottom_opt);

    ncplane_putstr_yx(
        bottom,
        1,
        2,
        "↑↓/scroll Navigate   ENTER Open   BACK Back   C Copy   M Move   R Rename   D Delete   Q Quit"
    );

    int scroll = 0;
    int selected = 0;
    const uint32_t max_visible = left_opt.rows - 1;

    // Render
    draw_list(left, fm, selected, normal, sel, scroll, max_visible);
    notcurses_render(nc);

    while (true)
    {
        ncinput ni;

        if (notcurses_get(nc, nullptr, &ni) == 0)
            continue;

        if (ni.evtype == NCTYPE_PRESS ||
    ni.evtype == NCTYPE_REPEAT ||
    ni.evtype == NCTYPE_UNKNOWN) {

            if (ni.id == NCKEY_DOWN) {
                if (auto files = fm.get_files(); selected < files.size() - 1) {
                    selected++;

                    if (selected >= scroll + max_visible)
                        scroll++;
                }
            }
            else if (ni.id == NCKEY_UP) {
                if (selected > 0) {
                    selected--;

                    if (selected < scroll)
                        scroll--;
                }
            }
            else if (ni.id == NCKEY_ENTER && ni.evtype == NCTYPE_PRESS) {
                open(fm, selected);
                clear(left, selected, scroll);
            }

            draw_list(left, fm, selected, normal, sel, scroll, max_visible);
            notcurses_render(nc);
    }
        if (ni.id == 'q' || ni.id == 'Q')
            break;
    }
    // Cleanup
    notcurses_stop(nc);
}