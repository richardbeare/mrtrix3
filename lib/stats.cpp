#include "stats.h"

namespace MR
{

  namespace Stats
  {

    using namespace App;

    const OptionGroup Options = OptionGroup ("Statistics options")
    + Option ("output",
        "output only the field specified. Multiple such options can be supplied if required. "
        "Choices are: " + join (field_choices, ", ") + ". Useful for use in scripts.").allow_multiple()
    + Argument ("field").type_choice (field_choices)

    + Option ("mask",
        "only perform computation within the specified binary mask image.")
    + Argument ("image").type_image_in ()

    + Option ("histogram",
        "generate histogram of intensities and store in specified text file. Note "
        "that the first line of the histogram gives the centre of the bins.")
    + Argument ("file").type_file_out ()

    + Option ("bins",
        "the number of bins to use to generate the histogram (default = 100).")
    + Argument ("num").type_integer (2, 100, std::numeric_limits<int>::max())

    + Option ("dump",
        "dump the voxel intensities to a text file.")
    + Argument ("file").type_file_out ();

  }

}
