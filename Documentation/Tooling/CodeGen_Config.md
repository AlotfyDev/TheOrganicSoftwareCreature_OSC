# codegen_config.yml
layer1_settings:
  template: "layer1_pure_functions.j2"
  output_suffix: "_genetic.hpp"
  rules:
    - "static_functions_only"
    - "constexpr_when_possible"
    - "error_struct_required"

layer2_settings:
  template: "layer2_dtos.j2" 
  output_suffix: "_membrane.hpp"
  rules:
    - "immutable_structs"
    - "enum_mappers_required"
    - "validation_methods"

layer3_settings:
  template: "layer3_components.j2"
  output_suffix: "_nervous.hpp"
  rules:
    - "atomic_state_fields"
    - "component_validation"
    - "l1_delegation"

layer4_settings:
  template: "layer4_orchestration.j2"
  output_suffix: "_conscious.hpp"
  rules:
    - "factory_methods"
    - "component_ownership"
    - "error_aggregation"

symbolic_mapping:
  enum_style: "scoped_enums"
  mapper_pattern: "<EnumName>Mapper"
  string_conversion: "boundary_only"