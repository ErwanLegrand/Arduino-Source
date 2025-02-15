/*  Type Symbol Finder
 *
 *  From: https://github.com/PokemonAutomation/Arduino-Source
 *
 */

#ifndef PokemonAutomation_PokemonSwSh_TypeSymbolFinder_H
#define PokemonAutomation_PokemonSwSh_TypeSymbolFinder_H

#include <map>
#include "CommonFramework/ImageTools/ImageBoxes.h"
#include "CommonFramework/Tools/ProgramEnvironment.h"
#include "CommonFramework/Tools/VideoFeed.h"
#include "PokemonSwSh/Resources/PokemonSwSh_TypeSprites.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonSwSh{


//  Find all type symbols inside the image.
std::multimap<double, std::pair<PokemonType, ImagePixelBox>> find_symbols(
    const QImage& image, double max_area_ratio
);



void test_find_symbols(
    ProgramEnvironment& env,
    VideoOverlay& overlay,
    const ImageFloatBox& box,
    const QImage& screen, double max_area_ratio
);


}
}
}
#endif
