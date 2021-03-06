/*
 * Copyright 2011-2013 Esrille Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>

#include <org/w3c/dom/Node.h>
#include <org/w3c/dom/Element.h>
#include <org/w3c/dom/css/CSSStyleSheet.h>

#include "css/ViewCSSImp.h"

std::ostream& operator<<(std::ostream& stream, org::w3c::dom::Node node);
void dumpTree(std::ostream& result, org::w3c::dom::Node node, std::string indent = "");

void dumpStyleSheet(std::ostream& result, org::w3c::dom::css::CSSStyleSheet sheet);

void printComputedValues(org::w3c::dom::Node node, org::w3c::dom::bootstrap::ViewCSSImp* view, std::string indent = "");

org::w3c::dom::css::CSSStyleSheet loadStyleSheet(std::istream& stream);
org::w3c::dom::css::CSSStyleSheet loadStyleSheet(const char* path);

org::w3c::dom::Document loadDocument(std::istream& stream);
org::w3c::dom::Document loadDocument(const char* html);

unsigned recordTime(const char* msg, ...);
unsigned getTick();

inline bool isReplacedElement(org::w3c::dom::Element& element)
{
    std::u16string tag = element.getLocalName();  // TODO: Check HTML namespace
    if (tag == u"img" || tag == u"iframe" || tag == u"object")  // TODO: more tags to come...
        return true;
    return false;
}

void initLogLevel(int* argc, char* argv[], int defaultLevel = 3);
int getLogLevel();

std::string getFileURL(const std::string& path);

//
// Test.glut.cpp
//
void init(int* argc, char* argv[], int width = -1, int height = -1);
bool isMainThread();
void deleteTexture(unsigned texture);

//
// Test.x11.cpp
//
void setWindowClass(const char* name, const char* cls);
void setWindowTitle(const std::string& title);
void setIcon(size_t n, size_t width, size_t height, uint32_t* image);

//
// ViewCSSImpGL.cpp
//
void initFonts(int* argc, char* argv[]);

#endif  // TEST_UTIL_H
