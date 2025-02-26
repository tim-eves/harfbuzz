// SPDX-License-Identifier: MIT
// Copyright 2010, SIL International, All rights reserved.

#pragma once

#include "inc/Main.h"
#include "inc/Face.h"

namespace graphite2 {

class Face;

class Cmap
{
public:

    virtual ~Cmap() throw() {}

    virtual uint16_t operator [] (const uint32_t) const throw() { return 0; }

    virtual operator bool () const throw() { return false; }

    CLASS_NEW_DELETE;
};

class DirectCmap : public Cmap
{
    DirectCmap(const DirectCmap &);
    DirectCmap & operator = (const DirectCmap &);

public:
    DirectCmap(const Face &);
    virtual uint16_t operator [] (const uint32_t usv) const throw();
    virtual operator bool () const throw();

    CLASS_NEW_DELETE;
private:
    const Face::Table   _cmap;
    const void        * _smp,
                      * _bmp;
};

class CachedCmap : public Cmap
{
    CachedCmap(const CachedCmap &);
    CachedCmap & operator = (const CachedCmap &);

public:
    CachedCmap(const Face &);
    virtual ~CachedCmap() throw();
    virtual uint16_t operator [] (const uint32_t usv) const throw();
    virtual operator bool () const throw();
    CLASS_NEW_DELETE;
private:
    bool m_isBmpOnly;
    uint16_t ** m_blocks;
};

} // namespace graphite2
