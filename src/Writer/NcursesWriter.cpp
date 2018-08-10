/*
 * NcursesWriter.cpp
 *
 * Created on: Jul 30, 2015
 *     Author: dpayne
 */
#include <cmath>

#include "Domain/VisConstants.h"
#include "Utils/Logger.h"
#include "Utils/NcursesUtils.h"
#include "Writer/NcursesWriter.h"

#ifdef _LINUX
/* Ncurses version 6.0.20170401 introduced an issue with COLOR_PAIR which broke
 * setting more than 256 color pairs. Specifically it uses an A_COLOR macro
 * which uses a 8 bit mask. This will work for colors since only 256 colors are
 * supported but it breaks color pairs since 2^16 color pairs are supported.
 */
#define VIS_A_COLOR (NCURSES_BITS(((1U) << 16) - 1U, 0))
#define VIS_COLOR_PAIR(n) (NCURSES_BITS((n), 0) & VIS_A_COLOR)
#else
#define VIS_COLOR_PAIR(n) (COLOR_PAIR(n))
#endif


vis::NcursesWriter::NcursesWriter()
{

    socket = OpenFlaschenTaschenSocket("");
    canvas = new UDPFlaschenTaschen(socket, 30, 22);
    canvas->SetOffset(0,0,0);
    canvas->Clear();
}

void vis::NcursesWriter::setup_color_pairs(
    bool is_override_terminal_colors,
    const std::vector<ColorDefinition> &colors)
{
  
}

void vis::NcursesWriter::setup_colors(
    bool is_override_terminal_colors,
    const std::vector<ColorDefinition> &colors)
{
 
}

void vis::NcursesWriter::write_background(int32_t height, int32_t width,
                                          vis::ColorDefinition color,
                                          const std::wstring &msg)
{
 
}


void vis::NcursesWriter::write_foreground(int32_t height, int32_t width,
                                          vis::ColorDefinition color,
                                          const std::wstring &msg)
{

}

void vis::NcursesWriter::write(const int32_t row, const int32_t column,
                               const vis::ColorDefinition color,
                               const std::wstring &msg, const wchar_t character)
{
    Color flaschcolor(color.get_red(), color.get_green(), color.get_blue());
    canvas->SetPixel(row, column, flaschcolor);
}

void vis::NcursesWriter::clear()
{
	canvas->Clear();
	canvas->Send();
}

void vis::NcursesWriter::flush()
{
	canvas->Send();
}

vis::ColorDefinition
vis::NcursesWriter::to_color_pair(int32_t number, int32_t max,
                                  std::vector<ColorDefinition> colors,
                                  bool wrap) const
{
}

vis::NcursesWriter::~NcursesWriter()
{
	canvas->Clear();
	canvas->Send();
}
