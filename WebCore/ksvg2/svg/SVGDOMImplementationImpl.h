/*
    Copyright (C) 2004, 2005 Nikolas Zimmermann <wildfox@kde.org>
                  2004, 2005 Rob Buis <buis@kde.org>

    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef KSVG_SVGDOMImplementationImpl_H
#define KSVG_SVGDOMImplementationImpl_H
#if SVG_SUPPORT

#include "DOMImplementationImpl.h"
#include <qstringlist.h>

namespace WebCore
{
    class DOMString;
    class DocumentImpl;
    class DocumentTypeImpl;
    class CSSStyleSheetImpl;

    typedef FrameView KDOMView;
}

namespace WebCore
{
    class SVGDOMImplementationImpl : public DOM::DOMImplementationImpl
    {
    public:
        SVGDOMImplementationImpl();
        virtual ~SVGDOMImplementationImpl();

        static SVGDOMImplementationImpl *self();

        // 'SVGDOMImplementationImpl' functions
        bool hasFeature(DOMStringImpl *feature, DOMStringImpl *version) const;
        DocumentTypeImpl *createDocumentType(DOMStringImpl *qualifiedName, DOMStringImpl *publicId, DOMStringImpl *systemId, int& exceptioncode) const;
        DocumentImpl *createDocument(DOMStringImpl *namespaceURI, DOMStringImpl *qualifiedName, DocumentTypeImpl *doctype, int& exceptioncode) const;
        DocumentImpl *createDocument(DOMStringImpl *namespaceURI, DOMStringImpl *qualifiedName, DocumentTypeImpl *doctype, bool createDocElement, KDOMView *view, int& exceptioncode) const;

        virtual CSSStyleSheetImpl *createCSSStyleSheet(DOMStringImpl *title, DOMStringImpl *media) const;

        virtual DocumentTypeImpl *defaultDocumentType() const;

        bool inAnimationContext() const;
        void setAnimationContext(bool value);

    private:
        bool m_animationContext : 1;

        static SVGDOMImplementationImpl *s_instance;
        static QStringList s_features;
    };
}

#endif // SVG_SUPPORT
#endif

// vim:ts=4:noet
