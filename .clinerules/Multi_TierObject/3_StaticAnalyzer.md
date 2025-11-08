#!/usr/bin/env python3
"""
Static analyzer for Organic Software Creature architecture.
Validates all four layers and their biological relationships.
"""
import sys, os, re, yaml, ast
from pathlib import Path

class OrganicAnalyzer:
    def __init__(self, standard_path="multi_tier_standard.yml"):
        self.standard = self.load_standard(standard_path)
        self.issues = []
        
    def load_standard(self, path):
        with open(path, 'r') as f:
            return yaml.safe_load(f)
    
    def analyze_file(self, file_path):
        """Analyze a single file for organic architecture compliance"""
        content = Path(file_path).read_text()
        
        # Layer-specific analysis
        if self.is_layer1_file(file_path):
            self.analyze_layer1(content, file_path)
        elif self.is_layer2_file(file_path):
            self.analyze_layer2(content, file_path)  
        elif self.is_layer3_file(file_path):
            self.analyze_layer3(content, file_path)
        elif self.is_layer4_file(file_path):
            self.analyze_layer4(content, file_path)
            
        # Cross-layer relationship analysis
        self.analyze_organic_relationships(content, file_path)
    
    def is_layer1_file(self, file_path):
        return any(pattern in file_path for pattern in ['_genetic.', '_pure.', '/layer1/'])
    
    def is_layer2_file(self, file_path):
        return any(pattern in file_path for pattern in ['_membrane.', '_dto.', '/layer2/'])
    
    def is_layer3_file(self, file_path):
        return any(pattern in file_path for pattern in ['_nervous.', '_stateful.', '/layer3/'])
    
    def is_layer4_file(self, file_path):
        return any(pattern in file_path for pattern in ['_conscious.', '_orchestration.', '/layer4/'])
    
    def analyze_layer1(self, content, file_path):
        """Analyze L1 Genetic Code for purity violations"""
        # Check for mutable state
        if re.search(r'\bstatic\s+\w+\s+\w+\s*=', content):
            self.issues.append(f"L1_VIOLATION: Mutable static state in {file_path}")
            
        # Check for side effects
        if re.search(r'\b(std::cout|printf|fopen|new\s+[^ ]+\[)', content):
            self.issues.append(f"L1_VIOLATION: Side effects in pure function {file_path}")
    
    def analyze_layer2(self, content, file_path):
        """Analyze L2 Cellular Membrane for immutability violations"""
        # Check for non-const fields
        if re.search(r'^\s*\w+\s+\w+;', content, re.MULTILINE) and not re.search(r'\bconst\b', content):
            self.issues.append(f"L2_VIOLATION: Non-const fields in DTO {file_path}")
            
        # Check for string literals in configuration
        if re.search(r'=\s*"[^"]*"', content) and 'fromString' not in content:
            self.issues.append(f"L2_VIOLATION: String literals without enum mapping in {file_path}")
    
    def analyze_layer3(self, content, file_path):
        """Analyze L3 Nervous System for concurrency violations"""
        # Check for non-atomic mutable state
        if re.search(r'\b(int|long|bool)\s+\w+;', content) and not re.search(r'\bstd::atomic<', content):
            self.issues.append(f"L3_VIOLATION: Non-atomic mutable state in {file_path}")
            
        # Check for shared mutable state patterns
        if re.search(r'\bstatic\s+std::atomic<', content):
            self.issues.append(f"L3_VIOLATION: Shared mutable state between components in {file_path}")
    
    def analyze_layer4(self, content, file_path):
        """Analyze L4 Conscious Mind for ownership violations"""
        # Check for proper L3 component ownership
        if re.search(r'std::shared_ptr<.*_nervous>', content):
            self.issues.append(f"L4_VIOLATION: Shared ownership of L3 components in {file_path}")
            
        # Check for factory methods
        if not re.search(r'static.*create.*\(', content):
            self.issues.append(f"L4_VIOLATION: Missing factory methods in {file_path}")
    
    def analyze_organic_relationships(self, content, file_path):
        """Analyze cross-layer biological relationships"""
        # L3 must call L1 only
        if '_nervous.' in file_path and not re.search(r'_genetic::', content):
            self.issues.append(f"ORGANIC_VIOLATION: L3 not calling L1 in {file_path}")
            
        # L4 must own L3 by value
        if '_conscious.' in file_path and re.search(r'&.*_nervous', content):
            self.issues.append(f"ORGANIC_VIOLATION: L4 using references to L3 in {file_path}")

def main():
    analyzer = OrganicAnalyzer()
    
    # Analyze all source files
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file.endswith(('.hpp', '.cpp', '.h', '.cc')):
                analyzer.analyze_file(os.path.join(root, file))
    
    # Report issues
    if analyzer.issues:
        print("ORGANIC ARCHITECTURE VIOLATIONS FOUND:")
        for issue in analyzer.issues:
            print(f"  - {issue}")
        return 1
    else:
        print("✓ Organic architecture validation passed")
        return 0

if __name__ == "__main__":
    sys.exit(main())