#ifndef NODE_INTELLIGENCE_TYPES_H
#define NODE_INTELLIGENCE_TYPES_H

#include <memory>
#include <functional>

// Include enums before namespace
#include "../SupportingTypes/Enums/E_RelationshipType.h"
#include "../SupportingTypes/Enums/E_RelationshipFrequencyBand.h"

#include "../SupportingTypes/Enums/E_DataType.h"
#include "../SupportingTypes/Enums/E_CommunicationProtocol.h"

// Include UniversalHeader after enums (updated to new Multi-Tier Object)
#include "../SupportingTypes/Objects/UniversalHeader/UniversalHeader.hpp"
#include "../SupportingTypes/Structs/S_TemporalFrequency.h"
// Include PathTraversal for NavigationResult
#include "../SupportingTypes/Structs/S_PathTraversal.h"

// Forward declarations to break circular dependencies

    struct SpatialPositioningMatrix;
    struct HierarchicalRelationshipsMatrix;
    struct OutgoingRelationshipsMatrix;
    struct IncomingRelationshipsMatrix;
    struct OutgoingDataflowMatrix;
    struct IncomingDataflowMatrix;




// ============================================
// POSITIONING AND SPATIAL TYPES (MOVED TO SupportingTypes/Structs/)
// ============================================

#include "../SupportingTypes/Structs/S_SpatialCoordinates.h"
#include "../SupportingTypes/Structs/S_SpatialRelationship.h"


// ============================================
// HIERARCHICAL RELATIONSHIP TYPES (MOVED TO SupportingTypes/Structs/)
// ============================================

#include "../SupportingTypes/Structs/S_HierarchyPath.h"
#include "../SupportingTypes/Structs/S_HierarchyTreeNode.h"

// ============================================
// RELATIONSHIP TYPES
// ============================================

#include "../SupportingTypes/Structs/NodeIntelligenceTypes/S_OutgoingRelationship.h"
#include "../SupportingTypes/Structs/S_IncomingRelationship.h"

// ============================================
// DATAFLOW TYPES
// ============================================

#include "../SupportingTypes/Structs/S_OutgoingDataFlow.h"
#include "../SupportingTypes/Structs/S_IncomingDataFlow.h"



// ============================================
// COMPLETE NODE INTELLIGENCE STRUCTURE
// ============================================


// Include the complete intelligence structure
#include "../SupportingTypes/Structs/S_SixMatrixHierarchicalCompleteNodeIntelligence.h"

// ============================================
// ANALYSIS AND INTELLIGENCE TYPES
// ============================================

#include "../SupportingTypes/Structs/NodeIntelligenceTypes/S_CrossMatrixIntelligence.h"
#include "../SupportingTypes/Structs/NodeIntelligenceTypes/S_BidirectionalAnalysis.h"
#include "../SupportingTypes/Structs/NodeIntelligenceTypes/S_PerformanceMetrics.h"

// ============================================
// ERROR AND RESULT TYPES
// ============================================

#include "../SupportingTypes/Structs/NodeIntelligenceTypes/S_Result.h"
#include "../SupportingTypes/Structs/NodeIntelligenceTypes/S_NavigationResult.h"

// ============================================
// CONSTANTS AND DEFAULTS
// ============================================

// Default values

    constexpr double DEFAULT_SPATIAL_COORDINATE = 0.0;
    constexpr double DEFAULT_SPATIAL_RADIUS = 100.0;
    constexpr double DEFAULT_SPATIAL_IMPORTANCE = 0.5;
    constexpr double DEFAULT_RELATIONSHIP_STRENGTH = 0.5;
    constexpr double DEFAULT_FREQUENCY_MHZ = 88.0;
    constexpr double DEFAULT_DIRECTION_DEGREES = 0.0;
    constexpr double DEFAULT_VOLUME_MB = 1.0;
    constexpr double DEFAULT_EFFICIENCY = 0.8;
    constexpr double DEFAULT_SELECTIVITY = 0.7;


// Maximum limits

    constexpr size_t MAX_SPATIAL_RELATIONSHIPS = 1000;
    constexpr size_t MAX_HIERARCHICAL_DEPTH = 50;
    constexpr size_t MAX_DATAFLOW_ENTRIES = 10000;
    constexpr double MAX_FREQUENCY_MHZ = 300000.0; // 300 GHz
    constexpr double MIN_FREQUENCY_MHZ = 0.00053; // 530 Hz


// Radio frequency mappings (from whitepaper specifications)

    constexpr double HIERARCHY_FREQUENCY = 88.0;      // FM 88.0 MHz - Hierarchy
    constexpr double CORRELATION_FREQUENCY = 720.0;   // AM 720 kHz - Correlation
    constexpr double DEPENDENCY_FREQUENCY = 156.0;    // 156.0 MHz - VHF - Dependency
    constexpr double COMMUNICATION_FREQUENCY = 162.0; // 162.0 MHz - VHF - Communication
    constexpr double ENABLING_FREQUENCY = 102.3;      // 102.3 MHz - FM - Enabling
    constexpr double CONTAINMENT_FREQUENCY = 540.0;   // AM 540 kHz - Containment
    constexpr double CAUSATION_FREQUENCY = 101.9;     // FM 101.9 MHz - Causation
    constexpr double SERVICE_FREQUENCY = 146.0;       // 146.0 MHz - VHF - Service
    constexpr double VALIDATION_FREQUENCY = 150.0;    // 150.0 MHz - VHF - Validation
    constexpr double TRIGGER_FREQUENCY = 154.0;       // 154.0 MHz - VHF - Trigger
    constexpr double TEMPORAL_FREQUENCY = 108.0;      // FM 108.0 MHz - Temporal
    constexpr double OPPOSITION_FREQUENCY = 88.5;     // FM 88.5 MHz - Opposition


#endif // NODE_INTELLIGENCE_TYPES_H
