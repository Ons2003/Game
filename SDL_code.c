// Define screen dimensions
#define SCREEN_WIDTH        (1500)
#define SCREEN_HEIGHT       (800)

// Max grid dimension
#define GRID_MAX_X_CELLS    (201)
#define GRID_MAX_Y_CELLS    (101)

#define GRID_DEFAULT_MARGIN         (0)
#define GRID_DEFAULT_COLOR          COLOR_BLACK
#define GRID_DEFAULT_BORDER_SIZE    (0)
#define GRID_DEFAULT_BORDER_COLOR   COLOR_GRAY

#define USE_AZERTY_KEYBOARD         0

//***************************************************************************************
// IMPORTANT NOTE:
//
//      To start coding, go down in this file to the 'FREE CODING' section.
//      All your code should be written inside the 'draw' function (line 1725).
//      There is also a 'DOCUMENTATION' section just above the 'FREE CODING' section.
//
//      Read the README.md file for more details.
//
//***************************************************************************************

/* Copyright (c) 2021 Ons Ouenniche,Omar Trabelsi <ons.ouenniche@medtech.tn> <omar.trabelsi@medtech.tn>
 * Copyright (c) 2018, 2019, 2021 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ---------------------------------------------------------------------------------
 * The 4x6 font:
 *  - Upper case letters
 *  - Lower case letters
 *  - Exclamation mark
 *  - Piriod (punctuation)
 *
 * Belongs to https://github.com/filmote
 * Source: https://github.com/filmote/Font4x6/blob/master/src/fonts/Font4x6.cpp
 * License: https://github.com/filmote/Font4x6/blob/master/LICENSE

    BSD 3-Clause License

    Copyright (c) 2018, Filmote
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    * Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ---------------------------------------------------------------------------------
 *
 * The 4x6 font modification/extension:
 * Some lower case letters have been modifed and the remaining font characters are made
 * by "Amine Ben Hassouna" and are distributed under the same license as this file.
 *
 */

//****************************************************************************************
// LIBRARY SECTION
//****************************************************************************************

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

// Define MAX and MIN macros
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

#define _COLOR(RED, GREEN, BLUE)    { RED, GREEN, BLUE, 0xFF }
#define COLOR(RED, GREEN, BLUE)     ((SDL_Color) { RED, GREEN, BLUE, 0xFF })

const SDL_Color NO_COLOR            = {0, 0, 0, 0};
const SDL_Color COLOR_BLACK         = _COLOR(0, 0, 0);
const SDL_Color COLOR_WHITE         = _COLOR(0xFF, 0xFF, 0xFF);
const SDL_Color COLOR_GRAY          = _COLOR(0x64, 0x64, 0x64);
const SDL_Color COLOR_DARK_GRAY     = _COLOR(0x1E, 0x1E, 0x1E);
const SDL_Color COLOR_LIGHT_GRAY    = _COLOR(0xC8, 0xC8, 0xC8);
const SDL_Color COLOR_RED           = _COLOR(0xF5, 0x3B, 0x56);
const SDL_Color COLOR_GREEN         = _COLOR(0x01, 0x9F, 0x13);
const SDL_Color COLOR_BLUE          = _COLOR(0x38, 0x95, 0xD3);
const SDL_Color COLOR_YELLOW        = _COLOR(0xF7, 0xDC, 0x11);
const SDL_Color COLOR_ORANGE        = _COLOR(0xFF, 0x85, 0);
const SDL_Color COLOR_PINK          = _COLOR(0xFF, 0, 0xCE);
const SDL_Color COLOR_VIOLET        = _COLOR(0x91, 0, 0xFF);

enum
{
    SDLK_DIVIDE = SDLK_SLASH,
    SDLK_MULTIPLY = SDLK_ASTERISK,
};

SDL_Keycode normalize_key(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_KP_0:
        return SDLK_0;
    case SDLK_KP_1:
        return SDLK_1;
    case SDLK_KP_2:
        return SDLK_2;
    case SDLK_KP_3:
        return SDLK_3;
    case SDLK_KP_4:
        return SDLK_4;
    case SDLK_KP_5:
        return SDLK_5;
    case SDLK_KP_6:
        return SDLK_6;
    case SDLK_KP_7:
        return SDLK_7;
    case SDLK_KP_8:
        return SDLK_8;
    case SDLK_KP_9:
        return SDLK_9;
    case SDLK_KP_ENTER:
        return SDLK_RETURN;
    case SDLK_KP_PERIOD:
        return SDLK_PERIOD;
    case SDLK_KP_COMMA:
        return SDLK_COMMA;
    case SDLK_KP_COLON:
        return SDLK_COLON;
    case SDLK_KP_PERCENT:
        return SDLK_PERCENT;
#if USE_AZERTY_KEYBOARD
    case 249:
        return SDLK_PERCENT;
#endif
    case SDLK_KP_PLUS:
        return SDLK_PLUS;
    case SDLK_KP_MINUS:
        return SDLK_MINUS;
    case SDLK_KP_MULTIPLY:
        return SDLK_MULTIPLY;
    case SDLK_KP_DIVIDE:
        return SDLK_DIVIDE;
    case SDLK_KP_EQUALS:
        return SDLK_EQUALS;
    default:
        break;
    }

    return key;
}

bool is_key_ascii(SDL_Keycode key)
{
    return key >= SDLK_SPACE && key <= SDLK_z;
}

bool is_key_letter(SDL_Keycode key)
{
    return key >= SDLK_a && key <= SDLK_z;
}

bool is_key_digit(SDL_Keycode key)
{
    return key >= SDLK_0 && key <= SDLK_9;
}

bool is_key_arithmetic_op(SDL_Keycode key)
{
    return key == SDLK_PLUS
           || key == SDLK_MINUS
           || key == SDLK_DIVIDE
           || key == SDLK_MULTIPLY
           || key == SDLK_PERCENT;
}

char key_to_char(SDL_Keycode key)
{
    key = normalize_key(key);

    if (is_key_letter(key))
    {
        return (char) (key - SDLK_a + 'A');
    }
    else if (key >= SDLK_SPACE && key <= SDLK_BACKQUOTE)
    {
        return (char) key;
    }

    return 0;
}

char key_to_char_lowercase(SDL_Keycode key)
{
    if (is_key_letter(key))
    {
        return (char) key;
    }
    else
    {
        return key_to_char(key);
    }
}


int key_to_int(SDL_Keycode key)
{
    key = normalize_key(key);

    if (is_key_digit(key))
    {
        return (int) (key - SDLK_0);
    }
    else
    {
        return -1;
    }
}

SDL_Keycode digit_to_key(int digit)
{
    return (abs(digit) % 10) + SDLK_0;
}

char digit_to_char(int digit)
{
    return (abs(digit) % 10) + '0';
}

int char_to_digit(char c)
{
    return c - '0';
}

struct Cell
{
    // Rect dimensions and color
    SDL_Rect rect;
    SDL_Color rect_color;

    // Border dimensions and color
    SDL_Rect border;
    SDL_Color border_color;
};
typedef struct Cell Cell;


struct Grid
{
    // x, y, width, height
    SDL_Rect rect;

    // Grid background color
    SDL_Color background_color;

    // Grid border thickness and color
    unsigned int border;
    SDL_Color border_color;

    // Number of cells over the x axis
    int x_cells;
    // Number of cells over the y axis
    int y_cells;

    // Cells boder thickness and color
    unsigned int cells_border;
    SDL_Color cells_border_color;

    // Matrix of Cells
    Cell cells[GRID_MAX_X_CELLS][GRID_MAX_Y_CELLS];
};
typedef struct Grid Grid;

void set_background_color(SDL_Renderer* renderer, SDL_Color color)
{
    // Initialize renderer color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Clear screen
    SDL_RenderClear(renderer);
}

int random_int(int min, int max)
{
    return ( rand() % (max + 1) ) + min;
}

bool is_color_equal(SDL_Color color1, SDL_Color color2)
{
    return *((Sint32*) &color1) == *((Sint32*) &color2);
}

void init_cell(Grid* grid, Cell* cell, int i, int j, SDL_Color color, SDL_Color border_color)
{
    // Init rect
    int interspace_width = grid->x_cells * grid->cells_border * 2;
    cell->rect.w = (grid->rect.w - (grid->border * 2) - interspace_width) / grid->x_cells;

    int interspace_heigth = grid->y_cells * grid->cells_border * 2;
    cell->rect.h = (grid->rect.h - (grid->border * 2) - interspace_heigth) / grid->y_cells;

    cell->rect.x = grid->rect.x + grid->border + grid->cells_border
                   + (grid->cells_border * 2 + cell->rect.w) * i;
    cell->rect.y = grid->rect.y + grid->border + grid->cells_border
                   + (grid->cells_border * 2 + cell->rect.h) * j;

    // Init rectColor
    cell->rect_color = color;

    // Init border
    cell->border.w = cell->rect.w + grid->cells_border * 2;
    cell->border.h = cell->rect.h + grid->cells_border * 2;
    cell->border.x = cell->rect.x - grid->cells_border;
    cell->border.y = cell->rect.y - grid->cells_border;

    // Init borderColor
    cell->border_color = border_color;
}

