#pragma once

struct PotentialMove
{
    int delta_x = 0;
    int delta_y = 0;

    bool is_only_valid_on_first_move = false;
    bool is_only_valid_on_capture = false;

    //for infinite repetitions, set to 0
    int repetitions_limit = 1;
    bool can_pass_through_pieces = false;

    //for infinite chains, set to 0
    int chain_limit = 1;
    bool is_only_chainable_on_capture = false;
};
