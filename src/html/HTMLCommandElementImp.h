/*
 * Copyright 2010-2013 Esrille Inc.
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

#ifndef ORG_W3C_DOM_BOOTSTRAP_HTMLCOMMANDELEMENTIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_HTMLCOMMANDELEMENTIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/html/HTMLCommandElement.h>
#include "HTMLElementImp.h"

#include <org/w3c/dom/html/HTMLElement.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class HTMLCommandElementImp : public ObjectMixin<HTMLCommandElementImp, HTMLElementImp>
{
public:
    // Node
    virtual Node cloneNode(bool deep = true);

    // HTMLCommandElement
    std::u16string getType();
    void setType(const std::u16string& type);
    std::u16string getLabel();
    void setLabel(const std::u16string& label);
    std::u16string getIcon();
    void setIcon(const std::u16string& icon);
    bool getDisabled();
    void setDisabled(bool disabled);
    bool getChecked();
    void setChecked(bool checked);
    std::u16string getRadiogroup();
    void setRadiogroup(const std::u16string& radiogroup);
    html::HTMLElement getCommand();
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return html::HTMLCommandElement::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::HTMLCommandElement::getMetaData();
    }

    HTMLCommandElementImp(DocumentImp* ownerDocument) :
        ObjectMixin(ownerDocument, u"command") {
    }
    HTMLCommandElementImp(HTMLCommandElementImp* org, bool deep) :
        ObjectMixin(org, deep) {
    }
};

}}}}  // org::w3c::dom::bootstrap

#endif  // ORG_W3C_DOM_BOOTSTRAP_HTMLCOMMANDELEMENTIMP_H_INCLUDED
