Micro 6x7px font for mcu/embedded project

Original idea by FireFly

Memory size
- digits + symbols - 13 \* 3 bytes each half glyph + 19 \* 1 byte indexes = 58 bytes
- all (digits + symbols + alphabet) - 24 \* 3 bytes each half glyph + 47 \* 2 bytes indexes = 166 bytes

indexes arrays may be unneeded if you use fixed print

![](https://github.com/bga/bit-font/raw/master/media/bit-font.png)