bool init_grid(Grid* grid)
{
    if(!grid->rect.w || !grid->rect.h || !grid->x_cells || !grid->y_cells)
    {
        fprintf(stderr, "Grid dimensions or number of cells not initialised !\n");
        return false;
    }

    if(grid->x_cells > GRID_MAX_X_CELLS || grid->y_cells > GRID_MAX_Y_CELLS)
    {
        fprintf(stderr, "Grid number of cells (%d,%d) is greater than (%d,%d) !\n",
                grid->x_cells, grid->y_cells,
                GRID_MAX_X_CELLS, GRID_MAX_Y_CELLS);
        return false;
    }

    // Init all cells
    for(int i = 0; i < grid->x_cells; ++i)
    {
        for(int j = 0; j < grid->y_cells; ++j)
        {
            init_cell(grid,
                      &(grid->cells[i][j]),
                      i, j,
                      grid->background_color,
                      grid->cells_border_color);
        }
    }

    return true;
}


void render_cell(Cell* cell, SDL_Renderer* renderer)
{
    if(cell->border.x != cell->rect.x) // Cells border thickness different from 0
    {
        // Set renderer color to cell color
        SDL_SetRenderDrawColor(renderer,
                               cell->border_color.r,
                               cell->border_color.g,
                               cell->border_color.b,
                               cell->border_color.a);

        // Render filled cell
        SDL_RenderFillRect(renderer, &(cell->border));
    }

    // Set renderer color to cell color
    SDL_SetRenderDrawColor(renderer,
                           cell->rect_color.r,
                           cell->rect_color.g,
                           cell->rect_color.b,
                           cell->rect_color.a);

    // Render filled cell
    SDL_RenderFillRect(renderer, &(cell->rect));
}

void render_grid(Grid* grid, SDL_Renderer* renderer)
{
    if(grid->border != 0) // Grid border thickness different from 0
    {
        // Set renderer color to draw the grid border
        SDL_SetRenderDrawColor(renderer,
                               grid->border_color.r,
                               grid->border_color.g,
                               grid->border_color.b,
                               grid->border_color.a);

        // Render grid border
        SDL_RenderFillRect(renderer, &(grid->rect));
    }

    // Render all cells
    for(int i = 0; i < grid->x_cells; ++i)
    {
        for(int j = 0; j < grid->y_cells; ++j)
        {
            render_cell(&(grid->cells[i][j]), renderer);
        }
    }
}

int ajust_grid_size(Grid* grid)
{
    if(!grid->rect.w || !grid->rect.h || !grid->x_cells || !grid->y_cells)
    {
        fprintf(stderr, "Grid dimensions or number of cells not initialised !\n");
        return false;
    }

    // Init rect
    int interspace_width = grid->x_cells * grid->cells_border * 2;
    grid->rect.w -= (grid->rect.w - (grid->border * 2) - interspace_width) % grid->x_cells;

    int interspace_heigth = grid->y_cells * grid->cells_border * 2;
    grid->rect.h -= (grid->rect.h - (grid->border * 2) - interspace_heigth) % grid->y_cells;

    return true;
}

void center_grid(Grid* grid, int screen_width, int screen_height)
{
    grid->rect.x = (screen_width - grid->rect.w) / 2;
    grid->rect.y = (screen_height - grid->rect.h) / 2;
}

void set_cell_color(Grid* grid, int x, int y, SDL_Color color)
{
    if (x >= 0 && x <= grid->x_cells && y >= 0 && y <= grid->y_cells)
    {
        grid->cells[x][y].rect_color = color;
    }
}

SDL_Color get_cell_color(Grid* grid, int x, int y)
{
    if (x >= 0 && x <= grid->x_cells && y >= 0 && y <= grid->y_cells)
    {
        return grid->cells[x][y].rect_color;
    }

    return NO_COLOR;
}

void set_cell_border_color(Grid* grid, int x, int y, SDL_Color color)
{
    if (x >= 0 && x <= grid->x_cells && y >= 0 && y <= grid->y_cells)
    {
        grid->cells[x][y].border_color = color;
    }
}

SDL_Color get_cell_border_color(Grid* grid, int x, int y)
{
    if (x >= 0 && x <= grid->x_cells && y >= 0 && y <= grid->y_cells)
    {
        return grid->cells[x][y].border_color;
    }

    return NO_COLOR;
}

void set_grid_color(Grid* grid, SDL_Color color)
{
    grid->background_color = color;

    // Set color of all cells
    for(int x = 0; x < grid->x_cells; ++x)
    {
        for(int y = 0; y < grid->y_cells; ++y)
        {
            grid->cells[x][y].rect_color = color;
        }
    }
}

SDL_Color get_grid_color(Grid* grid)
{
    return grid->background_color;
}

void set_grid_border_color(Grid* grid, SDL_Color color)
{
    grid->border_color = color;
    grid->cells_border_color = color;

    // Set border color of all cells
    for(int x = 0; x < grid->x_cells; ++x)
    {
        for(int y = 0; y < grid->y_cells; ++y)
        {
            grid->cells[x][y].border_color = color;
        }
    }
}

SDL_Color get_grid_border_color(Grid* grid)
{
    return grid->border_color;
}

#define FONT_PIXELS_UNKNOWN             1
#define FONT_PIXELS_NON_PRINTABLE_CHAR  1
#define FONT_PIXELS_PRINTABLE_CHAR      5

