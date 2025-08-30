/* pmem.h - v0.2 - public domain data structures - nickscha 2025

A C89 standard compliant, single header, nostdlib (no C Standard Library) Platform Memory Provider (PMEM).

This Test class defines cases to verify that we don't break the excepted behaviours in the future upon changes.

LICENSE

  Placed in the public domain and also MIT licensed.
  See end of file for detailed license information.

*/
#include "../pmem.h" /* Platform Memory Provider */
#include "test.h"    /* Simple Testing framework */

#define TEST_SIZE 31

void pmem_test_simple(void)
{
  char *ptr;
  unsigned int i;

  pmem block = {0};
  block.memory_size = TEST_SIZE;

  assert(pmem_allocate(&block));
  assert(block.memory_size == TEST_SIZE);
  assert(block.memory != (void *)0);

  ptr = (char *)block.memory;

  /* Verify that the memory is zeroed and accessible */
  for (i = 0; i < block.memory_size; ++i)
  {
    assert(ptr[i] == 0);
  }

  assert(pmem_free(&block));
}

void pmem_test_doulbe_free(void)
{
  pmem block = {0};
  block.memory_size = TEST_SIZE;

  assert(pmem_allocate(&block));
  assert(block.memory_size == TEST_SIZE);
  assert(block.memory != (void *)0);

  assert(pmem_free(&block));
  assert(!pmem_free(&block)); /* Second time free should fail because it was already freed */
}

int main(void)
{
  pmem_test_simple();
  pmem_test_doulbe_free();

  return 0;
}

/*
   -----------------------------------------------------------------------------
   This software is available under 2 licenses -- choose whichever you prefer.
   ------------------------------------------------------------------------------
   ALTERNATIVE A - MIT License
   Copyright (c) 2025 nickscha
   Permission is hereby granted, free of charge, to any person obtaining a copy of
   this software and associated documentation files (the "Software"), to deal in
   the Software without restriction, including without limitation the rights to
   use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
   of the Software, and to permit persons to whom the Software is furnished to do
   so, subject to the following conditions:
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
   ------------------------------------------------------------------------------
   ALTERNATIVE B - Public Domain (www.unlicense.org)
   This is free and unencumbered software released into the public domain.
   Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
   software, either in source code form or as a compiled binary, for any purpose,
   commercial or non-commercial, and by any means.
   In jurisdictions that recognize copyright laws, the author or authors of this
   software dedicate any and all copyright interest in the software to the public
   domain. We make this dedication for the benefit of the public at large and to
   the detriment of our heirs and successors. We intend this dedication to be an
   overt act of relinquishment in perpetuity of all present and future rights to
   this software under copyright law.
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
   WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
   ------------------------------------------------------------------------------
*/
