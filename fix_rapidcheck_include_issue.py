#!/usr/bin/env python3

import os
import glob

def fix_rapidcheck_include_issue(file_path):
    """Add missing exception header to fix RapidCheck compilation issue"""
    with open(file_path, 'r') as f:
        content = f.read()
    
    # Add the exception header before rapidcheck/gtest.h
    new_content = content.replace(
        '#include <rapidcheck/gtest.h>',
        '#include <exception>\n#include <rapidcheck/gtest.h>'
    )
    
    # Write the fixed content
    with open(file_path, 'w') as f:
        f.write(new_content)

def main():
    # Get all test files
    test_pattern = "/Users/goodmaa3/com/github/0x00b1/special-functions/test/*_test.cpp"
    test_files = glob.glob(test_pattern)
    
    print(f"Fixing RapidCheck include issue in {len(test_files)} test files...")
    
    for test_file in sorted(test_files):
        function_name = os.path.basename(test_file).replace('_test.cpp', '')
        fix_rapidcheck_include_issue(test_file)
        print(f"Fixed {function_name}_test.cpp")
    
    print(f"\nFixed all {len(test_files)} test files")
    print("Added #include <exception> to resolve RapidCheck compilation issue")

if __name__ == "__main__":
    main()