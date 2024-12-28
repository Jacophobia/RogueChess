

#include <BearLibTerminal.h>
#include <cstdio>

int main() {
    // Initialize the terminal
    terminal_open();
    terminal_set("window: title='Mouse Position Example', size=80x25; input: mouse+"); // Enable mouse input

    // Position of the character
    int char_x = 10;
    int char_y = 5;

    // Draw the character
    terminal_clear();
    terminal_put(char_x, char_y, '@');
    terminal_refresh();

    while (true) {
        // Wait for an event
        int key = terminal_read();

        if (key == TK_CLOSE || key == TK_Q) {
            // Exit the loop on window close or 'q' key
            terminal_close();
            return 0;
        }

        // Always display the current mouse position at the top left
        int mouse_x = terminal_state(TK_MOUSE_X);
        int mouse_y = terminal_state(TK_MOUSE_Y);
        char mouse_position[64];
        snprintf(mouse_position, sizeof(mouse_position), "Mouse at (%d, %d)", mouse_x, mouse_y);

        terminal_clear();
        terminal_printf(10, 10, mouse_position);

        // Redraw the character
        terminal_put(char_x, char_y, '@');

        if (key == TK_MOUSE_LEFT) {
            // Check if the mouse click is on the character
            if (mouse_x == char_x && mouse_y == char_y) {
                terminal_print(0, 1, "Character clicked!");
            }
            else {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "Mouse clicked at (%d, %d)", mouse_x, mouse_y);
                terminal_print(0, 1, buffer);
            }
        }

        terminal_refresh();
    }
}


/**
int main(int argc, char* argv[])
{
    std::cout << "Welcome to RogueChess!" << '\n';
    while (true)
    {
        std::cout << "Start a new game?" << ' ';
        std::string input;
        std::cin >> input;

        if (!input.empty() && input[0] != 'y')
        {
            return 0;
        }

        UI ui;

        std::vector<std::vector<char>> board = {
            {'#', '#', '#', '#', '#'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#'}
        };
        
        ui.display_board(board);

        // Game game;
        //
        // game.start();
        //
        // while (!game.is_game_over())
        // {
        //     game.next_turn();
        // }
    }
}
*/