.. _mrconvert:

mrconvert
===================

Synopsis
--------

Perform conversion between different file types and optionally extract a subset of the input image

Usage
--------

::

    mrconvert [ options ]  input output

-  *input*: the input image.
-  *output*: the output image.

Description
-----------

If used correctly, this program can be a very useful workhorse. In addition to converting images between different formats, it can be used to extract specific studies from a data set, extract a specific region of interest, or flip the images.

Options
-------

-  **-coord axis coord** extract data from the input image only at the coordinates specified.

-  **-vox sizes** change the voxel dimensions of the output image. The new sizes should be provided as a comma-separated list of values. Only those values specified will be changed. For example: 1,,3.5 will change the voxel size along the x & z axes, and leave the y-axis voxel size unchanged.

-  **-axes axes** specify the axes from the input image that will be used to form the output image. This allows the permutation, ommission, or addition of axes into the output image. The axes should be supplied as a comma-separated list of axes. Any ommitted axes must have dimension 1. Axes can be inserted by supplying -1 at the corresponding position in the list.

-  **-scaling values** specify the data scaling parameters used to rescale the intensity values. These take the form of a comma-separated 2-vector of floating-point values, corresponding to offset & scale, with final intensity values being given by offset + scale * stored_value. By default, the values in the input image header are passed through to the output image header when writing to an integer image, and reset to 0,1 (no scaling) for floating-point and binary images. Note that his option has no effect for floating-point and binary images.

Options for handling JSON (JavaScript Object Notation) files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  **-json_import file** import data from a JSON file into header key-value pairs

-  **-json_export file** export data from an image header key-value pairs into a JSON file

Options to modify generic header entries
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  **-clear_property key** remove the specified key from the image header altogether.

-  **-set_property key value** set the value of the specified key in the image header.

-  **-append_property key value** append the given value to the specified key in the image header (this adds the value specified as a new line in the header value).

Stride options
^^^^^^^^^^^^^^

-  **-stride spec** specify the strides of the output data in memory, as a comma-separated list. The actual strides produced will depend on whether the output image format can support it.

Data type options
^^^^^^^^^^^^^^^^^

-  **-datatype spec** specify output image data type. Valid choices are: float32, float32le, float32be, float64, float64le, float64be, int64, uint64, int64le, uint64le, int64be, uint64be, int32, uint32, int32le, uint32le, int32be, uint32be, int16, uint16, int16le, uint16le, int16be, uint16be, cfloat32, cfloat32le, cfloat32be, cfloat64, cfloat64le, cfloat64be, int8, uint8, bit.

DW gradient table import options
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  **-grad file** Provide the diffusion-weighted gradient scheme used in the acquisition in a text file. This should be supplied as a 4xN text file with each line is in the format [ X Y Z b ], where [ X Y Z ] describe the direction of the applied gradient, and b gives the b-value in units of s/mm^2. If a diffusion gradient scheme is present in the input image header, the data provided with this option will be instead used.

-  **-fslgrad bvecs bvals** Provide the diffusion-weighted gradient scheme used in the acquisition in FSL bvecs/bvals format files. If a diffusion gradient scheme is present in the input image header, the data provided with this option will be instead used.

DW gradient table export options
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  **-export_grad_mrtrix path** export the diffusion-weighted gradient table to file in MRtrix format

-  **-export_grad_fsl bvecs_path bvals_path** export the diffusion-weighted gradient table to files in FSL (bvecs / bvals) format

Options for importing phase-encode tables
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  **-import_pe_table file** import a phase-encoding table from file

-  **-import_pe_eddy config indices** import phase-encoding information from an EDDY-style config / index file pair

Options for exporting phase-encode tables
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  **-export_pe_table file** export phase-encoding table to file

-  **-export_pe_eddy config indices** export phase-encoding information to an EDDY-style config / index file pair

Standard options
^^^^^^^^^^^^^^^^

-  **-info** display information messages.

-  **-quiet** do not display information messages or progress status.

-  **-debug** display debugging messages.

-  **-force** force overwrite of output files. Caution: Using the same file as input and output might cause unexpected behaviour.

-  **-nthreads number** use this number of threads in multi-threaded applications (set to 0 to disable multi-threading)

-  **-failonwarn** terminate program if a warning is produced

-  **-help** display this information page and exit.

-  **-version** display version information and exit.

--------------



**Author:** J-Donald Tournier (jdtournier@gmail.com)

**Copyright:** Copyright (c) 2008-2017 the MRtrix3 contributors.

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, you can obtain one at http://mozilla.org/MPL/2.0/.

MRtrix is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

For more details, see http://www.mrtrix.org/.


