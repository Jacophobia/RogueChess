#pragma once

struct ValidMove
{
    int delta_x = 0;
    int delta_y = 0;

    int chains_remaining = 0;

    int attack_delta_x = 0;
    int attack_delta_y = 0;
};
