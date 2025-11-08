# multi_tier_standard.yml
name: Organic Software Creature Standard
version: "1.0.0"
description: |
  Executable standard for creating organic software creatures with four biological layers.
  Enforces purity, immutability, lock-free concurrency, and organic relationships.

biological_layers:
  - name: layer1_genetic_code
    alias: "Genetic DNA"
    responsibilities:
      - pure algorithmic functions
      - stateless transformations
      - deterministic mathematical operations
    concurrency_dna: "inherently_thread_safe"
    enforce:
      - "static_linkage_required"
      - "forbid_static_mutable"
      - "deterministic_output"
      - "forbid_side_effects"
      - "require_error_struct"

  - name: layer2_cellular_membrane  
    alias: "Cellular Membrane"
    responsibilities:
      - immutable data contracts
      - type-safe symbolic mappings
      - environmental interface
    concurrency_dna: "lock_free_immutability"
    enforce:
      - "require_immutable_members"
      - "forbid_shared_mutable_state"
      - "require_enum_over_string"
      - "validate_construction_deterministic"

  - name: layer3_nervous_system
    alias: "Nervous System"
    responsibilities:
      - stateful business intelligence
      - multiple independent components
      - atomic/thread-local state management
    concurrency_dna: "atomic_state_management"
    enforce:
      - "mutable_fields_atomic_or_threadlocal"
      - "no_shared_mutable_between_components"
      - "component_specific_validators"
      - "pure_l1_calls_only"

  - name: layer4_conscious_mind
    alias: "Conscious Mind"
    responsibilities:
      - orchestration and coordination
      - ownership of L3 components
      - unified behavioral interface
    concurrency_dna: "thread_local_coordination"
    enforce:
      - "owns_l3_components_by_value"
      - "factory_methods_required"
      - "validate_before_delegation"
      - "error_aggregation_required"

organic_relationships:
  l3_requires_l1: "All L3 components must use only L1 pure functions"
  l2_protects_all: "All external input must pass through L2 membrane"
  l4_owns_l3: "L4 must own L3 components by value"
  cellular_integrity: "Layers maintain mandatory biological contracts"

rules:
  - id: R01_purity_layer1
    description: "Layer1 functions must be pure: no IO, no global state, deterministic."
    severity: error
    layers: [layer1_genetic_code]

  - id: R02_immutability_layer2  
    description: "Layer2 DTOs must be immutable after construction with enum-based constants."
    severity: error
    layers: [layer2_cellular_membrane]

  - id: R03_lock_free_layer3
    description: "Layer3 state must be atomic or thread-local, no shared mutable state between components."
    severity: error  
    layers: [layer3_nervous_system]

  - id: R04_ownership_layer4
    description: "Layer4 must own L3 components by value and provide factory methods."
    severity: error
    layers: [layer4_conscious_mind]

  - id: R05_organic_relationships
    description: "Mandatory biological relationships between layers must be maintained."
    severity: error
    layers: all

ci:
  verify_workflow: .github/workflows/verify_organic_dna.yml
  checks:
    - layer1_purity: tests/test_layer1_purity.py
    - layer2_immutability: tests/test_layer2_immutability.py  
    - layer3_concurrency: tests/test_layer3_concurrency.py
    - layer4_orchestration: tests/test_layer4_orchestration.py
    - organic_integrity: tests/test_organic_relationships.py

schema_dir: schema
codegen_config: codegen_config.yml