const uint8_t FONT_PIXELS[] =
{
    0,

    // Unknown / Non printable
    0x3F,  // ░░▓▓▓▓▓▓
    0x31,  // ░░▓▓░░░▓
    0x31,  // ░░▓▓░░░▓
    0x3F,  // ░░▓▓▓▓▓▓


    // Sign list 1

    // #32 Symbol ' '
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░

    // #33 Symbol '!'
    0x00,  // ░░░░░░░░
    0x2F,  // ░░▓░▓▓▓▓
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░

    // #34 Symbol "
    0x03,  // ░░░░░░▓▓
    0x00,  // ░░░░░░░░
    0x03,  // ░░░░░░▓▓
    0x00,  // ░░░░░░░░

    // #35 Symbol '#'
    0x0A,  // ░░░░▓░▓░
    0x1F,  // ░░░▓▓▓▓▓
    0x0A,  // ░░░░▓░▓░
    0x1F,  // ░░░▓▓▓▓▓

    // #36 Symbol '$'
    0x16,  // ░░░▓░▓▓░
    0x3F,  // ░░▓▓▓▓▓▓
    0x1A,  // ░░░▓▓░▓░
    0x00,  // ░░░░░░░░

    // #37 Symbol '%'
    0x12,  // ░░░▓░░▓░
    0x08,  // ░░░░▓░░░
    0x04,  // ░░░░░▓░░
    0x12,  // ░░░▓░░▓░

    // #38 Symbol '&'
    0x37,  // ░░▓▓░▓▓▓
    0x29,  // ░░▓░▓░░▓
    0x3D,  // ░░▓▓▓▓░▓
    0x08,  // ░░░░▓░░░

    // #39 Symbol '
    0x00,  // ░░░░░░░░
    0x03,  // ░░░░░░▓▓
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░

    // #40 Symbol '('
    0x00,  // ░░░░░░░░
    0x1E,  // ░░░▓▓▓▓░
    0x21,  // ░░▓░░░░▓
    0x00,  // ░░░░░░░░

    // #41 Symbol ')'
    0x00,  // ░░░░░░░░
    0x21,  // ░░▓░░░░▓
    0x1E,  // ░░░▓▓▓▓░
    0x00,  // ░░░░░░░░

    // #42 Symbol '*'
    0x0A,  // ░░░░▓░▓░
    0x04,  // ░░░░░▓░░
    0x0A,  // ░░░░▓░▓░
    0x00,  // ░░░░░░░░

    // #43 Symbol '+'
    0x08,  // ░░░░▓░░░
    0x1C,  // ░░░▓▓▓░░
    0x08,  // ░░░░▓░░░
    0x00,  // ░░░░░░░░

    // #44 Symbol ','
    0x00,  // ░░░░░░░░
    0x20,  // ░░▓░░░░░
    0x10,  // ░░░▓░░░░
    0x00,  // ░░░░░░░░

    // #45 Symbol '-'
    0x08,  // ░░░░▓░░░
    0x08,  // ░░░░▓░░░
    0x08,  // ░░░░▓░░░
    0x00,  // ░░░░░░░░

    // #46 Symbol '.'
    0x00,  // ░░░░░░░░
    0x20,  // ░░▓░░░░░
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░

    // #47 Symbol '/'
    0x10,  // ░░░▓░░░░
    0x08,  // ░░░░▓░░░
    0x04,  // ░░░░░▓░░
    0x02,  // ░░░░░░▓░


    // Digits

    // #48 Number '0'
    0x1E,  // ░░░▓▓▓▓░
    0x29,  // ░░▓░▓░░▓
    0x25,  // ░░▓░░▓░▓
    0x1E,  // ░░░▓▓▓▓░

    // #49 Number '1'
    0x22,  // ░░▓░░░▓░
    0x3F,  // ░░▓▓▓▓▓▓
    0x20,  // ░░▓░░░░░
    0x00,  // ░░░░░░░░

    // #50 Number '2'
    0x32,  // ░░▓▓░░▓░
    0x29,  // ░░▓░▓░░▓
    0x29,  // ░░▓░▓░░▓
    0x26,  // ░░▓░░▓▓░

    // #51 Number '3'
    0x12,  // ░░░▓░░▓░
    0x21,  // ░░▓░░░░▓
    0x25,  // ░░▓░░▓░▓
    0x1A,  // ░░░▓▓░▓░

    // #52 Number '4'
    0x0C,  // ░░░░▓▓░░
    0x0A,  // ░░░░▓░▓░
    0x3F,  // ░░▓▓▓▓▓▓
    0x08,  // ░░░░▓░░░

    // #53 Number '5'
    0x17,  // ░░░▓░▓▓▓
    0x25,  // ░░▓░░▓░▓
    0x25,  // ░░▓░░▓░▓
    0x19,  // ░░░▓▓░░▓

    // #54 Number '6'
    0x1E,  // ░░░▓▓▓▓░
    0x25,  // ░░▓░░▓░▓
    0x25,  // ░░▓░░▓░▓
    0x18,  // ░░░▓▓░░░

    // #55 Number '7'.
    0x01,  // ░░░░░░░▓
    0x39,  // ░░▓▓▓░░▓
    0x05,  // ░░░░░▓░▓
    0x03,  // ░░░░░░▓▓

    // #56 Number '8'
    0x1A,  // ░░░▓▓░▓░
    0x25,  // ░░▓░░▓░▓
    0x25,  // ░░▓░░▓░▓
    0x1A,  // ░░░▓▓░▓░

    // #57 Number '9'
    0x06,  // ░░░░░▓▓░
    0x29,  // ░░▓░▓░░▓
    0x29,  // ░░▓░▓░░▓
    0x1E,  // ░░░▓▓▓▓░


    // Sign list 2

    // #58 Symbol ':'
    0x00,  // ░░░░░░░░
    0x14,  // ░░░▓░▓░░
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░

    // #59 Symbol ';'
    0x00,  // ░░░░░░░░
    0x20,  // ░░▓░░░░░
    0x14,  // ░░░▓░▓░░
    0x00,  // ░░░░░░░░

    // #60 Symbol '<'
    0x08,  // ░░░░▓░░░
    0x14,  // ░░░▓░▓░░
    0x22,  // ░░▓░░░▓░
    0x00,  // ░░░░░░░░

    // #61 Symbol '='
    0x14,  // ░░░▓░▓░░
    0x14,  // ░░░▓░▓░░
    0x14,  // ░░░▓░▓░░
    0x00,  // ░░░░░░░░

    // #62 Symbol '>'
    0x22,  // ░░▓░░░▓░
    0x14,  // ░░░▓░▓░░
    0x08,  // ░░░░▓░░░
    0x00,  // ░░░░░░░░

    // #63 Symbol '?'
    0x00,  // ░░░░░░░░
    0x29,  // ░░▓░▓░░▓
    0x06,  // ░░░░░▓▓░
    0x00,  // ░░░░░░░░

    // #64 Symbol '@'
    0x3F,  // ░░▓▓▓▓▓▓
    0x21,  // ░░▓░░░░▓
    0x2D,  // ░░▓░▓▓░▓
    0x0F,  // ░░░░▓▓▓▓


    // Upper case letters

    // #65 Letter 'A'
    0x3E,  // ░░▓▓▓▓▓░
    0x09,  // ░░░░▓░░▓
    0x09,  // ░░░░▓░░▓
    0x3E,  // ░░▓▓▓▓▓░

    // #66 Letter 'B'
    0x3F,  // ░░▓▓▓▓▓▓
    0x25,  // ░░▓░░▓░▓
    0x25,  // ░░▓░░▓░▓
    0x1A,  // ░░░▓▓░▓░

    // #67 Letter 'C'
    0x1E,  // ░░░▓▓▓▓░
    0x21,  // ░░▓░░░░▓
    0x21,  // ░░▓░░░░▓
    0x12,  // ░░░▓░░▓░

    // #68 Letter 'D'
    0x3F,  // ░░▓▓▓▓▓▓
    0x21,  // ░░▓░░░░▓
    0x21,  // ░░▓░░░░▓
    0x1E,  // ░░░▓▓▓▓░

    // #69 Letter 'E'
    0x3F,  // ░░▓▓▓▓▓▓
    0x25,  // ░░▓░░▓░▓
    0x25,  // ░░▓░░▓░▓
    0x21,  // ░░▓░░░░▓

    // #70 Letter 'F'
    0x3F,  // ░░▓▓▓▓▓▓
    0x05,  // ░░░░░▓░▓
    0x05,  // ░░░░░▓░▓
    0x01,  // ░░░░░░░▓

    // #71 Letter 'G'
    0x1E,  // ░░░▓▓▓▓░
    0x21,  // ░░▓░░░░▓
    0x29,  // ░░▓░▓░░▓
    0x3A,  // ░░▓▓▓░▓░

    // #72 Letter 'H'
    0x3F,  // ░░▓▓▓▓▓▓
    0x04,  // ░░░░░▓░░
    0x04,  // ░░░░░▓░░
    0x3F,  // ░░▓▓▓▓▓▓

    // #73 Letter 'I'
    0x21,  // ░░▓░░░░▓
    0x3F,  // ░░▓▓▓▓▓▓
    0x21,  // ░░▓░░░░▓
    0x00,  // ░░░░░░░░

    // #74 Letter 'J'
    0x10,  // ░░░▓░░░░
    0x21,  // ░░▓░░░░▓
    0x21,  // ░░▓░░░░▓
    0x1F,  // ░░░▓▓▓▓▓

    // #75 Letter 'K'
    0x3F,  // ░░▓▓▓▓▓▓
    0x04,  // ░░░░░▓░░
    0x0A,  // ░░░░▓░▓░
    0x31,  // ░░▓▓░░░▓

    // #76 Letter 'L'
    0x3F,  // ░░▓▓▓▓▓▓
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░

    // #77 Letter 'M'
    0x3F,  // ░░▓▓▓▓▓▓
    0x02,  // ░░░░░░▓░
    0x02,  // ░░░░░░▓░
    0x3F,  // ░░▓▓▓▓▓▓

    // #78 Letter 'N'
    0x3F,  // ░░▓▓▓▓▓▓
    0x02,  // ░░░░░░▓░
    0x04,  // ░░░░░▓░░
    0x3F,  // ░░▓▓▓▓▓▓

    // #79 Letter 'O'
    0x1E,  // ░░░▓▓▓▓░
    0x21,  // ░░▓░░░░▓
    0x21,  // ░░▓░░░░▓
    0x1E,  // ░░░▓▓▓▓░

    // #80 Letter 'P'
    0x3F,  // ░░▓▓▓▓▓▓
    0x09,  // ░░░░▓░░▓
    0x09,  // ░░░░▓░░▓
    0x06,  // ░░░░░▓▓░

    // #81 Letter 'Q'
    0x1E,  // ░░░▓▓▓▓░
    0x21,  // ░░▓░░░░▓
    0x11,  // ░░░▓░░░▓
    0x2E,  // ░░▓░▓▓▓░

    // #82 Letter 'R'
    0x3F,  // ░░▓▓▓▓▓▓
    0x09,  // ░░░░▓░░▓
    0x09,  // ░░░░▓░░▓
    0x36,  // ░░▓▓░▓▓░

    // #83 Letter 'S'
    0x22,  // ░░▓░░░▓░
    0x25,  // ░░▓░░▓░▓
    0x25,  // ░░▓░░▓░▓
    0x19,  // ░░░▓▓░░▓

    // #84 Letter 'T'
    0x01,  // ░░░░░░░▓
    0x3F,  // ░░▓▓▓▓▓▓
    0x01,  // ░░░░░░░▓
    0x01,  // ░░░░░░░▓

    // #85 Letter 'U'
    0x1F,  // ░░░▓▓▓▓▓
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░
    0x1F,  // ░░░▓▓▓▓▓

    // #86 Letter 'V'
    0x0F,  // ░░░░▓▓▓▓
    0x10,  // ░░░▓░░░░
    0x20,  // ░░▓░░░░░
    0x1F,  // ░░░▓▓▓▓▓

    // #87 Letter 'W'
    0x3F,  // ░░▓▓▓▓▓▓
    0x10,  // ░░░▓░░░░
    0x10,  // ░░░▓░░░░
    0x3F,  // ░░▓▓▓▓▓▓

    // #88 Letter 'X'
    0x3B,  // ░░▓▓▓░▓▓
    0x04,  // ░░░░░▓░░
    0x04,  // ░░░░░▓░░
    0x3B,  // ░░▓▓▓░▓▓

    // #89 Letter 'Y'
    0x03,  // ░░░░░░▓▓
    0x04,  // ░░░░░▓░░
    0x38,  // ░░▓▓▓░░░
    0x07,  // ░░░░░▓▓▓

    // #90 Letter 'Z'
    0x31,  // ░░▓▓░░░▓
    0x2D,  // ░░▓░▓▓░▓
    0x23,  // ░░▓░░░▓▓
    0x21,  // ░░▓░░░░▓


    // Sign list 3

    // #91 Symbol '['
    0x00,  // ░░░░░░░░
    0x3F,  // ░░▓▓▓▓▓▓
    0x21,  // ░░▓░░░░▓
    0x00,  // ░░░░░░░░

    // #92 Symbol '\'
    0x02,  // ░░░░░░▓░
    0x04,  // ░░░░░▓░░
    0x08,  // ░░░░▓░░░
    0x10,  // ░░░▓░░░░

    // #93 Symbol ']'
    0x00,  // ░░░░░░░░
    0x21,  // ░░▓░░░░▓
    0x3F,  // ░░▓▓▓▓▓▓
    0x00,  // ░░░░░░░░

    // #94 Symbol '^'
    0x02,  // ░░░░░░▓░
    0x01,  // ░░░░░░░▓
    0x02,  // ░░░░░░▓░
    0x00,  // ░░░░░░░░

    // #95 Symbol '_'
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░

    // #96 Symbol '`'
    0x00,  // ░░░░░░░░
    0x01,  // ░░░░░░░▓
    0x02,  // ░░░░░░▓░
    0x00,  // ░░░░░░░░


    // Lower case letters

    // #97 Letter 'a'
    0x10,  // ░░░▓░░░░
    0x2A,  // ░░▓░▓░▓░
    0x2A,  // ░░▓░▓░▓░
    0x3C,  // ░░▓▓▓▓░░

    // #98 Letter 'b'
    0x3F,  // ░░▓▓▓▓▓▓
    0x24,  // ░░▓░░▓░░
    0x24,  // ░░▓░░▓░░
    0x18,  // ░░░▓▓░░░

    // #99 Letter 'c'
    0x1C,  // ░░░▓▓▓░░
    0x22,  // ░░▓░░░▓░
    0x22,  // ░░▓░░░▓░
    0x14,  // ░░░▓░▓░░

    // #100 Letter 'd'
    0x18,  // ░░░▓▓░░░
    0x24,  // ░░▓░░▓░░
    0x24,  // ░░▓░░▓░░
    0x3F,  // ░░▓▓▓▓▓▓

    // #101 Letter 'e'
    0x1C,  // ░░░▓▓▓░░
    0x2A,  // ░░▓░▓░▓░
    0x2A,  // ░░▓░▓░▓░
    0x2C,  // ░░▓░▓▓░░

    // #102 Letter 'f'
    0x04,  // ░░░░░▓░░
    0x3E,  // ░░▓▓▓▓▓░
    0x05,  // ░░░░░▓░▓
    0x01,  // ░░░░░░░▓

    // #103 Letter 'g'
    0x26,  // ░░▓░░▓▓░
    0x29,  // ░░▓░▓░░▓
    0x29,  // ░░▓░▓░░▓
    0x1E,  // ░░░▓▓▓▓▓

    // #104 Letter 'h'
    0x3F,  // ░░▓▓▓▓▓▓
    0x04,  // ░░░░░▓░░
    0x04,  // ░░░░░▓░░
    0x38,  // ░░▓▓▓░░░

    // #105 Letter 'i'
    0x24,  // ░░▓░░▓░░
    0x3D,  // ░░▓▓▓▓░▓
    0x20,  // ░░▓░░░░░
    0x00,  // ░░░░░░░░

    // #106 Letter 'j'
    0x00,  // ░░░░░░░░
    0x20,  // ░░▓░░░░░
    0x24,  // ░░▓░░▓░░
    0x1D,  // ░░░▓▓▓░▓

    // #107 Letter 'k'
    0x3F,  // ░░▓▓▓▓▓▓
    0x08,  // ░░░░▓░░░
    0x14,  // ░░░▓░▓░░
    0x22,  // ░░▓░░░▓░

    // #108 Letter 'l'
    0x21,  // ░░▓░░░░▓
    0x3F,  // ░░▓▓▓▓▓▓
    0x20,  // ░░▓░░░░░
    0x00,  // ░░░░░░░░

    // #109 Letter 'm'
    0x3E,  // ░░▓▓▓▓▓░
    0x04,  // ░░░░░▓░░
    0x04,  // ░░░░░▓░░
    0x3E,  // ░░▓▓▓▓▓░

    // #110 Letter 'n'
    0x3E,  // ░░▓▓▓▓▓░
    0x04,  // ░░░░░▓░░
    0x02,  // ░░░░░░▓░
    0x3C,  // ░░▓▓▓▓░░

    // #111 Letter 'o'
    0x1C,  // ░░░▓▓▓░░
    0x22,  // ░░▓░░░▓░
    0x22,  // ░░▓░░░▓░
    0x1C,  // ░░░▓▓▓░░

    // #112 Letter 'p'
    0x3E,  // ░░▓▓▓▓▓░
    0x12,  // ░░░▓░░▓░
    0x12,  // ░░░▓░░▓░
    0x0C,  // ░░░░▓▓░░

    // #113 Letter 'q'
    0x0C,  // ░░░░▓▓░░
    0x12,  // ░░░▓░░▓░
    0x12,  // ░░░▓░░▓░
    0x3E,  // ░░▓▓▓▓▓░

    // #114 Letter 'r'
    0x3E,  // ░░▓▓▓▓▓░
    0x04,  // ░░░░░▓░░
    0x02,  // ░░░░░░▓░
    0x04,  // ░░░░░▓░░

    // #115 Letter 's'
    0x24,  // ░░▓░░▓░░
    0x2A,  // ░░▓░▓░▓░
    0x2A,  // ░░▓░▓░▓░
    0x12,  // ░░░▓░░▓░

    // #116 Letter 't'
    0x02,  // ░░░░░░▓░
    0x1F,  // ░░░▓▓▓▓▓
    0x22,  // ░░▓░░░▓░
    0x20,  // ░░▓░░░░░

    // #117 Letter 'u'
    0x1E,  // ░░░▓▓▓▓░
    0x20,  // ░░▓░░░░░
    0x20,  // ░░▓░░░░░
    0x1E,  // ░░░▓▓▓▓░

    // #118 Letter 'v'
    0x0E,  // ░░░░▓▓▓░
    0x10,  // ░░░▓░░░░
    0x20,  // ░░▓░░░░░
    0x1E,  // ░░░▓▓▓▓░

    // #119 Letter 'w'
    0x3E,  // ░░▓▓▓▓▓░
    0x10,  // ░░░▓░░░░
    0x10,  // ░░░▓░░░░
    0x3E,  // ░░▓▓▓▓▓░

    // #120 Letter 'x'
    0x36,  // ░░▓▓░▓▓░
    0x08,  // ░░░░▓░░░
    0x08,  // ░░░░▓░░░
    0x36,  // ░░▓▓░▓▓░

    // #121 Letter 'y'
    0x26,  // ░░▓░░▓▓░
    0x28,  // ░░▓░▓░░░
    0x28,  // ░░▓░▓░░░
    0x1E,  // ░░░▓▓▓▓░

    // #122 Letter 'z'
    0x32,  // ░░▓▓░░▓░
    0x2A,  // ░░▓░▓░▓░
    0x26,  // ░░▓░░▓▓░
    0x22,  // ░░▓░░░▓░


    // Sign list 4

    // #123 Symbol '{'
    0x08,  // ░░░░▓░░░
    0x3F,  // ░░▓▓▓▓▓▓
    0x21,  // ░░▓░░░░▓
    0x00,  // ░░░░░░░░

    // #124 Symbol '|'
    0x00,  // ░░░░░░░░
    0x3F,  // ░░▓▓▓▓▓▓
    0x00,  // ░░░░░░░░
    0x00,  // ░░░░░░░░

    // #125 Symbol '}'
    0x00,  // ░░░░░░░░
    0x21,  // ░░▓░░░░▓
    0x3F,  // ░░▓▓▓▓▓▓
    0x08,  // ░░░░▓░░░

    // #126 Symbol '~'
    0x10,  // ░░░▓░░░░
    0x08,  // ░░░░▓░░░
    0x10,  // ░░░▓░░░░
    0x08,  // ░░░░▓░░░
};

