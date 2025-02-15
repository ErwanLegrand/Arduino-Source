/*  Fill Geometry
 *
 *  From: https://github.com/PokemonAutomation/Arduino-Source
 *
 *
 *      Return a set of connected clusters.
 *
 */

#ifndef PokemonAutomation_CommonFramework_FillGeometry_H
#define PokemonAutomation_CommonFramework_FillGeometry_H

#include <stdint.h>
#include <vector>
#include "CommonFramework/ImageTools/ImageStats.h"
#include "ImageBoxes.h"
#include "CellMatrix.h"

namespace PokemonAutomation{

struct FillGeometry{
    ImagePixelBox box;
    CellMatrix::ObjectID id = 0;
    size_t area = 0;
    uint64_t sum_x = 0;
    uint64_t sum_y = 0;

    double aspect_ratio() const;
    double area_ratio() const;

    pxint_t center_x() const;
    pxint_t center_y() const;

    bool assert_aspect_ratio(double lower_bound, double upper_bound) const;
    bool assert_area_ratio(double lower_bound, double upper_bound) const;

    void merge_assume_no_overlap(const FillGeometry& obj);
};

enum class MapState : uint8_t{
    WALL,
    EMPTY,
    QUEUED,
    DONE,
};


bool fill_geometry(
    FillGeometry& geometry,
    CellMatrix& matrix, CellMatrix::ObjectID required_existing_id,
    pxint_t x, pxint_t y, bool allow_diagonal,
    CellMatrix::ObjectID id
);
std::vector<FillGeometry> find_all_objects(
    CellMatrix& matrix, CellMatrix::ObjectID required_existing_id,
    bool allow_diagonal,
    size_t min_area = 10
);


ImageStats object_stats(
    const QImage& image,
    const CellMatrix& matrix,
    const FillGeometry& object
);


}
#endif
