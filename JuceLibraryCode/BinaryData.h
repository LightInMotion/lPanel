/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   info_png;
    const int            info_pngSize = 3283;

    extern const char*   sequence_active2x_png;
    const int            sequence_active2x_pngSize = 13655;

    extern const char*   sequence_inactive2x_png;
    const int            sequence_inactive2x_pngSize = 12430;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 3;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}