void draw_font(Grid* grid,  size_t font_index, int at_x, int at_y, SDL_Color color)
{
    for (int x = 0; x < 4 && at_x + x < grid->x_cells; ++x)
    {
        const size_t k = font_index + x;
        for (int y = 0; y < 6 && at_y + y < grid->y_cells; ++y)
        {
            set_cell_color(
                grid,
                at_x + x,
                at_y + y,
                (FONT_PIXELS[k] & (1 << y)) ? color : grid->background_color
            );
        }
    }
}

void draw_char(Grid* grid, char c, int at_x, int at_y, SDL_Color color)
{
    size_t font_index = FONT_PIXELS_UNKNOWN;

    if (c >= ' ' && c <= '~')
    {
        font_index = ((c - ' ') * 4) + FONT_PIXELS_PRINTABLE_CHAR;
    }

    draw_font(grid, font_index, at_x, at_y, color);
}

void draw_text(Grid* grid, char* text, int at_x, int at_y, int space, SDL_Color color)
{
    int cursor_x = at_x;
    int cursor_y = at_y;

    int i = 0;
    while(text[i] && cursor_y < grid->y_cells)
    {
        draw_char(grid, text[i], cursor_x, cursor_y, color);
        cursor_x += 4 + space;
        i++;

        // Word wrap
        if (cursor_x > grid->x_cells - 4)
        {
            cursor_x = at_x;
            cursor_y += 6 + space;

            // Skip space
            if (text[i] == ' ')
                i++;
        }
    }
}

