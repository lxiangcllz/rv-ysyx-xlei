#!/usr/bin/env python3
"""Convert Logisim v3.0 hex memory image to raw binary."""

import sys


def logisim_hex_to_bytes(path):
    out = bytearray()
    with open(path, encoding="ascii") as fp:
        for line in fp:
            line = line.strip()
            if not line or line.startswith("v3.0"):
                continue
            _, _, words = line.partition(":")
            for word in words.split():
                val = int(word, 16)
                out.extend(
                    [
                        val & 0xFF,
                        (val >> 8) & 0xFF,
                        (val >> 16) & 0xFF,
                        (val >> 24) & 0xFF,
                    ]
                )
    return bytes(out)


def main():
    if len(sys.argv) != 3:
        print(f"usage: {sys.argv[0]} <input.hex> <output.bin>", file=sys.stderr)
        sys.exit(1)
    data = logisim_hex_to_bytes(sys.argv[1])
    with open(sys.argv[2], "wb") as fp:
        fp.write(data)
    print(f"wrote {len(data)} bytes to {sys.argv[2]}")


if __name__ == "__main__":
    main()
