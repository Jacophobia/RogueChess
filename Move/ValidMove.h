#pragma once

struct ValidMove
{
    int delta_x = 0;
    int delta_y = 0;

    int chains_remaining = 0;

    bool is_capture_move = false;
    int capture_delta_x = 0;
    int capture_delta_y = 0;
};