void draw_key(Grid* grid, SDL_Keycode key, int at_x, int at_y, SDL_Color color)
{
    char c = key_to_char(key);
    draw_char(grid, c, at_x, at_y, color);
}

SDL_Keycode get_key(SDL_Event* event)
{
    if (event->type == SDL_KEYDOWN)
    {
        return event->key.keysym.sym;
    }

    return SDLK_UNKNOWN;
}

bool _is_mouse_over_grid(Grid* grid, int x, int y)
{
    return x >= grid->rect.x && x <= grid->rect.x + grid->rect.w
           && y >= grid->rect.y && y <= grid->rect.y + grid->rect.h;
}

bool is_mouse_over_grid(Grid* grid)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    return _is_mouse_over_grid(grid, x, y);
}

bool is_mouse_clicked(Grid* grid, SDL_Event* event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        int x = event->button.x;
        int y = event->button.y;

        return _is_mouse_over_grid(grid, x, y);
    }

    return false;
}

bool is_mouse_moved(Grid* grid, SDL_Event* event)
{
    if (event->type == SDL_MOUSEMOTION)
    {
        int x = event->motion.x;
        int y = event->motion.y;

        return _is_mouse_over_grid(grid, x, y);
    }

    return false;
}

int get_mouse_pos_x(Grid* grid, SDL_Event* event)
{
    if (is_mouse_clicked(grid, event))
    {
        int x = event->button.x;
        return (x - grid->rect.x) / (grid->rect.w / grid->x_cells);
    }
    else if(is_mouse_moved(grid, event))
    {
        int x = event->motion.x;
        return (x - grid->rect.x) / (grid->rect.w / grid->x_cells);
    }
    else
    {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if(_is_mouse_over_grid(grid, x, y))
        {
            return (x - grid->rect.x) / (grid->rect.w / grid->x_cells);
        }
    }

    return -1;
}

int get_mouse_pos_y(Grid* grid, SDL_Event* event)
{
    if (is_mouse_clicked(grid, event))
    {
        int y = event->button.y;
        return (y - grid->rect.y) / (grid->rect.h / grid->y_cells);
    }
    else if(is_mouse_moved(grid, event))
    {
        int y = event->motion.y;
        return (y - grid->rect.y) / (grid->rect.h / grid->y_cells);
    }
    else
    {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if(_is_mouse_over_grid(grid, x, y))
        {
            return (y - grid->rect.y) / (grid->rect.h / grid->y_cells);
        }
    }

    return -1;
}

Uint8 get_mouse_button(Grid* grid, SDL_Event* event)
{
    if (is_mouse_clicked(grid, event))
    {
        return event->button.button;
    }

    return 0;
}

bool start(SDL_Renderer* renderer, int width, int height);

