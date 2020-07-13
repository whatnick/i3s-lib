/*
Copyright 2020 Esri

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of
the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.

For additional information, contact:
Environmental Systems Research Institute, Inc.
Attn: Contracts Dept
380 New York Street
Redlands, California, USA 92373
email: contracts@esri.com
*/

#pragma once
#include "utils/utl_i3s_assert.h"
#include "utils/utl_i3s_export.h"
#include <string>

namespace i3slib
{

namespace utl
{

//use ZLIB directly to decode the stream ( **not** valid for GZIP streams )
I3S_EXPORT int zlib_uncompress(unsigned char* dst, unsigned int dst_size, const unsigned char* src, unsigned int src_size);

static const int MY_DEFAULT_COMPRESSION = 1; // == Z_BEST_SPEED

I3S_EXPORT bool compress_gzip(const std::string& in, std::string* out, int level = MY_DEFAULT_COMPRESSION);
I3S_EXPORT bool compress_gzip(const char* src, int src_size, std::string* out, int level = MY_DEFAULT_COMPRESSION);
I3S_EXPORT bool uncompress_gzip(const std::string& in, std::string* out);

//! return true is GZIP headers (ID1=0x1F, ID2=0x8b) have been found and compression method is deflate bytes[3]=8
bool is_gzip(const unsigned char* packed, int n_bytes) noexcept;

//! return true is GZIP headers (ID1=0x1F, ID2=0x8b) have been found and compression method is deflate bytes[3]=8
inline bool is_gzip(const unsigned char* packed, int n_bytes) noexcept
{
  return n_bytes >= 3 && packed[0] == 0x1F && packed[1] == 0x8b && packed[2] == 0x08;
}

}//endof ::utl

} // namespace i3slib
