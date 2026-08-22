#include <notcurses/notcurses.h>
#include <string>
#include <filesystem>

using namespace std;
namespace fs=std::filesystem;
void ncurses_start(fs::path folder_path)
{
    // Notcurses initialization

    constexpr notcurses_options opts{};
    notcurses* nc = notcurses_init(&opts, stdout);

    // Base plane
    ncplane* std = notcurses_stdplane(nc);

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
        "↑↓ Navigate   ENTER Open   BACK Back   C Copy   M Move   R Rename   D Delete   Q Quit"
    );

    // Render

    notcurses_render(nc);

    while (true)
    {
        ncinput ni;

        if (notcurses_get(nc, nullptr, &ni) == 0)
            continue;

        if (ni.id == 'q' || ni.id == 'Q')
            break;

    }
    // Cleanup
    notcurses_stop(nc);
}