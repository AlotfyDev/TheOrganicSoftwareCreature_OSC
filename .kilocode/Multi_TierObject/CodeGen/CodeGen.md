#!/usr/bin/env python3
"""
Advanced code generator for Organic Software Creature architecture.
Generates all four layers with proper biological relationships.
"""
import os, yaml, jinja2
from pathlib import Path

class OrganicCodeGenerator:
    def __init__(self, config_path="codegen_config.yml"):
        self.config = self.load_config(config_path)
        self.template_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader('templates'),
            trim_blocks=True,
            lstrip_blocks=True
        )
    
    def load_config(self, path):
        with open(path, 'r') as f:
            return yaml.safe_load(f)
    
    def generate_layer1(self, schema):
        """Generate L1 Genetic Code pure functions"""
        template = self.template_env.get_template('layer1_pure_functions.j2')
        
        for algorithm in schema.get('algorithms', []):
            code = template.render(
                algorithm=algorithm,
                config=self.config['layer1_settings']
            )
            
            output_file = f"generated/{algorithm['name']}_genetic.hpp"
            Path(output_file).write_text(code)
    
    def generate_layer2(self, schema):
        """Generate L2 Cellular Membrane DTOs and mappers"""
        template = self.template_env.get_template('layer2_dtos.j2')
        
        for dto in schema.get('dtos', []):
            code = template.render(
                dto=dto,
                config=self.config['layer2_settings']
            )
            
            output_file = f"generated/{dto['name']}_membrane.hpp"
            Path(output_file).write_text(code)
    
    def generate_layer3(self, schema):
        """Generate L3 Nervous System components"""
        template = self.template_env.get_template('layer3_components.j2')
        
        for component in schema.get('components', []):
            code = template.render(
                component=component,
                config=self.config['layer3_settings']
            )
            
            output_file = f"generated/{component['name']}_nervous.hpp"
            Path(output_file).write_text(code)
    
    def generate_layer4(self, schema):
        """Generate L4 Conscious Mind orchestrator"""
        template = self.template_env.get_template('layer4_orchestration.j2')
        
        code = template.render(
            creature=schema.get('creature', {}),
            components=schema.get('components', []),
            config=self.config['layer4_settings']
        )
        
        output_file = f"generated/{schema['creature']['name']}_conscious.hpp"
        Path(output_file).write_text(code)
    
    def generate_organic_creature(self, schema_path):
        """Generate complete organic creature with all layers"""
        with open(schema_path, 'r') as f:
            schema = yaml.safe_load(f)
        
        os.makedirs('generated', exist_ok=True)
        
        self.generate_layer1(schema)
        self.generate_layer2(schema) 
        self.generate_layer3(schema)
        self.generate_layer4(schema)
        
        print("✓ Generated organic creature with all four layers")

if __name__ == "__main__":
    generator = OrganicCodeGenerator()
    generator.generate_organic_creature("schema/organic_creature.yml")