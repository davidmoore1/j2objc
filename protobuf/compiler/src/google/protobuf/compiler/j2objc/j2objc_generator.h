// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: kstanger@google.com (Keith Stanger)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.
//
// Generates Objective-C code for a given .proto file, that is compatible
// with client code that expects a transpiled Java API.

#ifndef GOOGLE_PROTOBUF_COMPILER_J2OBJC_GENERATOR_H__
#define GOOGLE_PROTOBUF_COMPILER_J2OBJC_GENERATOR_H__

#include <string>

#include "google/protobuf/compiler/j2objc/common.h"

namespace google {
namespace protobuf {
namespace compiler {
namespace j2objc {

class J2ObjCGenerator : public CodeGenerator {
 public:
  J2ObjCGenerator();
  ~J2ObjCGenerator();

  // implements CodeGenerator ----------------------------------------
  bool Generate(const FileDescriptor* file, const std::string& parameter,
                GeneratorContext* context, std::string* error) const override;

  uint64_t GetSupportedFeatures() const override {
    return FEATURE_PROTO3_OPTIONAL | FEATURE_SUPPORTS_EDITIONS;
  }

  Edition GetMinimumEdition() const override { return Edition::EDITION_PROTO2; }
  Edition GetMaximumEdition() const override { return Edition::EDITION_2023; }

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(J2ObjCGenerator);
};

}  // namespace j2objc
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

#endif  // GOOGLE_PROTOBUF_COMPILER_J2OBJC_GENERATOR_H__
