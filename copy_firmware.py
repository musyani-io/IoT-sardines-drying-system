#!/usr/bin/env python3
"""
Script to copy firmware.hex file to circuit/proteus directory after successful build.
This script is designed to be run automatically by PlatformIO after building.
The script will create the circuit/proteus directory if it doesn't exist.
"""

import os
import shutil
import sys
from pathlib import Path

def copy_firmware_elf():
    """
    Copy the firmware.elf file from .pio/build/ATmega328P/ to the circuit/proteus directory.
    """
    # Get the project root directory (where this script is located)
    project_root = Path(__file__).parent.absolute()
    
    # Define source and destination paths
    source_path = project_root / ".pio" / "build" / "ATmega328P" / "firmware.hex"
    destination_dir = project_root / "circuit" / "proteus"
    destination_path = destination_dir / "firmware.hex"
    
    try:
        # Check if source file exists
        if not source_path.exists():
            print(f"Error: Source file not found: {source_path}")
            return False
        
        # Create destination directory if it doesn't exist
        destination_dir.mkdir(parents=True, exist_ok=True)
        print(f"Created/verified directory: {destination_dir}")
        
        # Copy the file
        shutil.copy2(source_path, destination_path)
        print(f"Successfully copied firmware.hex to: {destination_path}")
        
        # Get file size for confirmation
        file_size = destination_path.stat().st_size
        print(f"File size: {file_size:,} bytes")
        
        return True
        
    except Exception as e:
        print(f"Error copying firmware.hex: {e}")
        return False

if __name__ == "__main__":
    success = copy_firmware_elf()
    sys.exit(0 if success else 1)
