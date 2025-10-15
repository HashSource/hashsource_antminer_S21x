#!/bin/bash

# ELF Binary Security Analysis
# https://codeberg.org/koutheir/binary-security-check

FIRMWARE_DIR="/home/danielsokil/Lab/HashSource/hashsource_antminer_S21x/bitmain_firmware/FR-1.1(250416-S21 Hyd.)/minerfs.no_header.image_extract"
OUTPUT_FILE="/home/danielsokil/Lab/HashSource/hashsource_antminer_S21x/BINARY_SECURITY_REPORT.md"

[ ! -d "$FIRMWARE_DIR" ] && { echo "ERROR: Directory not found"; exit 1; }

cd "$FIRMWARE_DIR" || exit 1

cat > "$OUTPUT_FILE" << EOF
# ELF Binary Security Analysis

**Generated:** $(date)
**Firmware:** FR-1.1(250416-S21 Hyd.)
**Tool:** [binary-security-check](https://codeberg.org/koutheir/binary-security-check)


The status of the security feature in the binary is indicated by a letter before the keyword:

- \`+\` means the feature is present/supported.
- \`!\` means the feature is absent/unsupported.
- \`~\` means the feature is probably present/supported.
- \`?\` means the feature status is unknown.

For example, \`!ASLR\` means the binary does not support Address Space Layout Randomization.
---

EOF

find . -type f -executable -exec file {} \; 2>/dev/null | grep -q "ELF" || { echo "No ELF binaries found"; exit 1; }

find . -type f -executable -exec file {} \; 2>/dev/null | grep "ELF" | cut -d: -f1 | sort | while read -r binary; do
    BINARY_PATH="${binary#./}"
    RESULT=$(binary-security-check --sysroot "$FIRMWARE_DIR" "$BINARY_PATH" 2>/dev/null | sed 's/\x1b\[[0-9;]*m//g')
    if [ $? -eq 0 ]; then
        echo "## \`$BINARY_PATH\`" >> "$OUTPUT_FILE"
        echo "" >> "$OUTPUT_FILE"
        echo '```' >> "$OUTPUT_FILE"
        echo "$RESULT" >> "$OUTPUT_FILE"
        echo '```' >> "$OUTPUT_FILE"
        echo "" >> "$OUTPUT_FILE"
    else
        echo "## \`$BINARY_PATH\`" >> "$OUTPUT_FILE"
        echo "" >> "$OUTPUT_FILE"
        echo "**ERROR:** Unable to analyze" >> "$OUTPUT_FILE"
        echo "" >> "$OUTPUT_FILE"
    fi
done

echo "Report saved to: $OUTPUT_FILE"