int main(int argc, char* argv[])
{
    // Unused argc, argv
    (void) argc;
    (void) argv;

    // Initialize the pseudo-random number generator
    srand(time(NULL));

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not be initialized!\n"
                "SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    // Disable compositor bypass
    if(!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        fprintf(stderr, "SDL can not disable compositor bypass!\n");
        return 0;
    }
#endif


    // Create window
    SDL_Window* window = SDL_CreateWindow("Simple grid with C and SDL2",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if(!window)
    {
        fprintf(stderr, "Window could not be created!\n"
                "SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        // Create renderer
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(!renderer)
        {
            fprintf(stderr, "Renderer could not be created!\n"
                    "SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            // Start rendering
            start(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

            // Destroy renderer
            SDL_DestroyRenderer(renderer);
        }

        // Destroy window
        SDL_DestroyWindow(window);
    }

    // Quit SDL
    SDL_Quit();

    return 0;
}

void delay(SDL_Renderer* renderer, Uint32 ms, SDL_Event* event)
{
    event->type = 0;

    for (Uint32 i = 0; i < ms / 10; i++)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            // User requests quit
            if(e.type == SDL_QUIT)
            {
                exit(0);
                break;
            }
            else if(e.type == SDL_KEYDOWN)
            {
                *event = e;
                event->key.keysym.sym = normalize_key(event->key.keysym.sym);
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                *event = e;
            }
            else if(e.type == SDL_MOUSEMOTION)
            {
                *event = e;
            }
        }

        // Update screen
        SDL_RenderPresent(renderer);

        // Wait 1ms
        SDL_Delay(10);
    }
}

bool render_and_delay(SDL_Renderer* renderer, Grid* grid, SDL_Color background_color, Uint32 ms, SDL_Event* event)
{
    // Set white background
    set_background_color(renderer, background_color);

    // Render grid
    render_grid(grid, renderer);

    // Wait
    delay(renderer, ms, event);

    return true;
}

// Global variables
SDL_Renderer* g_renderer = NULL;
Grid g_grid = {0};
SDL_Color g_background_color = COLOR_WHITE;
SDL_Event g_event = {0};

void draw(int x_cells, int y_cells);

bool start(SDL_Renderer* renderer, int width, int height)
{
    // Init global renderer
    g_renderer = renderer;

    // Set number of cells
    g_grid.x_cells = GRID_MAX_X_CELLS;
    g_grid.y_cells = GRID_MAX_Y_CELLS;

    // Set grid dimensions
    int margin = GRID_DEFAULT_MARGIN;
    int cell_size = min( (width - margin * 2) / g_grid.x_cells,
                         (height - margin * 2) / g_grid.y_cells );
    g_grid.rect.w = cell_size * g_grid.x_cells;
    g_grid.rect.h = cell_size * g_grid.y_cells;

    // Set grid backgroud
    g_grid.background_color = GRID_DEFAULT_COLOR;

    // Set grid border thickness and color
    g_grid.border = GRID_DEFAULT_BORDER_SIZE;
    g_grid.border_color = GRID_DEFAULT_BORDER_COLOR;

    // Set cells border thickness and color
    g_grid.cells_border = g_grid.border;
    g_grid.cells_border_color = g_grid.border_color;

    // Ajust size and center
    ajust_grid_size(&g_grid);
    center_grid(&g_grid, width, height);

    if(!init_grid(&g_grid))
    {
        fprintf(stderr, "Grid fail to initialize !\n");
        return false;
    }

    // Set white background
    set_background_color(renderer, g_background_color);
    g_grid.background_color = g_background_color;

    // Render grid
    render_grid(&g_grid, renderer);

    // Update screen
    SDL_RenderPresent(renderer);

    // Draw shapes
    draw(g_grid.x_cells, g_grid.y_cells);

    // Set white background
    set_background_color(renderer, g_background_color);
    g_grid.background_color = g_background_color;

    // Render grid
    render_grid(&g_grid, renderer);

    // Update screen
    SDL_RenderPresent(renderer);

    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit)
    {
        SDL_Event e;

        // Wait indefinitely for the next available event
        SDL_WaitEvent(&e);

        // User requests quit
        if(e.type == SDL_QUIT)
        {
            quit = true;
        }
        else if(e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }

        SDL_RenderPresent(renderer);
    }

    return true;
}

#define set_background_color(color)                 (g_background_color = color)
#define get_background_color()                      (g_background_color)
#define set_cell_color(x, y, color)                 set_cell_color(&g_grid, x, y, color)
#define get_cell_color(x, y)                        get_cell_color(&g_grid, x, y)
#define set_cell_border_color(x, y, color)          set_cell_border_color(&g_grid, x, y, color)
#define get_cell_border_color(x, y)                 get_cell_border_color(&g_grid, x, y)
#define set_grid_color(color)                       set_grid_color(&g_grid, color)
#define get_grid_color()                            get_grid_color(&g_grid)
#define set_grid_border_color(color)                set_grid_border_color(&g_grid, color)
#define get_grid_border_color()                     get_grid_border_color(&g_grid)
#define delay(ms)                                   render_and_delay(g_renderer, &g_grid, g_background_color, ms, &g_event)
#define get_key()                                  get_key(&g_event)
#define is_mouse_over_grid()                        is_mouse_over_grid(&g_grid)
#define is_mouse_clicked()                          is_mouse_clicked(&g_grid, &g_event)
#define is_mouse_moved()                            is_mouse_moved(&g_grid, &g_event)
#define get_mouse_pos_x()                           get_mouse_pos_x(&g_grid, &g_event)
#define get_mouse_pos_y()                           get_mouse_pos_y(&g_grid, &g_event)
#define get_mouse_button()                          get_mouse_button(&g_grid, &g_event)
#define exit()                                      exit(0)
#define draw_key(key, at_x, at_y, color)            draw_key(&g_grid, key, at_x, at_y, color)
#define draw_char(c, at_x, at_y, color)             draw_char(&g_grid, c, at_x, at_y, color)
#define draw_text(text, at_x, at_y, space, color)   draw_text(&g_grid, text, at_x, at_y, space, color)
#define printf(...)                                 (fprintf (stdout, __VA_ARGS__), fflush(stdout))
//***************************************************************************************
// DOCUMENTATION
//***************************************************************************************

//***************************************************************************************
//
// Available function:
//
//      set_background_color(color)
//          Set the background color to one of the predefined colors
//
//      get_background_color()
//          Get the current background color
//
//      set_cell_color(x, y, color)
//          Set the color of the cell at coordinates (x, y)
//
//      get_cell_color(x, y)
//          Get the current color of the cell at coordinates (x, y)
//
//      set_cell_border_color(x, y, color)
//          Set the border color of the cell at coordinates (x, y)
//
//      get_cell_border_color(x, y)
//          Get the current border color of the cell at coordinates (x, y)
//
//      set_grid_color(color)
//          Set the grid (all cells) color
//
//      get_grid_color()
//          Get the grid color
//
//      set_grid_border_color(color)
//          Set the grid (and cells) border color
//
//      get_grid_border_color()
//          Get the current grid border color
//
//      delay(ms)
//          Wait a specified number of milliseconds
//
//      get_key()
//          Get the pressed key
//
//      is_mouse_over_grid()
//          Check if the mouse is over the grid.
//
//      is_mouse_clicked()
//          Check if the mouse was clicked (over the grid).
//
//      is_mouse_moved()
//          Check if the mouse was moved (over the grid).
//
//      get_mouse_pos_x()
//          Get the x coordinate of mouse.
//
//      get_mouse_pos_y()
//          Get the y coordinate of mouse.
//
//      get_mouse_button()
//          Get the clicked mouse button (SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT).
//
//      draw_key(key, at_x, at_y, color)
//          Write a key at position (at_x, at_y) with a specific color
//
//      draw_char(c, at_x, at_y, color)
//          Write a character at position (at_x, at_y) with a specific color
//
//      draw_text(text, at_x, at_y, space, color)
//          Write a text at position (at_x, at_y) with a specific color
//          The space parameter represents the spacing between characters
//
//      is_key_ascii(key)
//          Check if a key is an ASCII-based character
//
//      is_key_letter(key)
//          Check if a key is a letter
//
//      is_key_digit(key)
//          Check if a key is a digit
//
//      is_key_arithmetic_op(key)
//          Check if a key is an arithmetic operator (+, -, *, /, %)
//
//      key_to_char(key)
//          Convert a key to a character
//
//      key_to_char_lowercase(key)
//          Convert a key to a lowercase character
//
//      key_to_int(key)
//          Convert a key to a digit (integer)
//
//      digit_to_key(digit)
//          Convert a digit (integer) to a key
//
//      digit_to_char(digit)
//          Convert a digit (integer) to a character
//
//      char_to_digit(c)
//          Convert a character to a digit (integer)
//
//      random_int(min, max)
//          Get a random integer between min and max
//
//      is_color_equal(color1, color2)
//          Check if 'color1' is equal to 'color2' (return a boolean)
//
//      exit()
//          Exit the program
//
// Available colors:
//
//      COLOR_BLACK
//      COLOR_WHITE
//      COLOR_GRAY
//      COLOR_DARK_GRAY
//      COLOR_LIGHT_GRAY
//      COLOR_RED
//      COLOR_GREEN
//      COLOR_BLUE
//      COLOR_YELLOW
//      COLOR_ORANGE
//      COLOR_PINK
//      COLOR_VIOLET
//
// Custom color:
//
//      COLOR( red, green, blue )
//
// Available keys:
//  (Full list at https://wiki.libsdl.org/SDL_Keycode)
//
//      SDLK_RETURN
//      SDLK_SPACE
//      SDLK_BACKSPACE
//      SDLK_ESCAPE
//      SDLK_{character}
//      SDLK_{digit}
//      SDLK_UP
//      SDLK_DOWN
//      SDLK_RIGHT
//      SDLK_LEFT
//      SDLK_EXCLAIM
//      SDLK_PERIOD
//      SDLK_COLON
//      SDLK_EQUALS
//      SDLK_PLUS
//      SDLK_MINUS
//      SDLK_DIVIDE
//      SDLK_MULTIPLY
//      SDLK_PERCENT
//
//
//***************************************************************************************

//***************************************************************************************
// FREE CODING SECTION
//***************************************************************************************


struct pacmans {
    int x;
    int y ;
    SDL_Color color ;

};
typedef struct pacmans pacman ;
struct ghosts{
    int x ;
    int y ;
    SDL_Color color ;

};
typedef struct ghosts ghost;

bool check_interaction(ghost g, pacman p){
    if ((g.x+1 == p.x && g.y+1 == p.y )|| (g.x == p.x+1 && g.y+1 == p.y )||
        (g.x == p.x+1 && g.y == p.y+1 )|| (g.x+1 == p.x && g.y == p.y+1 )||
        (g.x == p.x && g.y == p.y )|| (g.x+1 == p.x+1 && g.y+1 == p.y+1 ))
{
        return true ;
    }
    else {
        return false ;
    }
}
void check_obstacle(int *x,int * y,SDL_Color obstacle_color){
    //CHECK RIGHT
    int x_next = (*x)+2 ; int y_next = (*y )+1 ;
    SDL_Color c = obstacle_color  ;
    if (is_color_equal(get_cell_color(x_next,*y),c)||  is_color_equal(get_cell_color(x_next,y_next),c)){
        *x -=1 ;
    }
    //CHECK LEFT
    x_next = (*x)-1 ;
    if (is_color_equal(get_cell_color(x_next,*y),c) || is_color_equal(get_cell_color(x_next,y_next),c)){
        *x+=1;
    }
    //CHECK TOP
    x_next = (*x) + 1 ; y_next = (*y)-1 ;
    if ( is_color_equal(get_cell_color(*x, y_next),c) || is_color_equal(get_cell_color(x_next,y_next),c)){
        *y+=1;
    }
    //CHECK BOTTOM
    y_next = (*y) +2 ;
    if (is_color_equal(get_cell_color(*x,y_next),c) || is_color_equal(get_cell_color(x_next, y_next),c)|| y_next >= 93){
        *y-=1;
    }

}
void count_score(int *x,int * y,int *score,SDL_Color dots_color){

    SDL_Color c = dots_color ;
    //CHECK RIGHT
    int x_next = (*x)+2 ; int y_next = (*y )+1 ;
    if (is_color_equal(get_cell_color(x_next,*y),c)||  is_color_equal(get_cell_color(x_next,y_next),c)){
        *score+=1;
    }
    //CHECK LEFT
    x_next = (*x)-1 ;
    if (is_color_equal(get_cell_color(x_next,*y),c) || is_color_equal(get_cell_color(x_next,y_next),c)){
        *score+=1;
    }
    //CHECK TOP
    x_next = (*x) + 1 ; y_next = (*y)-1 ;
    if ( is_color_equal(get_cell_color(*x, y_next),c) || is_color_equal(get_cell_color(x_next,y_next),c)){
        *score+=1;
    }
    //CHECK BOTTOM
    y_next = (*y) +2 ;
    if (is_color_equal(get_cell_color(*x,y_next),c) || is_color_equal(get_cell_color(x_next, y_next),c)|| y_next >= 93){
        *score+=1;
    }
}
void draw_dots(){
    int x,y ;
    for(x=0;x<=200;x+=3){
        for(y=0;y<=100;y+=3){
            if ((x>=30 && x<=165)&&(y>=24 && y<=77)){
                continue;
            }
            if ( is_color_equal(get_cell_color(x,y),COLOR_BLACK) ) {
                    set_cell_color(x,y,COLOR_YELLOW);
            }
        }
    }
}
void draw_ghost(ghost g){
    set_cell_color(g.x,g.y,g.color);
    set_cell_color(g.x+1,g.y,g.color);
    set_cell_color(g.x,g.y+1,g.color);
    set_cell_color(g.x+1,g.y+1,g.color);

}
void draw_pac(pacman p){
    set_cell_color(p.x,p.y,p.color);
    set_cell_color(p.x+1,p.y,p.color);
    set_cell_color(p.x,p.y+1,p.color);
    set_cell_color(p.x+1,p.y+1,p.color);

}
void draw_score_bar(){
    int x,y ;
    //bar
    for (x = 0; x<201;x++){
        for(y=92;y<101;y++){
            if (x==0|| x==200){
                set_cell_color(x,y,COLOR_RED);
                continue;
            }
            if ((y==100)||(y==92)){
                set_cell_color(x,y,COLOR_BLUE);
                continue ;
            }
            set_cell_color(x,y,COLOR_BLACK);
        }
    }
    //EXIT
    draw_text("Exit:ESC",5,93,1,COLOR_WHITE);
    //score
    draw_text("Score:",60,93,2,COLOR_PINK);
    //Time
    draw_text("TIME:",130,93,2,COLOR_VIOLET);

}
void endscore_bar(char scorer[]){
    rect(120,20,COLOR_BLACK,COLOR_BLUE);
    draw_text("your score is ",45,46,2,COLOR_GREEN);
    draw_text(scorer,130,46,2,COLOR_BLUE);
}
void frame_and_lines(){
    int x,y ;
//HORIZONTAL LINES

    for(x=0;x<= 200;x++){
        if (( x>= 0&& x<=10)||(x>=190 && x<=200)){
            set_cell_color(x,58,COLOR_BLUE);
            set_cell_color(x,55,COLOR_BLUE);
            set_cell_color(x,45,COLOR_BLUE);
            set_cell_color(x,42,COLOR_BLUE);
        }
        //BOXES
        if ((x>=12&&x<=40)||(x>=50 && x<=70)||(x>=80 && x<=95)||(x>=110 && x<=140)||(x>=150 && x<=170)){
            set_cell_color(x,15,COLOR_BLUE);
            set_cell_color(x,18,COLOR_BLUE);
        } else {
            set_cell_color(x,85,COLOR_BLUE);
            set_cell_color(x,88,COLOR_BLUE);
        }
    set_cell_color(x,100,COLOR_BLUE);
    set_cell_color(x,0,COLOR_BLUE);

            }
//BOXES
    //1
        for(x=12;x<=40;x++){
            for(y=15;y<=18;y++){
                set_cell_color(x,y,COLOR_BLUE);}
        }
            for(x=50;x<=70;x++){
                for(y=15;y<=18;y++){
                    set_cell_color(x,y,COLOR_BLUE);}
        }
                for(x=80;x<=95;x++){
                    for(y=15;y<=18;y++){
                        set_cell_color(x,y,COLOR_BLUE);}
        }
                    for(x=110;x<=140;x++){
                        for(y=15;y<=18;y++){
                            set_cell_color(x,y,COLOR_BLUE);}
        }
                        for(x=150;x<=170;x++){
                            for(y=15;y<=18;y++){
                                set_cell_color(x,y,COLOR_BLUE);}
        }
    //2
        for(x=0;x<=12;x++){
                for(y=85;y<=88;y++){
                    set_cell_color(x,y,COLOR_BLUE);}
        }
                for(x=40;x<=50;x++){
                    for(y=85;y<=88;y++){
                        set_cell_color(x,y,COLOR_BLUE);}
        }
                    for(x=70;x<=80;x++){
                        for(y=85;y<=88;y++){
                            set_cell_color(x,y,COLOR_BLUE);}
        }
                        for(x=95;x<=110;x++){
                            for(y=85;y<=88;y++){
                                set_cell_color(x,y,COLOR_BLUE);}
        }
                            for(x=140;x<=150;x++){
                                for(y=85;y<=88;y++){
                                    set_cell_color(x,y,COLOR_BLUE);}
        }
                                for(x=170;x<=200;x++){
                                    for(y=85;y<=88;y++){
                                        set_cell_color(x,y,COLOR_BLUE);}
        }


// VERTICAL BOXES LINES
    for(y=0;y<= 100;y++){

       // Don't color from (a,b)
           if (y > 45 && y < 55){
             continue ;
            }
        //EMPTY
            if ((y>=42 && y <= 45)||(y>= 55 && y<=58)){
               for(x=0;x<=10;x++){
                   set_cell_color(x,y,COLOR_BLUE);
               }
               for(x=190;x<=200;x++){
                   set_cell_color(x,y,COLOR_BLUE);
               }
            }
              set_cell_color(0,y,COLOR_BLUE);
              set_cell_color(200,y,COLOR_BLUE);
            }

}
void game_over(){
    rect(75,19,COLOR_BLACK,COLOR_RED);
    draw_text("GAME OVER",75,46,2,COLOR_GREEN);
}
void move_ghost(ghost *g,int distance_x,int distance_y,int* reset){
    *reset +=1 ;
    if (*reset <(distance_x)){
        g->x ++;
    } else if (*reset <(distance_x)+(distance_y)){
        g->y++;
    } else if (*reset < (distance_y) + (2*distance_x)){
        g->x--;
    }else if (*reset <(2*distance_y) + (2*distance_x)){
        g->y--;
    }else if (*reset == ((2*distance_y) + (2*distance_x))){
        *reset = -1 ;
    }

}
void m_tech(){
    set_background_color(COLOR_BLACK);
    set_grid_color(COLOR_BLACK);
    int x,y ;
    for(x=0;x<201;x++){
        for(y =0; y<101;y++){
            set_cell_color(x,y,COLOR_BLACK);
        }
    }
///*************M*******************
        //HORIZONTAL
        for (x=30; x<=57;x++){
            if(x>40 && x<47){
                set_cell_color(x,25,COLOR_BLUE);
                set_cell_color(x,35,COLOR_BLUE);
                continue;
            }
            set_cell_color(x,75,COLOR_BLUE);
            set_cell_color(x,25,COLOR_BLUE);
        }
                                                                //VERTICAL
                                                                for(y=25;y<=75;y++){
                                                                    set_cell_color(30,y,COLOR_BLUE);
                                                                    set_cell_color(57,y,COLOR_BLUE);
                                                                    if (y>35){
                                                                        set_cell_color(40,y,COLOR_BLUE);
                                                                        set_cell_color(47,y,COLOR_BLUE);
                                                                    }
                                                                }

    //*************T*******************
        //HORIZONTAL
        for(x=61;x<=87;x++){
        set_cell_color(x,25,COLOR_BLUE);
           if (x>=61&& x<=69){
            set_cell_color(x,35,COLOR_BLUE);
           } else if (x>=69&&x<=79){
            set_cell_color(x,75,COLOR_BLUE);
           } else if (x>=79&& x<=87){
            set_cell_color(x,35,COLOR_BLUE);
           }
        }
                                            //VERTICAL
                                                for(y=25;y<=75;y++){
                                                   if (y>=25&& y<35){
                                                    set_cell_color(61,y,COLOR_BLUE);
                                                    set_cell_color(87,y,COLOR_BLUE);
                                                   } else {
                                                    set_cell_color(69,y,COLOR_BLUE);
                                                    set_cell_color(79,y,COLOR_BLUE);
                                                   }
                                                }
 //*************E*******************
        //HORIZONTAL
        for (x=92; x<=110;x++){
            if(x>92 && x<96){
                set_cell_color(x,25,COLOR_BLUE);
                set_cell_color(x,75,COLOR_BLUE);
                continue;
            }
            set_cell_color(x,25,COLOR_BLUE);
            set_cell_color(x,35,COLOR_BLUE);
            set_cell_color(x,47,COLOR_BLUE);
            set_cell_color(x,53,COLOR_BLUE);
            set_cell_color(x,65,COLOR_BLUE);
            set_cell_color(x,75,COLOR_BLUE);
        }
                                                    //VERTICAL
                                                    for(y=25;y<=75;y++){
                                                        set_cell_color(92,y,COLOR_BLUE);
                                                        if ((y>25&&y<35)|| (y>47 && y<53) ||(y>65 && y<75)){
                                                            set_cell_color(110,y,COLOR_BLUE);
                                                        } else if ((y>35&&y<47)||(y>53&&y<65)){
                                                            set_cell_color(96,y,COLOR_BLUE);
                                                        }
                                                    }
 //*************C*******************
    //HORIZONTAL
    for(x=115;x<=136;x++){
    set_cell_color(x,25,COLOR_BLUE);
    set_cell_color(x,75,COLOR_BLUE);
       if (x>=116&& x<=125){
        continue;
       }
    set_cell_color(x,35,COLOR_BLUE);
    set_cell_color(x,65,COLOR_BLUE);
    }
                                                //VERTICAL
                                                    for(y=25;y<=75;y++){
                                                    set_cell_color(115,y,COLOR_BLUE);
                                                       if (y>=25&& y<35){
                                                        set_cell_color(136,y,COLOR_BLUE);
                                                       } else if( y>= 35&& y<=65){
                                                        set_cell_color(125,y,COLOR_BLUE);
                                                       } else {
                                                        set_cell_color(136,y,COLOR_BLUE);
                                                       }
                                                 }
//*************H*******************
    //HORIZONTAL
    for(x=140;x<=165;x++){
       if ((x>=140&& x<=148)||(x>=157 && x<=165)){
        set_cell_color(x,25,COLOR_BLUE);
        set_cell_color(x,75,COLOR_BLUE);
       } else {
        set_cell_color(x,45,COLOR_BLUE);
        set_cell_color(x,55,COLOR_BLUE);
       }
     }
                                                        //VERTICAL
                                                            for(y=25;y<=75;y++){
                                                            set_cell_color(140,y,COLOR_BLUE);
                                                            set_cell_color(165,y,COLOR_BLUE);
                                                            if( y> 45&& y<55){
                                                                continue;}
                                                            set_cell_color(148,y,COLOR_BLUE);
                                                            set_cell_color(157,y,COLOR_BLUE);
                                                           }
}
void rect(int w, int h,SDL_Color fill_color,SDL_Color border_color){
    for (int i = 100-(w/2) ; i <100+(w/2); i++){
        for(int j = 50-(h/2); j <50+(h/2); j++){
            if (i==100-(w/2)|| i==99+(w/2)){
                set_cell_color(i,j,border_color);
                continue ;
            }
            if (j ==50-(h/2) || j == 49+(h/2)){
                set_cell_color(i,j,border_color);
                continue ;
            }
            set_cell_color(i,j,fill_color);
        }
    }
}
void reinitialize_x(int* x){
      // Reinitialize position x
        if (*x < 0){
             *x = 199 ;
        } else if (*x>= 200){
             *x = 1 ;
        }
}
void reinitialize_y(int *y){
     // Reinitialize position y
        if (*y<=0){
            *y = 99 ;
        } else if (*y >= 100 ){
            *y =1 ;
        }
}
void run_background(){
    //BACKGROUND
    m_tech();
    frame_and_lines();
    draw_dots();
    draw_score_bar();
}
void score_to_text(int score ,char text[]){
        text[3] = digit_to_char(score %10);
        text[2] = digit_to_char((int)score/10);
        text[1] = digit_to_char((int)score/100);
        text[0] = digit_to_char((int)score /1000);

}
void start_bar(){
    rect(80,20,COLOR_BLACK,COLOR_RED);
    draw_text("Press space",68,45,2,COLOR_GREEN);
}
void final_scores(int score1, int score2){
    int winner ;
    if (score1 > score2){
        winner = 1 ;
    } else if (score1== score2){
        winner = 0 ;
    } else {
        winner = 2 ;
    }
    rect(80,20,COLOR_BLACK,COLOR_RED);

    if (winner == 1){
        draw_text("PLAYER1 WINS",68,45,2,COLOR_GREEN);
    } else if (winner == 2){
        draw_text("PLAYER2 WINS",68,45,2,COLOR_GREEN);
    } else {
        draw_text("IT'S A TIE",68,45,2,COLOR_GREEN);
    }

}
void time_to_text(int time,char timer[]){
        timer[1] = digit_to_char(time%10);
        timer[0] = digit_to_char((int)time/10);

}
void undraw_ghost(ghost g){
    set_cell_color(g.x,g.y,COLOR_BLACK);
    set_cell_color(g.x+1,g.y,COLOR_BLACK);
    set_cell_color(g.x,g.y+1,COLOR_BLACK);
    set_cell_color(g.x+1,g.y+1,COLOR_BLACK);
}
void undraw_pac(pacman p){
    set_cell_color(p.x,p.y,COLOR_BLACK);
    set_cell_color(p.x+1,p.y,COLOR_BLACK);
    set_cell_color(p.x,p.y+1,COLOR_BLACK);
    set_cell_color(p.x+1,p.y+1,COLOR_BLACK);
}

ghost ghost1={5,5,COLOR_PINK};
ghost ghost2={5,78,COLOR_GRAY};
ghost ghost3={170,5,COLOR_LIGHT_GRAY};
ghost ghost4={170,60,COLOR_VIOLET};
ghost ghost5={40,4,COLOR_ORANGE};
ghost ghost6={60,79,COLOR_RED};
pacman pac ={0,50,COLOR_GREEN};

bool begins = false ;

SDL_Keycode key = SDLK_RIGHT;

int counter = 0 ;
int ends = 0 ;
int score1 = 1 ;
int reset1 =0;
int reset2=0;
int reset3=0;
int reset4 = 0 ;
int reset5 =0;
int reset6 = 0 ;

char scorer[5] ;
char timer[10] ;


void draw(int x_cells, int y_cells)
{
    int time = 30 ;
    run_background();
    rect(100,20,COLOR_BLACK,COLOR_GREEN);
    draw_text("PLAYER'S 1 TURN",56,45,2,COLOR_GREEN);
    delay(2000);
    run_background();
    start_bar();
//Waiting for user to press space
    while (!begins)
    {
        SDL_Keycode c = get_key();
        if (c==SDLK_SPACE)
        {
            begins = true;
            run_background();
        }
        delay(10);
    }
// Staring game loop
    while(begins)
    {
        //PACMAN motion
        undraw_pac(pac);
        reinitialize_x(&pac.x);
        reinitialize_y(&pac.y);
        undraw_pac(pac);
        check_obstacle(&pac.x,&pac.y,COLOR_BLUE);
        //Keyboard
        SDL_Keycode next_key = get_key();
        //Keep pac moving
        if (next_key)
        {
            key = next_key ;
        }
        switch(key)
        {
        case SDLK_UP :
            --pac.y;
            break ;
        case SDLK_DOWN :
            pac.y++;
            break ;
        case SDLK_RIGHT :
            pac.x++;
            break ;
        case SDLK_LEFT :
            pac.x--;
            break ;
        case SDLK_ESCAPE :
            exit();
            break;
        default :
            break ;
        }
        draw_pac(pac);
        //ghost1 motion
        undraw_ghost(ghost1);
        move_ghost(&ghost1,50,5,&reset1);
        draw_ghost(ghost1);

        //ghost2 motion
        undraw_ghost(ghost2);
        move_ghost(&ghost2,50,5,&reset2);
        draw_ghost(ghost2);

        //ghost3 motion
        undraw_ghost(ghost3);
        move_ghost(&ghost3,28,20,&reset3);
        draw_ghost(ghost3);

        //ghost4 motion
        undraw_ghost(ghost4);
        move_ghost(&ghost4,25,15,&reset4);
        draw_ghost(ghost4);

        //ghost5 motion
        undraw_ghost(ghost5);
        move_ghost(&ghost5,76,6,&reset5);
        draw_ghost(ghost5);

          //ghost6 motion
        undraw_ghost(ghost6);
        move_ghost(&ghost6,53,10,&reset6);
        draw_ghost(ghost6);

        //timer
        if ((counter %50)==0)
        {
            time -= 1 ;
        }
        counter++;

        //score && time display
        count_score(&pac.x,&pac.y,&score1,COLOR_YELLOW);
        score_to_text(score1,scorer);
        draw_text(scorer,95,93,2,COLOR_GREEN);
        time_to_text(time,timer);
        draw_text(timer,160,93,2,COLOR_RED);

        //game over
        if (check_interaction(ghost1,pac)|| check_interaction(ghost2,pac)||
            check_interaction(ghost3,pac)|| check_interaction(ghost4,pac)||
            check_interaction(ghost5,pac)|| check_interaction(ghost6,pac)){
            break ;
        }
        // End of game exit
        if (time ==0){
            break ;
        }
        //Speed
        delay(15);
    }
    if (time != 0){
        game_over();
        score1 = 0 ;
        delay(2000);

    } else {
        endscore_bar(scorer);
        delay(2000);
    }
/////////////////////////player2////////////////
pac.x = 0 ; pac.y = 50 ;
ghost1.x = 5; ghost1.y = 5 ;
ghost2.x = 5; ghost2.y =78;
ghost3.x = 170; ghost3.y = 5;
ghost4.x = 170; ghost4.y = 60;
ghost5.x = 40; ghost5.y = 4;
ghost6.x = 60; ghost6.y = 79;
begins = false ;

SDL_Keycode key = SDLK_RIGHT;

counter = 0 ;
ends = 0 ;
int score2 = 1 ;
reset1 =0;
reset2=0;
reset3=0;
reset4 = 0 ;
reset5 =0;
reset6 = 0 ;
time = 30 ;

    run_background();
    rect(100,20,COLOR_BLACK,COLOR_GREEN);
    draw_text("PLAYER'S 2 TURN",56,45,2,COLOR_GREEN);
    delay(2000);
    run_background();
    start_bar();
//Waiting for user to press space
    while (!begins)
    {
        SDL_Keycode c = get_key();
        if (c==SDLK_SPACE)
        {
            begins = true;
            run_background();
        }
        delay(10);
    }
// Staring game loop
    while(begins)
    {
        //PACMAN motion
        undraw_pac(pac);
        reinitialize_x(&pac.x);
        reinitialize_y(&pac.y);
        undraw_pac(pac);
        check_obstacle(&pac.x,&pac.y,COLOR_BLUE);
        //Keyboard
        SDL_Keycode next_key = get_key();
        //Keep pac moving
        if (next_key)
        {
            key = next_key ;
        }
        switch(key)
        {
        case SDLK_UP :
            --pac.y;
            break ;
        case SDLK_DOWN :
            pac.y++;
            break ;
        case SDLK_RIGHT :
            pac.x++;
            break ;
        case SDLK_LEFT :
            pac.x--;
            break ;
        case SDLK_ESCAPE :
            exit();
            break;
        default :
            break ;
        }
        draw_pac(pac);
        //ghost1 motion
        undraw_ghost(ghost1);
        move_ghost(&ghost1,50,5,&reset1);
        draw_ghost(ghost1);

        //ghost2 motion
        undraw_ghost(ghost2);
        move_ghost(&ghost2,50,5,&reset2);
        draw_ghost(ghost2);

        //ghost3 motion
        undraw_ghost(ghost3);
        move_ghost(&ghost3,28,20,&reset3);
        draw_ghost(ghost3);

        //ghost4 motion
        undraw_ghost(ghost4);
        move_ghost(&ghost4,25,15,&reset4);
        draw_ghost(ghost4);

        //ghost5 motion
        undraw_ghost(ghost5);
        move_ghost(&ghost5,76,6,&reset5);
        draw_ghost(ghost5);

          //ghost6 motion
        undraw_ghost(ghost6);
        move_ghost(&ghost6,53,10,&reset6);
        draw_ghost(ghost6);

        //timer
        if ((counter %50)==0)
        {
            time -= 1 ;
        }
        counter++;

        //score && time display
        count_score(&pac.x,&pac.y,&score2,COLOR_YELLOW);
        score_to_text(score2,scorer);
        draw_text(scorer,95,93,2,COLOR_GREEN);
        time_to_text(time,timer);
        draw_text(timer,160,93,2,COLOR_RED);

        //game over
        if (check_interaction(ghost1,pac)|| check_interaction(ghost2,pac)||
            check_interaction(ghost3,pac)|| check_interaction(ghost4,pac)||
            check_interaction(ghost5,pac)|| check_interaction(ghost6,pac)){
            break ;
        }
        // End of game exit
        if (time ==0){
            break ;
        }
        //Speed
        delay(15);
    }
    if (time != 0){
        game_over();
        score2 = 0 ;
        delay(2000);
    } else {
        endscore_bar(scorer);
        delay(2000);
    }
    set_grid_color(COLOR_BLACK);
    final_scores(score1,score2);


}

//END




