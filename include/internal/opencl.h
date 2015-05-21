
// =================================================================================================
// This file is part of the CLTune project, which loosely follows the Google C++ styleguide and uses
// a tab-size of two spaces and a max-width of 100 characters per line.
//
// Author: cedric.nugteren@surfsara.nl (Cedric Nugteren)
//
// This file implements the main OpenCL class which is used to initialize and tear down an OpenCL
// environment, including a single OpenCL platform, device, context, and queue. In turn, this class
// relies on the C++ OpenCL header, which is a wrapper for the C OpenCL API.
//
// -------------------------------------------------------------------------------------------------
//
// Copyright 2014 SURFsara
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//  http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// =================================================================================================

#ifndef CLTUNE_OPENCL_H_
#define CLTUNE_OPENCL_H_

#include <string>
#include <vector>
#include <stdexcept>

#include "internal/clpp11.h"

#include "cltune.h"

namespace cltune {
// =================================================================================================

// See comment at top of file for a description of the class
class OpenCL {
 public:
  
  // Messages printed to stdout (in colours)
  static const std::string kMessageFull;

  // Types of devices to consider
  const cl_device_type kDeviceType = CL_DEVICE_TYPE_ALL;

  // Initializes the OpenCL platform, device, and creates a context and a queue
  explicit OpenCL(const size_t platform_id, const size_t device_id);
  ~OpenCL();

  // Accessors
  const Device device() const { return device_; }
  const Context context() const { return context_; }
  CommandQueue queue() const { return queue_; }
  
 private:

  // Settings
  bool suppress_output_;

  // OpenCL variables
  Platform platform_;
  Device device_;
  Context context_;
  CommandQueue queue_;
};

// =================================================================================================
} // namespace cltune

// CLTUNE_OPENCL_H_
#endif
