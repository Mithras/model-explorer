/* Copyright 2024 The Model Explorer Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "absl/strings/string_view.h"
#include "pybind11/pybind11.h"
#include "pybind11_abseil/import_status_module.h"
#include "pybind11_abseil/status_casters.h"  // IWYU pragma : keep
#include "direct_flatbuffer_to_json_graph_convert.h"
#include "direct_saved_model_to_json_graph_convert.h"
#include "model_json_graph_convert.h"
#include "visualize_config.h"

using tooling::visualization_client::VisualizeConfig;

namespace pybind11 {

PYBIND11_MODULE(_pywrap_convert_wrapper, m) {
  pybind11::google::ImportStatusModule();

  class_<VisualizeConfig>(m, "VisualizeConfig")
      .def(init<>())
      .def_readwrite("const_element_count_limit",
                     &VisualizeConfig::const_element_count_limit);

  m.def(
      "ConvertSavedModelToJson",
      [](const VisualizeConfig& config, absl::string_view model_path) {
        return ::tooling::visualization_client::ConvertSavedModelToJson(
            config, model_path);
      },
      R"pbdoc(
      Converts a SavedModel to visualizer JSON string through tf dialect MLIR 
      module if succeeded, otherwise raises `StatusNotOk` exception.
      )pbdoc");

  m.def(
      "ConvertFlatbufferToJson",
      [](const VisualizeConfig& config, absl::string_view model_path,
         bool is_modelpath) {
        return ::tooling::visualization_client::ConvertFlatbufferToJson(
            config, model_path, is_modelpath);
      },
      R"pbdoc(
      Converts a Flatbuffer to visualizer JSON string through tfl dialect MLIR 
      module if succeeded, otherwise raises `StatusNotOk` exception.
      )pbdoc");

  m.def(
      "ConvertFlatbufferDirectlyToJson",
      [](const VisualizeConfig& config, absl::string_view model_path) {
        return ::tooling::visualization_client::ConvertFlatbufferDirectlyToJson(
            config, model_path);
      },
      R"pbdoc(
      Converts a Flatbuffer directly to visualizer JSON string without MLIR or
      execution. Raises `StatusNotOk` exception if failed.
      )pbdoc");

  m.def(
      "ConvertSavedModelDirectlyToJson",
      [](const VisualizeConfig& config, absl::string_view model_path) {
        return ::tooling::visualization_client::ConvertSavedModelDirectlyToJson(
            config, model_path);
      },
      R"pbdoc(
      Converts a SavedModel directly to visualizer JSON string without MLIR or
      execution. Raises `StatusNotOk` exception if failed.
      )pbdoc");

  m.def(
      "ConvertGraphDefDirectlyToJson",
      [](const VisualizeConfig& config, absl::string_view model_path) {
        return ::tooling::visualization_client::ConvertGraphDefDirectlyToJson(
            config, model_path);
      },
      R"pbdoc(
      Converts a GraphDef directly to visualizer JSON string without MLIR or
      execution. Raises `StatusNotOk` exception if failed.
      )pbdoc");
}

}  // namespace pybind11